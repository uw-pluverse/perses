





public class MethodReferenceQualification_1 extends P1.pub {

  void bar () {
    P1.pub p = new P1.pub();
    p.foo();
    this.foo();
    foo();
  }

  public static void main(String[] args) {
    (new MethodReferenceQualification_1()).bar();
  }
}
