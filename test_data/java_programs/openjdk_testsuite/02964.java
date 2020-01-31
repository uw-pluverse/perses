



import java.util.function.Supplier;
import java.util.stream.Stream;

public class MethodRefNewInnerInLambdaNPE1 {
    public static void main(String[] args) {
        if (new MethodRefNewInnerInLambdaNPE1().getList().get().getClass() != TT.class)
            throw new AssertionError("sanity failed");
    }

    Supplier<TT> getList() {
        return () -> Stream.of(1).map(TT::new).findFirst().get();
    }

    class TT {
        public TT(int i) {

        }
    }
}
