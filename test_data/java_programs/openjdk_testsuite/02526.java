

import java.lang.annotation.*;
import java.io.*;
import java.net.URL;
import java.util.List;

import com.sun.tools.classfile.*;


public class Wildcards extends ClassfileTestHelper {
    public static void main(String[] args) throws Exception {
        new Wildcards().run();
    }

    public void run() throws Exception {
        expected_tinvisibles = 3;
        expected_tvisibles = 0;

        ClassFile cf = getClassFile("Wildcards$Test.class");
        test(cf);
        for (Field f : cf.fields) {
            test(cf, f);
        }
        for (Method m: cf.methods) {
            test(cf, m,false);
        }

        countAnnotations();

        if (errors > 0)
            throw new Exception(errors + " errors found");
        System.out.println("PASSED");
    }

    
    static class Test {
        @Target({ElementType.TYPE_USE, ElementType.TYPE_PARAMETER})
        @interface A {}

        List<? extends @A Number> f;

        List<? extends @A Object> test(List<? extends @A Number> p) {
            List<? extends @A Object> l;  
            return null;
        }
    }
}
