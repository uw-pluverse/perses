

class T6521805 {

    static class Inner extends T6521805.Outer {

        Inner(T6521805 t) {
            t.super();
        }

        T6521805 this$0 = null;

        public void foo() {
            this$0 = new T6521805();
        }
    }

    class Outer {}

}
