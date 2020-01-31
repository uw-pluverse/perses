



class T6932571neg {
    interface I<T>{ }
    interface I1 extends I<String> {}
    static class Y implements I<String> {}
    final static class S implements I<String> {}

    <G extends I<G>> void test() {
        S s = new S();
        G g = (G) s;
    }
}
