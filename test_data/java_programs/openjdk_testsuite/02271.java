

interface LibInterface {
    @Deprecated
        void m();
}

class LibClass {
    public void m() { }
}

class Test3 extends LibClass implements LibInterface {
}
