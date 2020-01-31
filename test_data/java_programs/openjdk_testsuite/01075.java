



class AnonymousConstructorExceptions {

    static class A1 {
        A1() throws RuntimeException {}
    }

    static class A2 {
        A2() throws Error {}
    }

    static class A3 {
        A3() throws Exception {}
    }

    void test1() {
        A1 bar = new A1() { };
    }

    void test2() {
        A2 bar = new A2() { };
    }

    void test3() throws Exception {
        A3 bar = new A3() { };
    }

}
