

class T6969184 {
    static class C1<X> {
        void m1(C1<? extends NonExistentClass> n) {}
        void m2(C1<? super NonExistentClass> n) {}
        void m3(C1<?> n) {}
    }

    static class C2<X extends NonExistentBound> {
        void m1(C2<? extends NonExistentClass> n) {}
        void m2(C2<? super NonExistentClass> n) {}
        void m3(C2<?> n) {}
    }

    static class C3<X extends NonExistentBound1 & NonExistentBound2> {
        void m1(C3<? extends NonExistentClass> n) {}
        void m2(C3<? super NonExistentClass> n) {}
        void m3(C3<?> n) {}
    }
}
