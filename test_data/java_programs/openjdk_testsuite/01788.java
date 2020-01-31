



import java.io.File;

import com.sun.tools.classfile.AccessFlags;
import com.sun.tools.classfile.Attribute;
import com.sun.tools.classfile.ClassFile;
import com.sun.tools.classfile.InnerClasses_attribute;
import com.sun.tools.classfile.InnerClasses_attribute.Info;
import com.sun.tools.javac.util.Assert;

public class InnerClassAttrMustNotHaveStrictFPFlagTest {

    public static void main(String[] args) throws Exception {
        new InnerClassAttrMustNotHaveStrictFPFlagTest().run();
    }

    private void run() throws Exception {
        File classPath = new File(System.getProperty("test.classes"), getClass().getSimpleName() + ".class");
        analyzeClassFile(classPath);
    }

    void analyzeClassFile(File path) throws Exception {
        ClassFile classFile = ClassFile.read(path);
        InnerClasses_attribute innerClasses =
                (InnerClasses_attribute) classFile.attributes.get(Attribute.InnerClasses);
        for (Info classInfo : innerClasses.classes) {
            Assert.check(!classInfo.inner_class_access_flags.is(AccessFlags.ACC_STRICT),
                    "Inner classes attribute must not have the ACC_STRICT flag set");
        }
    }

    strictfp void m() {
        new Runnable() {
            @Override
            public void run() {}
        };
    }

    static strictfp class Strict extends InnerClassAttrMustNotHaveStrictFPFlagTest {}

}
