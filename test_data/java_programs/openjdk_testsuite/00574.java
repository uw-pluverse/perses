



import java.io.BufferedInputStream;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;

import com.sun.tools.javac.util.Assert;
import com.sun.tools.classfile.ClassFile;

import static com.sun.tools.classfile.ConstantPool.CONSTANT_Utf8;
import static com.sun.tools.classfile.ConstantPool.CONSTANT_Utf8_info;
import static com.sun.tools.classfile.ConstantPool.CPInfo;

public class EmptyUTF8ForInnerClassNameTest {

    public static void main(String[] args) throws Exception {
        new EmptyUTF8ForInnerClassNameTest().run();
    }

    void run() throws Exception {
        checkClassFile(Paths.get(System.getProperty("test.classes"),
                this.getClass().getName() + "$1.class"));
        checkClassFile(Paths.get(System.getProperty("test.classes"),
                this.getClass().getName() + "$EnumPlusSwitch.class"));
    }

    void checkClassFile(final Path path) throws Exception {
        ClassFile classFile = ClassFile.read(
                new BufferedInputStream(Files.newInputStream(path)));
        for (CPInfo cpInfo : classFile.constant_pool.entries()) {
            if (cpInfo.getTag() == CONSTANT_Utf8) {
                CONSTANT_Utf8_info utf8Info = (CONSTANT_Utf8_info)cpInfo;
                Assert.check(utf8Info.value.length() > 0,
                        "UTF8 with length 0 found at class " + classFile.getName());
            }
        }
    }

    static class EnumPlusSwitch {
        enum E {E1}

        public int m (E e) {
            switch (e) {
                case E1:
                    return 0;
            }
            return -1;
        }
    }

}
