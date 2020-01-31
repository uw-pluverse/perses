



interface Attribute<T> { }

interface AttributeSet1 {
    <T> Attribute<T> get(Class<T> category);
}

class AttributeSet1Impl implements AttributeSet1 {
    public Attribute get(Class category) { return null; }
}
