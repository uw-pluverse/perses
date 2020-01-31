



class TargetType15 {

    interface SAM<T> {
        T foo(T a, T b);
    }

    void m1(SAM<? extends String> f_1) {}
    void m2(SAM<? super String> f_2) {}
    void m3(SAM<?> f_3) {}

    SAM<? extends String> f_1 = (a, b) -> a;
    SAM<? super String> f_2 = (a, b) -> a;
    SAM<?> f_3 = (a, b) -> a;

    {
        m1((a, b) -> a);
        m2((a, b) -> a);
        m3((a, b) -> a);
    }
}
