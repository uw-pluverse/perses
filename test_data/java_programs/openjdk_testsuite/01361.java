



class TypesIncompatibleAbstractDefault {
    interface A {
        default void m() { }
    }

    interface B {
        void m();
    }

    interface AB extends A, B { }
}
