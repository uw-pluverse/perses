



enum NoFinal4 {
    A, B, C;
    private void finalize() {
        System.err.println("FISK");
    }
}
