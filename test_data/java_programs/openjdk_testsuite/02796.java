


interface I1{
  int f();
}
interface I2 {
  void f() ;
}

interface InconsistentReturn extends I1,I2 { }
