

import java.lang.annotation.*;
import java.io.*;
import java.net.URL;
import java.util.List;

import com.sun.tools.classfile.*;



public class DeadCode extends ClassfileTestHelper {
    public static void main(String[] args) throws Exception {
        new DeadCode().run();
    }

    public void run() throws Exception {
        expected_tinvisibles = 1;
        expected_tvisibles = 0;

        ClassFile cf = getClassFile("DeadCode$Test.class");
        test(cf);
        for (Field f : cf.fields) {
            test(cf, f);
        }
        for (Method m: cf.methods) {
            test(cf, m, true);
        }

        countAnnotations();

        if (errors > 0)
            throw new Exception(errors + " errors found");
        System.out.println("PASSED");
    }

    
    static class Test {
        @Target({ElementType.TYPE_USE, ElementType.TYPE_PARAMETER})
        @interface A {}

        void test() {
            List<? extends @A Object> o = null;
            o.toString();

            @A String m;
            if (false) {
                @A String a;
                @A String b = "m";
                b.toString();
                List<? extends @A Object> c = null;
                c.toString();
            }
        }
    }

}
