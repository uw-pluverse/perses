



class TargetType48 {
    interface I1 {
        void a();
        void b();
        void c();
    }

    interface I2 extends I1 {
        default void a() { }
    }

    interface I3 extends I2 {
        default void b() { }
    }

    I3 i3 = ()->{ };
}
