



public class LambdaConv08 {

    static int assertionCount = 0;

    static void assertTrue(boolean cond) {
        assertionCount++;
        if (!cond)
            throw new AssertionError();
    }

    public interface ObjectF { Object invoke(); }
    public interface StringF extends ObjectF { String invoke(); }

    public static void call(StringF stringFunc) {
        assertTrue(true);
    }

    public static void call(ObjectF objectFunc) {  }

    public static void main(String[] args)   {
        call(()-> "Hello");
        assertTrue(assertionCount == 1);
    }
}
