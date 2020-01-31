



public class T6657499<T> {
    T t;
    public T test() {
        class Local {private T t;};
        class Local2 {T m() {return t;}};
        T t3 = new Local().t;
        return new Local2().m();
    }
    public static void main(String[] args) {
        String s = new T6657499<String>().test();
    }
}
