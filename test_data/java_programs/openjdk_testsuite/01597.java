



import java.lang.annotation.ElementType;
import java.lang.annotation.Target;
import java.io.BufferedInputStream;
import java.lang.annotation.Retention;
import java.lang.annotation.RetentionPolicy;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;

import com.sun.tools.classfile.AccessFlags;
import com.sun.tools.classfile.Attribute;
import com.sun.tools.classfile.Attributes;
import com.sun.tools.classfile.ClassFile;
import com.sun.tools.classfile.Method;
import com.sun.tools.javac.util.Assert;

public class AnnotationsAreNotCopiedToBridgeMethodsTest {

    public static void main(String[] args) throws Exception {
        new AnnotationsAreNotCopiedToBridgeMethodsTest().run();
    }

    void run() throws Exception {
        checkClassFile(Paths.get(System.getProperty("test.classes"),
                this.getClass().getSimpleName() + "$CovariantReturnType.class"));
        checkClassFile(Paths.get(System.getProperty("test.classes"),
                this.getClass().getSimpleName() +
                "$CovariantReturnType$VisibilityChange.class"));
    }

    void checkClassFile(final Path cfilePath) throws Exception {
        ClassFile classFile = ClassFile.read(
                new BufferedInputStream(Files.newInputStream(cfilePath)));
        for (Method method : classFile.methods) {
            if (method.access_flags.is(AccessFlags.ACC_BRIDGE)) {
                checkForAttr(method.attributes,
                        "Annotations hasn't been copied to bridge method",
                        Attribute.RuntimeVisibleAnnotations,
                        Attribute.RuntimeVisibleParameterAnnotations);
            }
        }
    }

    void checkForAttr(Attributes attrs, String errorMsg, String... attrNames) {
        for (String attrName : attrNames) {
            Assert.checkNonNull(attrs.get(attrName), errorMsg);
        }
    }

    @Target(value = {ElementType.PARAMETER})
    @Retention(RetentionPolicy.RUNTIME)
    @interface ParamAnnotation {}

    @Target(value = {ElementType.METHOD})
    @Retention(RetentionPolicy.RUNTIME)
    @interface MethodAnnotation {}

    abstract class T<A,B> {
        B m(A a){return null;}
    }

    class CovariantReturnType extends T<Integer, Integer> {
        @MethodAnnotation
        Integer m(@ParamAnnotation Integer i) {
            return i;
        }

        public class VisibilityChange extends CovariantReturnType {}

    }

}
