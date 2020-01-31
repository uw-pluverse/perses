



import com.sun.tools.classfile.*;
import com.sun.tools.javac.api.JavacTaskImpl;
import com.sun.tools.javac.code.Symbol;
import com.sun.tools.javac.jvm.ClassReader.BadClassFile;
import com.sun.tools.javac.jvm.Target;
import com.sun.tools.javac.util.Assert;
import com.sun.tools.javac.util.JCDiagnostic;
import java.io.File;
import java.util.Arrays;
import java.util.Objects;
import javax.tools.JavaCompiler;
import javax.tools.ToolProvider;

public class BadClassfile {
    public static void main(String... args) throws Exception {
        test("BadClassfile$DefaultMethodTest", "compiler.misc.invalid.default.interface");
        test("BadClassfile$StaticMethodTest", "compiler.misc.invalid.static.interface");
    }

    private static void test(String classname, String expected) throws Exception {
        File classfile = new File(System.getProperty("test.classes", "."), classname + ".class");
        ClassFile cf = ClassFile.read(classfile);

        cf = new ClassFile(cf.magic, Target.JDK1_7.minorVersion,
                 Target.JDK1_7.majorVersion, cf.constant_pool, cf.access_flags,
                cf.this_class, cf.super_class, cf.interfaces, cf.fields,
                cf.methods, cf.attributes);

        new ClassWriter().write(cf, classfile);

        JavaCompiler c = ToolProvider.getSystemJavaCompiler();
        JavacTaskImpl task = (JavacTaskImpl) c.getTask(null, null, null, Arrays.asList("-classpath", System.getProperty("test.classes", ".")), null, null);

        try {
            Symbol clazz = com.sun.tools.javac.main.JavaCompiler.instance(task.getContext()).resolveIdent(classname);

            clazz.complete();
        } catch (BadClassFile f) {
            JCDiagnostic embeddedDiag = (JCDiagnostic) f.diag.getArgs()[1];
            assertEquals(expected, embeddedDiag.getCode());
            assertEquals(Integer.toString(Target.JDK1_7.majorVersion), embeddedDiag.getArgs()[0]);
            assertEquals(Integer.toString(Target.JDK1_7.minorVersion), embeddedDiag.getArgs()[1]);
        }
    }

    private static void assertEquals(Object expected, Object actual) {
        Assert.check(Objects.equals(expected, actual),
                     "expected: " + expected + ", but was: " + actual);
    }

    interface DefaultMethodTest {
        default void test() { }
    }
    interface StaticMethodTest {
        static void test() { }
    }
}
