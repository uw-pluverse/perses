



class AnonInnerException_3 {

    void foo() throws Exception {

        class Inner extends AnonInnerExceptionAux {};

        AnonInnerExceptionAux x = new Inner();

    }
}

class AnonInnerExceptionAux {
    AnonInnerExceptionAux() throws Exception {}
}
