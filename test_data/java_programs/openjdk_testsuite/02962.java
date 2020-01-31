



import java.util.function.Function;
import java.util.stream.Stream;

public class MethodRefNewInnerInLambdaVerify1 {
    public static void main(String[] args) {
        if (new MethodRefNewInnerInLambdaVerify1().map().apply(1).getClass() != TT.class)
            throw new AssertionError("sanity failed");
    }

    Function<Integer,TT> map() {
        return (i) -> Stream.of(i).map(TT::new).findFirst().get();
    }

    class TT {
        public TT(int i) {

        }
    }
}
