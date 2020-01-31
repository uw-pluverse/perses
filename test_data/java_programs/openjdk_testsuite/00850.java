



public enum OkFinal {
    A {
        protected void finalize(Void nil) {
            System.out.println("FISK");
        }
    };

    public static void main(String[] args) {
        System.out.println("HEST");
    }
}
