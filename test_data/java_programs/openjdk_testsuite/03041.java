

class BadExpressionLambda {

    interface SAM {
        void invoke();
    }

    public static void m() {}

    void test() {
        SAM sam1 = () -> m(); 
        SAM sam2 = () -> true ? m() : m(); 
    }
}
