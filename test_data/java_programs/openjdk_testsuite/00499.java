



interface MyComparable<T extends MyComparable<T>> {
    int compareTo(T other);
}
abstract class MyEnum<E extends MyEnum<E>> implements MyComparable<E> {
    public int compareTo(E other) {
        return 0;
    }
}
class MyColor extends MyEnum {
    void f() {}
}
