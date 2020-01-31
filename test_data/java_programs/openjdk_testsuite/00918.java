



class T5090220 {
    static void foo(int i1, Integer i2) {
        System.out.println("Integer");
    }
    static void foo(Integer i1, double d) {
        System.out.println("double");
    }
    public static void main(String[] args) {
        foo(5, 5);
    }
}
