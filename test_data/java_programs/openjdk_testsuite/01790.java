

class T6521805a {

    static class Outer {
        T6521805a this$0 = null;
    }

    public class Inner extends Outer {
        public void foo() {
            this$0 = new T6521805a();
        }
    }
}
