


class T6923080 {
    void test() {
        C c = new <Integer>C();  
        Object o = c.<Float>m(); 
    }

    static class C {
        <T> C()   { }
        <T> T m() { return null; }
    }
}
