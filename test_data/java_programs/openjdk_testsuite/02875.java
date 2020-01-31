


public class MethodReference65 {

    interface SAM<X> {
        void m(X ss, String s);
    }

    void m(String... s) { }

    public static void main(String[] args) {
        SAM<MethodReference65> st = MethodReference65::m;
        st.m(new MethodReference65(), "");
    }
}
