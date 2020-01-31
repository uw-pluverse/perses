



class TargetType47 {
    interface A {
        void a();
        void b();
        default void c() { };
    }

    interface B extends A {
        default void b() { };
    }

    B b = ()-> {};
}
