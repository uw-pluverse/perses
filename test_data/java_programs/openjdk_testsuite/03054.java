



class LambdaExpr04 {

    interface SAM {
        void m(int i);
    }
    static SAM lambda_01 = (int pos) -> { };

    static final SAM lambda_02 = (int pos) -> { };

    SAM lambda_03 = (int pos) -> { };

    final SAM lambda_04 = (int pos) -> { };
}
