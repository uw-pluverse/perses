



public enum EnumSwitch4 {
    foo, bar, baz;

    public static void main(String[] args) {
        EnumSwitch4 e = null;
        try {
            switch (e) {
            default: break;
            }
            throw new Error("failed to throw NullPointerException");
        } catch (NullPointerException ex) {
            System.out.println("passed");
        }
    }
}
