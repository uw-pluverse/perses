





class CantAccessInnerClsConstructor {

    interface SAM {
        Outer m();
    }

    class Outer { }

    static void test() {
        SAM s = Outer::new;
    }
}
