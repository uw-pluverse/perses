

class MethodReference22 {

    void m1(String x) { }
    void m1(MethodReference22 rec, String x) { }

    static void m2(String x) { }
    static void m2(MethodReference22 rec, String x) { }

    static void m3(String x) { }
    void m3(MethodReference22 rec, String x) { }

    void m4(String x) { }
    static void m4(MethodReference22 rec, String x) { }

    interface SAM1 {
        void m(String x);
    }

    interface SAM2 {
        void m(MethodReference22 rec, String x);
    }

    static void call1(SAM1 s) {   }

    static void call2(SAM2 s) {   }

    static void call3(SAM1 s) {   }
    static void call3(SAM2 s) {   }

    static void test1() {
        SAM1 s1 = MethodReference22::m1; 
        call1(MethodReference22::m1); 
        SAM1 s2 = MethodReference22::m2; 
        call1(MethodReference22::m2); 
        SAM1 s3 = MethodReference22::m3; 
        call1(MethodReference22::m3); 
        SAM1 s4 = MethodReference22::m4; 
        call1(MethodReference22::m4); 
    }

    static void test2() {
        SAM2 s1 = MethodReference22::m1; 
        call2(MethodReference22::m1); 
        SAM2 s2 = MethodReference22::m2; 
        call2(MethodReference22::m2); 
        SAM2 s3 = MethodReference22::m3; 
        call2(MethodReference22::m3); 
        SAM2 s4 = MethodReference22::m4; 
        call2(MethodReference22::m4); 
    }

    static void test3() {
        call3(MethodReference22::m1); 
        call3(MethodReference22::m2); 
        call3(MethodReference22::m3); 
        call3(MethodReference22::m4); 
    }
}
