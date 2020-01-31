



class LambdaExpr08 {

    interface SAM {
       String m();
    }

    void test() {
        final String s;
        s = "";
        SAM sam = () -> s;
    }
}
