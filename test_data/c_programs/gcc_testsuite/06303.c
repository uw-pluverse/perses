







struct s0;
struct s0 { int a; };
struct s0;
void f (void) { struct s0; }



const union u0;
union u0 { long b; };

extern struct s1;







struct s2 { char x; };
const struct s2;

union u1;
extern union u1;

union u2 { long b; };
void g(void) { const union u2; }






union u3 { float v; };
void h(void) { const struct u3; }






struct s3;
const struct s3 { int a; };

union u4;
extern union u4 { int z; };

enum e0 { E0 };
void i(void) { const enum e0 { E1 }; }

union u5 { int p; };
void j(void) { extern struct u5 { int q; }; }
