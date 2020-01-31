



public class ProtectedAccess_3 {
    ProtectedAccess_3() {
        new Object() {
            public void finalize() throws Throwable {
                ProtectedAccess_3.this.finalize();
            }
        };
    }

    public static void main(String[] argv) {
        new ProtectedAccess_3();
    }
}
