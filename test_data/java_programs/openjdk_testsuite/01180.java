



class TypesIncompatibleUnrelatedDefaults {
    interface A {
        default void m() { }
    }

    interface B {
        default void m() { }
    }

    interface AB extends A, B { }
}
