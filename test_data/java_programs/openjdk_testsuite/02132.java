



package varargs.warning.warn2;

class Warn2 {
    void f(String... args) {}
    void g(String... args) {
        f(args);
    }
}
