



public class T7003595b {
    public static void main(String... args) throws Exception {
        class A {}
        class B extends A {}
        B.class.getSuperclass().getDeclaringClass();
    }
}
