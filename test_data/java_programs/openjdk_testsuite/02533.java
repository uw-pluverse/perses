

import java.lang.annotation.*;
import java.io.*;
import java.net.URL;
import java.util.List;

import com.sun.tools.classfile.*;

public class ClassfileTestHelper {
    int expected_tinvisibles = 0;
    int expected_tvisibles = 0;
    int expected_invisibles = 0;
    int expected_visibles = 0;

    
    public Boolean verbose = true;
    void println(String msg) { if (verbose) System.out.println(msg); }
    void print(String msg) { if (verbose) System.out.print(msg); }

    File writeTestFile(String fname, String source) throws IOException {
      File f = new File(fname);
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(f)));
        out.println(source);
        out.close();
        return f;
    }

    File compile(File f) {
        int rc = com.sun.tools.javac.Main.compile(new String[] {
                "-source", "1.8", "-g", f.getPath() });
        if (rc != 0)
            throw new Error("compilation failed. rc=" + rc);
        String path = f.getPath();
        return new File(path.substring(0, path.length() - 5) + ".class");
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

    ClassFile getClassFile(URL url) throws IOException, ConstantPoolException {
        InputStream in = url.openStream();
        try {
            return ClassFile.read(in);
        } finally {
            in.close();
        }
    }

    
    void test(ClassFile cf) {
        test("CLASS",cf, null, null, Attribute.RuntimeVisibleTypeAnnotations, true);
        test("CLASS",cf, null, null, Attribute.RuntimeInvisibleTypeAnnotations, false);
        
        test("CLASS",cf, null, null, Attribute.RuntimeVisibleAnnotations, true);
        test("CLASS",cf, null, null, Attribute.RuntimeInvisibleAnnotations, false);
    }

    void test(ClassFile cf, Field f, Boolean local) {
        if (!local) {
            test("FIELD",cf, f, null, Attribute.RuntimeVisibleTypeAnnotations, true);
            test("FIELD",cf, f, null, Attribute.RuntimeInvisibleTypeAnnotations, false);
            test("FIELD",cf, f, null, Attribute.RuntimeVisibleAnnotations, true);
            test("FIELD",cf, f, null, Attribute.RuntimeInvisibleAnnotations, false);
        } else {
            test("CODE",cf, f, null, Attribute.RuntimeVisibleTypeAnnotations, true);
            test("CODE",cf, f, null, Attribute.RuntimeInvisibleTypeAnnotations, false);
            test("CODE",cf, f, null, Attribute.RuntimeVisibleAnnotations, true);
            test("CODE",cf, f, null, Attribute.RuntimeInvisibleAnnotations, false);
        }
    }

    void test(ClassFile cf, Field f) {
        test(cf, f, false);
    }

    
    void test(ClassFile cf, Method m, Boolean local) {
        if (!local) {
            test("METHOD",cf, null, m, Attribute.RuntimeVisibleTypeAnnotations, true);
            test("METHOD",cf, null, m, Attribute.RuntimeInvisibleTypeAnnotations, false);
            test("METHOD",cf, null, m, Attribute.RuntimeVisibleAnnotations, true);
            test("METHOD",cf, null, m, Attribute.RuntimeInvisibleAnnotations, false);
        } else  {
            test("MCODE",cf, null, m, Attribute.RuntimeVisibleTypeAnnotations, true);
            test("MCODE",cf, null, m, Attribute.RuntimeInvisibleTypeAnnotations, false);
            test("MCODE",cf, null, m, Attribute.RuntimeVisibleAnnotations, true);
            test("MCODE",cf, null, m, Attribute.RuntimeInvisibleAnnotations, false);
        }
    }

    
    void test(ClassFile cf, Method m ) {
        test(cf, m, false);
    }

    
    
    void test(String ttype, ClassFile cf, Field f, Method m, String annName, boolean visible) {
        String testtype = ttype;
        String name = null;
        int index = -1;
        Attribute attr = null;
        Code_attribute cAttr = null;
        boolean isTAattr = annName.contains("TypeAnnotations");
        try {
            switch(testtype) {
                case "FIELD":
                    name = f.getName(cf.constant_pool);
                    index = f.attributes.getIndex(cf.constant_pool, annName);
                    if(index!= -1)
                        attr = f.attributes.get(index);
                    break;
                case "CODE":
                    name = f.getName(cf.constant_pool);
                    
                    index = cf.attributes.getIndex(cf.constant_pool, Attribute.Code);
                    if(index!= -1) {
                        attr = cf.attributes.get(index);
                        assert attr instanceof Code_attribute;
                        cAttr = (Code_attribute)attr;
                        index = cAttr.attributes.getIndex(cf.constant_pool, annName);
                        if(index!= -1)
                            attr = cAttr.attributes.get(index);
                    }
                    break;
                case "METHOD":
                    name = m.getName(cf.constant_pool);
                    index = m.attributes.getIndex(cf.constant_pool, annName);
                    if(index!= -1)
                        attr = m.attributes.get(index);
                    break;
                case "MCODE":
                    name = m.getName(cf.constant_pool);
                    
                    index = m.attributes.getIndex(cf.constant_pool, Attribute.Code);
                    if(index!= -1) {
                        attr = m.attributes.get(index);
                        assert attr instanceof Code_attribute;
                        cAttr = (Code_attribute)attr;
                        index = cAttr.attributes.getIndex(cf.constant_pool, annName);
                        if(index!= -1)
                            attr = cAttr.attributes.get(index);
                    }
                    break;
                default:
                    name = cf.getName();
                    index = cf.attributes.getIndex(cf.constant_pool, annName);
                    if(index!= -1) attr = cf.attributes.get(index);
            }
        } catch(ConstantPoolException cpe) { cpe.printStackTrace(); }

        if (index != -1) {
            if(isTAattr) { 
                RuntimeTypeAnnotations_attribute tAttr =
                        (RuntimeTypeAnnotations_attribute)attr;
                println(testtype + ": " + name + ", " + annName + ": " +
                        tAttr.annotations.length );
                if (tAttr.annotations.length > 0) {
                    for (int i = 0; i < tAttr.annotations.length; i++) {
                        println("  types:" + tAttr.annotations[i].position.type);
                    }
                } else {
                    println("");
                }
                allt += tAttr.annotations.length;
                if (visible)
                    tvisibles += tAttr.annotations.length;
                else
                    tinvisibles += tAttr.annotations.length;
            } else {
                RuntimeAnnotations_attribute tAttr =
                        (RuntimeAnnotations_attribute)attr;
                println(testtype + ": " + name + ", " + annName + ": " +
                        tAttr.annotations.length );
                all += tAttr.annotations.length;
                if (visible)
                    visibles += tAttr.annotations.length;
                else
                    invisibles += tAttr.annotations.length;
            }
        }
    }

    void countAnnotations() {
        errors=0;
        int expected_allt = expected_tvisibles + expected_tinvisibles;
        int expected_all = expected_visibles + expected_invisibles;

        if (expected_allt != allt) {
            errors++;
            System.err.println("Failure: expected " + expected_allt +
                    " type annotations but found " + allt);
        }
        if (expected_all != all) {
            errors++;
            System.err.println("Failure: expected " + expected_all +
                    " annotations but found " + all);
        }
        if (expected_tvisibles != tvisibles) {
            errors++;
            System.err.println("Failure: expected " + expected_tvisibles +
                    " typevisible annotations but found " + tvisibles);
        }

        if (expected_tinvisibles != tinvisibles) {
            errors++;
            System.err.println("Failure: expected " + expected_tinvisibles +
                    " typeinvisible annotations but found " + tinvisibles);
        }
        allt=0;
        tvisibles=0;
        tinvisibles=0;
        all=0;
        visibles=0;
        invisibles=0;
    }

    int errors;
    int allt;
    int tvisibles;
    int tinvisibles;
    int all;
    int visibles;
    int invisibles;
}
