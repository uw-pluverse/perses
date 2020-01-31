





class IncompatibleAbstracts {

    interface SAM {
        void m(String s);
        void m(Integer i);
    }

    SAM s = x-> { };
}
