struct S1 { int mem1; char mem2;};
struct S1 s1_obj;

struct { int mem3; char mem4;} anon_obj;
struct S2 { struct S1 mem5; char mem6;};

struct S3 { struct S4 *mem7; int mem8 : 3;};

struct S4 { int mem9; 
            struct S5 {char mem10;} mem11;};

