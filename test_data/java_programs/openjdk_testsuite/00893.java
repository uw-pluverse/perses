



enum NoFinal {
    A {
        protected void finalize() {
            System.err.println("FISK");
        }
    };
}
