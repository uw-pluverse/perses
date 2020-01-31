



class A<T1> {
    T1 obj1;
    Object obj2;
    <T2> A(T1 t1, T2 t2) {
        obj1 = t1;
        obj2 = t2;
    }
    public String toString() {
        return (obj1 + " " + obj2).intern();
    }
}

public class GenericAnonCtor {
    public static void main(String[] args) {
        A<Integer> a = new <String>A<Integer>(new Integer(11), "foo") {};
        if (a.toString() != "11 foo") throw new Error();
    }
}
