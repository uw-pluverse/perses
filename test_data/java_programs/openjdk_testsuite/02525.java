

import java.lang.annotation.*;
import java.io.*;
import java.net.URL;
import java.util.List;

import com.sun.tools.classfile.*;



public class TypeCasts extends ClassfileTestHelper{
    public static void main(String[] args) throws Exception {
        new TypeCasts().run();
    }

    public void run() throws Exception {
        expected_tinvisibles = 4;
        expected_tvisibles = 0;

        ClassFile cf = getClassFile("TypeCasts$Test.class");
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

        void emit() {
            Object o = null;
            String s = null;

            String a0 = (@A String)o;
            Object a1 = (@A Object)o;

            String b0 = (@A String)s;
            Object b1 = (@A Object)s;
        }

        void alldeadcode() {
            Object o = null;

            if (false) {
                String a0 = (@A String)o;
            }
        }
    }
}
