



public enum ValueOf {
    a, b, c, d, e;
    public static void main(String[] args) {
        String[] names = {"b", "a"};
        if (valueOf("a") != a) throw new Error();
        if (valueOf("d") != d) throw new Error();
        if (valueOf("e") != e) throw new Error();
        try {
            ValueOf f = valueOf("f");
            throw new Error();
        } catch (IllegalArgumentException ex) {
        }
    }
}
