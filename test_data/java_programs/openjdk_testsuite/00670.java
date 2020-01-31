



public class BadSigTest<Outer> {
    void m(){
        class Local1{}
        class Local2 extends Local1{}
        Local2.class.getTypeParameters();
    }
    public static void main(String[] args) {
        new BadSigTest().m();
    }
}
