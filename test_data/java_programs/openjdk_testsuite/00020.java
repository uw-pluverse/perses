



package covar3;

interface Test3<T> {
    void f(     T f);
    void f(String f);
}

class T {
    void f(Test3<String> x) {
        x.f("");
    }
}
