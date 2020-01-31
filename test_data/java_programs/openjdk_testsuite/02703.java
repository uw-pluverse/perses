


interface I1{
  int f();
}
interface I2 {
  void f() ;
}

interface InconsistentInheritedSignature extends I1,I2 { }
