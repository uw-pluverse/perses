

class T7030687<X> {
    class Member { }
    static class Nested {}

    void test() {
        class Local {}

        Member m = new Member<>();
        Nested n = new Nested<>();
        Local l = new Local<>();
    }
}
