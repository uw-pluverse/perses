
interface Clinit {
    String s = Inner.m();

    static class Inner {
        static String m() { return ""; }
    }
}
