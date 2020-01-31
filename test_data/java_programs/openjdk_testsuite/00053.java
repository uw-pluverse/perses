



public class T5034571 {
    interface I1 {
        void i1();
    }

    class G1<T extends I1> {
        T get() { return null; }
    }

    interface I2 {
        void i2();
    }

    class Main {
        void f1(G1<?> g1) {
            g1.get().i1();
        }
        void f2(G1<? extends I2> g1) {
            g1.get().i1();
            g1.get().i2();
        }
    }
}
