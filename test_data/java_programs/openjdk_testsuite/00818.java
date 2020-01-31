



class T7023703pos {

    void testForLoop() {
        final int bug;
        for (;"a".equals("b");) {
            final int item = 0;
        }
        bug = 0; 
    }

    void testForEachLoop(boolean cond, java.util.Collection<Integer> c) {
        final int bug;
        for (Integer i : c) {
            if (cond) {
                final int item = 0;
            }
        }
        bug = 0; 
    }

    void testWhileLoop() {
        final int bug;
        while ("a".equals("b")) {
            final int item = 0;
        }
        bug = 0; 
    }

    void testDoWhileLoop() {
        final int bug;
        do {
            final int item = 0;
        } while ("a".equals("b"));
        bug = 0; 
    }

    private static class Inner {
        private final int a, b, c, d, e;

        public Inner() {
            a = b = c = d = e = 0;
        }
    }
}
