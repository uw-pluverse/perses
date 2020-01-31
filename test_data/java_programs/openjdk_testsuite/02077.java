

class T6231847 {
    interface T6231847I {}
    static class T6231847C {}

    T6231847 t;
    Object o = new <Object> T6231847I() {};
    Object p = new T6231847I(o) {};
    Object q = t.new T6231847I() {};
    Object r = t.new <Object> T6231847I(o) {};
    Object s = t.new T6231847C() {};
}
