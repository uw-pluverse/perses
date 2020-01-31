



interface A<T> {
    public void f(T x);
}

class X {
}



class C<T extends X> extends B<T> implements A<T> {



}

class B<T extends X> implements A<T> {
    public void f(T x) {
        System.out.println("B.f()");
    }
}

class D extends C<X> {
    public void f(X y) {
        System.out.println("D.f()");
    }
}

public class BridgeOrder {
    public static void main(String args[]) {
        A<X> x = new D();
        x.f(new X());
    }
}
