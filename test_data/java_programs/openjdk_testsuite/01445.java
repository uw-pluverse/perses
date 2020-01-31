



class IncompatibleThrownTypesInMref {
    interface SAM {
        void m();
    }

    static void f() throws Exception { }

    SAM s = IncompatibleThrownTypesInMref::f;
}
