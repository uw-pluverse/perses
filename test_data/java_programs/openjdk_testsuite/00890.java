



enum NoFinal2 {
    A, B, C;
    protected void finalize() {
        System.err.println("FISK");
    }
}
