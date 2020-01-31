

public class MethodReference73 {

    interface SAM {
        void m(MethodReference73 rec, String x);
    }

    void m1(MethodReference73 rec, String x) {}
    static void m1(MethodReference73 rec, Object x) {}
    void m1(String x) {}

    static void m2(MethodReference73 rec, String x) {}
    void m2(Object x) {}
    static void m2(String x) {}

    static void m3(MethodReference73 rec, String x) {}
    void m3(String x) {}

    void m4(MethodReference73 rec, String x) {}
    static void m4(MethodReference73 rec, Object x) {}
    static void m4(String x) {}
    void m4(Object x) {}

    static void m5(MethodReference73 rec, String x) {}
    static void m5(String x) {}

    static void m6(MethodReference73 rec, String x) {}
    void m6(String x, int i) {}

    void m7(MethodReference73 rec, String x) {}
    void m7(String x) {}

    static void m8(MethodReference73 rec, String x, int i) {}
    void m8(String x) {}

    void m9(MethodReference73 rec, String x) {}
    static void m9(MethodReference73 rec, Object x) {}
    static void m9(String x) {}

    void m10(MethodReference73 rec, String x) {}
    static void m10(MethodReference73 rec, Object x) {}
    void m10(String x, int i) {}

    void m11(MethodReference73 rec, String x) {}
    void m11(Object x) {}
    static void m11(String x) {}

    static void m12(MethodReference73 rec, String x, int i) {}
    void m12(Object x) {}
    static void m12(String x) {}

    void m13(MethodReference73 rec, String x) {}
    void m13(String x, int i) {}

    static void m14(MethodReference73 rec, String x, int i) {}
    static void m14(String x) {}

    void m15(MethodReference73 rec, String x) {}
    static void m15(String x) {}

    static void m16(MethodReference73 rec, String x, int i) {}
    void m16(String x, int i) {}

    

    static void test() {
        SAM s1 = MethodReference73::m1;           
        SAM s2 = MethodReference73::m2;           
        SAM s3 = MethodReference73::m3;           
        SAM s4 = MethodReference73::m4;           

        SAM s5 = MethodReference73::m5;           
        SAM s6 = MethodReference73::m6;           

        SAM s7 = MethodReference73::m7;           
        SAM s8 = MethodReference73::m8;           

        SAM s9 = MethodReference73::m9;           
        SAM s10 = MethodReference73::m10;         
        SAM s11 = MethodReference73::m11;         
        SAM s12 = MethodReference73::m12;         
        SAM s13 = MethodReference73::m13;         
        SAM s14 = MethodReference73::m14;         
        SAM s15 = MethodReference73::m15;         

        SAM s16 = MethodReference73::m16;         
    }
}
