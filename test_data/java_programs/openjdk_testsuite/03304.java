



class LambdaExpr13 {

    Runnable ir;
    static Runnable sr;

    { ir = () -> { ir.run(); }; }
    static { sr = () -> { sr.run(); }; }

    static void m1() {
        sr = () -> { sr.run(); };
    }

    void m2() {
        ir = () -> { ir.run(); };
    }
}
