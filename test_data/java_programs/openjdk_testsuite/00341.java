



public class Crash01<A extends TestClass1 & IA> {
  public A value;
  public void testit(){
    value.testClass();
  }
}

class TestClass1{ public void testClass(){} }
interface IA{}
