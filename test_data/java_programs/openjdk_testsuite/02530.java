

import java.lang.annotation.*;
import java.io.*;
import java.net.URL;
import java.util.List;

import com.sun.tools.classfile.*;



public class NewTypeArguments extends ClassfileTestHelper{
    public static void main(String[] args) throws Exception {
        new NewTypeArguments().run();
    }

    public void run() throws Exception {
        expected_tinvisibles = 3;
        expected_tvisibles = 0;

        ClassFile cf = getClassFile("NewTypeArguments$Test.class");
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
        <E> Test(E e) {}

        void test() {
            new <@A String> Test(null);
            new <@A List<@A String>> Test(null);
        }
    }
}
