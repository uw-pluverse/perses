



import com.sun.tools.javac.code.Type;
import com.sun.tools.javac.code.TypeTag;
import com.sun.tools.javac.code.Symtab;
import com.sun.tools.javac.code.Types;
import com.sun.tools.javac.file.JavacFileManager;
import com.sun.tools.javac.tree.JCTree.JCLiteral;
import com.sun.tools.javac.util.Context;
import com.sun.tools.javac.tree.TreeMaker;
import static com.sun.tools.javac.code.TypeTag.*;

public class MakeLiteralTest {
    public static void main(String... args) throws Exception {
        new MakeLiteralTest().run();
    }

    void run() throws Exception {
        Context context = new Context();
        JavacFileManager.preRegister(context);
        Symtab syms = Symtab.instance(context);
        maker = TreeMaker.instance(context);
        types = Types.instance(context);

        test("abc",                     CLASS,      syms.stringType,    "abc");
        test(Boolean.FALSE,             BOOLEAN,    syms.booleanType,   Integer.valueOf(0));
        test(Boolean.TRUE,              BOOLEAN,    syms.booleanType,   Integer.valueOf(1));
        test(Byte.valueOf((byte) 1),    BYTE,       syms.byteType,      Byte.valueOf((byte) 1));
        test(Character.valueOf('a'),    CHAR,       syms.charType,      Integer.valueOf('a'));
        test(Double.valueOf(1d),        DOUBLE,     syms.doubleType,    Double.valueOf(1d));
        test(Float.valueOf(1f),         FLOAT,      syms.floatType,     Float.valueOf(1f));
        test(Integer.valueOf(1),        INT,        syms.intType,       Integer.valueOf(1));
        test(Long.valueOf(1),           LONG,       syms.longType,      Long.valueOf(1));
        test(Short.valueOf((short) 1),  SHORT,      syms.shortType,     Short.valueOf((short) 1));

        if (errors > 0)
            throw new Exception(errors + " errors found");
    }

    void test(Object value, TypeTag tag, Type type, Object constValue) {
        JCLiteral l = maker.Literal(value);
        if (!l.type.hasTag(tag))
            error("unexpected tag: " + l.getTag() + ": expected: " + tag);
        if (!types.isSameType(l.type, type))
            error("unexpected type: " + l.type + ": expected: " + type);
        if (l.type.constValue().getClass() != constValue.getClass()
                || !constValue.equals(l.type.constValue()))  {
            error("unexpected const value: "
                    + l.type.constValue().getClass() + " " + l.type.constValue()
                    + ": expected:" + constValue.getClass() + " " + constValue);
        }
    }

    void error(String msg) {
        System.err.println("Error: " + msg);
        errors++;
    }

    TreeMaker maker;
    Types types;
    int errors;
}
