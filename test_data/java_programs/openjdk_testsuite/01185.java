





class IncompatibleRetTypeInLambda {
    interface SAM {
        Integer m();
    }

    SAM s = ()-> "";
}
