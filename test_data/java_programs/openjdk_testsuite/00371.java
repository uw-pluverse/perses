



class StreinBug {

    static class Box<T extends Number> {
        void f(Box<T> bt) { }
    }

    public void g() {
        Box<? super Number> b0 = null;
        Box<Number> b1 = b0;
        b0.f(b1); 
    }

}
