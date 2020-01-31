




class InvalidGenericLambdaTarget {

    interface SAM {
        <Z> void m();
    }

    SAM s = x-> { };
}
