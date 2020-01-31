



import java.util.function.Function;

public class MethodReferenceIntersection2 {

    interface B { }

    interface A { }

    static class C implements A, B { }

    static class Info {
        <H extends A & B> Info(H h) { }

        static <H extends A & B> Info info(H h) {
            return new Info(h);
        }
    }

    public static void main(String[] args) {
        test();
    }

    
    static <H extends B & A> void test() {
        Function<H, Info> f1L = _h -> new Info(_h);
        Function<H, Info> f1 = Info::new;
        Function<H, Info> f2L = _h -> Info.info(_h);
        Function<H, Info> f2 = Info::info;
        H c = (H) new C();
        if(f1.apply(c) instanceof Info &&
           f2.apply(c) instanceof Info) {
           System.out.println("Passes.");
        } else {
           throw new AssertionError();
        }
    }
}
