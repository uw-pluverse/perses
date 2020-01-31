




public class SuperNew {
    class Inner1 {
    }
    class Inner2 {
        Inner2(Inner1 ignore) {}
        Inner2() {
            this(new Inner1()); 
        }
        Inner2(String s) {
            this(SuperNew.this.new Inner1()); 
        }
        Inner2(char junk) {
            this(newInner1()); 
        }
        Inner2(byte junk) {
            this(SuperNew.this.newInner1()); 
        }
    }
    Inner1 newInner1() { return new Inner1(); }
}
