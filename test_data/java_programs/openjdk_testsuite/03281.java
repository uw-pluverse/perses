



class LambdaExpr20 {

    interface K {
        default void m() { }
    }

    static class Test implements K {
        @Override
        public void m() {
            Runnable r = () -> { K.super.m(); };
            r.run();
        }
    }
}
