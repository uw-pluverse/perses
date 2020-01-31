



class T4723909 {
    static class Test {
        public static void main(String[] args) {
            new Subclass().test(0);
        }
    }
    static class Superclass {
        static void test(int i) {
            System.out.println("test(int i)");
        }
    }
    static class Subclass extends Superclass {
        static void test(long l) {
            System.out.println("test(long l)");
        }
    }
}
