



public class LambdaParenGenericOrig {

    @FunctionalInterface
    public static interface Function1<R, A> {
        R apply(A input);
    }

    @FunctionalInterface
    public static interface Function2<R, A1, A2> {
        R apply(A1 input1, A2 input2);
    }

    public static void main(String[] args) {
        final Function2<Integer, Integer, Integer> add = (x, y) -> x + y;
        final Function1<Integer, Integer> inc = x -> (add.apply(x, 1));
        System.out.println(inc.apply(0));
    }
}
