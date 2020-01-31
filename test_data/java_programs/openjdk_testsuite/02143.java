
class T8055514 {
    void m(int... args) { }

    void m2(int... args) { }
    static void m2(String s) { }

    void m3(int... args) { }
    static void m3(String s) { }
    static void m3(Runnable r) { }

    void m4(int... args) { }
    void m4(int i1, int i2, int i3) { }

    static void test() {
        m(1,2,3); 
        m2(1,2,3); 
        m3(1,2,3); 
        m4(1,2,3); 
    }
}
