

class EffectivelyFinalThrows {
    interface SAM<E extends Throwable> {
        public void t() throws E;
    }
    <E extends Throwable> void test(SAM<E> s) throws E {
        s.t();
    }
    void test2(SAM<Checked> s) throws Checked {
        test(() -> {
            try {
                s.t();
            } catch (Throwable t) {
                throw t;
            }
        });
    }
    static class Checked extends Exception {}
}
