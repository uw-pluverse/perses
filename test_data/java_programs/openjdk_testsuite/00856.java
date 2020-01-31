



enum NoFinal5 {
    A, B, C;
    void finalize() {
        System.err.println("FISK");
    }
}
