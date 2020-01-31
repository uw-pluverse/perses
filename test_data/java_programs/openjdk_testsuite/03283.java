

class T8021567 {

    interface I_int { int m(); }

    interface I_char { char m(); }

    interface I_byte { byte m(); }

    void m(I_byte b) { }
    void m(I_char b) { }
    void m(I_int b) { }

    void test() {
        m(() -> 1); 
        m(() -> 256); 
        m(() -> { int i = 1; return i; }); 
        m(() -> { int i = 256; return i; }); 
    }
}
