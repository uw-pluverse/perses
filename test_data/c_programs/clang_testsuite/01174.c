union S {
  unsigned ac : 4;
  unsigned : 4;
  unsigned clock : 1;
  unsigned : 0;
  unsigned flag : 1;
};
struct X {
  unsigned light : 1;
  unsigned toaster : 1;
  int count;
  union S stat;
};
