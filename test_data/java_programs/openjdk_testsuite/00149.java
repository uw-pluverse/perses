



public class LowerBoundGLB {

    interface Box<T> {
        T get();
        void set(T arg);
    }

    <T> T doGLB(Box<? super T> b1, Box<? super T> b2) {
        return null;
    }

    void test(Box<? super String> l1, Box<? super CharSequence> l2) {
        doGLB(l1, l2).substring(3);
    }

}
