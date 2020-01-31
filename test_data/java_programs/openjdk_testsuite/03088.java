
import java.io.File;
import java.io.IOException;
import java.lang.reflect.Method;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.StringJoiner;

import org.testng.annotations.BeforeMethod;
import org.testng.annotations.Test;

import tools.javac.combo.*;

import static org.testng.Assert.fail;



@Test
public abstract class BridgeMethodTestCase extends JavacTemplateTestBase {

    private static final String TYPE_LETTERS = "ABCDIJK";

    private static final String BASE_INDEX_CLASS = "class C0 {\n" +
                                                   "    int val;\n" +
                                                   "    C0(int val) { this.val = val; }\n" +
                                                   "    public int getVal() { return val; }\n" +
                                                   "}\n";
    private static final String INDEX_CLASS_TEMPLATE = "class C#ID extends C#PREV {\n" +
                                                       "    C#ID(int val) { super(val); }\n" +
                                                       "}\n";



    protected static String LINKAGE_ERROR = "-1";

    private List<File> compileDirs = new ArrayList<>();

    
   protected void compileSpec(String spec) throws IOException {
        compileSpec(spec, false);
    }

    
    protected void compileSpec(String spec, String... errorKeys) throws IOException {
        compileSpec(spec, false, errorKeys);
    }

    protected void compileSpec(String spec, boolean debug, String... errorKeys) throws IOException {
        ClassModel cm = new Parser(spec).parseClassModel();
        for (int i = 0; i <= cm.maxIndex() ; i++) {
            if (debug) System.out.println(indexClass(i));
            addSourceFile(String.format("C%d.java", i), new StringTemplate(indexClass(i)));
        }
        for (Map.Entry<String, ClassModel> e : classes(cm).entrySet()) {
            if (debug) System.out.println(e.getValue().toSource());
            addSourceFile(e.getKey() + ".java", new StringTemplate(e.getValue().toSource()));
        }
        compileDirs.add(compile(true));
        resetSourceFiles();
        if (errorKeys.length == 0)
            assertCompileSucceeded();
        else
            assertCompileErrors(errorKeys);
    }

    
    protected void recompileSpec(String spec, String... names) throws IOException {
        List<String> nameList = Arrays.asList(names);
        ClassModel cm = new Parser(spec).parseClassModel();
        for (int i = 0; i <= cm.maxIndex() ; i++) {
            addSourceFile(String.format("C%d.java", i), new StringTemplate(indexClass(i)));
        }
        for (Map.Entry<String, ClassModel> e : classes(cm).entrySet())
            if (nameList.contains(e.getKey()))
                addSourceFile(e.getKey() + ".java", new StringTemplate(e.getValue().toSource()));
        compileDirs.add(compile(Arrays.asList(classPaths()), true));
        resetSourceFiles();
        assertCompileSucceeded();
    }

    protected void assertLinkage(String name, String... expected) throws ReflectiveOperationException {
        for (int i=0; i<expected.length; i++) {
            String e = expected[i];
            if (e.equals(LINKAGE_ERROR)) {
                try {
                    int actual = invoke(name, i);
                    fail("Expected linkage error, got" + fromNum(actual));
                }
                catch (LinkageError x) {
                    
                }
            }
            else {
                if (e.length() == 1)
                    e += "0";
                int expectedInt = toNum(e);
                int actual = invoke(name, i);
                if (expectedInt != actual)
                    fail(String.format("Expected %s but found %s for %s.m()%d", fromNum(expectedInt), fromNum(actual), name, i));
            }
        }
    }

    private Map<String, ClassModel> classes(ClassModel cm) {
        HashMap<String, ClassModel> m = new HashMap<>();
        classesHelper(cm, m);
        return m;
    }

    private String indexClass(int index) {
        if (index == 0) {
            return BASE_INDEX_CLASS;
        } else {
            return INDEX_CLASS_TEMPLATE
                    .replace("#ID", String.valueOf(index))
                    .replace("#PREV", String.valueOf(index - 1));
        }
    }

    private static String overrideName(int index) {
        return "C" + index;
    }

    private void classesHelper(ClassModel cm, Map<String, ClassModel> m) {
        if (!m.containsKey(cm.name))
            m.put(cm.name, cm);
        for (ClassModel s : cm.supertypes)
            classesHelper(s, m);
    }

    private static String fromNum(int num) {
        return String.format("%c%d", TYPE_LETTERS.charAt(num / 10), num % 10);
    }

    private static int toNum(String name, int index) {
        return 10*(TYPE_LETTERS.indexOf(name.charAt(0))) + index;
    }

    private static int toNum(String string) {
        return 10*(TYPE_LETTERS.indexOf(string.charAt(0))) + Integer.parseInt(string.substring(1, 2));
    }

    private int invoke(String name, int index) throws ReflectiveOperationException {
        File[] files = classPaths();
        Class clazz = loadClass(name, files);
        Method[] ms = clazz.getMethods();
        for (Method m : ms) {
            if (m.getName().equals("m") && m.getReturnType().getName().equals(overrideName(index))) {
                m.setAccessible(true);
                Object instance = clazz.newInstance();
                Object c0 = m.invoke(instance);
                Method getVal = c0.getClass().getMethod("getVal");
                getVal.setAccessible(true);
                return (int)getVal.invoke(c0);
            }
        }
        throw new NoSuchMethodError("cannot find method m()" + index + " in class " + name);
    }

    private File[] classPaths() {
        File[] files = new File[compileDirs.size()];
        for (int i=0; i<files.length; i++)
            files[files.length - i - 1] = compileDirs.get(i);
        return files;
    }

    @BeforeMethod
    @Override
    public void reset() {
        compileDirs.clear();
        super.reset();
    }

    private static class ClassModel {

        enum MethodType {
            ABSTRACT('a'), CONCRETE('c'), DEFAULT('d');

            public final char designator;

            MethodType(char designator) {
                this.designator = designator;
            }

            public static MethodType find(char c) {
                for (MethodType m : values())
                    if (m.designator == c)
                        return m;
                throw new IllegalArgumentException();
            }
        }

        private final String name;
        private final boolean isInterface;
        private final List<ClassModel> supertypes;
        private final MethodType methodType;
        private final int methodIndex;

        private ClassModel(String name,
                           boolean anInterface,
                           List<ClassModel> supertypes,
                           MethodType methodType,
                           int methodIndex) {
            this.name = name;
            isInterface = anInterface;
            this.supertypes = supertypes;
            this.methodType = methodType;
            this.methodIndex = methodIndex;
        }

        @Override
        public String toString() {
            StringBuilder sb = new StringBuilder();
            sb.append(name);
            if (methodType != null) {
                sb.append(methodType.designator);
                sb.append(methodIndex);
            }
            if (!supertypes.isEmpty()) {
                sb.append("(");
                for (int i=0; i<supertypes.size(); i++) {
                    if (i > 0)
                        sb.append(",");
                    sb.append(supertypes.get(i).toString());
                }
                sb.append(")");
            }
            return sb.toString();
        }

        int maxIndex() {
            int maxSoFar = methodIndex;
            for (ClassModel cm : supertypes) {
                maxSoFar = Math.max(cm.maxIndex(), maxSoFar);
            }
            return maxSoFar;
        }

        public String toSource() {
            String extendsClause = "";
            String implementsClause = "";
            String methodBody = "";
            boolean isAbstract = "AB".contains(name);

            for (ClassModel s : supertypes) {
                if (!s.isInterface) {
                    extendsClause = String.format("extends %s", s.name);
                    break;
                }
            }

            StringJoiner sj = new StringJoiner(", ");
            for (ClassModel s : supertypes)
                if (s.isInterface)
                    sj.add(s.name);
            if (sj.length() > 0) {
                if (isInterface)
                    implementsClause = "extends " + sj.toString();
                else
                implementsClause = "implements " + sj.toString();
            }
            if (methodType != null) {
                switch (methodType) {
                    case ABSTRACT:
                        methodBody = String.format("public abstract %s m();", overrideName(methodIndex));
                        break;
                    case CONCRETE:
                        methodBody = String.format("public %s m() { return new %s(%d); };",
                                overrideName(methodIndex), overrideName(methodIndex), toNum(name, methodIndex));
                        break;
                    case DEFAULT:
                        methodBody = String.format("public default %s m() { return new %s(%d); };",
                                overrideName(methodIndex), overrideName(methodIndex), toNum(name, methodIndex));
                        break;

                }
            }

            return String.format("public %s %s %s %s %s {  %s }", isAbstract ? "abstract" : "",
                                 isInterface ? "interface" : "class",
                                 name, extendsClause, implementsClause, methodBody);
        }
    }

    private static class Parser {
        private final String input;
        private final char[] chars;
        private int index;

        private Parser(String s) {
            input = s;
            chars = s.toCharArray();
        }

        private char peek() {
            return index < chars.length ? chars[index] : 0;
        }

        private boolean peek(String validChars) {
            return validChars.indexOf(peek()) >= 0;
        }

        private char advanceIf(String validChars) {
            if (peek(validChars))
                return chars[index++];
            else
                return 0;
        }

        private char advanceIfDigit() {
            return advanceIf("0123456789");
        }

        private int index() {
            StringBuilder buf = new StringBuilder();
            char c = advanceIfDigit();
            while (c != 0) {
                buf.append(c);
                c = advanceIfDigit();
            }
            return Integer.valueOf(buf.toString());
        }

        private char advance() {
            return chars[index++];
        }

        private char expect(String validChars) {
            char c = advanceIf(validChars);
            if (c == 0)
                throw new IllegalArgumentException(String.format("Expecting %s at position %d of %s", validChars, index, input));
            return c;
        }

        public ClassModel parseClassModel() {
            List<ClassModel> supers = new ArrayList<>();
            char name = expect(TYPE_LETTERS);
            boolean isInterface = "IJK".indexOf(name) >= 0;
            ClassModel.MethodType methodType = peek(isInterface ? "ad" : "ac") ? ClassModel.MethodType.find(advance()) : null;
            int methodIndex = 0;
            if (methodType != null) {
                methodIndex = index();
            }
            if (peek() == '(') {
                advance();
                supers.add(parseClassModel());
                while (peek() == ',') {
                    advance();
                    supers.add(parseClassModel());
                }
                expect(")");
            }
            return new ClassModel(new String(new char[]{ name }), isInterface, supers, methodType, methodIndex);
        }
    }
}
