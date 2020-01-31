



public class InnerClassLiterals {

    
    public static void main(String[] args) {
        Class x1 = int.class;
        Class x2 = float.class;
        Class x3 = void.class;
        Class x4 = String.class;
        Class x5 = Integer.class;
        Class x6 = InnerClassLiterals.class;
        
        Class x7 = InnerClassLiterals.Inner1.class;
        Class x8 = InnerClassLiterals.Inner2.class;
    }

    class Inner1 {}

    static class Inner2 {}
}
