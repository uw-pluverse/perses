



import java.util.function.*;

public interface PotentiallyAmbiguousWarningTest {

    
    interface I1 {
        void foo(Consumer<Integer> c);
        void foo(IntConsumer c);
    }

    
    class C1 {
        void foo(Consumer<Integer> c) { }
        void foo(IntConsumer c) { }
    }

    interface I2 {
        void foo(Consumer<Integer> c);
    }

    
    interface J1 extends I2 {
        void foo(IntConsumer c);
    }

    
    interface I3 extends I1 {}

    
    interface I4 extends I1 {
        void foo(IntConsumer c);
    }

    class C2 {
        void foo(Consumer<Integer> c) { }
    }

    
    class D1 extends C2 {
        void foo(IntConsumer c) { }
    }

    
    class C3 implements I2 {
        public void foo(Consumer<Integer> c) { }
        public void foo(IntConsumer c) { }
    }

    
    class C4 extends C1 {}

    
    class C5 extends C1 {
        void foo(IntConsumer c) {}
    }

    interface I5<T> {
        void foo(T c);
    }

    
    interface J2 extends I5<IntConsumer> {
        void foo(Consumer<Integer> c);
    }
}
