







class IncompatibleDescsInFunctionalIntf {
    interface A {
        Integer m(String i) throws Exception;
    }

    interface B {
        String m(String i);
    }

    interface SAM extends A,B { }

    SAM s = x-> { };
}
