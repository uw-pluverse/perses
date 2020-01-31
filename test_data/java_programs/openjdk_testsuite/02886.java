
class MostSpecific12 {

    interface I<T> { void take(T arg1, String arg2); }
    interface J<T> { void take(String arg1, T arg2); }
    interface K { void take(String arg1, String arg2); }

    <T> void m1(I<T> arg) {}
    void m1(K arg) {}

    <T> void m2(J<T> arg) {}
    <T> void m2(K arg) {}

    <T> void m3(I<T> arg) {}
    <T> void m3(J<T> arg) {}

    void test() {
        m1((String s1, String s2) -> {}); 
        m2((String s1, String s2) -> {}); 
        m3((String s1, String s2) -> {}); 

        m1(this::referencedMethod); 
        m2(this::referencedMethod); 
        m3(this::referencedMethod); 

        m1(String::compareTo); 
        m2(String::compareTo); 
        m3(String::compareTo); 
    }

    void referencedMethod(String s1, String s2) {}

}
