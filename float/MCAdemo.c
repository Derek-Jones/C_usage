/* Monte Carlo Arithmetic tests */
/* Copyright (c) 1999 D. Stott Parker */

        /* $Id: MCAdemo.c,v 1.10 1999/06/29 19:20:20 stott Exp stott $ */
/*
 *  5 Dec 08  Derek M. Jones
 * 
 * Updated to use float.h
 * _HIDDENBIT and FSIGNIF not dependent on IEEE_UNAVAILABLE
 * Provided command line support for some calculations
 */

/*
**
** Compile this program with the command:
**
**           gcc  <...flags...>  MCAdemo.c  -lm
**
** Here "gcc" is an example of a C compiler.
**
** Available flags:
**
** -DRANDOM
**      use random() instead of drand48()
**
** -DSKEWNESS_AND_EXCESS
**      numerical analysis tests should not only find averages and std. errors,
**      but also find skewness (normalized 3rd moment) and excess (4th moment).
**
** -DSCATTERPLOTS
**      the program for cos(z) and T20(z) generates random points with MCA.
**
** -DPIVOTING
**      the Gaussian elimination routine performs pivoting (partial pivoting).
**
** -DCOMPLETE -DPIVOTING
**      the Gaussian elimination routine not only uses pivoting,
**      it uses complete pivoting.
**
** -DTRACE
**      the MCA arithmetic routines are all traced.
**
*/

/*----------------------------------------------------------------------*/
/*                  CONFIGURATION-DEPENDENT CODE                        */
/*----------------------------------------------------------------------*/
/*     If IEEE FP is not available on your system, or if your           */
/*     library does not contain the scalbn() and ilogb() functions,     */
/*     modify the definitions below as appropriate.                     */
/*----------------------------------------------------------------------*/
/*  Standard constants for IEEE 754 single precision are shown.  This   */
/*  assumes 32-bit single precision binary floating-point arithmetic,   */
/*  with 24-bit fractions (one bit being an implicit "hidden bit")      */
/*  and 8-bit exponents (using an offset of 127 to make it positive).   */
/*  IEEE double format has 11-bit exponents (and an offset of 1023).    */
/*  It also assumes casting a double to float does round-to-nearest.    */
/*  If your FP system meets these assumptions, even if not IEEE FP,     */
/*  there is a good chance this program will still operate as intended. */
/*----------------------------------------------------------------------*/

#include <float.h>
#include <math.h>
#include <stdlib.h>
#include <values.h>

#ifdef AIX
#define _HIDDENBIT      1
#define   scalbn        scalb
#endif

#define _HIDDENBIT      1

#define  FSIGNIF        FLT_MANT_DIG

#ifdef IEEE_UNAVAILABLE

#define  FMAXEXP        128
#define  FMINEXP        -127
#define  DMAXEXP        1024
#define  DMINEXP        -1023
#define  MAXINT         2147483647

/* include these functions if they are undefined */
double scalbn(double x, int n)
{
        int i = n;
        double X = x;
        /* IEEE checks here whether X is NaN or +/-INF */
        if (i > DMAXEXP) return  1.0/0.0 ;
        if (i < DMINEXP) return -1.0/0.0 ;
        while (i > 0) { X *= 2.0; i--; }
        while (i < 0) { X *= 0.5; i++; }
        return X;
}

int ilogb(double x)
{
        double X = x;
        int i = 0;
        /* IEEE checks here whether X is NaN or +/-INF */
        if (X < 0.0) X = -X;
        if (X == 0.0) return MAXINT;
        while (X < 1.0 && i > DMINEXP) { X *= 2.0; i--; }
        while (X > 1.0 && i < DMAXEXP) { X *= 0.5; i++; }
        return i;
}

#endif



#define IEEE_single_fraction_precision  FSIGNIF
#define exponent(d)     ilogb(d)


#define scaled_to_virtual_precision(d,e)        \
        scalbn((d),(e) - (virtual_precision - _HIDDENBIT))

static int virtual_precision = IEEE_single_fraction_precision;
                                        /*** DEFAULT: single precision ***/

/* This implements virtual precision only up to single precision. */
static int
mca_set_virtual_precision (int t)
{
        int previous_virtual_precision = virtual_precision;
        if (1 <= t && t <= IEEE_single_fraction_precision)
                virtual_precision = t;
        return previous_virtual_precision;
}

#ifdef RANDOM
long random (void);
#define u01     (random () / 2147483648.0) /* uniformly random in [0, 1) */ 
#else
double drand48 (void);
#define u01     (drand48 ()) /* uniformly random in [0, 1) */
#endif

/*----------------------------------------------------------------------*/

#define U       u01
#define Umu     0.5                     /* (1/2) = mean of U */
#define Usigma  0.28867513459481288225  /* sqrt(1/12) = stddev of U */
#define SQRT10  3.1622776601683793320
#define NORMAL(mu,sigma)        mu+sigma*(U+U+U+U+U+U+U+U+U+U-10*Umu)/(SQRT10*Usigma)


#define IS_ZERO(d)      ((d == 0.0) || (d == -0.0))

#define absolute_perturbation_at_virtual_precision(d,noise)     \
                (IS_ZERO(d) ? d : d+scaled_to_virtual_precision(noise,exponent(d)))
#define relative_perturbation_at_virtual_precision(d,noise)     \
                (IS_ZERO(d) ? d : d*(1.0 + scaled_to_virtual_precision(noise,0)))

static double u01_value;
static double cestac_value;
#define CESTAC_noise    ( ((u01_value=u01) < 0.25) ? ((double) -1)      \
                                : ((u01_value > 0.75) ? ((double) 1)    \
                                : ((double) 0)))
#define PER(d)  ((IS_ZERO(d) || ((cestac_value = CESTAC_noise) == 0)) ? d \
                 : absolute_perturbation_at_virtual_precision(d,cestac_value))
#define uniform_noise   (u01 - 0.5)

/*
**
** IEEE round-to-nearest is assumed to be the default by this program.
**
*/

#define NEAREST_FLOAT(x)        ((float) (x))
        /* assumes IEEE round-to-nearest (FP_RN) is on by default.  */

#define round_to_float(x)       NEAREST_FLOAT(outbound(x))

#define EXACT(x)        NEAREST_FLOAT(x)
#define INEXACT(x)      round_to_float(x)


typedef int randomization_method;

#define identity        1
#define uniform_absolute        2
#define uniform_relative        3
#define CESTAC  4
#define randomization_method_limit      5

  /* Randomize as in CESTAC (for machines with rounding):
     add -1 with probability 1/4,
     add  0 with probability 1/2,
     add +1 with probability 1/4.  */


char* randomization_method_name (randomization_method r)
{
  switch (r) {
    case identity:                  return "identity";
    case uniform_absolute:          return "uniform_absolute";
    case uniform_relative:          return "uniform_relative";
    case CESTAC:                    return "CESTAC";
    default:                        return "??";
  }
}


static randomization_method inbound_method = uniform_relative;
                                        /*** DEFAULT ***/

static randomization_method outbound_method = uniform_relative;
                                        /*** DEFAULT ***/

static randomization_method
mca_set_inbound_method (randomization_method r)
{
        randomization_method previous_inbound_method = inbound_method;
        inbound_method = r;
        return previous_inbound_method;
}

static randomization_method
mca_set_outbound_method (randomization_method r)
{
        randomization_method previous_outbound_method = outbound_method;
        outbound_method = r;
        return previous_outbound_method;
}



static double
inbound (float fa)
{
  double a = (double) fa;
  if IS_ZERO(fa) return a;

/* The only 'exact' value we handle now is zero (IEEE doesn't track exacts) */
/* There is no way to randomize zero:  zero is exact, and has no exponent.  */
/* Stretch defined zero with exponent (permitting significance tracking). */

  switch (inbound_method) {

    case identity:
      return a;

    case uniform_absolute:
      return absolute_perturbation_at_virtual_precision(a,uniform_noise);

    case uniform_relative:
      return relative_perturbation_at_virtual_precision(a,uniform_noise);

    case CESTAC:
      return PER(a);

    default:
      abort ();
    }
}

static double
outbound (double a)
{
  if IS_ZERO(a) return a;

/* The only 'exact' value we handle now is zero (IEEE doesn't track exacts) */
/* There is no way to randomize zero:  zero is exact, and has no exponent.  */
/* Stretch defined zero with exponent (permitting significance tracking). */

  switch (outbound_method) {

    case identity:
      return a;

    case uniform_absolute:
      return absolute_perturbation_at_virtual_precision(a,uniform_noise);

    case uniform_relative:
      return relative_perturbation_at_virtual_precision(a,uniform_noise);

    case CESTAC:
      return PER(a);

    default:
      abort ();
    }
}

/*
** This program does not attempt to be fast.
** Nor does it pretend to be exact (though it tries to be very close).
**
*/

static double double_add (double a, double b) { return a + b; }
static float float_add (float a, float b) { return NEAREST_FLOAT(a + b); }
float mca_add (float a, float b)
{
#ifdef TRACE
     double ra, rb; float rab;
     ra = inbound(a);
     rb = inbound(b);
     rab = round_to_float( ra + rb );
     printf("mca add %g + %g => %g + %g => %g\n", a,b,ra,rb,rab);
     return rab;
#else
     return round_to_float( inbound(a) + inbound(b) );
#endif
}

static double double_subtract (double a, double b) { return a - b; }
static float float_subtract (float a, float b) { return NEAREST_FLOAT(a - b); }
float mca_subtract (float a, float b)
{
#ifdef TRACE
     double ra, rb; float rab;
     ra = inbound(a);
     rb = inbound(b);
     rab = round_to_float( ra - rb );
     printf("mca sub %g - %g => %g - %g => %g\n", a,b,ra,rb,rab);
     return rab;
#else
     return round_to_float( inbound(a) - inbound(b) );
#endif
}

static double double_multiply (double a, double b) { return a * b; }
static float float_multiply (float a, float b) { return NEAREST_FLOAT(a * b); }
float mca_multiply (float a, float b)
{
#ifdef TRACE
  double ra, rb; float rab;
  ra = inbound(a);
  rb = inbound(b);
  rab = round_to_float( ra * rb );
  printf("mca mul %g * %g => %g * %g => %g\n", a,b,ra,rb,rab);
  return rab;
#else
  return round_to_float( inbound(a) * inbound(b) );
#endif
}

static double double_divide (double a, double b) { return a / b; }
static float float_divide (float a, float b) { return NEAREST_FLOAT(a / b); }
float mca_divide (float a, float b)
{
#ifdef TRACE
  double ra, rb; float rab;
  ra = inbound(a);
  rb = inbound(b);
  rab = round_to_float( ra / rb );
  printf("mca div %g / %g => %g / %g => %g\n", a,b,ra,rb,rab);
  return rab;
#else
  return round_to_float( inbound(a) / inbound(b) );
#endif
}

static double double_square (double a) { return double_multiply(a,a); }
static float float_square (float a) { return float_multiply(a,a); }
float mca_square (float a) {
#ifdef TRACE
  double ra, rb; float raa;
  ra = inbound(a);
  rb = inbound(a);
  raa = round_to_float( ra * rb );
  printf("mca sqr %g => %g * %g => %g\n", a,ra,rb,raa);
  return raa;
#else
  return mca_multiply( a, a );
#endif
}

static double double_sqrt (double a) { return sqrt(a); }
static float float_sqrt (float a)
{
  return NEAREST_FLOAT( sqrt((double) a) );
}
float mca_sqrt (float a)
{
#ifdef TRACE
  double ra; float raa;
  ra = inbound(a);
  raa = round_to_float( sqrt( ra ) );
  printf("mca sqt %g => sqrt %g => %g\n", a,ra,raa);
  return raa;
#else
  return round_to_float( sqrt( inbound(a) ) );
#endif
}

double double_power(double a, int n)
{
  register int i;
  register double t = a;
  for (i=2 ; i <= n ; i++) t *= a;
  return t;
}

float float_power(float a, int n)
{
  register int i;
  register float t = a;
  for (i=2 ; i <= n ; i++) t *= a;
  return t;
}

float mca_power(float a, int n)
{
  register int i;
  register float t = a;
  for (i=2 ; i <= n ; i++) t = mca_multiply(a, t);
#ifdef TRACE
  printf("mca pow %g ^ %d => %g\n", a,n,t);
#endif
  return t;
}

typedef int bool;

bool mca_eq (float a, float b) { return  IS_ZERO(mca_subtract(a,b)); }
bool mca_ne (float a, float b) { return !IS_ZERO(mca_subtract(a,b)); }
bool mca_gt (float a, float b) { return (mca_subtract(a,b) >  0.0); }
bool mca_ge (float a, float b) { return (mca_subtract(a,b) >= 0.0); }
bool mca_lt (float a, float b) { return (mca_subtract(a,b) <  0.0); }
bool mca_le (float a, float b) { return (mca_subtract(a,b) <= 0.0); }



#include <stdio.h>

typedef struct stats {
    double N;
    double A, M2;
#ifdef SKEWNESS_AND_EXCESS
    double M3, M4;
#endif
} STATS;

static double N1, N, DX, DX2, Test;

#ifdef SKEWNESS_AND_EXCESS
#define init_stats(x)   {x.N = 0; x.A = 0; x.M2 = 0; x.M3 = 0; x.M4 = 0;}
/*
** semi-clever incremental algorithm for maintaining moments 2, 3, 4.
** M2 is N times the second moment, M3 is N times the third moment, etc.
** Adapted from:
**   C.C. Spicer, Calculation of Power Sums of Deviations About the Mean,
**   Applied Statistics 21, p.226 (1972).
*/
#define record_stats(v,x) {     \
        N1 = x.N;               \
        N  = N1+1;              \
        DX = (v-x.A)/N;         \
        DX2 = DX*DX;            \
        x.M4 += -DX * (4*x.M3 - DX * (6*x.M2 + N1 * (1 + N1*N1*N1) * DX2));     \
        x.M3 += -DX * (3*x.M2 - N*N1*(N-2) * DX2);      \
        x.M2 += N * N1 * DX2;   \
        x.A  += DX;             \
        x.N++;                  \
}
#else
#define init_stats(x)   {x.N = 0; x.A = 0; x.M2 = 0;}
/*
** semi-clever incremental algorithm for maintaining average A
** and M2, which is N times the second moment.  From Knuth v.2 (2nd ed).
*/
#define record_stats(v,x) {     \
        DX = (v-x.A);           \
        x.N  += 1;              \
        x.A  += DX/x.N;         \
        x.M2 += DX * (v-x.A);   \
}
#endif

#define stats_average(x)        ( (x.A) )
#define stats_stderr(x)      ( ((x.N > 1) && (x.M2 > 0)) ? \
                                sqrt(x.M2/(x.N-1)/x.N) : ((double) 0) )
#define stats_stddev(x)      ( ((x.N > 1) && (x.M2 > 0)) ? \
                                sqrt(x.M2/(x.N-1)) : ((double) 0) )
#define skewness(x)          ( (x.M2 > 0) ? \
                                (x.M3 * sqrt(x.N/x.M2) / x.M2) : ((double) 0) )
#define kurtosis(x)          ( ((x.N > 1) && (x.M2 > 0)) ? \
                                (x.M4 * x.N / x.M2 / x.M2 ) : ((double) 0))
#define excess(x)            ( kurtosis(x) - 3 )
#define skewness_variance(N)    ( (6*N*(N-1)) / ((N-2)*(N+1)*(N+3)) )
#define excess_variance(N)      ( (24*N*(N-1)*(N-1)) / ((N-3)*(N-2)*(N+3)*(N+5)) )
/*
**  formulas for unbiased skewness, kurtosis, excess are from pp. 234-235 of:
**  B.L. van der Waerden, Mathematical Statistics, Springer-Verlag, 1969.
**  Actually they are apparently due to R.A. Fisher and explained in
**  Cramer's book on Mathematical Statistics.
**  Skewness is also commonly called "g1", and excess is called "g2".
*/

#define stats_skewness(x)       unbiased_skewness(x)
#define stats_excess(x)    unbiased_excess(x)

#define unbiased_skewness(x) ( ((x.N > 2) && (x.M2 > 0))                        \
                            ? ( skewness(x) * sqrt( x.N * (x.N-1) ) / (x.N-2) ) \
                            : ((double) 0) )

#define unbiased_excess(x)  ( ((x.N > 3) && (x.M2 > 0))                         \
                            ? ( ((x.N+1)*excess(x) + 6) * (x.N-1) / ((x.N-2) * (x.N-3)) )       \
                            : ((double) 0) )

#define skewness_test(x) ( ((N=x.N) > 2)                                        \
                            ? (stats_skewness(x) / sqrt(skewness_variance(N)))  \
                            : ((double) 0) )

#define excess_test(x)   ( ((N=x.N) > 3)                                        \
                            ? (stats_excess(x) / sqrt(excess_variance(N)))      \
                            : ((double) 0) )

#define NTEST(T)         ( ((-2.57 <= (Test=T)) && (Test <= 2.57)) ? "    " : "<***" )
/*
**  if the test is "    ", there is no evidence that the distribution is non-normal.
**  if the test is "<***", there is only a ~1% chance that the distribution is normal,
**      since it is outside 2.57 sigma.
*/


void printline () {
printf(
"----------------------------------------------------------------------------\n"
);
}
void newline () {
  printf("\n");
}

int quadratic_test (int n, int num_samples)
{
  register int sample, scale;

  double d_a, d_b, d_c;
  float  f_a, f_b, f_c;
  float  r_a, r_b, r_c;
  double d_r1,  d_r2;
  float  f_r1,  f_r2;
  float  r_r1,  r_r2;
  STATS  s_r1,  s_r2;
  int interactive, inexact;

  d_a = (double)  7169;
  d_b = (double) -8686;
  d_c = (double)  2631;

/* 7169 -8686 2631 */

  printf("Enter 0 for default coefficients, 1 for prompted input of a, b, c: ");
  scanf("%d", &interactive);
  newline();
  if (interactive) {
        printf("a = ");
        scanf("%lg", &d_a);
        printf("b = ");
        scanf("%lg", &d_b);
        printf("c = ");
        scanf("%lg", &d_c);
  }

  printf("Enter 0 if coefficients are EXACT, or 1 if they are INEXACT: ");
  scanf("%d", &inexact);
  newline();

  if (d_b*d_b - 4*d_a*d_c < 0) d_c = -d_c;

  /* things are chosen so that (b^2 - 4*a*c) >= 0, for simplicity */

  scale = n;
  while ((scale--) > 0) {   /* make the problem more ill-conditioned */
        d_b = d_b * 2;
  }

  f_a = NEAREST_FLOAT(d_a);
  f_b = NEAREST_FLOAT(d_b);
  f_c = NEAREST_FLOAT(d_c);

  newline();
  printline();
  printf("Quadratic equation test\n");
  printf("Solving the equation\n");
  printf("%11.7f x^2 %11.7f x  +%11.7f   =   0 \n", d_a, d_b, d_c );
  printf("using the standard quadratic formula:\n");
  printf("        r1 = (-b + sqrt(b*b - 4*a*c)) / (2*a); \n");
  printf("        r2 = (-b - sqrt(b*b - 4*a*c)) / (2*a); \n");
  printf("NOTE:  input coefficients are assumed to be %s\n",
         (inexact ? "INEXACT" : "EXACT") );
  newline();
  printf("Results with   inbound %s   outbound %s\n",
          randomization_method_name(inbound_method),
          randomization_method_name(outbound_method));
  printf("also  virtual precision %d \n(averaged over %d samples):\n",
          virtual_precision,
          num_samples);
  printline();
  newline();

  d_r1 = double_divide(
           double_add(
             -d_b,
             double_sqrt(
               double_subtract(
                 double_square(d_b),
                 ((double) 4) * double_multiply(d_a,d_c))
               )),
           (((double) 2) * d_a));
  d_r2 = double_divide(
           double_add(
             -d_b,
             -double_sqrt(
                double_subtract(
                  double_square(d_b),
                  ((double) 4) * double_multiply(d_a,d_c))
              )),
           (((double) 2) * d_a));

  f_r1 = float_divide(
           float_add(
             -f_b,
             float_sqrt(
               float_subtract(
                 float_square(f_b),
                 ((float) 4) * float_multiply(f_a,f_c))
             )),
           (((float) 2) * f_a));
  f_r2 = float_divide(
           float_add(
             -f_b,
             -float_sqrt(
                float_subtract(
                  float_square(f_b),
                  ((float) 4) * float_multiply(f_a,f_c))
                )),
           (((float) 2) * f_a));

  printf("IEEE double precision roots:  %21.14e %21.14e \n", d_r1, d_r2 );
  printf("IEEE single precision roots:  %12.5e          %12.5e \n", f_r1, f_r2 );
  newline();

  init_stats(s_r1);
  init_stats(s_r2);

  for ( sample=1; sample<=num_samples; sample++ ) {

    if (inexact) {
       r_a = INEXACT(d_a);
       r_b = INEXACT(d_b);
       r_c = INEXACT(d_c);
    } else {
       r_a = EXACT(d_a);
       r_b = EXACT(d_b);
       r_c = EXACT(d_c);
    }

    r_r1 = mca_divide(
             mca_add(
               -r_b,
               mca_sqrt(
                 mca_subtract(
                   mca_square(r_b),
                   EXACT(4) * mca_multiply(r_a,r_c))
                )),
             (EXACT(2) * r_a));
    r_r2 = mca_divide(
             mca_add(
               -r_b,
               -mca_sqrt(
                  mca_subtract(
                    mca_square(r_b),
                    EXACT(4) * mca_multiply(r_a,r_c))
                   )),
             (EXACT(2) * r_a));

    printf("%2d. roots computed with MCA:  %12.5e          %12.5e \n",
        sample, r_r1, r_r2 );

    record_stats( r_r1, s_r1 );
    record_stats( r_r2, s_r2 );
  }

  printf("MCA single      average:      %12.5e          %12.5e \n",
                                stats_average(s_r1), stats_average(s_r2) );
  printf("standard deviation           [%12.5e]        [%12.5e]\n",
                                stats_stddev(s_r1), stats_stddev(s_r2) );
  printf("standard error               [%12.5e]        [%12.5e]\n",
                                stats_stderr(s_r1), stats_stderr(s_r2) );
#ifdef SKEWNESS_AND_EXCESS
  printf("skewness                     [%12.5e] %4s   [%12.5e] %4s\n",
                stats_skewness(s_r1), NTEST(stats_skewness(s_r1)),
                stats_skewness(s_r2), NTEST(stats_skewness(s_r2)) );
  printf("excess                       [%12.5e] %4s   [%12.5e] %4s\n",
                stats_excess(s_r1), NTEST(stats_excess(s_r1)),
                stats_excess(s_r2), NTEST(stats_excess(s_r2)) );
#endif

  newline();
  printline();
  newline();
  return 0;
}

int bakeoff_test (int n, int num_samples)
{
  register int sample, scale;

  double d_a, d_b, d_c;
  float  r_a, r_b, r_c;
  double d_r2;
  float  r_r2;
  int interactive, inexact;

  d_a = (double)  7169;
  d_b = (double) -8686;
  d_c = (double)  2631;

  printf("Enter 0 for default coefficients, 1 for prompted input of a, b, c: ");
  scanf("%d", &interactive);
  newline();
  if (interactive) {
        printf("a = ");
        scanf("%lg", &d_a);
        printf("b = ");
        scanf("%lg", &d_b);
        printf("c = ");
        scanf("%lg", &d_c);
  }

  printf("Enter 0 if coefficients are EXACT, or 1 if they are INEXACT: ");
  scanf("%d", &inexact);
  newline();

  if (d_b*d_b - 4*d_a*d_c < 0) d_c = -d_c;

  /* things are chosen so that (b^2 - 4*a*c) >= 0, for simplicity */

  scale = n;
  while (--scale > 0) {   /* make the problem more ill-conditioned */
        d_b = d_b * 2;
  }

  d_r2 = double_divide(
           double_add(
             -d_b,
             -double_sqrt(
                double_subtract(
                  double_square(d_b),
                  ((double) 4) * double_multiply(d_a,d_c))
              )),
           (((double) 2) * d_a));

  printf("Solving the equation\n");
  printf("%11.7f x^2 %11.7f x  +%11.7f   =   0 \n", d_a, d_b, d_c );
  printf("NOTE:  input coefficients are assumed to be %s\n",
         (inexact ? "INEXACT" : "EXACT") );
  printf("Comparison across all inbound/outbound methods\n");
  printf("with  virtual precision %d \n(averaged over %d samples):\n",
          virtual_precision,
          num_samples);
  {
    randomization_method in, out;
    randomization_method old_in  = mca_set_inbound_method(  identity );
    randomization_method old_out = mca_set_outbound_method( identity );
    STATS s_r2;

    printf("outbound                 inbound\n");
    printf("method                   method \n");
    printline();
    printf("                ");
    for (in = 0 ; in < randomization_method_limit ; in++)
      printf(" & %s", randomization_method_name(in) );
    printf(" \\\\\n");
    printline();
    for (out = 0 ; out < randomization_method_limit ; out++) {
      mca_set_outbound_method( out );
      printf("%16s ", randomization_method_name(out) );
      for (in = 0 ; in < randomization_method_limit ; in++) {
        mca_set_inbound_method( in );

        init_stats( s_r2 );

        for ( sample=1; sample<=num_samples; sample++ ) {

          if (inexact) {
             r_a = INEXACT(d_a);
             r_b = INEXACT(d_b);
             r_c = INEXACT(d_c);
          } else {
             r_a = EXACT(d_a);
             r_b = EXACT(d_b);
             r_c = EXACT(d_c);
          }

          r_r2 = mca_divide(
                   mca_add(
                     -r_b,
                     -mca_sqrt(
                        mca_subtract(
                          mca_square(r_b),
                          EXACT(4) * mca_multiply(r_a,r_c))
                         )),
                   (EXACT(2) * r_a));
          record_stats( r_r2, s_r2 );

        }
        printf("&  %3.1f ", log10(d_r2/fabs((d_r2 - stats_average(s_r2)))) );
        printf(" [%3.1f] ", log10(d_r2/stats_stderr(s_r2)) );
      }
      printf(" \\\\\n");
    }
    in =  mca_set_inbound_method( old_in );
    out = mca_set_outbound_method( old_out );
  }
  newline();
  printline();
  newline();

  return 0;
}

int sdev_test (int num_samples, int m)
{
  register int i, sample, cond;

  double d_S2_K, d_M_K, d_T_K, d_Q_K;
  float  f_S2_K, f_M_K, f_T_K, f_Q_K;
  float  r_S2_K, r_M_K, r_T_K, r_Q_K;
  STATS  s_S2_K;

  double d_S2_2, d_XBAR_2;
  float  f_S2_2, f_XBAR_2;
  float  r_S2_2, r_XBAR_2;
  STATS  s_S2_2;

  double d_S2_W, d_XBAR_W, d_M_W, d_T_W, d_Q_W, d_R_W;
  float  f_S2_W, f_XBAR_W, f_M_W, f_T_W, f_Q_W, f_R_W;
  float  r_S2_W, r_XBAR_W, r_M_W, r_T_W, r_Q_W, r_R_W;
  STATS  s_S2_W;

  double d_S2_T, d_XBAR_T, d_SUMX_T, d_SUMX2_T;
  float  f_S2_T, f_XBAR_T, f_SUMX_T, f_SUMX2_T;
  float  r_S2_T, r_XBAR_T, r_SUMX_T, r_SUMX2_T;
  STATS  s_S2_T;

  double d_S2_C, d_XBAR_C, d_M_C, d_T_C, d_Q_C;
  float  f_S2_C, f_XBAR_C, f_M_C, f_T_C, f_Q_C;
  float  r_S2_C, r_XBAR_C, r_M_C, r_T_C, r_Q_C;
  STATS  s_S2_C;

  double d_sigma;

#define MAX_OBSERVATIONS        5000

  double d_x[MAX_OBSERVATIONS];
  float  f_x[MAX_OBSERVATIONS];
  float  r_x[MAX_OBSERVATIONS];

  if (m>MAX_OBSERVATIONS) {
      printf("sdev_test error: recompile with MAX_OBSERVATIONS >= %d\n",m);
      return -1;
  }
  
  printf("Computing standard deviations (from a population of %d values)\n",m);
  printf("Five algorithms drawn from:\n\n");
  printf("  D.E. Knuth, Seminumerical Algorithms (3rd ed.), 1998, p. 232.\n");
  printf("  T. Chan, J.G. Lewis, CACM 22:9, Sept. 1979, p. 528.\n\n");
  printf("With  virtual precision %d \n(averaged over %d samples):\n",
          virtual_precision,
          num_samples);

  printf("For each algorithm to compute the standard deviation, we give:\n");
  printf("    the actual number of significant digits in sample average\n");
  printf("    [the significant digits estimated from stderr of sample average]\n\n");
  printf("Algorithm input: %d random normal values, drawn from N(1.0,sigma)\n\n",m);
  printf("              &  Knuth's  & Two-Pass  &  West's   & Textbook  & Cotton's  \\\\\n");
  printf("     sigma    & algorithm & algorithm & algorithm & algorithm & algorithm \\\\\n");

  d_sigma = 1.0;
  for (cond = 1, d_sigma = 1.0 ; cond <= 7 ; cond++, d_sigma /= 10.0 ) {

    init_stats( s_S2_K );
    init_stats( s_S2_2 );
    init_stats( s_S2_W );
    init_stats( s_S2_T );
    init_stats( s_S2_C );
    
    for ( i=1 ; i <= m ; i++ ) {
        d_x[i] = NORMAL(1.0, d_sigma); 
        f_x[i] = NEAREST_FLOAT(d_x[i]);
        r_x[i] = INEXACT(d_x[i]);
    }
  
    for ( sample=1; sample<=num_samples; sample++ ) {
  
    /*----------------------------------------------------------------------
           Knuth's Algorithm
     ----------------------------------------------------------------------*/
      d_T_K = 0.0;
      d_M_K = d_x[1];
      for ( i=2 ; i <= m ; i++ ) {
          d_Q_K = (d_x[i] - d_M_K);
          d_M_K = d_M_K + d_Q_K / i;
          d_T_K = d_T_K + d_Q_K * (d_x[i] - d_M_K);
      }
      d_S2_K = d_T_K / (m - 1);

      f_T_K = 0.0;
      f_M_K = f_x[1];
      for ( i=2 ; i <= m ; i++ ) {
          f_Q_K = (f_x[i] - f_M_K);
          f_M_K = f_M_K + f_Q_K / i;
          f_T_K = f_T_K + f_Q_K * (f_x[i] - f_M_K);
      }
      f_S2_K = f_T_K / (m - 1);

      r_T_K = 0.0;
      r_M_K = r_x[1];
      for ( i=2 ; i <= m ; i++ ) {
          r_Q_K = mca_subtract( r_x[i] , r_M_K );
          r_M_K = mca_add( r_M_K , mca_divide( r_Q_K, EXACT(i) ));
          r_T_K = mca_add( r_T_K ,
                mca_multiply( r_Q_K , mca_subtract( r_x[i] , r_M_K )));
      }
      r_S2_K = mca_divide( r_T_K , EXACT(m - 1) );

    /*----------------------------------------------------------------------
           Two-Pass Algorithm
     ----------------------------------------------------------------------*/
      d_XBAR_2 = 0.0;
      f_XBAR_2 = 0.0;
      r_XBAR_2 = 0.0;

      for ( i=1 ; i <= m ; i++ ) {
          d_XBAR_2 = d_XBAR_2 + d_x[i];
          f_XBAR_2 = f_XBAR_2 + f_x[i];
          r_XBAR_2 = mca_add( r_XBAR_2 , r_x[i] );
      }
      d_XBAR_2 = d_XBAR_2 / m;
      f_XBAR_2 = f_XBAR_2 / m;
      r_XBAR_2 = mca_divide( r_XBAR_2 , EXACT(m) );

      d_S2_2 = 0.0;
      f_S2_2 = 0.0;
      r_S2_2 = 0.0;
      for ( i=1 ; i <= m ; i++ ) {
          d_S2_2 = d_S2_2 + double_square( d_x[i] - d_XBAR_2 );
          f_S2_2 = f_S2_2 +  float_square( f_x[i] - f_XBAR_2 );
          r_S2_2 = mca_add( r_S2_2 ,
                        mca_square( mca_subtract( r_x[i], r_XBAR_2 )));
      }
      d_S2_2 = d_S2_2 / (m - 1);
      f_S2_2 = f_S2_2 / (m - 1);
      r_S2_2 = mca_divide( r_S2_2 , EXACT(m - 1) );
    
    /*----------------------------------------------------------------------
           West's Algorithm
     ----------------------------------------------------------------------*/
      d_T_W = 0.0;
      f_T_W = 0.0;
      r_T_W = 0.0;

      d_M_W = d_x[1];
      f_M_W = f_x[1];
      r_M_W = r_x[1];

      for ( i=2 ; i <= m ; i++ ) {
          d_Q_W = d_x[i] - d_M_W;
          f_Q_W = f_x[i] - f_M_W;
          r_Q_W = r_x[i] - r_M_W;

          d_R_W = d_Q_W / i;
          f_R_W = f_Q_W / i;
          r_R_W = mca_divide( r_Q_W , EXACT(i) );

          d_M_W = d_M_W + d_R_W;
          f_M_W = f_M_W + f_R_W;
          r_M_W = mca_add( r_M_W , r_R_W );

          d_T_W = d_T_W + (i-1) * d_Q_W * d_R_W;
          f_T_W = f_T_W + (i-1) * f_Q_W * f_R_W;
          r_T_W = mca_add( r_T_W ,
                mca_multiply( EXACT(i-1) ,
                        mca_multiply( r_Q_W , r_R_W )));
      }

      d_S2_W = d_T_W / (m - 1);
      f_S2_W = f_T_W / (m - 1);
      r_S2_W = mca_divide( r_T_W , EXACT(m - 1) );
    
    /*----------------------------------------------------------------------
           Textbook Algorithm
     ----------------------------------------------------------------------*/
      d_SUMX_T = 0.0; d_SUMX2_T = 0.0;
      f_SUMX_T = 0.0; f_SUMX2_T = 0.0;
      r_SUMX_T = 0.0; r_SUMX2_T = 0.0;

      for ( i=1 ; i <= m ; i++ ) {
        d_SUMX_T = d_SUMX_T + d_x[i];
        f_SUMX_T = f_SUMX_T + f_x[i];
        r_SUMX_T = mca_add( r_SUMX_T , r_x[i] );

        d_SUMX2_T = d_SUMX2_T + double_square(d_x[i]);
        f_SUMX2_T = f_SUMX2_T + float_square(f_x[i]);
        r_SUMX2_T = mca_add( r_SUMX2_T , mca_square(r_x[i]) );
      }

        d_XBAR_T = d_SUMX_T / m;
        f_XBAR_T = f_SUMX_T / m;
        r_XBAR_T = mca_divide( r_SUMX_T , EXACT(m) );

        d_S2_T = (d_SUMX2_T - d_XBAR_T * d_SUMX_T) / (m - 1);
        f_S2_T = (f_SUMX2_T - f_XBAR_T * f_SUMX_T) / (m - 1);
        r_S2_T = mca_divide(
                mca_subtract( r_SUMX2_T , mca_multiply( r_XBAR_T , r_SUMX_T )),
                EXACT(m - 1));
    
    /*----------------------------------------------------------------------
           Cotton's Algorithm
     ----------------------------------------------------------------------*/
      d_T_C = 0.0;
      f_T_C = 0.0;
      r_T_C = 0.0;

      d_M_C = d_x[1];
      f_M_C = f_x[1];
      r_M_C = r_x[1];

      for ( i=2 ; i <= m ; i++ ) {
          d_Q_C = d_M_C;
          f_Q_C = f_M_C;
          r_Q_C = r_M_C;

          d_M_C = d_Q_C + (d_x[i] - d_Q_C) / i;
          f_M_C = f_Q_C + (f_x[i] - f_Q_C) / i;
          r_M_C = mca_add( r_Q_C ,
                mca_divide( mca_subtract(r_x[i] , r_Q_C) , EXACT(i) ));

          d_T_C = d_T_C + double_square(d_x[i])
                + (i-1) * double_square(d_Q_C)
                -   i   * double_square(d_M_C);
          f_T_C = f_T_C + float_square(f_x[i])
                + (i-1) * float_square(f_Q_C)
                -   i   * float_square(f_M_C);
          r_T_C = mca_add( r_T_C , mca_add( mca_square(r_x[i]),
                  mca_subtract(
                        mca_multiply( EXACT(i-1) , mca_square(r_Q_C) ),
                        mca_multiply( EXACT(i)   , mca_square(r_M_C) ))));
      }

      d_S2_C = d_T_C / (m - 1);
      f_S2_C = f_T_C / (m - 1);
      r_S2_C = mca_divide( r_T_C, EXACT(m - 1) );


    /*---------------------------------------------------------------------*/



      record_stats( r_S2_K, s_S2_K );
      record_stats( r_S2_2, s_S2_2 );
      record_stats( r_S2_W, s_S2_W );
      record_stats( r_S2_T, s_S2_T );
      record_stats( r_S2_C, s_S2_C );

      }


    printf(" %10.6f   & %8.4f  & %8.4f  & %8.4f  & %8.4f  & %8.4f  \\\\\n",
        d_sigma,
        log10(d_S2_K/fabs((d_S2_K - stats_average(s_S2_K)))),
        log10(d_S2_2/fabs((d_S2_2 - stats_average(s_S2_2)))),
        log10(d_S2_W/fabs((d_S2_W - stats_average(s_S2_W)))),
        log10(d_S2_T/fabs((d_S2_T - stats_average(s_S2_T)))),
        log10(d_S2_C/fabs((d_S2_C - stats_average(s_S2_C))))
    );
    printf("              & [%7.4f] & [%7.4f] & [%7.4f] & [%7.4f] & [%7.4f] \\\\\n",
        log10(d_S2_K/stats_stderr(s_S2_K)),
        log10(d_S2_2/stats_stderr(s_S2_2)),
        log10(d_S2_W/stats_stderr(s_S2_W)),
        log10(d_S2_T/stats_stderr(s_S2_T)),
        log10(d_S2_C/stats_stderr(s_S2_C))
    );

  }

  newline();
  printline();
  newline();

  return 0;
}

int sdev_plot (int num_samples, int m)
{
  register int i, sample;

  double d_S2_2, d_XBAR_2, d_sigma_2;
  float  f_S2_2, f_XBAR_2, f_sigma_2;
  float  r_S2_2, r_XBAR_2, r_sigma_2;

  double d_S2_T, d_XBAR_T, d_SUMX_T, d_SUMX2_T, d_sigma_T;
  float  f_S2_T, f_XBAR_T, f_SUMX_T, f_SUMX2_T, f_sigma_T;
  float  r_S2_T, r_XBAR_T, r_SUMX_T, r_SUMX2_T, r_sigma_T;

  double c, sqsqsqsq2;

#define MAX_OBS        1024

  double d_x[MAX_OBS];
  float  f_x[MAX_OBS];
  float  r_x[MAX_OBS];

  if (m>MAX_OBS) {
      printf("sdev_plot error: recompile with MAX_OBS >= %d\n",m);
      return -1;
  }
  
  
    /*----------------------------------------------------------------------
           Two-Pass Algorithm
     ----------------------------------------------------------------------*/

  printf("twopass := [\n");

  for (c = 1.0 ; c <= 32768.0 ; c *= 2.0) {

    for ( i=1 ; i <= m ; i++ ) {
        d_x[i] = c + i; 
        f_x[i] = NEAREST_FLOAT(d_x[i]);
        r_x[i] = INEXACT(d_x[i]);
    }
  
    for ( sample=1; sample<=num_samples; sample++ ) {

      d_XBAR_2 = 0.0;
      f_XBAR_2 = 0.0;
      r_XBAR_2 = 0.0;

      for ( i=1 ; i <= m ; i++ ) {
          d_XBAR_2 = d_XBAR_2 + d_x[i];
          f_XBAR_2 = f_XBAR_2 + f_x[i];
          r_XBAR_2 = mca_add( r_XBAR_2 , r_x[i] );
      }
      d_XBAR_2 = d_XBAR_2 / m;
      f_XBAR_2 = f_XBAR_2 / m;
      r_XBAR_2 = mca_divide( r_XBAR_2 , EXACT(m) );

      d_S2_2 = 0.0;
      f_S2_2 = 0.0;
      r_S2_2 = 0.0;
      for ( i=1 ; i <= m ; i++ ) {
          d_S2_2 = d_S2_2 + double_square( d_x[i] - d_XBAR_2 );
          f_S2_2 = f_S2_2 +  float_square( f_x[i] - f_XBAR_2 );
          r_S2_2 = mca_add( r_S2_2 ,
                        mca_square( mca_subtract( r_x[i], r_XBAR_2 )));
      }
      d_S2_2 = d_S2_2 / (m - 1);
      f_S2_2 = f_S2_2 / (m - 1);
      r_S2_2 = mca_divide( r_S2_2 , EXACT(m - 1) );
    
      d_sigma_2 = (d_S2_2 < 0) ? -0.0 : double_sqrt( d_S2_2 );
      f_sigma_2 = (f_S2_2 < 0) ? -0.0 : float_sqrt( f_S2_2 );
      r_sigma_2 = (r_S2_2 < 0) ? -0.0 : mca_sqrt( r_S2_2 );

      printf(" [%15.5f ,  %12.7f ]", c, r_sigma_2 );
      if (sample<num_samples || c<32768) printf(",\n"); else printf("\n");

    }
  }

  printf(" ];\n");
    
    /*----------------------------------------------------------------------
           Textbook Algorithm
     ----------------------------------------------------------------------*/

  printf("textbook := [\n");

  sqsqsqsq2 = sqrt(sqrt(sqrt(2.0)));

  for (c = 1.0 ; c <= 32768.0 ; c = c*sqsqsqsq2) {

    
    for ( i=1 ; i <= m ; i++ ) {
        d_x[i] = c + i; 
        f_x[i] = NEAREST_FLOAT(d_x[i]);
        r_x[i] = INEXACT(d_x[i]);
    }

    for ( sample=1; sample<=num_samples; sample++ ) {

      d_SUMX_T = 0.0; d_SUMX2_T = 0.0;
      f_SUMX_T = 0.0; f_SUMX2_T = 0.0;
      r_SUMX_T = 0.0; r_SUMX2_T = 0.0;

      for ( i=1 ; i <= m ; i++ ) {
        d_SUMX_T = d_SUMX_T + d_x[i];
        f_SUMX_T = f_SUMX_T + f_x[i];
        r_SUMX_T = mca_add( r_SUMX_T , r_x[i] );

        d_SUMX2_T = d_SUMX2_T + double_square(d_x[i]);
        f_SUMX2_T = f_SUMX2_T + float_square(f_x[i]);
        r_SUMX2_T = mca_add( r_SUMX2_T , mca_square(r_x[i]) );
      }

        d_XBAR_T = d_SUMX_T / m;
        f_XBAR_T = f_SUMX_T / m;
        r_XBAR_T = mca_divide( r_SUMX_T , EXACT(m) );

        d_S2_T = (d_SUMX2_T - d_XBAR_T * d_SUMX_T) / (m - 1);
        f_S2_T = (f_SUMX2_T - f_XBAR_T * f_SUMX_T) / (m - 1);
        r_S2_T = mca_divide(
                mca_subtract( r_SUMX2_T , mca_multiply( r_XBAR_T , r_SUMX_T )),
                EXACT(m - 1));
    
      d_sigma_T = (d_S2_T < 0) ? -0.0 : double_sqrt( d_S2_T );
      f_sigma_T = (f_S2_T < 0) ? -0.0 : float_sqrt( f_S2_T );
      r_sigma_T = (r_S2_T < 0) ? -0.0 : mca_sqrt( r_S2_T );

      printf(" [%15.5f ,  %12.7f ]", c, r_sigma_T );
      if (sample==num_samples && c*sqsqsqsq2>32768) printf("\n"); else printf(",\n");

    }
  }

  printf(" ];\n");
  printf("plotsetup(ps,plotoutput=`sdev_plot.eps`,plotoptions=`portrait,color`);\n");
  printf("semilogplot(textbook,view=[1024..32768,0..60],color=red,style=POINT,symbol=DIAMOND);\n");
  printf("semilogplot(twopass,view=[1024..32768,0..60],color=blue,style=POINT,symbol=BOX);\n");
  printf("semilogplot(twopass,view=[1024..32768,0..60],color=aquamarine,style=LINE);\n");


    /*---------------------------------------------------------------------*/

  return 0;
}

int logistics (int num_samples, int m)
{
  register int i, sample;

#define MAX_IT        1024

  double d_x[MAX_IT];
  float  f_x[MAX_IT];
  float  r_x[MAX_IT];

  double d_s, d_t;
  float  f_s, f_t;
  float  r_s, r_t;


  if (m>MAX_IT) {
      printf("logistic error: recompile with MAX_IT >= %d\n",m);
      return -1;
  }

  printf("logistic := [\n");
  
    for ( sample=1; sample<=num_samples; sample++ ) {

      d_x[1] = 0.54321;
      f_x[1] = NEAREST_FLOAT(d_x[1]);
      r_x[1] = INEXACT(d_x[1]);

      printf("[[%4d ,  %12.7f ]", ((int) 1), r_x[1] );
      if (1<m) printf(",\n"); else printf("\n");

      for ( i=2 ; i <= m ; i++ ) {

          d_s    = double_subtract( 1.0, d_x[i-1] );
          d_t    = double_multiply( 4.0, d_x[i-1] );
          d_x[i] = double_multiply( d_s, d_t    );

          f_s    =  float_subtract( 1.0, f_x[i-1] );
          f_t    =  float_multiply( 4.0, f_x[i-1] );
          f_x[i] =  float_multiply( f_s, f_t    );

          r_s    =    mca_subtract( 1.0, r_x[i-1] );
          r_t    =    mca_multiply( 4.0, r_x[i-1] );
          r_x[i] =    mca_multiply( r_s, r_t    );


          printf(" [%6d ,  %12.7f ]", i, r_x[i] );
          if (i<m) printf(",\n"); else printf("\n");
      }

      if (sample<num_samples) printf("],\n"); else printf("]\n");
    }

  printf(" ];\n");
  printf("plot(logistic,0..45, color=[blue,red,green]);\n");

  return 0;
}

int triangle_test (int num_samples)
{
  int it;

  double d_r, d_x, d_y, d_z;
  float  f_r, f_x, f_y, f_z;
  float  r_r, r_x, r_y, r_z;
  STATS  s_r;

/*
**Kahan's example
**(relying on the fact that x and y are exactly representable in IEEE format):
*/
  d_x = (double) 1234567;
  d_y = (double) 1234567;
  d_z = (double) 1.043e-8;
/*
  d_x = (double) 1.234567000000000002e18;
  d_y = (double) 1.234567000000000001e18;
  d_z = (double) 1.043;
*/

/*
**  r =  ((x+y+z)   *   (z-(x-y)) *   (z+(x-y)) * (x+(y-z)))
**      /((x+y+2*z) * (2*z-(x-y)) * (2*z+(x-y)) * (x+(y-2*z)))
*/

  d_r = double_sqrt(double_divide(
          double_multiply(
          double_multiply(
          double_multiply(
             double_add( double_add(d_x,d_y), d_z ),
             double_add( d_z,-double_add(d_x,-d_y) )),
             double_add( d_z, double_add(d_x,-d_y) )),
             double_add( d_x, double_add(d_y,-d_z) )),
          double_multiply(
          double_multiply(
          double_multiply(
             double_add( double_add(d_x,d_y), 2*d_z ),
             double_add( 2*d_z,-double_add(d_x,-d_y) )),
             double_add( 2*d_z, double_add(d_x,-d_y) )),
             double_add( d_x, double_add(d_y,-2*d_z) ))));

  f_x = NEAREST_FLOAT(d_x);
  f_y = NEAREST_FLOAT(d_y);
  f_z = NEAREST_FLOAT(d_z);

  f_r = float_sqrt(float_divide(
          float_multiply(
          float_multiply(
          float_multiply(
             float_add( float_add(f_x,f_y), f_z ),
             float_add( f_z,-float_add(f_x,-f_y) )),
             float_add( f_z, float_add(f_x,-f_y) )),
             float_add( f_x, float_add(f_y,-f_z) )),
          float_multiply(
          float_multiply(
          float_multiply(
             float_add( float_add(f_x,f_y), 2*f_z ),
             float_add( 2*f_z,-float_add(f_x,-f_y) )),
             float_add( 2*f_z, float_add(f_x,-f_y) )),
             float_add( f_x, float_add(f_y,-2*f_z) ))));

  init_stats( s_r );

  for (it = 1 ; it <= num_samples ; it++) {

    r_x = EXACT(d_x);
    r_y = EXACT(d_y);
    r_z = INEXACT(d_z);
  
    r_r = mca_sqrt(mca_divide(
            mca_multiply(
            mca_multiply(
            mca_multiply(
               mca_add( mca_add(r_x,r_y), r_z ),
               mca_add( r_z,-       (r_x -r_y) )),
               mca_add( r_z,        (r_x -r_y) )),
               mca_add( r_x, mca_add(r_y,-r_z) )),
            mca_multiply(
            mca_multiply(
            mca_multiply(
               mca_add( mca_add(r_x,r_y), 2*r_z ),
               mca_add( 2*r_z,-       (r_x -r_y) )),
               mca_add( 2*r_z,        (r_x -r_y) )),
               mca_add( r_x, mca_add(r_y,-2*r_z) ))));

    record_stats( r_r, s_r );
  }

  newline();
  printline();
  printf("Kahan's problem of evaluating the ratio of two narrow triangles:\n");
  printf(" r =  ((x+y+z)   *   (z-(x-y)) *   (z+(x-y)) * (x+(y-z)))\n");
  printf("     /((x+y+2*z) * (2*z-(x-y)) * (2*z+(x-y)) * (x+(y-2*z)))\n");
  printf("for x = %g, y = %g, z = %g\n", d_x, d_y, d_z);
  printf("NOTE:  x, y and (x-y) are assumed EXACT, and z INEXACT.\n");

  printf("Results with   inbound %s   outbound %s\n",
          randomization_method_name(inbound_method),
          randomization_method_name(outbound_method));
  printf("also  virtual precision %d \n(averaged over %d samples):\n",
          virtual_precision,
          num_samples);
  newline();
/*
**Exact value for Kahan's problem:
  printf("Exact value           r = %21.14e\n", ((double) 0.5));
*/
  printf("Exact value           r = %21.14e\n", ((double) 0.1619032391407125379628));
  printf("IEEE double precision r = %21.14e\n", d_r);
  printf("IEEE single precision r = %12.5e\n", f_r);
  printf("MCA  single precision r = %12.5e\n", stats_average(s_r) );
  printf("standard deviation       [%12.5e]\n",  stats_stddev(s_r) );
  printf("standard error           [%12.5e]\n",  stats_stderr(s_r) );
#ifdef SKEWNESS_AND_EXCESS
  printf("skewness                 [%12.5e] %4s\n",
                stats_skewness(s_r), NTEST(stats_skewness(s_r)) );
  printf("excess                   [%12.5e] %4s\n",
                stats_excess(s_r), NTEST(stats_excess(s_r)) );
#endif
  newline();
  printline();
  newline();

}

int Rump_test (int num_samples)
{
  int it;

  double d_x, d_y, d_z;
  float  f_x, f_y, f_z;
  float  r_x, r_y, r_z;
  STATS  s_x, s_y, s_z;

  d_x = (double) 77617;
  d_y = (double) 33096;

/*
**  z = 333.75*y^6 + x^2*(11*x^2*y^2 - y^6 - 121*y^4 - 2) + 5.5*y^8 + x/(2*y);
*/

  d_z = double_add(
          double_add(
            double_add(
              double_multiply( ((double) 333.75), double_power(d_y,6) ),
              double_multiply(
                double_power(d_x,2),
                double_add(
                  double_add(
                    double_add(
                      double_multiply(
                        ((double) 11),
                        double_multiply( double_power(d_x,2), double_power(d_y,2))),
                      -double_power(d_y,6)),
                    double_multiply( ((double) -121), double_power(d_y,4))),
                  ((double) -2)))),
              double_multiply( ((double) 5.5), double_power(d_y,8))),
              double_divide( d_x, double_multiply( ((double) 2), d_y)));


  f_x = NEAREST_FLOAT(d_x);
  f_y = NEAREST_FLOAT(d_y);

  f_z = float_add(
          float_add(
            float_add(
              float_multiply( NEAREST_FLOAT(333.75), float_power(f_y,6) ),
              float_multiply(
                float_power(f_x,2),
                float_add(
                  float_add(
                    float_add(
                      float_multiply(
                        NEAREST_FLOAT(11),
                        float_multiply( float_power(f_x,2), float_power(f_y,2))),
                      -float_power(f_y,6)),
                    float_multiply( NEAREST_FLOAT(-121), float_power(f_y,4))),
                  NEAREST_FLOAT(-2)))),
              float_multiply( NEAREST_FLOAT(5.5), float_power(f_y,8))),
              float_divide( f_x, float_multiply( NEAREST_FLOAT(2), f_y)));


  r_x  = EXACT(d_x);
  r_y  = EXACT(d_y);
  init_stats( s_z );

  for (it = 1 ; it <= num_samples ; it++) {
    r_z = mca_add(
            mca_add(
              mca_add(
                mca_multiply( EXACT(333.75), mca_power(r_y,6) ),
                mca_multiply(
                  mca_power(r_x,2),
                  mca_add(
                    mca_add(
                      mca_add(
                        mca_multiply(
                          EXACT(11),
                          mca_multiply( mca_power(r_x,2), mca_power(r_y,2))),
                        -mca_power(r_y,6)),
                      mca_multiply( EXACT(-121), mca_power(r_y,4))),
                  EXACT(-2)))),
              mca_multiply( EXACT(5.5), mca_power(r_y,8))),
              mca_divide( r_x, mca_multiply( EXACT(2), r_y)));
  
    record_stats( r_z, s_z );
  }

  newline();
  printline();
  printf("Rump's problem:\n");
  printf("Evaluating\n");
  printf("z = 333.75*y^6 + x^2*(11*x^2*y^2-y^6-121*y^4-2) + 5.5*y^8 + x/(2*y)\n");
  printf("for x = %g, y = %g\n", d_x, d_y);

  printf("Results with   inbound %s   outbound %s\n",
          randomization_method_name(inbound_method),
          randomization_method_name(outbound_method));
  printf("also  virtual precision %d \n(averaged over %d samples):\n",
          virtual_precision,
          num_samples);
  newline();
  printf("Exact value           z = -0.8273960599468213681411650954798...\n");
  printf("IEEE double precision z = %21.14e\n", d_z);
  printf("IEEE single precision z = %12.5e\n", f_z);
  printf("MCA  single precision z = %12.5e\n", stats_average(s_z) );
  printf("standard deviation       [%12.5e]\n",  stats_stddev(s_z) );
  printf("standard error           [%12.5e]\n",  stats_stderr(s_z) );
#ifdef SKEWNESS_AND_EXCESS
  printf("skewness                 [%12.5e] %4s\n",
                stats_skewness(s_z), NTEST(stats_skewness(s_z)) );
  printf("excess                   [%12.5e] %4s\n",
                stats_excess(s_z), NTEST(stats_excess(s_z)) );
#endif
  newline();
  printline();
  newline();

}

int Knuth_test (int num_samples)
{
  int it;

  double d_u, d_v, d_x, d_y, d_z;
  float  f_u, f_v, f_x, f_y, f_z;
  float  r_u, r_v, r_x, r_y, r_z;
  STATS  s_u, s_v, s_x, s_y, s_z;

  d_x = (double)  11111113.;
  d_y = (double) -11111111.;
  d_z = (double)  7.5111111;

/*
**  u = ((x + y) + z);
**  v = (x + (y + z));
*/

  d_u = double_add(double_add(d_x, d_y), d_z);
  d_v = double_add(d_x, double_add(d_y, d_z));

  f_x = NEAREST_FLOAT(d_x);
  f_y = NEAREST_FLOAT(d_y);
  f_z = NEAREST_FLOAT(d_z);
  
  f_u = float_add(float_add(f_x, f_y), f_z);
  f_v = float_add(f_x, float_add(f_y, f_z));

  init_stats( s_u );
  init_stats( s_v );
  for (it = 1 ; it <= num_samples ; it++) {

    r_x = INEXACT(d_x);  /* assumed, though binary rep. is 24 bits long */
    r_y = INEXACT(d_y);  /* assumed, though binary rep. is 24 bits long */
    r_z = INEXACT(d_z);
  
    r_u = mca_add(mca_add(f_x, f_y), f_z);
    r_v = mca_add(f_x, mca_add(f_y, f_z));

    record_stats( r_u, s_u );
    record_stats( r_v, s_v );
  }

  newline();
  printline();
  printf("Knuth's problem:\n");
  printf("Evaluating  u = ((x + y) + z),   v = (x + (y + z)) \n");
  printf("for x = %f, y = %f, z = %f\n", d_x, d_y, d_z);

  printf("Results with   inbound %s   outbound %s\n",
          randomization_method_name(inbound_method),
          randomization_method_name(outbound_method));
  printf("also  virtual precision %d \n(averaged over %d samples):\n",
          virtual_precision,
          num_samples);
  newline();
  printf("IEEE double precision u = %21.14f\n", d_u);
  printf("IEEE single precision u = %12.5f\n", f_u);
  printf("MCA  single precision u = %12.5f\n", stats_average(s_u) );
  printf("standard deviation       [%12.5f]\n", stats_stddev(s_u) );
  printf("standard error           [%12.5f]\n", stats_stderr(s_u) );
#ifdef SKEWNESS_AND_EXCESS
  printf("skewness                 [%12.5e] %4s\n",
                stats_skewness(s_u), NTEST(stats_skewness(s_u)) );
  printf("excess                   [%12.5e] %4s\n",
                stats_excess(s_u), NTEST(stats_excess(s_u)) );
#endif
  newline();
  newline();
  printf("IEEE double precision v = %21.14f\n", d_v);
  printf("IEEE single precision v = %12.5f\n", f_v);
  printf("MCA  single precision v = %12.5f\n", stats_average(s_v) );
  printf("standard deviation       [%12.5f]\n", stats_stddev(s_v) );
  printf("standard error           [%12.5f]\n", stats_stderr(s_v) );
#ifdef SKEWNESS_AND_EXCESS
  printf("skewness                 [%12.5e] %4s\n",
                stats_skewness(s_v), NTEST(stats_skewness(s_v)) );
  printf("excess                   [%12.5e] %4s\n",
                stats_excess(s_v), NTEST(stats_excess(s_v)) );
#endif
  newline();
  printline();
  newline();

}

#define MAX_ITERATIONS  100

int startling_test (int n, int num_samples)
{
  register int i, it, sample;
  if (n+1>MAX_ITERATIONS) {
      printf("startling_test error: recompile with MAX_ITERATIONS >= %d\n",n+1);
      return -1;
  }
  {
  double d_u[MAX_ITERATIONS];
  float  f_u[MAX_ITERATIONS];
  float  r_u[MAX_ITERATIONS];
  STATS  s_u[MAX_ITERATIONS];

  newline();
  printline();
  printf("Evaluation of the sequence u_n (up to n = %d)\n", n);
  printf("Results with   inbound %s   outbound %s\n",
          randomization_method_name(inbound_method),
          randomization_method_name(outbound_method));
  printf("also  virtual precision %d \n(averaged over %d samples):\n",
          virtual_precision,
          num_samples);
  printline();
  newline();

  d_u[0] = ((double)  2);
  d_u[1] = ((double) -4);

  f_u[0] = ((float)   2);
  f_u[1] = ((float)  -4);

  for (i = 1 ; i < n ; i++) {
    d_u[i+1] = double_add( ((double) 111),
                           double_add( double_divide(((double) -1130),d_u[i]),
                                       double_divide(((double) 3000),
                                                     double_multiply(d_u[i],d_u[i-1])
               )));

    f_u[i+1] = float_add( ((float) 111),
                           float_add( float_divide(((float) -1130),f_u[i]),
                                      float_divide(((float) 3000),
                                                   float_multiply(f_u[i],f_u[i-1])
               )));
  }

  for (i = 0 ; i <= n ; i++) init_stats( s_u[i] );

  r_u[0] = INEXACT( 2);  /* making this EXACT reduces error */
  printf("\nMCA single u[ 0] = %14.6f\n",r_u[0]);
  r_u[1] = INEXACT(-4);  /* making this EXACT reduces error */
  printf("MCA single u[ 1] = %14.6f\n",r_u[1]);

  record_stats( r_u[0], s_u[0] );
  record_stats( r_u[1], s_u[1] );

  for (it = 1 ; it <= num_samples ; it++) {
    for (i = 1 ; i < n ; i++) {
      r_u[i+1] = mca_add( ((float) 111),
                            mca_add( mca_divide(((float) -1130),r_u[i]),
                                       mca_divide(((float) 3000),
                                                    mca_multiply(r_u[i],r_u[i-1]))
                         ));
      printf("MCA single u[%2d] = %14.6f\n",(i+1),r_u[i+1]);
      record_stats( r_u[i+1], s_u[i+1] );
    }
  }

  for (i = 0 ; i <= n ; i++) {
    printf("IEEE double precision  u[%2d] = %21.14e\n", i, d_u[i]);
    printf("IEEE single precision  u[%2d] = %12.5e\n", i, f_u[i]);
    printf("MCA  single   average  u[%2d] = %12.5e\n", i,stats_average(s_u[i]));
    printf("standard deviation            [%12.5e]\n", stats_stddev(s_u[i]));
    printf("standard error                [%12.5e]\n", stats_stderr(s_u[i]));
#ifdef SKEWNESS_AND_EXCESS
    printf("skewness                      [%12.5e] %s\n",
                        stats_skewness(s_u[i]), NTEST(skewness_test(s_u[i])));
    printf("excess                        [%12.5e] %s\n",
                        stats_excess(s_u[i]), NTEST(excess_test(s_u[i])));
#endif

    newline();
  }

  printline();
  newline();
  }
  {
  double d_x[MAX_ITERATIONS];
  float  f_x[MAX_ITERATIONS];
  float  r_x[MAX_ITERATIONS];
  STATS  s_x[MAX_ITERATIONS];

  newline();
  printline();
  printf("Evaluation of the sequence x_n (up to n = %d)\n", n);
  printf("Results with   inbound %s   outbound %s\n",
          randomization_method_name(inbound_method),
          randomization_method_name(outbound_method));
  printf("also  virtual precision %d \n(averaged over %d samples):\n",
          virtual_precision,
          num_samples);
  printline();
  newline();

  d_x[1]   = ((double) 1.5100050721319);

  for (i = 1 ; i < n ; i++) {
    double d_x1 = d_x[i];
    double d_x2 = double_multiply(d_x1,d_x1);
    double d_x3 = double_multiply(d_x1,d_x2);
    double d_x4 = double_multiply(d_x1,d_x3);
    d_x[i+1] = double_divide(
                double_add(     double_multiply( ((double)   3), d_x4 ),
                  double_add(   double_multiply( ((double) -20), d_x3 ),
                    double_add( double_multiply( ((double)  35), d_x2 ),
                                                 ((double) -24)))),
                double_add(     double_multiply( ((double)   4), d_x3 ),
                  double_add(   double_multiply( ((double) -30), d_x2 ),
                    double_add( double_multiply( ((double)  70), d_x1 ),
                                                 ((double) -50))))
               );
  }

  f_x[1]   = NEAREST_FLOAT(1.5100050721319);

  for (i = 1 ; i < n ; i++) {
    float f_x1 = f_x[i];
    float f_x2 = float_multiply(f_x1,f_x1);
    float f_x3 = float_multiply(f_x1,f_x2);
    float f_x4 = float_multiply(f_x1,f_x3);
    f_x[i+1] = float_divide(
                float_add(     float_multiply( ((float)   3), f_x4 ),
                  float_add(   float_multiply( ((float) -20), f_x3 ),
                    float_add( float_multiply( ((float)  35), f_x2 ),
                                               ((float) -24)))),
                float_add(     float_multiply( ((float)   4), f_x3 ),
                  float_add(   float_multiply( ((float) -30), f_x2 ),
                    float_add( float_multiply( ((float)  70), f_x1 ),
                                               ((float) -50))))
               );
  }

  for (i = 1 ; i <= n ; i++) init_stats( s_x[i] );

  for (it = 1 ; it <= num_samples ; it++) {

    r_x[1]   = INEXACT(1.5100050721319);
    printf("\nMCA single x[ 1] = %14.6f\n",r_x[1]);

    record_stats( r_x[1], s_x[1] );

    for (i = 1 ; i < n ; i++) {
      float r_x1 = r_x[i];
      float r_x2 = mca_multiply(r_x1,r_x1);
      float r_x3 = mca_multiply(r_x1,r_x2);
      float r_x4 = mca_multiply(r_x1,r_x3);
      r_x[i+1] = mca_divide(
                   mca_add(     mca_multiply( EXACT(   3), r_x4 ),
                     mca_add(   mca_multiply( EXACT( -20), r_x3 ),
                       mca_add( mca_multiply( EXACT(  35), r_x2 ),
                                                    EXACT( -24)))),
                   mca_add(     mca_multiply( EXACT(   4), r_x3 ),
                     mca_add(   mca_multiply( EXACT( -30), r_x2 ),
                       mca_add( mca_multiply( EXACT(  70), r_x1 ),
                                                    EXACT( -50))))
                 );
      printf("MCA single x[%2d] = %14.6f\n",(i+1),r_x[i+1]);
      record_stats( r_x[i+1], s_x[i+1] );
    }
  }

  for (i = 1 ; i <= n ; i++) {
    printf("IEEE double precision  x[%2d] = %21.14e\n", i, d_x[i]);
    printf("IEEE single precision  x[%2d] = %12.5e\n", i, f_x[i]);
    printf("MCA  single   average  x[%2d] = %12.5e\n", i,stats_average(s_x[i]));
    printf("standard deviation            [%12.5e]\n", stats_stddev(s_x[i]));
    printf("standard error                [%12.5e]\n", stats_stderr(s_x[i]));
#ifdef SKEWNESS_AND_EXCESS
    printf("skewness                      [%12.5e] %s\n",
                        stats_skewness(s_x[i]), NTEST(skewness_test(s_x[i])));
    printf("excess                        [%12.5e] %s\n",
                        stats_excess(s_x[i]), NTEST(excess_test(s_x[i])));
#endif
    newline();
  }

  printline();
  newline();
  }
}

int basic_test (int n, int num_samples)
{
  register int iz, sample;

  double d_z;
  float  f_z;
  float  r_z;

  double d_term, d_cosz, d_prevcosz;
  float  f_term, f_cosz, f_prevcosz;
  float  r_term, r_cosz, r_prevcosz;
  STATS  s_cosz;

  double d_z2, d_T20z;
  float  f_z2, f_T20z;
  float  r_z2, r_T20z;
  STATS  s_T20z;

  int kd, kf, kr;


  newline();
  printline();
  printf("Evaluation of cos(z) by power series expansion\n");
  printf("Results with   inbound %s   outbound %s\n",
          randomization_method_name(inbound_method),
          randomization_method_name(outbound_method));
  printf("also  virtual precision %d \n(averaged over %d samples):\n",
          virtual_precision,
          num_samples);
  printline();
  newline();

  for (iz = 0 ; iz <= n ; iz++) {

    d_z = ((double) M_PI_2 * ((double) iz))/((double) n); /* from 0 to Pi/2 */

    f_z = NEAREST_FLOAT(d_z);

    r_z = INEXACT(d_z);

    printf("\nz = (%2d/%2d) pi/2 = %21.14e\n", iz, n, d_z);

    {
      d_term = 1.0;
      d_cosz = 1.0;
      d_prevcosz  = 0.0;
      for (kd=2 ; (d_prevcosz != d_cosz) && (kd<50) ; kd += 2) {
         d_prevcosz = d_cosz;
         d_term = double_multiply( d_term,
                                    -double_divide(
                                               double_multiply(d_z,d_z),
                                               ((double) (kd*(kd-1)))));
         d_cosz = double_add(d_cosz,d_term);
      }

      f_term = 1.0;
      f_cosz = 1.0;
      f_prevcosz  = 0.0;
      for (kf=2 ; (f_prevcosz != f_cosz) && (kf<50) ; kf += 2) {
         f_prevcosz = f_cosz;
         f_term = float_multiply( f_term,
                                    -float_divide(
                                               float_multiply(f_z,f_z),
                                               ((float) (kf*(kf-1)))));
         f_cosz = float_add(f_cosz,f_term);
      }
    }

    init_stats( s_cosz );
    for ( sample=1; sample<=num_samples; sample++ ) {
      r_term = 1.0;
      r_cosz = 1.0;
      r_prevcosz  = 0.0;
      for (kr=2 ; (r_prevcosz != r_cosz) && (kr<50) ; kr += 2) {
         r_prevcosz = r_cosz;
         r_term = mca_multiply( r_term,
                                    -mca_divide(
                                                mca_multiply(f_z,f_z),
                                                EXACT( (kr*(kr-1)) )));
         r_cosz = mca_add(r_cosz,r_term);
      }
      record_stats( r_cosz, s_cosz );
    }

    printf("C Library:             cos(z) = %21.14e\n", cos(d_z));
    printf("IEEE double precision  cos(z) = %21.14e  (%d terms in series)\n",
                                        d_cosz, ((int) kd/2));
    printf("IEEE single precision  cos(z) = %12.5e         (%d terms in series)\n",
                                        f_cosz, ((int) kf/2));
    printf("MCA  single   average  cos(z) = %12.5e         (%d terms in series)\n",
                                        stats_average(s_cosz), ((int) kr/2));
    printf("standard deviation             [%12.5e]\n", stats_stddev(s_cosz));
    printf("standard error                 [%12.5e]\n", stats_stderr(s_cosz));
#ifdef SKEWNESS_AND_EXCESS
    printf("skewness                       [%12.5e] %s\n",
                        stats_skewness(s_cosz), NTEST(skewness_test(s_cosz)));
    printf("excess                         [%12.5e] %s\n",
                        stats_excess(s_cosz), NTEST(excess_test(s_cosz)));
#endif
  }

  newline();
  printline();
  printf("Evaluation of the Tchebycheff polynomial T_20(z) using Horner's rule\n");
  printf("T_20(z) = cos(20*arccos(z)) \n");
  printf("        = 1+(-200+(6600+(-84480+(549120+(-2050048+(4659200+(-6553600+(5570560\n");
  printf("           +(-2621440+524288*z^2)*z^2)*z^2)*z^2)*z^2)*z^2)*z^2)*z^2)*z^2)*z^2\n");
  newline();
  printf("Results with   inbound %s   outbound %s\n",
          randomization_method_name(inbound_method),
          randomization_method_name(outbound_method));
  printf("also  virtual precision %d \n(averaged over %d samples):\n",
          virtual_precision,
          num_samples);
  printline();
  newline();

  for (iz = 0 ; iz <= n ; iz++) {
    d_z = ((double) iz)/((double) n); /* about 1.0 */
    f_z = NEAREST_FLOAT(d_z);

    printf("\nz = (%2d/%2d) = %21.14e\n", iz,n, d_z);
    {
      d_z2 = double_square(d_z);
      d_T20z = double_add((double) 1,
        double_multiply( double_add( (double) -200,
        double_multiply( double_add( (double)  6600,
        double_multiply( double_add( (double) -84480,
        double_multiply( double_add( (double)  549120,
        double_multiply( double_add( (double) -2050048,
        double_multiply( double_add( (double)  4659200,
        double_multiply( double_add( (double) -6553600,
        double_multiply( double_add( (double)  5570560,
        double_multiply( double_add( (double) -2621440,
        double_multiply((double)  524288, d_z2)),
        d_z2)) ,d_z2)) ,d_z2)) ,d_z2)) ,d_z2)) ,d_z2)) ,d_z2)) ,d_z2)) ,d_z2));

      f_z2 = float_square(f_z);
      f_T20z = float_add(1,
        float_multiply( float_add( NEAREST_FLOAT(-200),
        float_multiply( float_add( NEAREST_FLOAT( 6600),
        float_multiply( float_add( NEAREST_FLOAT(-84480),
        float_multiply( float_add( NEAREST_FLOAT( 549120),
        float_multiply( float_add( NEAREST_FLOAT(-2050048),
        float_multiply( float_add( NEAREST_FLOAT( 4659200),
        float_multiply( float_add( NEAREST_FLOAT(-6553600),
        float_multiply( float_add( NEAREST_FLOAT( 5570560),
        float_multiply( float_add( NEAREST_FLOAT(-2621440),
        float_multiply( NEAREST_FLOAT( 524288), f_z2)),
        f_z2)) ,f_z2)) ,f_z2)) ,f_z2)) ,f_z2)) ,f_z2)) ,f_z2)) ,f_z2)) ,f_z2));
    }
    init_stats( s_T20z );
    for ( sample=1; sample<=num_samples; sample++ ) {
      r_z = INEXACT(d_z);
      r_z2 = mca_square(r_z);
      r_T20z = mca_add(1,
        mca_multiply( mca_add( EXACT(-200),
        mca_multiply( mca_add( EXACT( 6600),
        mca_multiply( mca_add( EXACT(-84480),
        mca_multiply( mca_add( EXACT( 549120),
        mca_multiply( mca_add( EXACT(-2050048),
        mca_multiply( mca_add( EXACT( 4659200),
        mca_multiply( mca_add( EXACT(-6553600),
        mca_multiply( mca_add( EXACT( 5570560),
        mca_multiply( mca_add( EXACT(-2621440),
        mca_multiply( EXACT( 524288), r_z2)),
        r_z2)) ,r_z2)) ,r_z2)) ,r_z2)) ,r_z2)) ,r_z2)) ,r_z2)) ,r_z2)) ,r_z2));
        record_stats( r_T20z, s_T20z );
    }
    printf("C Library:        cos(20*arccos(z)) = %21.14e\n",cos(20*acos(d_z)));
    printf("IEEE double precision Horner T20(z) = %21.14e\n", d_T20z);
    printf("IEEE single precision Horner T20(z) = %12.5e\n", f_T20z);
    printf("MCA  single   average Horner T20(z) = %12.5e\n", stats_average(s_T20z));
    printf("standard deviation                   [%12.5e]\n", stats_stddev(s_T20z));
    printf("standard error                       [%12.5e]\n", stats_stderr(s_T20z));
#ifdef SKEWNESS_AND_EXCESS
    printf("skewness                             [%12.5e] %s\n",
                        stats_skewness(s_T20z), NTEST(skewness_test(s_T20z)));
    printf("excess                               [%12.5e] %s\n",
                        stats_excess(s_T20z), NTEST(excess_test(s_T20z)));
#endif
  }
  newline();
  printline();

  newline();
  printline();
  printf("Evaluation of the Tchebycheff polynomial T_20(z) in factored form\n");
  printf("T_20(z) = 1 + 8*z^2*(z-1)*(z+1)*(4*z^2+2*z-1)^2*(4*z^2-2*z-1)^2*(16*z^4-20*z^2+5)^2\n");
  newline();
  printf("Results with   inbound %s   outbound %s\n",
          randomization_method_name(inbound_method),
          randomization_method_name(outbound_method));
  printf("also  virtual precision %d \n(averaged over %d samples):\n",
          virtual_precision,
          num_samples);
  printline();
  newline();

  for (iz = 0 ; iz <= n ; iz++) {
    d_z = ((double) iz)/((double) n); /* about 1.0 */
    f_z = NEAREST_FLOAT(d_z);

    printf("\nz = (%2d/%2d) = %21.14e\n", iz,n, d_z);
    {
      d_z2 = double_square(d_z);
      d_T20z = double_add((double)  1,
        double_multiply((double)  8,
        double_multiply(d_z2,
        double_multiply(double_add( d_z, (double) -1 ),
        double_multiply(double_add( d_z, (double)  1 ),
        double_multiply(double_square(
                        double_add(double_multiply((double)  4, d_z2),
                        double_add(double_multiply((double)  2, d_z),
                                                   (double) -1))),
        double_multiply(double_square(
                        double_add(double_multiply((double)  4, d_z2),
                        double_add(double_multiply((double) -2,
                                                   d_z), (double) -1))),
                       double_square(
                        double_add(double_multiply((double)  16,
                                                   double_square(d_z2)),
                        double_add(double_multiply((double) -20, d_z2),
                                   (double)  5)))
        )))))));

      f_z2 = float_square(f_z);
      f_T20z = float_add(NEAREST_FLOAT( 1),
        float_multiply(NEAREST_FLOAT( 8),
        float_multiply(f_z2,
        float_multiply(float_add( f_z, NEAREST_FLOAT(-1)),
        float_multiply(float_add( f_z, NEAREST_FLOAT( 1)),
        float_multiply(float_square(
                        float_add(float_multiply(NEAREST_FLOAT( 4), f_z2),
                        float_add(float_multiply(NEAREST_FLOAT( 2), f_z),
                                  NEAREST_FLOAT(-1)))),
        float_multiply(float_square(
                        float_add(float_multiply(NEAREST_FLOAT( 4), f_z2),
                        float_add(float_multiply(NEAREST_FLOAT(-2), f_z),
                                  NEAREST_FLOAT(-1)))),
                       float_square(
                        float_add(float_multiply(NEAREST_FLOAT( 16),
                                                 float_square(f_z2)),
                        float_add(float_multiply(NEAREST_FLOAT(-20), f_z2),
                                  NEAREST_FLOAT( 5))))
        )))))));

    }
    init_stats( s_T20z );
    for ( sample=1; sample<=num_samples; sample++ ) {
      r_z = INEXACT(d_z);
      r_z2 = mca_square(r_z);
      r_T20z = mca_add(EXACT( 1),
        mca_multiply(EXACT( 8),
        mca_multiply(r_z2,
        mca_multiply(mca_add( r_z, EXACT(-1)),
        mca_multiply(mca_add( r_z, EXACT( 1)),
        mca_multiply(mca_square(
                        mca_add(mca_multiply(EXACT( 4), r_z2),
                        mca_add(mca_multiply(EXACT( 2), r_z), EXACT(-1)))),
        mca_multiply(mca_square(
                        mca_add(mca_multiply(EXACT( 4), r_z2),
                        mca_add(mca_multiply(EXACT(-2), r_z), EXACT(-1)))),
                       mca_square(
                        mca_add(mca_multiply(EXACT( 16), mca_square(r_z2)),
                        mca_add(mca_multiply(EXACT(-20), r_z2), EXACT( 5))))
        )))))));
        record_stats( r_T20z, s_T20z );
    }
    printf("C Library:          cos(20*arccos(z)) = %21.14e\n", cos(20*acos(d_z)) );
    printf("IEEE double precision factored T20(z) = %21.14e\n", d_T20z);
    printf("IEEE single precision factored T20(z) = %12.5e\n", f_T20z);
    printf("MCA  single   average factored T20(z) = %12.5e\n", stats_average(s_T20z));
    printf("standard deviation                     [%12.5e]\n", stats_stddev(s_T20z));
    printf("standard error                         [%12.5e]\n", stats_stderr(s_T20z));
#ifdef SKEWNESS_AND_EXCESS
    printf("skewness                               [%12.5e] %s\n",
                        stats_skewness(s_T20z), NTEST(skewness_test(s_T20z)));
    printf("excess                                 [%12.5e] %s\n",
                        stats_excess(s_T20z), NTEST(excess_test(s_T20z)));
#endif
  }
  newline();
  printline();

#ifdef SCATTERPLOTS
  printf("Horner_T20 := [\n");
  for (iz = 0 ; iz <= n*100 ; iz++ ) {
      r_z = (0.5 + 0.5*u01);
      r_z2 = mca_square(r_z);
      r_T20z = mca_add(1,
        mca_multiply( mca_add( EXACT(-200),
        mca_multiply( mca_add( EXACT( 6600),
        mca_multiply( mca_add( EXACT(-84480),
        mca_multiply( mca_add( EXACT( 549120),
        mca_multiply( mca_add( EXACT(-2050048),
        mca_multiply( mca_add( EXACT( 4659200),
        mca_multiply( mca_add( EXACT(-6553600),
        mca_multiply( mca_add( EXACT( 5570560),
        mca_multiply( mca_add( EXACT(-2621440),
        mca_multiply( EXACT( 524288), r_z2)),
        r_z2)) ,r_z2)) ,r_z2)) ,r_z2)) ,r_z2)) ,r_z2)) ,r_z2)) ,r_z2)) ,r_z2));
    printf(" [ %12.5e , %12.5e ],\n", r_z, r_T20z);
  }
  printf(" [ %12.5e , %12.5e ]];\n", r_z, r_T20z);
  printf("plot(Horner_T20, style=POINT, title=`Horner T_20(x)`);\n");

  printf("factored_T20 := [\n");
  for (iz = 0 ; iz <= n*100 ; iz++ ) {
      r_z = (0.5 + 0.5*u01);
      r_z2 = mca_square(r_z);
      r_T20z = mca_add(EXACT( 1),
        mca_multiply( EXACT( 8),
        mca_multiply( r_z2,
        mca_multiply( mca_add( r_z, EXACT(-1)),
        mca_multiply( mca_add( r_z, EXACT( 1)),
        mca_multiply( mca_square(
                        mca_add( mca_multiply( EXACT( 4), r_z2),
                        mca_add( mca_multiply( EXACT( 2), r_z), EXACT(-1)))),
        mca_multiply(mca_square(
                        mca_add( mca_multiply( EXACT( 4), r_z2),
                        mca_add( mca_multiply( EXACT(-2), r_z), EXACT(-1)))),
                       mca_square(
                        mca_add( mca_multiply( EXACT( 16), mca_square(r_z2)),
                        mca_add( mca_multiply( EXACT(-20), r_z2), EXACT( 5))))
        )))))));
    printf(" [ %12.5e , %12.5e ],\n", r_z, r_T20z);
  }
  printf(" [ %12.5e , %12.5e ]];\n", r_z, r_T20z);
  printf("plot(factored_T20, style=POINT, title=`Factored T_20(x)`);\n");
  newline();
  printline();
#endif

  return 0;
}

int Huskey_test (double h, int n, int num_samples)
{
  double d_x, d_y, d_xt, d_yt, d_xs, d_ys, d_h, d_t;
  float  f_x, f_y, f_xt, f_yt, f_xs, f_ys, f_h, f_t;
  float  r_x, r_y, r_xt, r_yt, r_xs, r_ys, r_h, r_t;
  STATS  s_x, s_y;

  int i, sample;

  double T = n * h;

  newline();
  printline();
  printf("Evaluation of sin(t), cos(t) by Huskey's approach on the ENIAC.\n");
  printf("Heun's method is used to integrate  x'(t)=y(t), y'(t)=x(t).\n");
  printf("Integration stepsize h = %21.14e\n", h);
  printf("Results with   inbound %s   outbound %s\n",
          randomization_method_name(inbound_method),
          randomization_method_name(outbound_method));
  printf("also  virtual precision %d \n(averaged over %d samples):\n",
          virtual_precision,
          num_samples);
  printline();
  newline();

/*
**   Heun's method for integrating  x'(t) = y(t), y'(t) = -x(t)  to value T:
**
**   x = 0.0;
**   y = 1.0;
**   t = 0.0;
**   for (i = 1 ; i <= N ; i++ ) {
**     t  = t + h
**     xs = x + h * y;
**     ys = y - h * x;
**     xt = x + h/2 * (ys + y);
**     yt = y - h/2 * (xs + x);
**     x  = xt;
**     y  = yt;
**   }
**
**   The exact solution is  x(t) = sin(t),  y(t) = cos(t).
**
**   From H. Huskey,
**        "On the Precision of a Certain Procedure of Numerical Integration",
**        J. Res. Nat. Bur. Stds. 42:1, 57--62, 1949.
**
**   Huskey gets great roundoff error when he removes the parentheses above:
**     xt = x + (h/2 * ys) + (h/2 * y);
**     yt = y - (h/2 * xs) + (h/2 * x).
**   He notes that the error is **not** random when the stepsize is small.
**   In particular, using 10-digit decimal arithmetic and a stepsize value
**   h = 2e-5  with t between 0.5211 and 0.5264 (about Pi/6),
**   Huskey observes that values of the increments  (h/2 * ys) and (h/2 * y)
**   often have the same final digit 4, and so the same rounding error
**   (rounding away this digit 4) is made repeatedly.  Thus the roundoff errors
**   are not random, as Rademacher had earlier argued they would be.
**
**   In the appendix to this paper, Hartree explains Huskey's observation.
**   Specifically, if we are using p-digit base-beta arithmetic, since
**   y = cos(t) then the final digit of  beta^{p+1} (h/2 * y) is constant
**   if the last digit of  beta^{p+1} 1/2 h^2 |y'| is zero, or equivalently
**              beta n - 1/2  <  beta^{p+1}/2 h^2 |y'|  <  beta n + 1/2
**   where n is an integer.  He shows it also follows that this last digit
**   will not change for  1/(beta^{p+1} 1/2 h^3 |y''|)  steps.
**
**   This problem does not seem to be directly reproducible in IEEE arithmetic.
**   With IEEE single-precision  beta=2 and p = 24.
**   With binary arithmetic, we want to guarantee the last q bits
**   of  2^{p+q} 1/2 h^2 |y'|  are zero, or equivalently
**              n 2^q - 1/2  <  2^{24+q} 1/2 h^2 |y'|  <  n 2^q + 1/2
**   for some integer n, i.e.,
**              n - 1/2  <  2^{23} h^2 |y'|  <  n + 1/2
**   which requires  h >= 2^{-11}.  However the number of steps with
**   repeated roundoff is then small, and the compounding is not that bad.
**
**   The program does produce fairly high errors in y(t) when h = 2^{-12}
**   and t = Pi/6, while with random rounding the error is reduced.
**   Unfortunately, Hartree's formulas do not explain this.
**   Intuitively, when h is the square root of the machine precision,
**   then |x''| = h^2 |x|, and |y''| = h^2 |y|, so the second-order terms
**   are precisely at the level of roundoff.  Thus when |x| or |y| are
**   slightly less than 0.5, then consistently rounding is downward, etc.
*/

  d_x = (double) 0;
  d_y = (double) 1;
  d_t = (double) 0;
  d_h = h;

  for (i = 1 ; i <= n ; i++) {
    d_t  +=  h;
    d_xs = double_add(d_x, double_multiply(d_h, d_y));
    d_ys = double_add(d_y,-double_multiply(d_h, d_x));
    d_xt = double_add(d_x, double_multiply(d_h/2, double_add(d_ys, d_y)));
    d_yt = double_add(d_y,-double_multiply(d_h/2, double_add(d_xs, d_x)));
/*
**  worse roundoff:
    d_xt = double_add(d_x, double_add(double_multiply(d_h/2, d_ys),
                                      double_multiply(d_h/2, d_y)));
    d_yt = double_add(d_y,-double_add(double_multiply(d_h/2, d_xs),
                                      double_multiply(d_h/2, d_x)));
*/
    d_x  = d_xt;
    d_y  = d_yt;
  }

  f_x = NEAREST_FLOAT(0);
  f_y = NEAREST_FLOAT(1);
  f_t = NEAREST_FLOAT(0);
  f_h = NEAREST_FLOAT(d_h);

  for (i = 1 ; i <= n ; i++) {
    f_t  +=  h;
    f_xs = float_add(f_x, float_multiply(f_h, f_y));
    f_ys = float_add(f_y,-float_multiply(f_h, f_x));
    f_xt = float_add(f_x, float_multiply(f_h/2, float_add(f_ys, f_y)));
    f_yt = float_add(f_y,-float_multiply(f_h/2, float_add(f_xs, f_x)));
/*
**  worse roundoff:
    f_xt = float_add(f_x, float_add(float_multiply(f_h/2, f_ys),
                                    float_multiply(f_h/2, f_y)));
    f_yt = float_add(f_y,-float_add(float_multiply(f_h/2, f_xs),
                                    float_multiply(f_h/2, f_x)));
printf("t = %g, x = %g (%g)\n", f_t, f_xt, f_xt-sin(f_t));
*/
    f_x  = f_xt;
    f_y  = f_yt;
  }

  init_stats( s_x );
  init_stats( s_y );
  for ( sample=1; sample<=num_samples; sample++ ) {

    r_x = EXACT(0);
    r_y = EXACT(1);
    r_t = EXACT(0);
    r_h = EXACT(d_h);   /* since d_h is a power of 2 */

    for (i = 1 ; i <= n ; i++) {
      f_t  +=  h;
      r_xs = mca_add(r_x, mca_multiply(r_h, r_y));
      r_ys = mca_add(r_y,-mca_multiply(r_h, r_x));
      r_xt = mca_add(r_x, mca_multiply(r_h/2, mca_add(r_ys, r_y)));
      r_yt = mca_add(r_y,-mca_multiply(r_h/2, mca_add(r_xs, r_x)));
/*
**    worse roundoff:
      r_xt = mca_add(r_x, mca_add(mca_multiply(r_h/2, r_ys),
                                  mca_multiply(r_h/2, r_y)));
      r_yt = mca_add(r_y,-mca_add(mca_multiply(r_h/2, r_xs),
                                  mca_multiply(r_h/2, r_x)));
*/
      r_x  = r_xt;
      r_y  = r_yt;
    }
    record_stats( r_x, s_x );
    record_stats( r_y, s_y );
  }

  printf("                           T  = %21.14e\n", T);
  printf("C Library:             cos(T) = %21.14e\n", cos(T));
  printf("IEEE double precision  cos(T) = %21.14e\n", d_y);
  printf("IEEE single precision  cos(T) = %12.5e\n",  f_y);
  printf("MCA  single   average  cos(T) = %12.5e\n",  stats_average(s_y));
  printf("standard deviation             [%12.5e]\n", stats_stddev(s_y));
  printf("standard error                 [%12.5e]\n", stats_stderr(s_y));
#ifdef SKEWNESS_AND_EXCESS
  printf("skewness                       [%12.5e] %s\n",
                        stats_skewness(s_y), NTEST(skewness_test(s_y)));
  printf("excess                         [%12.5e] %s\n",
                        stats_excess(s_y), NTEST(excess_test(s_y)));
#endif
  newline();
  newline();
  printf("C Library:             sin(T) = %21.14e\n", sin(T));
  printf("IEEE double precision  sin(T) = %21.14e\n", d_x);
  printf("IEEE single precision  sin(T) = %12.5e\n",  f_x);
  printf("MCA  single   average  sin(T) = %12.5e\n",  stats_average(s_x));
  printf("standard deviation             [%12.5e]\n", stats_stddev(s_x));
  printf("standard error                 [%12.5e]\n", stats_stderr(s_x));
#ifdef SKEWNESS_AND_EXCESS
  printf("skewness                       [%12.5e] %s\n",
                        stats_skewness(s_x), NTEST(skewness_test(s_x)));
  printf("excess                         [%12.5e] %s\n",
                        stats_excess(s_x), NTEST(excess_test(s_x)));
#endif
  newline();

  return 0;
}

int Kahan_rp_test ()
{
  int itest, ix;
  char * label[2] = { "off", "uniform" };
  double u, rp_u, eps;
  float x, rp_x, cf_x;

  u = NEAREST_FLOAT(1.60631924);
  eps = scaled_to_virtual_precision(1.0,0);
  /* we currently use single precision, while Kahan used double precision */

  mca_set_inbound_method( identity );
  mca_set_outbound_method( identity );

  rp_u = double_divide(
           double_add(((double) 622),
             -double_multiply(u,
                 double_add(((double) 751),
                   -double_multiply(u,
                       double_add(((double) 324),
                         -double_multiply(u,
                             double_add(((double) 59),
                               -double_multiply(((double) 4),u)))))))),
           double_add(((double) 112),
             -double_multiply(u,
                 double_add(((double) 151),
                   -double_multiply(u,
                       double_add(((double) 72),
                         -double_multiply(u,
                             double_add(((double) 14),
                               -u))))))));

  for (itest = 0 ; itest <= 1; itest++ ) {
    if (itest == 0) {
      mca_set_inbound_method( identity );
    } else {
      mca_set_inbound_method( uniform_absolute );
    }

  printf("reprise of Kahan's example for showing roundoff is not random\n");
    printf("Kahan_rp_%s := [\n",label[itest]);

    for (ix = 0 ; ix <= 300 ; ix++ ) {
      x = EXACT(u + ix*eps);
          rp_x = mca_divide(
                   mca_add(EXACT(622),
                     -mca_multiply(x,
                         mca_add(EXACT(751),
                           -mca_multiply(x,
                               mca_add(EXACT(324),
                                 -mca_multiply(x,
                                     mca_add(EXACT(59),
                                       -mca_multiply(EXACT(4),x)))))))),
                   mca_add(EXACT(112),
                     -mca_multiply(x,
                         mca_add(EXACT(151),
                           -mca_multiply(x,
                               mca_add(EXACT(72),
                                 -mca_multiply(x,
                                     mca_add(EXACT(14),
                                       -x))))))));
      printf(" [%14.7e, %14.7e],\n", x, (rp_x - rp_u));
    }
    printf(" [%14.7e, %14.7e]];\n", x, (rp_x - rp_u));
    printf("plot(Kahan_rp_%s,style=POINT,axes=FRAME,title=`Kahan rp(x) randomization %s`);\n",
       label[itest], label[itest] );
  }
  newline();
  printline();
  newline();

  return 0;
}

double factorial (int n)
{
  register int i;
  double fact = 1;
  for (i=1; i<n; i++) fact = fact * i;
  return(fact);
}

int Hilbert_test (int n, int num_samples)
{
  register int i, j, k, c, r, sample;
  double twopower;
  float maxvalue, t;
  float a, b;
  int Achoice;
  int bchoice;

#define MAX_MATRIX_DIM  50

  if ((n+2) > MAX_MATRIX_DIM) {
      printf("sdev_test error: recompile with MAX_MATRIX_DIM >= %d\n",(n+2));
      return -1;
  }
  {
  double D [MAX_MATRIX_DIM] [MAX_MATRIX_DIM];

  float A [MAX_MATRIX_DIM] [MAX_MATRIX_DIM];
  STATS A0 [MAX_MATRIX_DIM] [MAX_MATRIX_DIM];
  STATS A1 [MAX_MATRIX_DIM] [MAX_MATRIX_DIM];
#ifndef PIVOTING
  STATS A2 [MAX_MATRIX_DIM] [MAX_MATRIX_DIM];
#endif
  for ( i=1; i<=n; i++ ) for ( j=1; j<=n+1; j++ ) init_stats(A0[i][j]);
  for ( i=1; i<=n; i++ ) for ( j=1; j<=n+1; j++ ) init_stats(A1[i][j]);
#ifndef PIVOTING
  for ( i=1; i<=n; i++ ) for ( j=1; j<=n+1; j++ ) init_stats(A2[i][j]);
#endif

  printf("Enter 0 for Hilbert matrix,\n");
  printf("      1 for Pascal matrix,\n");
  printf("      2 for prompted input of A and b: ");
  scanf("%d", &Achoice);
  newline();
  if (Achoice==0) {
     printf("Enter  0 for b[i]=1/i,  1 for b[i]=1,  2 for b[i]=2^(1-i): ");
     scanf("%d", &bchoice);
     newline();
  }
  if (Achoice==1) {
     printf("Enter  0 for b[i]=i,  1 for b[i]=1,  2 for b[i]=2^(i-1): ");
     scanf("%d", &bchoice);
     newline();
  }

  for ( i=1; i<=n; i++ ) {
    for ( j=1; j<=n; j++ ) {
      switch (Achoice) {
        case 0:   /* A[i][j] = 1/(i+j-1) */
                  D[i][j] = ((double) 1)/((double) i+j-1);
                  break;
        case 1:   /* A[i][j] = (i+j-2)!/(i-1)!/(j-1)! */
                  D[i][j] = factorial(i+j-2)/factorial(i-1)/factorial(j-1);
                  break;
        case 2:   /* user-defined */
                  printf("A[%d][%d] = ",i,j);
                  scanf("%lg", &(D[i][j]));
                  break;
      }
    }
  }
  twopower = ((double) 1);
  for ( i=1; i<=n; i++ ) {
    switch (Achoice) {
        case 0:  /* Hilbert Matrix */
                switch (bchoice) {
                      case 0:  /* b[i] = 1/i */
                               D[i][n+1] = ((double) 1)/((double) i);
                               break;
                      case 1:  /* b[i] = 1 */
                               D[i][n+1] = ((double) 1);
                               break;
                      case 2:  /* b[i] = 2^(1-i) */
                               D[i][n+1] = twopower;
                               twopower = twopower/((double) 2);
                               break;
                    }
                break;
        case 1:  /* Pascal Matrix */
                switch (bchoice) {
                      case 0:  /* b[i] = i */
                               D[i][n+1] = ((double) i);
                               break;
                      case 1:  /* b[i] = 1 */
                               D[i][n+1] = ((double) 1);
                               break;
                      case 2:  /* b[i] = 2^(i-1) */
                               D[i][n+1] = twopower;
                               twopower = twopower*((double) 2);
                               break;
                    }
                break;
        case 2:  /* user defined */
                printf("b[%d] = ",i);
                scanf("%lg", &(D[i][n+1]));
    }
  }

  for ( sample=1; sample<=num_samples; sample++ ) {

    for ( i=1; i<=n; i++ )
      for ( j=1; j<=n+1; j++ ) {
        A[i][j] = INEXACT( D[i][j] );
        record_stats(A[i][j], A0[i][j]);
      }

    for ( k=1; k<n; k++ ) {
  
#ifdef PIVOTING
      /* find max value in subarray A[i][j], i, j >= k */
      maxvalue = 0.0;
      r = 0;
      c = 0;
      for ( i=k; i<=n; i++ )
#ifdef COMPLETE
        for ( j=k; j<=n+1; j++ )
#else
        for ( j=k; j<=k; j++ )
#endif
          if ((t = fabs((double) A[i][j])) > maxvalue) {
            maxvalue = t;
            r = i;
            c = j;
          }
  
      if (maxvalue == 0) { return 1; }
  
      /* interchange the k-th and r-th rows */
      for ( j=k; j<=n+1; j++ ) {
        t = A[k][j]; A[k][j] = A[r][j]; A[r][j] = t;
      }
  
#ifdef COMPLETE
      /* interchange the k-th and c-th columns */
      for ( i=1; i<=n; i++ ) {
        t = A[i][k]; A[i][k] = A[i][c]; A[i][c] = t;
      }
#endif
#endif
  
      for ( i=k+1; i<=n; i++ ) {
        /* A[i][k] = A[i][k] / A[k][k]; */
        A[i][k] = mca_divide( A[i][k], A[k][k] );
        for ( j=k+1; j<=n+1; j++ )
          /* A[i][j] = A[i][j] - A[i][k] * A[k][j];*/
          A[i][j] = mca_subtract( A[i][j],
                        mca_multiply( A[i][k], A[k][j] ) );
      }
  
    }
    for ( k=n; k>=1; k-- ) {
      if (A[k,k] != 0) {
        /* b[k] := b[k]/A[k,k]; */
        A[k][n+1] = mca_divide( A[k][n+1], A[k][k] );
        for ( i=k-1; i>=1; i-- ) {
         /* b[i] := b[i] - A[i,k] * b[k]; */
         A[i][n+1] = mca_subtract(A[i][n+1],
                        mca_multiply( A[i][k], A[k][n+1] ));
        }
      }
    }
    for ( i=1; i<=n; i++ )
        for ( j=1; j<=n+1; j++ )
                record_stats(A[i][j], A1[i][j]);

#ifndef PIVOTING
    for ( i=1; i<=n; i++ )
        for ( j=1; j<=n; j++ ) {
             t = 0;
             for ( k=1; k<=i && k<=j ; k++ ) {
                if (k==i) t = mca_add(t, A[i][j]);
                                  /* = U[i,j] =  L[i,k] * U[k,j] */
                else t = mca_add(t, mca_multiply(A[i][k], A[k][j]));
                                        /*    =  L[i,k] * U[k,j] */
             }
             record_stats(t, A2[i][j]);
        }
#endif

  }

  newline();
  printline();
  printf("Gaussian elimination test\n");;
  printf("Results with   inbound %s   outbound %s\n",
          randomization_method_name(inbound_method),
          randomization_method_name(outbound_method));
  printf("also  virtual precision %d \n(averaged over %d samples):\n",
          virtual_precision,
          num_samples);

  printf("\nStarting matrix [A|b]\n");
  printf("Each average value is shown above its [standard error value]\n");
  for ( i=1; i<=n; i++ ) {
    newline();
    for ( j=1; j<=n; j++ ) printf("%13.5e ", stats_average(A0[i][j]));
    printf("  | %13.5e ", stats_average(A0[i][n+1]));
    newline();
    for ( j=1; j<=n; j++ ) printf(" [%10.5e]", stats_stderr(A0[i][j]));
    printf("  |  [%10.5e]", stats_stderr(A0[i][n+1]));
  }
  newline();

  printline();
  printf("\nResulting solution x\n");
  printf("Each average value is shown above its [standard error value]\n");
  newline();
  for ( i=1; i<=n; i++ ) {
    printf("   %13.5e\n", stats_average(A1[i][n+1]));
    printf("    [%10.5e]\n", stats_stderr(A1[i][n+1]));
#ifdef SKEWNESS_AND_EXCESS
    printf("    [%7.1e] %s\n",
                stats_skewness(A1[i][n+1]), NTEST(skewness_test(A1[i][n+1])) );
    printf("    [%7.1e] %s\n",
                stats_excess(A1[i][n+1]), NTEST(excess_test(A1[i][n+1])) );
#endif
  }
  newline();

  printline();
  printf("\nEnding matrix L\\U   (L = unit lower triangle, U = upper triangle)\n");
  printf("Each average value is shown above its [standard error value]\n");
  for ( i=1; i<=n; i++ ) {
    newline();
    for ( j=1; j<i;    j++ ) printf("%13.5e ", stats_average(A1[i][j]));
    for ( j=i; j<=n  ; j++ ) printf("%13.5e ", stats_average(A1[i][j]));
    newline();
    for ( j=1; j<i   ; j++ ) printf(" [%10.5e]", stats_stderr(A1[i][j]));
    for ( j=i; j<=n  ; j++ ) printf(" [%10.5e]", stats_stderr(A1[i][j]));
#ifdef SKEWNESS_AND_EXCESS
    newline();
    for ( j=1; j<i   ; j++ ) printf(" [%7.1e] %s",
                stats_skewness(A1[i][j]), NTEST(skewness_test(A1[i][j])) );
    for ( j=i; j<=n  ; j++ ) printf(" [%7.1e] %s",
                stats_skewness(A1[i][j]), NTEST(skewness_test(A1[i][j])) );
    newline();
    for ( j=1; j<i   ; j++ ) printf(" [%7.1e] %s",
                stats_excess(A1[i][j]), NTEST(excess_test(A1[i][j])) );
    for ( j=i; j<=n  ; j++ ) printf(" [%7.1e] %s",
                stats_excess(A1[i][j]), NTEST(excess_test(A1[i][j])) );
#endif
  }
  newline();

#ifndef PIVOTING
  printline();
  printf("\nProduct of L with U\n");
  printf("Each average value is shown above its [standard error value]\n");
  for ( i=1; i<=n; i++ ) {
    newline();
    for ( j=1; j<=n; j++ ) printf("%13.5e ", stats_average(A2[i][j]));
    newline();
    for ( j=1; j<=n; j++ ) printf(" [%10.5e]", stats_stderr(A2[i][j]));
#ifdef SKEWNESS_AND_EXCESS
    newline();
    for ( j=1; j<=n; j++ ) printf(" [%7.1e] %s",
                stats_skewness(A2[i][j]), NTEST(skewness_test(A2[i][j])) );
    newline();
    for ( j=1; j<=n; j++ ) printf(" [%7.1e] %s",
                stats_excess(A2[i][j]), NTEST(excess_test(A2[i][j])) );
#endif
  }
  newline();
#endif

  }
  printline();
  newline();

  return 0;
}

double
get_double (char* s)
{
   double d;
   printline();
   printf("Enter %s: ", s);
   if (scanf("%g", &d) != 1) exit(-1);
   newline();
   printline();
   return d;
}

int
get_int (char* s)
{
   int n;
   printline();
   printf("Enter %s: ", s);
   if (scanf("%d", &n) != 1) exit(-1);
   newline();
   printline();
   return n;
}

randomization_method
get_inbound ()
{
    randomization_method ra;
    printf("Choose from among the following inbound randomization methods\n");
    printline();
    for (ra = 0 ; ra < randomization_method_limit ; ra++)
      printf("%5d. %s\n", ra, randomization_method_name(ra) );
    printline();
    printf("Enter your selection now: ");
    if (scanf("%d", &ra) != 1) exit(-1);
    newline();
    if (ra < randomization_method_limit) 
      mca_set_inbound_method( ra );
    else {
      fprintf(stderr,"bad  randomization_method  value\n"); 
      return ra;
    }
    printf("inbound method set to: %s\n", randomization_method_name(ra) );
    printline();
    return ra;
}

randomization_method
get_outbound ()
{
    randomization_method ra;
    printf("Choose from among the following outbound randomization methods\n");
    printline();
    for (ra = 0 ; ra < randomization_method_limit ; ra++)
      printf("%5d. %s\n", ra, randomization_method_name(ra) );
    printline();
    printf("Enter your selection now: ");
    if (scanf("%d", &ra) != 1) exit(-1);
    newline();
    if (ra < randomization_method_limit) 
      mca_set_outbound_method( ra );
    else {
      fprintf(stderr,"bad  randomization_method  value\n"); 
      return ra;
    }
    printf("outbound method set to: %s\n", randomization_method_name(ra) );
    printline();
    return ra;
}

int
get_virtual_precision ()
{
    int t;
    printf("Enter virtual precision (integer between 1 and 24): ");
    if (scanf("%d", &t) != 1) exit(-1);
    newline();
    mca_set_virtual_precision( t );
    printf("virtual_precision set to: %d\n", virtual_precision );
    printline();
    return virtual_precision;
}


void perform_calculation(int problem, int num_samples, int other_val)
{
switch (problem) {
      case -1:  return;
      case  0:  printf("Problem number not supported via command line\n");
                break;

      case  1:  quadratic_test(other_val, num_samples);
	        break;

      case  2:  triangle_test(num_samples);
	        break;

      case  3:  Kahan_rp_test();
	        break;

      case  4:  Knuth_test(num_samples);
	        break;

      case  5:  Rump_test(num_samples);
	        break;

      case  6:  startling_test(other_val, num_samples);
	        break;

      case  7:  basic_test(other_val, num_samples);
	        break;

      case  8:  Hilbert_test(other_val, num_samples);
	        break;

      case  9:  { double h = double_power(0.5, other_val);
                Huskey_test( h, floor(M_PI/6.0/h), num_samples);};
	        break;

      case 10:  bakeoff_test(other_val, num_samples);
	        break;

      case 11:  sdev_test (num_samples, other_val);
	        break;

      case 12:  sdev_plot (num_samples, other_val);
	        break;

      case 13:  logistics (num_samples, other_val);
	        break;

    }

return;
}

int
main (int argc, char **argv)
{
int num_samples;
int problem;
int other_val;

  if (argc > 0)
      {
      problem=strtol(argv[1], NULL, 10);
      if (argc > 1)
         num_samples=strtol(argv[2], NULL, 10);
      if (argc > 2)
         other_val=strtol(argv[3], NULL, 10);
      perform_calculation(problem, num_samples, other_val);
      }
  else
  while (1) {
    printf("Choose from among the following:\n");
    printline();
    printf("  -1.  exit.\n");
    printf("   0.  change randomization method and virtual precision.\n");
    printf("   1.  Quadratic equation solving.\n");
    printf("   2.  Kahan's test:  ratio of areas of two narrow triangles.\n");
    printf("   3.  Kahan's example: roundoff of a rational polynomial.\n");
    printf("   4.  Knuth's example: ((x + y) + z) vs. (x + (y + z)) \n");
    printf("   5.  Rump's example: an expression with heavy cancellation.\n");
    printf("   6.  Startling examples:  u[i] and x[i],  1 <= i <= n.\n");
    printf("   7.  Basic numerical computation:  cos(z) and T_20(z).\n");
    printf("   8.  Gaussian elimination on e.g. the Hilbert matrix.\n");
    printf("   9.  Huskey's integration of cos(t) & sin(t), 0 <= t <= Pi/6.\n");
    printf("  10.  Bakeoff among randomization methods.\n");
    printf("  11.  Standard deviation computation using 5 algorithms.\n");
    printf("  12.  Standard deviation plots: textbook vs. two-pass.\n");
    printf("  13.  Logistic iteration trace: in chaos, roundoff matters.\n");
    printline();
    printf("Enter your selection now: ");
    if (scanf("%d", &problem) == EOF) exit(0);
    newline();
    printline();

    switch (problem) {
      case -1:  break;
      case  0:  break;
      case  3:  break;
      default:  num_samples = get_int("number of samples");
    }

    switch (problem) {
      case -1:  return 0;
      case  0:  get_inbound(); get_outbound(); get_virtual_precision(); break;
      case  1:  quadratic_test(get_int("scale"), num_samples);          break;
      case  2:  triangle_test(num_samples);                             break;
      case  3:  Kahan_rp_test();                                        break;
      case  4:  Knuth_test(num_samples);                                break;
      case  5:  Rump_test(num_samples);                                 break;
      case  6:  startling_test(get_int("n"), num_samples);              break;
      case  7:  basic_test(get_int("number of points"), num_samples);   break;
      case  8:  Hilbert_test(get_int("n"), num_samples);                break;
      case  9:  { double h = double_power(0.5,get_int("step size exponent"));
                Huskey_test( h, floor(M_PI/6.0/h), num_samples);};      break;
      case 10:  bakeoff_test(get_int("scale"), num_samples);            break;
      case 11:  sdev_test (num_samples,get_int("no. of observations")); break;
      case 12:  sdev_plot (num_samples,get_int("no. of observations")); break;
      case 13:  logistics (num_samples,get_int("no. of iterations"));   break;
    }
  }

  return 0;
}
