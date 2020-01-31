





class T<X> {

    class U<Y> extends T<X> {
        <B> U(B b) {
            <Object>super();
        }
        U(int i) {
            <Object>this("");
        }
    }

    class V<Z> extends U<Z> {
        <C> V(T<X> t) {
            t.<Integer>super("");
        }
    }

    <A> T() {
    }

    <K> void f() {
        this.<Object>f();
    }

    public static void main(String[] args) {
        T<Integer> x = new <Object>T<Integer>();
        T<Integer>.U<Float> y = x.new <Object>U<Float>("");
        x.<Object>f();
    }
}
