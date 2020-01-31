



package varargs.versus.generics;


class T {
    <T> void f(T t, Object... args) {}
    void g(Object x, Object y, Object z) {
        f(x, y, z);
    }
}
