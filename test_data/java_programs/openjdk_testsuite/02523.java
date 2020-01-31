

import java.io.*;
import java.lang.annotation.Retention;
import java.lang.annotation.RetentionPolicy;
import java.net.URL;
import java.util.List;

import com.sun.tools.classfile.*;


public class NoTargetAnnotations {

    public static void main(String[] args) throws Exception {
        new NoTargetAnnotations().run();
    }

    public void run() throws Exception {
        ClassFile cf = getClassFile("NoTargetAnnotations$Test.class");
        for (Field f : cf.fields) {
            test(cf, f);
            testDeclaration(cf, f);
        }
        for (Method m: cf.methods) {
            test(cf, m);
            testDeclaration(cf, m);
        }

        countAnnotations();

        if (errors > 0)
            throw new Exception(errors + " errors found");
        System.out.println("PASSED");
    }

    ClassFile getClassFile(String name) throws IOException, ConstantPoolException {
        URL url = getClass().getResource(name);
        InputStream in = url.openStream();
        try {
            return ClassFile.read(in);
        } finally {
            in.close();
        }
    }

    
    void test(ClassFile cf, Method m) {
        test(cf, m, Attribute.RuntimeVisibleTypeAnnotations, true);
        test(cf, m, Attribute.RuntimeInvisibleTypeAnnotations, false);
    }

    void test(ClassFile cf, Field m) {
        test(cf, m, Attribute.RuntimeVisibleTypeAnnotations, true);
        test(cf, m, Attribute.RuntimeInvisibleTypeAnnotations, false);
    }

    void testDeclaration(ClassFile cf, Method m) {
        testDecl(cf, m, Attribute.RuntimeVisibleAnnotations, true);
        testDecl(cf, m, Attribute.RuntimeInvisibleAnnotations, false);
    }

    void testDeclaration(ClassFile cf, Field m) {
        testDecl(cf, m, Attribute.RuntimeVisibleAnnotations, true);
        testDecl(cf, m, Attribute.RuntimeInvisibleAnnotations, false);
    }

    
    
    void test(ClassFile cf, Method m, String name, boolean visible) {
        int index = m.attributes.getIndex(cf.constant_pool, name);
        if (index != -1) {
            Attribute attr = m.attributes.get(index);
            assert attr instanceof RuntimeTypeAnnotations_attribute;
            RuntimeTypeAnnotations_attribute tAttr = (RuntimeTypeAnnotations_attribute)attr;
            all += tAttr.annotations.length;
            if (visible)
                visibles += tAttr.annotations.length;
            else
                invisibles += tAttr.annotations.length;
        }
    }

    
    
    void test(ClassFile cf, Field m, String name, boolean visible) {
        int index = m.attributes.getIndex(cf.constant_pool, name);
        if (index != -1) {
            Attribute attr = m.attributes.get(index);
            assert attr instanceof RuntimeTypeAnnotations_attribute;
            RuntimeTypeAnnotations_attribute tAttr = (RuntimeTypeAnnotations_attribute)attr;
            all += tAttr.annotations.length;
            if (visible)
                visibles += tAttr.annotations.length;
            else
                invisibles += tAttr.annotations.length;
        }
    }

    
    
    void testDecl(ClassFile cf, Method m, String name, boolean visible) {
        int index = m.attributes.getIndex(cf.constant_pool, name);
        if (index != -1) {
            Attribute attr = m.attributes.get(index);
            assert attr instanceof RuntimeAnnotations_attribute;
            RuntimeAnnotations_attribute tAttr = (RuntimeAnnotations_attribute)attr;
            this.declAnnotations += tAttr.annotations.length;
        }
    }

    
    
    void testDecl(ClassFile cf, Field m, String name, boolean visible) {
        int index = m.attributes.getIndex(cf.constant_pool, name);
        if (index != -1) {
            Attribute attr = m.attributes.get(index);
            assert attr instanceof RuntimeAnnotations_attribute;
            RuntimeAnnotations_attribute tAttr = (RuntimeAnnotations_attribute)attr;
            this.declAnnotations += tAttr.annotations.length;
        }
    }

    File compileTestFile(File f) {
        int rc = com.sun.tools.javac.Main.compile(new String[] { "-XDTA:writer", "-source", "1.8", "-g", f.getPath() });
        if (rc != 0)
            throw new Error("compilation failed. rc=" + rc);
        String path = f.getPath();
        return new File(path.substring(0, path.length() - 5) + ".class");
    }

    void countAnnotations() {
        int expected_all = expected_visibles + expected_invisibles;

        if (expected_all != all) {
            errors++;
            System.err.println("expected " + expected_all
                    + " annotations but found " + all);
        }

        if (expected_visibles != visibles) {
            errors++;
            System.err.println("expected " + expected_visibles
                    + " visibles annotations but found " + visibles);
        }

        if (expected_invisibles != invisibles) {
            errors++;
            System.err.println("expected " + expected_invisibles
                    + " invisibles annotations but found " + invisibles);
        }

        if (expected_decl != declAnnotations) {
            errors++;
            System.err.println("expected " + expected_decl
                    + " declaration annotations but found " + declAnnotations);
        }
    }

    int errors;
    int all;
    int visibles;
    int invisibles;

    int declAnnotations;

    
    static int expected_invisibles = 0;
    static int expected_visibles = 0;
    static int expected_decl = 1;

    static class Test {
        @Retention(RetentionPolicy.RUNTIME)
        @interface A {}

        @A String method() {
            return null;
        }
    }
}
