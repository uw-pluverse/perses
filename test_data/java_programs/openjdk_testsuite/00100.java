



public class T5021635 {
    static class M<T> {}
    static <T extends M<U>, U> void f1() {
    }
    void g() {
        f1();
    }
}
