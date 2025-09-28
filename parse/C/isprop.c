                            /* isprop.c, 13 Apr 10 */


#include <ctype.h>

#include "global.h"
#include "isprop.h"


BOOL is_dec_point(DIGIT_CHAR ch)
{
return ch == DP_CHAR;
}


BOOL is_zero(DIGIT_CHAR ch)
{
return ch == '0';
}


BOOL is_xdigit(DIGIT_CHAR ch)
{
return isxdigit(ch) != 0;
}


BOOL is_digit(DIGIT_CHAR ch)
{
return isdigit(ch) != 0;
}


BOOL is_start_digit(DIGIT_CHAR ch)
{
return is_digit(ch) != 0;
}


BOOL is_num_digit(DIGIT_CHAR ch)
{
return is_digit(ch) || is_dec_point(ch);
}


BOOL is_exp_digit(DIGIT_CHAR ch)
{
return is_digit(ch) != 0;
}


BOOL is_exp_sign(DIGIT_CHAR ch)
{
return (ch == '+') || (ch == '-');
}


BOOL is_mantissa_sign(DIGIT_CHAR ch)
{
return (ch == '+') || (ch == '-');
}


BOOL is_exp_prefix(DIGIT_CHAR ch)
{
return (tolower(ch) == 'e') || (tolower(ch) == 'd');
}


BOOL is_number(const char *str)
{
int ch_offset=0;

if (is_dec_point(str[0]))
   ch_offset++;

while (is_digit(str[ch_offset]) || is_dec_point(str[ch_offset]))
   ch_offset++;

if (is_exp_prefix(str[ch_offset]))
   {
   ch_offset++;
   if (is_exp_sign(str[ch_offset]))
      ch_offset++;
   while (is_digit(str[ch_offset]))
      ch_offset++;
   }

return str[ch_offset] == NULL_CHAR;
}


BOOL is_ident_ch(DIGIT_CHAR ch)
{
return isalpha(ch) || isdigit(ch);
}


BOOL is_letter(DIGIT_CHAR ch)
{
return isalpha(ch) != 0;
}


BOOL is_start_letter(DIGIT_CHAR ch)
{
return is_letter(ch) != 0;
}


