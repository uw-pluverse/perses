



public class NewBeforeOuterConstructed2 {
    NewBeforeOuterConstructed2(Object o) {}
    class Middle extends NewBeforeOuterConstructed2 {
        Middle(int i) {
            super(null);
        }
        Middle() {
            
            
            
            
            super(new Middle(1));
        }
        class Inner {}
        void f() {
            System.out.println("ok");
        }
    }
    public static void main(String[] args) {
        NewBeforeOuterConstructed2 c = new NewBeforeOuterConstructed2(new Object());
        Middle m = c.new Middle();
        m.f();
    }
}
