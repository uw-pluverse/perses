


class T6747671a {

    DeprecatedClass a1; 

    @SuppressWarnings("deprecation")
    DeprecatedClass a2;

    <X extends DeprecatedClass> DeprecatedClass m1(DeprecatedClass a)
            throws DeprecatedClass { return null; } 

    @SuppressWarnings("deprecation")
    <X extends DeprecatedClass> DeprecatedClass m2(DeprecatedClass a)
            throws DeprecatedClass { return null; }

    void test() {
        DeprecatedClass a1; 

        @SuppressWarnings("deprecation")
        DeprecatedClass a2;
    }
}
