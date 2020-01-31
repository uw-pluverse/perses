





class IncompatibleRetTypeInMref {
    interface SAM {
        Integer m();
    }

    static String f() { }

    SAM s = IncompatibleRetTypeInMref::f;
}
