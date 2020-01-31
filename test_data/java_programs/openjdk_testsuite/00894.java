



enum NoFinal3 {
    A, B, C;
    public void finalize() {
        System.err.println("FISK");
    }
}
