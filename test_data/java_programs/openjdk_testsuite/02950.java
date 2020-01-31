



public class MethodReferenceComplexNullCheckTest {
    public static void main(String[] args) {
        F fr = null;
        boolean npeFired = false;
        try {
            IForm frf = fr::doit;
        } catch (NullPointerException npe) {
            npeFired = true;
        } finally {
            if (!npeFired) throw new AssertionError( "NPE should have been thrown");
        }
    }

    interface IForm {
       void xyz(Object... args);
    }

    class F {
       private void doit(Object... args) { }
    }
}
