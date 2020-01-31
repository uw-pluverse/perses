



class AnonInnerException_2 {

    boolean done = true;

    void foo() throws Exception {

        AnonInnerExceptionAux y =
            new AnonInnerExceptionAux() {
              
              {
                  if (done)
                      throw new java.io.IOException();
              }
        };
    }
}

class AnonInnerExceptionAux {
    AnonInnerExceptionAux() throws MyException {}
}

class MyException extends Exception {}
