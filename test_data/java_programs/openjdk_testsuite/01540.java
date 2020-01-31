




class IncompatibleArgTypesInLambda {
    interface SAM {
        void m(Integer x);
    }

    SAM s = (String x)-> {};
}
