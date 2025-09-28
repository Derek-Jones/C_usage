                        /* decls.c,  12 May 06 */

int i;
type i;
const int i;
extern int i;
int *i;
int ***i;
int * volatile i;
int i[];
int i[3+1];
int i[3+1][];
int (i);
int i();
int i(j);
int *i();
int (*i)();
int (*(i))();
int *i[j+k];
void char short int long long long unsigned signed i;
float double long double i;
const volatile restrict i;
extern static auto register i;
extern static auto register const short char i;
typedef int i;
;
struct tag;
struct {int mem;};
struct {int mem,mem2;};
struct {int mem :99;};
struct {int     :99;};
struct {char mem; int mem2;};
struct tag {int mem;};
struct tag {struct {int mem;} mem;};
struct tag i;
struct tag {int mem;} i;
struct tag {int mem;} *i;
struct tag {int mem;} i[3];
union tag;
enum x i;
enum {a,b,c} i;
enum i {a=22, b=a};
void f(int i);
void f(int i, char p);
void f(int i) {
void (f)(int i) {

