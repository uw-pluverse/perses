



public class T4916620 {
    static class BB<T, S> { }
    static class BD<T> extends BB<T, T> { }

    void f() {
        BD<Number> bd = new BD<Number>();
        BB<? extends Number, ? super Integer> bb = bd;
        Object o = (BD<Number>) bb;
    }
}
