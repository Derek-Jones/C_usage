# 1 "t.c"
# 1 "<built-in>"
# 1 "<command line>"
# 1 "t.c"

static int x = 5;
int f() {
  int x = 3;
  {
    extern int x;
    return x;
  }
}
