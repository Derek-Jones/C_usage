void f(void)
{
for (y; ;)
     if (z)
        continue;

for (y; ;)
   {
     for (u; ;)
        if (z)
           p++;
        else
           continue;
   }

for (y; ;)
   {
     if (z)
	continue;
   }
}

void f(void)
{
for (y; ;)
     if (z)
        break;

for (y; ;)
   {
     for (u; ;)
        if (z)
           p++;
        else
           break;
   }

for (y; ;)
   {
     if (z)
	break;
   }
}

void f(void)
{
switch (x)
   {
case 1: x--;
        break;

case 2: case 3: x++;
        break;
   }

switch (x)
   {
case 1: x--;
        break;

case 2: case 3: x++;
        break;

default: break;
   }

}


