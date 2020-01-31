



class ExceptionalFinally {
    static class E extends Exception {}

    public void t() throws E {}

    public void a() {
        try {
            t();
        } catch (E x) {
            t();
        } finally {
            return;
        }
    }
}
