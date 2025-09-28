
enum blah {x, y=-2};
enum b2{a=3, b, c=99};
enum b3{d=0xff, e, f=0xfeef};

enum b2 eobj;

void func(void)
{
sizeof(eobj);
sizeof(int);
sizeof (struct {int i;});
sizeof d;
}

