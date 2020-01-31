



public class LambdaParenGeneric {

    @FunctionalInterface
    public interface FI {
        Integer apply();
    }

    public static class Val<A> {
        A value;
        Val(A v) { value = v; }
    }

    public static void main(String[] args) {
        FI inc = () -> (new Val<Integer>(77).value);
        System.out.println(inc.apply());
    }
}
