



import java.util.Arrays;
import java.util.function.Function;
import java.util.function.Supplier;

public class MethodReferenceArrayClone {
    public static void main(String[] args) {
        int[] intArgs = new int[] {1, 2, 3, 4, 5};
        checkInt("int[]::clone", int[]::clone, intArgs);
        checkInt("a -> a.clone()", a -> a.clone(), intArgs);
        checkInt("intArgs::clone", intArgs::clone, intArgs);

        String[] stringArgs = new String[] {"hi", "de", "ho"};
        checkString("String[]::clone", String[]::clone, stringArgs);
        checkString("a -> a.clone()", a -> a.clone(), stringArgs);
        checkString("args::clone", stringArgs::clone, stringArgs);
    }

    private static void checkInt(String label, Supplier<int[]> s, int[] expected) {
        if (!Arrays.equals(s.get(), expected)) {
            throw new RuntimeException("Unexpected value " + label + ": " + Arrays.toString(s.get()));
        }
    }

    private static void checkInt(String label, Function<int[], int[]> f, int[] a) {
        checkInt(label, () -> f.apply(a), a);
    }

    private static void checkString(String label, Supplier<String[]> s, String[] expected) {
        if (!Arrays.equals(s.get(), expected)) {
            throw new RuntimeException("Unexpected value " + label + ": " + Arrays.toString(s.get()));
        }
    }

    private static void checkString(String label, Function<String[], String[]> f, String[] a) {
        checkString(label, () -> f.apply(a), a);
    }
}
