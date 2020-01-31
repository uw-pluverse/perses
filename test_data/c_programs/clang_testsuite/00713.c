typedef struct s1 { float f; } Sf;
typedef struct s2 { double d; } Sd;
typedef struct s4 { Sf fs; } SSf;
typedef struct s5 { Sd ds; } SSd;
void bar(Sf a, Sd b, SSf d, SSd e) {}
void foo(void)
{
  Sf p1 = { 22.63f };
  Sd p2 = { 19.47 };
  SSf p4 = { { 22.63f } };
  SSd p5 = { { 19.47 } };
  bar(p1, p2, p4, p5);
}
