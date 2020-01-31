



import a.*;
public class AccessTest {
    private static class Impl extends B {
        public void method(Inner inner) {
            for (A a : inner)
                System.out.println(a);
        }
    }
}
