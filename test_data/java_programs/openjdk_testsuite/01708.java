



import com.sun.tools.classfile.Attribute;
import com.sun.tools.classfile.ClassFile;
import com.sun.tools.classfile.Code_attribute;
import com.sun.tools.classfile.ConstantPool;
import com.sun.tools.classfile.ConstantPool.CONSTANT_String_info;
import com.sun.tools.classfile.ConstantPool.CPInfo;
import com.sun.tools.classfile.ConstantPool.InvalidIndex;
import com.sun.tools.classfile.Instruction;
import com.sun.tools.classfile.Instruction.KindVisitor;
import com.sun.tools.classfile.Instruction.TypeKind;
import com.sun.tools.classfile.Method;
import com.sun.tools.javac.util.Assert;
import java.io.BufferedInputStream;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;

public class DeadCodeGeneratedForEmptyTryTest {

    public static void main(String[] args) throws Exception {
        new DeadCodeGeneratedForEmptyTryTest().run();
    }

    void run() throws Exception {
        checkClassFile(Paths.get(System.getProperty("test.classes"),
                this.getClass().getName() + "$Test.class"));
    }

    int utf8Index;
    int numberOfRefToStr = 0;
    ConstantPool constantPool;

    void checkClassFile(final Path path) throws Exception {
        ClassFile classFile = ClassFile.read(
                new BufferedInputStream(Files.newInputStream(path)));
        constantPool = classFile.constant_pool;
        utf8Index = constantPool.getUTF8Index("STR_TO_LOOK_FOR");
        for (Method method: classFile.methods) {
            if (method.getName(constantPool).equals("methodToLookFor")) {
                Code_attribute codeAtt = (Code_attribute)method.attributes.get(Attribute.Code);
                for (Instruction inst: codeAtt.getInstructions()) {
                    inst.accept(codeVisitor, null);
                }
            }
        }
        Assert.check(numberOfRefToStr == 1,
                "There should only be one reference to a CONSTANT_String_info structure in the generated code");
    }

    CodeVisitor codeVisitor = new CodeVisitor();

    class CodeVisitor implements KindVisitor<Void, Void> {

        void checkIndirectRefToString(int cp_index) {
            try {
                CPInfo cInfo = constantPool.get(cp_index);
                if (cInfo instanceof CONSTANT_String_info) {
                    CONSTANT_String_info strInfo = (CONSTANT_String_info)cInfo;
                    if (strInfo.string_index == utf8Index) {
                        numberOfRefToStr++;
                    }
                }
            } catch (InvalidIndex ex) {
                throw new AssertionError("invalid constant pool index at " + cp_index);
            }
        }

        @Override
        public Void visitNoOperands(Instruction instr, Void p) {
            return null;
        }

        @Override
        public Void visitArrayType(Instruction instr, TypeKind kind, Void p) {
            return null;
        }

        @Override
        public Void visitBranch(Instruction instr, int offset, Void p) {
            return null;
        }

        @Override
        public Void visitConstantPoolRef(Instruction instr, int index, Void p) {
            checkIndirectRefToString(index);
            return null;
        }

        @Override
        public Void visitConstantPoolRefAndValue(Instruction instr, int index, int value, Void p) {
            checkIndirectRefToString(index);
            return null;
        }

        @Override
        public Void visitLocal(Instruction instr, int index, Void p) {
            return null;
        }

        @Override
        public Void visitLocalAndValue(Instruction instr, int index, int value, Void p) {
            return null;
        }

        @Override
        public Void visitLookupSwitch(Instruction instr, int default_, int npairs, int[] matches, int[] offsets, Void p) {
            return null;
        }

        @Override
        public Void visitTableSwitch(Instruction instr, int default_, int low, int high, int[] offsets, Void p) {
            return null;
        }

        @Override
        public Void visitValue(Instruction instr, int value, Void p) {
            return null;
        }

        @Override
        public Void visitUnknown(Instruction instr, Void p) {
            return null;
        }

    }

    public class Test {
        void methodToLookFor() {
            try {
            } finally {
                System.out.println("STR_TO_LOOK_FOR");
            }
        }
    }
}
