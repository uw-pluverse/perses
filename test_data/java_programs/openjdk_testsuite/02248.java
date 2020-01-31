

class T4906100 {
    void f1(int a, int b) {
        if (a == b);
            System.out.println("a == b");
    }

    @SuppressWarnings("empty")
    void f2(int a, int b) {
        if (a == b);
            System.out.println("a == b");
    }

    
    void f3(int a, int b) {
        if (a == b) { }
            System.out.println("a == b");
    }
}
