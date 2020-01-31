



import java.util.Comparator;

class LambdaConv11<T> {

    interface SAM<X> extends Comparator<X> {
        public int compare(X left, X right);
    }

    SAM<T> y = (l, r) -> 0;
}
