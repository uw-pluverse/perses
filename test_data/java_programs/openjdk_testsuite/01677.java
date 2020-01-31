



import java.io.*;
import java.util.*;
import javax.tools.*;
import com.sun.tools.classfile.*;
import com.sun.tools.classfile.ConstantPool.CONSTANT_Methodref_info;

public class NoStringToLower {
    public static void main(String... args) throws Exception {
        NoStringToLower c = new NoStringToLower();
        if (c.run(args))
            return;

        if (is_jtreg())
            throw new Exception(c.errors + " errors occurred");
        else
            System.exit(1);
    }

    static boolean is_jtreg() {
        return (System.getProperty("test.src") != null);
    }

    
    boolean run(String... args) throws Exception {
        JavaCompiler c = ToolProvider.getSystemJavaCompiler();
        JavaFileManager fm = c.getStandardFileManager(null, null, null);
        JavaFileManager.Location javacLoc = findJavacLocation(fm);
        String[] pkgs = {
            "javax.annotation.processing",
            "javax.lang.model",
            "javax.tools",
            "com.sun.source",
            "com.sun.tools.classfile",
            "com.sun.tools.doclet",
            "com.sun.tools.doclint",
            "com.sun.tools.javac",
            "com.sun.tools.javadoc",
            "com.sun.tools.javah",
            "com.sun.tools.javap",
            "com.sun.tools.jdeps",
            "com.sun.tools.sjavac"
        };
        for (String pkg: pkgs) {
            for (JavaFileObject fo: fm.list(javacLoc,
                    pkg, EnumSet.of(JavaFileObject.Kind.CLASS), true)) {
                scan(fo);
            }
        }

        return (errors == 0);
    }

    
    JavaFileManager.Location findJavacLocation(JavaFileManager fm) {
        JavaFileManager.Location[] locns =
            { StandardLocation.PLATFORM_CLASS_PATH, StandardLocation.CLASS_PATH };
        try {
            for (JavaFileManager.Location l: locns) {
                JavaFileObject fo = fm.getJavaFileForInput(l,
                    "com.sun.tools.javac.Main", JavaFileObject.Kind.CLASS);
                if (fo != null)
                    return l;
            }
        } catch (IOException e) {
            throw new Error(e);
        }
        throw new IllegalStateException("Cannot find javac");
    }

    
    void scan(JavaFileObject fo) throws IOException {
        InputStream in = fo.openInputStream();
        try {
            ClassFile cf = ClassFile.read(in);
            for (ConstantPool.CPInfo cpinfo: cf.constant_pool.entries()) {
                if (cpinfo.getTag() == ConstantPool.CONSTANT_Methodref) {
                    CONSTANT_Methodref_info ref = (CONSTANT_Methodref_info) cpinfo;
                    String methodDesc = ref.getClassInfo().getName() + "." + ref.getNameAndTypeInfo().getName() + ":" + ref.getNameAndTypeInfo().getType();

                    if ("java/lang/String.toLowerCase:()Ljava/lang/String;".equals(methodDesc)) {
                        error("found reference to String.toLowerCase() in: " + fo.getName());
                    }
                    if ("java/lang/String.toUpperCase:()Ljava/lang/String;".equals(methodDesc)) {
                        error("found reference to String.toLowerCase() in: " + fo.getName());
                    }
                }
            }
        } catch (ConstantPoolException ignore) {
        } finally {
            in.close();
        }
    }

    
    void error(String msg) {
        System.err.println("Error: " + msg);
        errors++;
    }

    int errors;
}
