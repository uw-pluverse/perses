

import java.util.List;

public class EagerReturnTypeResolutionTestb {
    interface I<S> {}
    interface J<S> extends I<S> {}
    interface K extends I<String> {}
    interface L<S> extends I {}

    <T> T lower(List<? extends T> l) { return null; }
    <T> T lower2(List<? extends T> l1, List<? extends T> l2) { return null; }

    <T> T upper(List<? super T> l) { return null; }
    <T> T upper2(List<? super T> l1, List<? super T> l2) { return null; }

    <T> T eq(List<T> l) { return null; }
    <T> T eq2(List<T> l1, List<T> l2) { return null; }

    <X> void takeI(I<X> i) {}
    void takeIString(I<String> i) {}
    I<String> iStringField;

    void takeLong(long arg) {}
    long longField;

    void testSimpleCaptureOK(List<I<?>> i1) {
        takeI(lower(i1)); 
        takeI(eq(i1)); 
        takeI(upper(i1)); 
        takeIString(upper(i1)); 
        iStringField = upper(i1); 
    }

    void testSimpleCaptureKO(List<I<?>> i1) {
        takeIString(lower(i1)); 
        takeIString(eq(i1)); 
        iStringField = lower(i1); 
        iStringField = eq(i1); 
    }

    void testMultiCaptureOK(List<I<String>> i1, List<I<Integer>> i2, List<I<?>> i3,
                          List<J<String>> j1, List<J<Integer>> j2, List<K> k1) {
        
        takeI(lower2(i1, i2)); 
        takeI(lower2(i1, i3)); 
        takeI(upper2(i1, i3)); 

        takeIString(upper2(i1, i3)); 
        iStringField = upper2(i1, i3); 

        takeI(lower2(j1, j2)); 
        takeI(lower2(j1, k1)); 
        takeI(upper2(j1, k1)); 

        takeIString(lower2(j1, k1)); 
        takeIString(upper2(j1, k1)); 

        iStringField = lower2(j1, k1); 
        iStringField = upper2(j1, k1); 
        takeI(lower2(j2, k1)); 
    }

    void testMultiCaptureKO(List<I<String>> i1, List<I<Integer>> i2, List<I<?>> i3,
                          List<J<String>> j1, List<J<Integer>> j2, List<K> k1) {
        takeI(eq2(i1, i2)); 
        takeI(upper2(i1, i2)); 

        takeIString(lower2(i1, i2)); 
        takeIString(eq2(i1, i2)); 
        takeIString(upper2(i1, i2)); 

        iStringField = lower2(i1, i2); 
        iStringField = eq2(i1, i2); 
        iStringField = upper2(i1, i2); 

        takeI(eq2(i1, i3)); 
        takeIString(lower2(i1, i3)); 
        takeIString(eq2(i1, i3)); 

        iStringField = lower2(i1, i3); 
        iStringField = eq2(i1, i3); 
        takeI(eq2(j1, j2)); 
        takeI(upper2(j1, j2)); 

        takeIString(lower2(j1, j2)); 
        takeIString(eq2(j1, j2)); 
        takeIString(upper2(j1, j2)); 

        iStringField = lower2(j1, j2); 
        iStringField = eq2(j1, j2); 
        iStringField = upper2(j1, j2); 

        takeI(eq2(j1, k1)); 
        takeIString(eq2(j1, k1)); 
        iStringField = eq2(j1, k1); 
        takeI(eq2(j2, k1)); 
        takeI(upper2(j2, k1)); 

        takeIString(lower2(j2, k1)); 
        takeIString(eq2(j2, k1)); 
        takeIString(upper2(j2, k1)); 

        iStringField = lower2(j2, k1); 
        iStringField = eq2(j2, k1); 
        iStringField = upper2(j2, k1); 
    }

    void testRawOK(List<I> i1, List<J> j1, List<L<String>> l1) {
        takeI(lower(i1)); 
        takeI(eq(i1)); 
        takeI(upper(i1)); 

        takeIString(lower(i1)); 
        takeIString(eq(i1)); 
        takeIString(upper(i1)); 

        iStringField = lower(i1); 
        iStringField = eq(i1); 
        iStringField = upper(i1); 

        takeI(lower(j1)); 
        takeI(eq(j1)); 
        takeI(upper(j1)); 

        takeIString(lower(j1)); 
        takeIString(eq(j1)); 
        takeIString(upper(j1)); 

        iStringField = lower(j1); 
        iStringField = eq(j1); 
        iStringField = upper(j1); 

        takeI(lower(l1)); 
        takeI(eq(l1)); 
        takeI(upper(l1)); 

        takeIString(lower(l1)); 
        takeIString(eq(l1)); 
        takeIString(upper(l1)); 

        iStringField = lower(l1); 
        iStringField = eq(l1); 
        iStringField = upper(l1); 
    }

    void testPrimOK(List<Integer> i1, List<Long> l1, List<Double> d1) {
        takeLong(lower(i1)); 
        takeLong(eq(i1)); 
        takeLong(upper(i1)); 

        longField = lower(i1); 
        longField = eq(i1); 
        longField = upper(i1); 

        takeLong(lower(l1)); 
        takeLong(eq(l1)); 
        takeLong(upper(l1)); 

        longField = lower(l1); 
        longField = eq(l1); 
        longField = upper(l1); 
    }

    void testPrimKO(List<Integer> i1, List<Long> l1, List<Double> d1) {
        takeLong(lower(d1)); 
        takeLong(eq(d1)); 
        takeLong(upper(d1)); 

        longField = lower(d1); 
        longField = eq(d1); 
        longField = upper(d1); 
    }
}
