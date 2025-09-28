
int bar(int ()); // This prototype cannot be parsed by CIL
int bar(int x()); // If you add a name to the function, it works
int bar(int (*)()); // This also works (and it is more appropriate)


g(); // This cannot be parsed by CIL
int g(); // This is Ok



