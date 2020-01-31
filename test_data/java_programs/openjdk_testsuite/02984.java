


public class T8023389 {

    static class U1 {}
    static class X1 extends U1 {}

    interface I { }

    interface SAM<T> {
        void m(T t);
    }

    
    SAM<? extends U1> sam1 = (SAM<? extends U1>) (X1 x) -> { };
    SAM<? extends U1> sam2 = (SAM<? extends U1> & I) (X1 x) -> { };
}
