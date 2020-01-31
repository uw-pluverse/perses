



interface Attribute<T> { }

interface AttributeSet2 {
    <T> Attribute<?> get(Class<T> category);
}

class AttributeSet2Impl implements AttributeSet2 {
    public Attribute get(Class category) { return null; }
}

interface AttributeSet3 {
    Attribute<?> get(Class<?> category);
}

class AttributeSet3Impl implements AttributeSet3 {
    public Attribute get(Class category) { return null; }
}

interface AttributeSet4 {
    Attribute<?> get(Number category);
}

class AttributeSet4Impl implements AttributeSet4 {
    public Attribute get(Number category) { return null; }
}

interface AttributeSet5 {
    Attribute<?> get(Attribute<Number> category);
}

class AttributeSet5Impl implements AttributeSet5 {
    public Attribute get(Attribute category) { return null; }
}

interface I1<T> {
    void f(Attribute<T> l);
}

class C1 implements I1<String> {
    public void f(Attribute l) { }
    void test() {
        Attribute<Number> n = null;
        f(n);
    }
}

interface A2 {
    void f(Attribute<String> a);
}

class B2 {
    public void f(Attribute a) { }
}

class C2 extends B2 implements A2 {
    void test(Attribute<Number> a) {
        f(a);
    }
}
