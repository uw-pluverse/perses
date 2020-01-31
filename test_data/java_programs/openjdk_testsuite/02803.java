



class ExceptionalFinally2 {
    static class E extends Exception {}

    public void t() throws E {}

    void f() {
        try {
            try {
                t();
            } finally {
                return;
            }
        } catch (E x) { 
        }
    }
}
