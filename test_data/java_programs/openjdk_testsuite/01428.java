




class NoSuitableFunctionalIntfInst {

    interface SAM<X extends Number> {
        void m(X x);
    }

    SAM<?> ss = (String s)-> { };
}
