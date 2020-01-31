



class C {
    void m(Object... args) { }
}

class InexactVarargsCall {
    void m() {
        C c = new C();
        c.m(null);
    }
}
