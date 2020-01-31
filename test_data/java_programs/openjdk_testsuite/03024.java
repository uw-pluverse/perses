



import java.util.function.*;

public class ExplicitVSImplicitLambdaTest {
    private void test()
    {
        
        MyComparator.mycomparing1((String e) -> e.concat(""));
        MyComparator.mycomparing2((String e) -> e.concat(""));
        MyComparator.mycomparing3((String e) -> e.concat(""));
        MyComparator.mycomparing4((String e) -> e.concat(""));

        
        MyComparator.mycomparing1((e) -> e.toString());
        MyComparator.mycomparing2((e) -> e.toString());
        MyComparator.mycomparing3((e) -> e.toString());
        MyComparator.mycomparing4((e) -> e.toString());
    }
}

interface MyComparator<T> {
    public static <T, U extends Comparable<? super U>> MyComparator<T> mycomparing1(
            Function<? super T, ? extends U> keyExtractor) {
        return null;
    }

    public static <T, U extends Comparable<? super U>> MyComparator<T> mycomparing2(
            Function<? super T, ? super U> keyExtractor) {
        return null;
    }

    public static <T, U extends Comparable<? super U>> MyComparator<T> mycomparing3(
            Function<? extends T, ? extends U> keyExtractor) {
        return null;
    }

    public static <T, U extends Comparable<? super U>> MyComparator<T> mycomparing4(
            Function<? extends T, ? super U> keyExtractor) {
        return null;
    }
}
