



public class T6302214a {
    class X<T> {}
    class X2 extends X<String> {}
    class Test {
        X<? extends Object> x;
        X2 x2 = (X2)x;
    }
}
