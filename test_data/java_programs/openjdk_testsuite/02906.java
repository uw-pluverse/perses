


class Intersection01 {

    interface SAM {
        void m();
    }

    Object o1 = (java.io.Serializable & SAM)()->{};
    Object o2 = (SAM & java.io.Serializable)()->{};
    Object o3 = (java.io.Serializable & SAM)Intersection01::m;
    Object o4 = (SAM & java.io.Serializable)Intersection01::m;

    static void m() { }
}
