



class T7148556 {

    interface A extends Cloneable {
       public Object clone();
    }

    interface B extends A, java.util.List { }

    void test(B b) {
        b.clone();
    }
}
