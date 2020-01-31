int (*FP)();
int (^IFP) ();
int (^II) (int);
int main() {
  int (*FPL) (int) = FP;
  int (^PFR) (int) = IFP;
  PFR = II;
  int (^IFP) () = PFR;
  const int (^CIC) () = IFP;
  const int (^CICC) () = CIC;
  int * const (^IPCC) () = 0;
  int * const (^IPCC1) () = IPCC;
  int * (^IPCC2) () = IPCC;
  int (^IPCC3) (const int) = PFR;
  int (^IPCC4) (int, char (^CArg) (double));
  int (^IPCC5) (int, char (^CArg) (double)) = IPCC4;
  int (^IPCC6) (int, char (^CArg) (float)) = IPCC4;
  IPCC2 = 0;
  IPCC2 = 1;
  int (^x)() = 0;
  int (^y)() = 3;
  int a = 1;
  int (^z)() = a+4;
}
int blah() {
  int (^IFP) (float);
  char (^PCP)(double, double, char);
  IFP(1.0);
  IFP (1.0, 2.0);
  char ch = PCP(1.0, 2.0, 'a');
  return PCP(1.0, 2.0);
}
