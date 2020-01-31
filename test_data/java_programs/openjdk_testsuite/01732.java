



import java.util.ArrayList;
import java.util.List;
import java.io.File;
import java.io.IOException;

import com.sun.tools.classfile.ClassFile;
import com.sun.tools.classfile.ConstantPoolException;
import com.sun.tools.classfile.Descriptor;
import com.sun.tools.classfile.Descriptor.InvalidDescriptor;
import com.sun.tools.classfile.Method;

import static com.sun.tools.classfile.AccessFlags.ACC_STRICT;

public class CheckACC_STRICTFlagOnDefaultMethodTest {
    private static final String AssertionErrorMessage =
        "All methods should have the ACC_STRICT access flag " +
        "please check output";
    private static final String offendingMethodErrorMessage =
        "Method %s of class %s doesn't have the ACC_STRICT access flag";

    private List<String> errors = new ArrayList<>();

    public static void main(String[] args)
            throws IOException, ConstantPoolException, InvalidDescriptor {
        new CheckACC_STRICTFlagOnDefaultMethodTest().run();
    }

    private void run()
            throws IOException, ConstantPoolException, InvalidDescriptor {
        String testClasses = System.getProperty("test.classes");
        check(testClasses,
                "CheckACC_STRICTFlagOnDefaultMethodTest$StrictfpInterface.class");
        if (errors.size() > 0) {
            for (String error: errors) {
                System.err.println(error);
            }
            throw new AssertionError(AssertionErrorMessage);
        }
    }

    void check(String dir, String... fileNames)
        throws
            IOException,
            ConstantPoolException,
            Descriptor.InvalidDescriptor {
        for (String fileName : fileNames) {
            ClassFile classFileToCheck = ClassFile.read(new File(dir, fileName));

            for (Method method : classFileToCheck.methods) {
                if ((method.access_flags.flags & ACC_STRICT) == 0) {
                    errors.add(String.format(offendingMethodErrorMessage,
                            method.getName(classFileToCheck.constant_pool),
                            classFileToCheck.getName()));
                }
            }
        }
    }

    strictfp interface StrictfpInterface {
        default void default_interface_method() {}
        static void static_interface_method() {}
    }

}
