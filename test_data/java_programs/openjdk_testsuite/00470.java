



class CovariantCompat1 {
    static class A {
        public A foo() { return this; }
    }
    static class B extends A {
        public B foo() { return this; }
    }
}
