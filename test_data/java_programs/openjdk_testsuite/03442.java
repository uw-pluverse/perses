



public class VerifyErrorWithDoubleAssignmentTest {

    static class A<D> {
        D d;

        D getD() {
            return null;
        }
    }

    static class B extends A<Integer> {
        Integer y;
        B() {
            y = d = getD();
        }
    }

    public static void main(String[] args) {
        new B();
    }
}
