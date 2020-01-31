

import java.lang.annotation.*;
import static java.lang.annotation.RetentionPolicy.*;
import static java.lang.annotation.ElementType.*;
import com.sun.tools.classfile.*;

public class T8008769 extends ClassfileTestHelper{
    public static void main(String[] args) throws Exception {
        new T8008769().run();
    }

    public void run() throws Exception {
        expected_tvisibles = 4;
        ClassFile cf = getClassFile("T8008769$Test.class");
        for (Method m : cf.methods) {
            test(cf, m, true);
        }
        countAnnotations();

        if (errors > 0)
            throw new Exception(errors + " errors found");
        System.out.println("PASSED");
    }

    
    static class Test<T> {
        public void test() {
            Test<@A @B String>    t0 = new Test<>(); 
            Test<@B @B String>    t1 = new Test<>(); 
            Test<@A @A @A String> t2 = new Test<>(); 
       }
    }
    @Retention(RUNTIME) @Target(TYPE_USE) @Repeatable( AC.class ) @interface A { }
    @Retention(RUNTIME) @Target(TYPE_USE) @Repeatable( BC.class ) @interface B { }
    @Retention(RUNTIME) @Target(TYPE_USE) @interface AC { A[] value(); }
    @Retention(RUNTIME) @Target(TYPE_USE) @interface BC { B[] value(); }
}
