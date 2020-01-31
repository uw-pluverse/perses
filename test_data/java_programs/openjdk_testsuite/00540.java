



public class FinalBridge extends MyEnum<FinalBridge> {
    public static void main(String[] args) {}
}
interface MyComparable<T extends MyComparable<T>> {
    int compareTo(T other);
}
class MyEnum<E extends MyEnum<E>> implements MyComparable<E> {
    public final int compareTo(E other) {
        return 0;
    }
}
