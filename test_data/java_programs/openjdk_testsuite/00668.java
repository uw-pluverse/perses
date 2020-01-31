


import com.sun.tools.javac.code.Type;
import com.sun.tools.javac.code.Type.*;
import com.sun.tools.javac.code.Symbol.*;
import java.io.*;
import java.lang.reflect.Array;
import java.util.EnumSet;

public class TestComparisons {

    private int errors = 0;
    private int testnum = 0;

    static final File testdir = new File("8013357");

    private enum CompareType {
        BYTE_PRIM("byte"),
        SHORT_PRIM("short"),
        CHAR_PRIM("char"),
        INTEGER_PRIM("int"),
        LONG_PRIM("long"),
        FLOAT_PRIM("float"),
        DOUBLE_PRIM("double"),
        BOOLEAN_PRIM("boolean"),

        BYTE("Byte"),
        SHORT("Short"),
        CHAR("Character"),
        INTEGER("Integer"),
        LONG("Long"),
        FLOAT("Float"),
        DOUBLE("Double"),
        BOOLEAN("Boolean"),

        BYTE_SUPER("List<? super Byte>", true),
        SHORT_SUPER("List<? super Short>", true),
        CHAR_SUPER("List<? super Character>", true),
        INTEGER_SUPER("List<? super Integer>", true),
        LONG_SUPER("List<? super Long>", true),
        FLOAT_SUPER("List<? super Float>", true),
        DOUBLE_SUPER("List<? super Double>", true),
        BOOLEAN_SUPER("List<? super Boolean>", true),

        OBJECT("Object"),
        NUMBER("Number"),
        STRING("String");

        public final boolean isList;
        public final String name;

        private CompareType(final String name, final boolean isList) {
            this.isList = isList;
            this.name = name;
        }

        private CompareType(final String name) {
            this(name, false);
        }
    }

    
    
    private static final int truthtab[][] = {
        
        
        { 1, 1, 1, 1, 1, 1, 1, 0, 
          1, 1, 1, 1, 1, 1, 1, 0, 
          0, 0, 0, 0, 0, 0, 0, 0, 
          0, 0, 0                 
        },
        
        
        { 1, 1, 1, 1, 1, 1, 1, 0, 
          1, 1, 1, 1, 1, 1, 1, 0, 
          0, 0, 0, 0, 0, 0, 0, 0, 
          0, 0, 0                 
        },
        
        
        { 1, 1, 1, 1, 1, 1, 1, 0, 
          1, 1, 1, 1, 1, 1, 1, 0, 
          0, 0, 0, 0, 0, 0, 0, 0, 
          0, 0, 0                 
        },
        
        
        { 1, 1, 1, 1, 1, 1, 1, 0, 
          1, 1, 1, 1, 1, 1, 1, 0, 
          0, 0, 0, 0, 0, 0, 0, 0, 
          0, 0, 0                 
        },
        
        
        { 1, 1, 1, 1, 1, 1, 1, 0, 
          1, 1, 1, 1, 1, 1, 1, 0, 
          0, 0, 0, 0, 0, 0, 0, 0, 
          0, 0, 0                 
        },
        
        
        { 1, 1, 1, 1, 1, 1, 1, 0, 
          1, 1, 1, 1, 1, 1, 1, 0, 
          0, 0, 0, 0, 0, 0, 0, 0, 
          0, 0, 0                 
        },
        
        
        { 1, 1, 1, 1, 1, 1, 1, 0, 
          1, 1, 1, 1, 1, 1, 1, 0, 
          0, 0, 0, 0, 0, 0, 0, 0, 
          0, 0, 0                 
        },
        
        { 0, 0, 0, 0, 0, 0, 0, 2, 
          0, 0, 0, 0, 0, 0, 0, 2, 
          0, 0, 0, 0, 0, 0, 0, 0, 
          0, 0, 0                 
        },
        
        
        { 1, 1, 1, 1, 1, 1, 1, 0, 
          3, 0, 0, 0, 0, 0, 0, 0, 
          3, 3, 3, 3, 3, 3, 3, 3, 
          3, 3, 0                 
        },
        
        
        { 1, 1, 1, 1, 1, 1, 1, 0, 
          0, 3, 0, 0, 0, 0, 0, 0, 
          3, 3, 3, 3, 3, 3, 3, 3, 
          3, 3, 0                 
        },
        
        
        { 1, 1, 1, 1, 1, 1, 1, 0, 
          0, 0, 3, 0, 0, 0, 0, 0, 
          3, 3, 3, 3, 3, 3, 3, 3, 
          3, 0, 0                 
        },
        
        
        { 1, 1, 1, 1, 1, 1, 1, 0, 
          0, 0, 0, 3, 0, 0, 0, 0, 
          3, 3, 3, 3, 3, 3, 3, 3, 
          3, 3, 0                 
        },
        
        
        { 1, 1, 1, 1, 1, 1, 1, 0, 
          0, 0, 0, 0, 3, 0, 0, 0, 
          3, 3, 3, 3, 3, 3, 3, 3, 
          3, 3, 0                 
        },
        
        
        { 1, 1, 1, 1, 1, 1, 1, 0, 
          0, 0, 0, 0, 0, 3, 0, 0, 
          3, 3, 3, 3, 3, 3, 3, 3, 
          3, 3, 0                 
        },
        
        
        { 1, 1, 1, 1, 1, 1, 1, 0, 
          0, 0, 0, 0, 0, 0, 3, 0, 
          3, 3, 3, 3, 3, 3, 3, 3, 
          3, 3, 0                 
        },
        
        { 0, 0, 0, 0, 0, 0, 0, 2, 
          0, 0, 0, 0, 0, 0, 0, 2, 
          3, 3, 3, 3, 3, 3, 3, 3, 
          3, 0, 0                 
        },
        
        
        { 0, 0, 0, 0, 0, 0, 0, 0, 
          3, 3, 3, 3, 3, 3, 3, 3, 
          3, 3, 3, 3, 3, 3, 3, 3, 
          3, 3, 3                 
        },
        
        
        { 0, 0, 0, 0, 0, 0, 0, 0, 
          3, 3, 3, 3, 3, 3, 3, 3, 
          3, 3, 3, 3, 3, 3, 3, 3, 
          3, 3, 3                 
        },
        
        
        { 0, 0, 0, 0, 0, 0, 0, 0, 
          3, 3, 3, 3, 3, 3, 3, 3, 
          3, 3, 3, 3, 3, 3, 3, 3, 
          3, 3, 3                 
        },
        
        
        { 0, 0, 0, 0, 0, 0, 0, 0, 
          3, 3, 3, 3, 3, 3, 3, 3, 
          3, 3, 3, 3, 3, 3, 3, 3, 
          3, 3, 3                 
        },
        
        
        { 0, 0, 0, 0, 0, 0, 0, 0, 
          3, 3, 3, 3, 3, 3, 3, 3, 
          3, 3, 3, 3, 3, 3, 3, 3, 
          3, 3, 3                 
        },
        
        
        { 0, 0, 0, 0, 0, 0, 0, 0, 
          3, 3, 3, 3, 3, 3, 3, 3, 
          3, 3, 3, 3, 3, 3, 3, 3, 
          3, 3, 3                 
        },
        
        
        { 0, 0, 0, 0, 0, 0, 0, 0, 
          3, 3, 3, 3, 3, 3, 3, 3, 
          3, 3, 3, 3, 3, 3, 3, 3, 
          3, 3, 3                 
        },
        
        
        { 0, 0, 0, 0, 0, 0, 0, 0, 
          3, 3, 3, 3, 3, 3, 3, 3, 
          3, 3, 3, 3, 3, 3, 3, 3, 
          3, 3, 3                 
        },
        
        
        { 0, 0, 0, 0, 0, 0, 0, 0, 
          3, 3, 3, 3, 3, 3, 3, 3, 
          3, 3, 3, 3, 3, 3, 3, 3, 
          3, 3, 3                 
        },
        
        
        { 0, 0, 0, 0, 0, 0, 0, 0, 
          3, 3, 0, 3, 3, 3, 3, 0, 
          3, 3, 3, 3, 3, 3, 3, 3, 
          3, 3, 0                 
        },
        
        
        { 0, 0, 0, 0, 0, 0, 0, 0, 
          0, 0, 0, 0, 0, 0, 0, 0, 
          3, 3, 3, 3, 3, 3, 3, 3, 
          3, 0, 3                 
        }
    };

    private void assert_compile_fail(final File file, final String body) {
        final String filename = file.getPath();
        final String[] args = { filename };
        final StringWriter sw = new StringWriter();
        final PrintWriter pw = new PrintWriter(sw);
        final int rc = com.sun.tools.javac.Main.compile(args, pw);
        pw.close();
        if (rc == 0) {
            System.err.println("Compilation of " + file.getName() +
                               " didn't fail as expected.\nFile:\n" +
                               body + "\nOutput:\n" + sw.toString());
            errors++;
        }
    }

    private void assert_compile_succeed(final File file, final String body) {
        final String filename = file.getPath();
        final String[] args = { filename };
        final StringWriter sw = new StringWriter();
        final PrintWriter pw = new PrintWriter(sw);
        final int rc = com.sun.tools.javac.Main.compile(args, pw);
        pw.close();
        if (rc != 0) {
            System.err.println("Compilation of " + file.getName() +
                               " didn't succeed as expected.\nFile:\n" +
                               body + "\nOutput:\n" +
                               sw.toString());
            errors++;
        }
    }

    private String makeBody(final int num,
                            final CompareType left,
                            final CompareType right) {
        return "import java.util.List;\n" +
            "public class Test" + num + " {\n" +
            "    public boolean test(" + left.name +
            " left, " + right.name + " right) {\n" +
            "        return left" + (left.isList ? ".get(0)" : "") +
            " == right" + (right.isList ? ".get(0)" : "") + ";\n" +
            "    }\n" +
            "}\n";
    }

    private File writeFile(final String filename,
                           final String body)
        throws IOException {
        final File f = new File(testdir, filename);
        f.getParentFile().mkdirs();
        final FileWriter out = new FileWriter(f);
        out.write(body);
        out.close();
        return f;
    }

    private void test(final CompareType left, final CompareType right)
        throws IOException {
        final int num = testnum++;
        final String filename = "Test" + num + ".java";
        final String body = makeBody(num, left, right);
        final File file = writeFile(filename, body);
        if (truthtab[left.ordinal()][right.ordinal()] != 0)
            assert_compile_succeed(file, body);
        else
            assert_compile_fail(file, body);
    }

    void run() throws Exception {
        testdir.mkdir();

        for(CompareType left : CompareType.values())
            for(CompareType right : CompareType.values())
                test(left, right);

        if (errors != 0)
            throw new Exception("ObjectZeroCompare test failed with " +
                                errors + " errors.");
    }

    public static void main(String... args) throws Exception {
        new TestComparisons().run();
    }
}
