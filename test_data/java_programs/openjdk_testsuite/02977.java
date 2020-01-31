
import java.util.List;

class T8016177a {

    interface ToIntFunction<X> {
        int m(X x);
    }

    interface Function<X, Y> {
        Y m(X x);
    }

    <T,R> void m1(List<T> s, Function<T,R> f) { }
    <T,R> void m1(List<T> s, ToIntFunction<T> f) { }

    <T,R> List<R> m2(List<T> s, Function<T,R> f) { return null; }
    <T,R> List<R> m2(List<T> s, ToIntFunction<T> f) { return null; }

    <T,R> List<T> m3(List<T> s, Function<T,R> f) { return null; }
    <T,R> List<R> m3(List<T> s, ToIntFunction<T> f) { return null; }

    <T,R> List<T> m4(List<T> s, Function<T,R> f) { return null; }
    <T,R> List<T> m4(List<T> s, ToIntFunction<T> f) { return null; }

    <T,R> List<R> m5(List<T> s, Function<T,R> f) { return null; }
    <T,R> List<T> m5(List<T> s, ToIntFunction<T> f) { return null; }

    <T extends R,R> List<R> m6(List<T> s, Function<T,R> f) { return null; }
    <T extends R,R> List<T> m6(List<T> s, ToIntFunction<T> f) { return null; }

    void test(List<String> ss) {
         m1(ss, s->s.length()); 
         m2(ss, s->s.length()); 
         m3(ss, s->s.length()); 
         m4(ss, s->s.length()); 
         m5(ss, s->s.length()); 
         m6(ss, s->s.length()); 
    }
}
