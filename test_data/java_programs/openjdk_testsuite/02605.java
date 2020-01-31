



class AnonInnerException_1 {

    boolean done = true;

    void foo() throws Exception {

        AnonInnerExceptionAux x =
            new AnonInnerExceptionAux(){};

        
    }
}

class AnonInnerExceptionAux {
    AnonInnerExceptionAux() throws Exception {}
}

class MyException extends Exception {}
