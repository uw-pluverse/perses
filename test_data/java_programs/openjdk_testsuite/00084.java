



public class T4942040 {
    static <T> T f(T a, T b) {
        return a;
    }
    static Cloneable main(Cloneable a, float[] b) {
        return f(a, b);
    }
}
