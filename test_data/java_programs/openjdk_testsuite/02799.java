



import com.sun.tools.classfile.ClassFile;
import com.sun.tools.classfile.ConstantPool.CONSTANT_Class_info;
import com.sun.tools.classfile.ConstantPool.CPInfo;
import com.sun.tools.classfile.ConstantPoolException;
import java.io.File;
import java.io.IOException;

import static pkg.ClassToBeStaticallyImportedA.staticFieldA;
import static pkg.ClassToBeStaticallyImportedB.staticFieldB;

public class CPoolRefClassContainingInlinedCts {

    public static void main(String args[]) throws Exception {
        new CPoolRefClassContainingInlinedCts().run();
    }

    void run() throws Exception {
        checkReferences();
    }

    int numberOfReferencedClassesToBeChecked = 0;

    void checkClassName(String className) {
        switch (className) {
            case "SimpleAssignClassA" : case "BinaryExpClassA":
            case "UnaryExpClassA" : case "CastClassA":
            case "ParensClassA" : case "CondClassA":
            case "IfClassA" : case "pkg/ClassToBeStaticallyImportedA":
            case "SimpleAssignClassB" : case "BinaryExpClassB":
            case "UnaryExpClassB" : case "CastClassB":
            case "ParensClassB" : case "CondClassB":
            case "IfClassB" : case "pkg/ClassToBeStaticallyImportedB":
                numberOfReferencedClassesToBeChecked++;
        }
    }

    void checkReferences() throws IOException, ConstantPoolException {
        File testClasses = new File(System.getProperty("test.classes"));
        File file = new File(testClasses,
                CPoolRefClassContainingInlinedCts.class.getName() + ".class");
        ClassFile classFile = ClassFile.read(file);
        int i = 1;
        CPInfo cpInfo;
        while (i < classFile.constant_pool.size()) {
            cpInfo = classFile.constant_pool.get(i);
            if (cpInfo instanceof CONSTANT_Class_info) {
                checkClassName(((CONSTANT_Class_info)cpInfo).getName());
            }
            i += cpInfo.size();
        }
        if (numberOfReferencedClassesToBeChecked != 16) {
            throw new AssertionError("Class reference missing in the constant pool");
        }
    }

    private int assignA = SimpleAssignClassA.x;
    private int binaryA = BinaryExpClassA.x + 1;
    private int unaryA = -UnaryExpClassA.x;
    private int castA = (int)CastClassA.x;
    private int parensA = (ParensClassA.x);
    private int condA = (CondClassA.x == 1) ? 1 : 2;
    private static int ifConstantA;
    private static int importStaticA;
    static {
        if (IfClassA.x == 1) {
            ifConstantA = 1;
        } else {
            ifConstantA = 2;
        }
    }
    static {
        if (staticFieldA == 1) {
            importStaticA = 1;
        } else {
            importStaticA = 2;
        }
    }

    
    private static final int assignB = SimpleAssignClassB.x;
    private static final int binaryB = BinaryExpClassB.x + 1;
    private static final int unaryB = -UnaryExpClassB.x;
    private static final int castB = (int)CastClassB.x;
    private static final int parensB = (ParensClassB.x);
    private static final int condB = (CondClassB.x == 1) ? 1 : 2;
    private static final int ifConstantB;
    private static final int importStaticB;
    static {
        if (IfClassB.x == 1) {
            ifConstantB = 1;
        } else {
            ifConstantB = 2;
        }
    }
    static {
        if (staticFieldB == 1) {
            importStaticB = 1;
        } else {
            importStaticB = 2;
        }
    }
}

class SimpleAssignClassA {
    public static final int x = 1;
}

class SimpleAssignClassB {
    public static final int x = 1;
}

class BinaryExpClassA {
    public static final int x = 1;
}

class BinaryExpClassB {
    public static final int x = 1;
}

class UnaryExpClassA {
    public static final int x = 1;
}

class UnaryExpClassB {
    public static final int x = 1;
}

class CastClassA {
    public static final int x = 1;
}

class CastClassB {
    public static final int x = 1;
}

class ParensClassA {
    public static final int x = 1;
}

class ParensClassB {
    public static final int x = 1;
}

class CondClassA {
    public static final int x = 1;
}

class CondClassB {
    public static final int x = 1;
}

class IfClassA {
    public static final int x = 1;
}

class IfClassB {
    public static final int x = 1;
}
