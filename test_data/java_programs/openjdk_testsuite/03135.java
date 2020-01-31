



class MethodReference26 {

    static void m(Integer i) { }

    interface SAM {
        void m(int x);
    }

    static void call(int i, SAM s) {   }
    static void call(Integer i, SAM s) {   }

    static void test() {
        call(1, MethodReference26::m); 
    }
}
