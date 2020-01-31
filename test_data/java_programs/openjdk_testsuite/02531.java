



import java.lang.annotation.*;
import static java.lang.annotation.RetentionPolicy.*;
import static java.lang.annotation.ElementType.*;
import com.sun.tools.classfile.*;


public class T8010015 extends ClassfileTestHelper{
    public static void main(String[] args) throws Exception {
        new T8010015().run();
    }

    public void run() throws Exception {
        expected_tvisibles = 1;
        expected_visibles = 1;
        ClassFile cf = getClassFile("T8010015$Test$1innerClass.class");
        for (Field f : cf.fields) {
            test(cf, f);
        }
        countAnnotations();

        if (errors > 0)
            throw new Exception(errors + " errors found");
        System.out.println("PASSED");
    }

    
    interface MapFun<T, R> { R m( T n); }
    static class Test {
        MapFun<Class<?>,String> cs;
        void test() {
            cs = c -> {
                     class innerClass {
                         @A Class<?> icc = null;
                         innerClass(Class<?> _c) { icc = _c; }
                         String getString() { return icc.toString(); }
                     }
                     return new innerClass(c).getString();
            };
            System.out.println("cs.m : " + cs.m(Integer.class));
        }

    public static void main(String... args) {new Test().test(); }
    }
    @Retention(RUNTIME) @Target({TYPE_USE,FIELD}) @interface A { }
}
