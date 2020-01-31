



import java.io.*;
import java.lang.annotation.*;
import java.util.*;
import com.sun.tools.classfile.*;


public class LocalVariableTable {
    public static void main(String... args) throws Exception {
        new LocalVariableTable().run();
    }

    void run() throws Exception {
        
        
        Class<?>[] classes = getClass().getDeclaredClasses();
        Arrays.sort(classes, (c1, c2) -> c1.getName().compareTo(c2.getName()));

        for (Class<?> c : classes) {
            if (c.getSimpleName().startsWith("Lambda"))
                check(c);
        }
        if (errors > 0)
            throw new Exception(errors + " errors found");
    }

    
    void check(Class<?> c) throws Exception {
        System.err.println("Checking " + c.getSimpleName());

        Expect expect = c.getAnnotation(Expect.class);
        if (expect == null) {
            error("@Expect not found for class " + c.getSimpleName());
            return;
        }

        ClassFile cf = ClassFile.read(getClass().getResource(c.getName() + ".class").openStream());
        Method m = getLambdaMethod(cf);
        if (m == null) {
            error("lambda method not found");
            return;
        }

        Code_attribute code = (Code_attribute) m.attributes.get(Attribute.Code);
        if (code == null) {
            error("Code attribute not found");
            return;
        }

        LocalVariableTable_attribute lvt =
                (LocalVariableTable_attribute) code.attributes.get(Attribute.LocalVariableTable);
        if (lvt == null) {
            error("LocalVariableTable attribute not found");
            return;
        }

        Set<String> foundNames = new LinkedHashSet<>();
        for (LocalVariableTable_attribute.Entry e: lvt.local_variable_table) {
            foundNames.add(cf.constant_pool.getUTF8Value(e.name_index));
        }

        Set<String> expectNames = new LinkedHashSet<>(Arrays.asList(expect.value()));
        if (!foundNames.equals(expectNames)) {
            Set<String> foundOnly = new LinkedHashSet<>(foundNames);
            foundOnly.removeAll(expectNames);
            for (String s: foundOnly)
                error("Unexpected name found: " + s);
            Set<String> expectOnly = new LinkedHashSet<>(expectNames);
            expectOnly.removeAll(foundNames);
            for (String s: expectOnly)
                error("Expected name not found: " + s);
        }
    }

    
    Method getLambdaMethod(ClassFile cf) throws ConstantPoolException {
        for (Method m: cf.methods) {
            if (m.getName(cf.constant_pool).startsWith("lambda$"))
                return m;
        }
        return null;
    }

    
    void error(String msg) {
        System.err.println("Error: " + msg);
        errors++;
    }

    int errors;

    
    @Retention(RetentionPolicy.RUNTIME)
    @interface Expect {
        String[] value();
    }

    
    interface Run0 {
        public void run();
    }

    
    interface Run1 {
        public void run(int a0);
    }

    
    interface Run2 {
        public void run(int a0, int a1);
    }

    

    @Expect({ "x" })
    static class Lambda_Args0_Local1 {
        Run0 r = () -> { int x = 0; };
    }

    @Expect({ "x", "this" })
    static class Lambda_Args0_Local1_this {
        int v;
        Run0 r = () -> { int x = v; };
    }

    @Expect({ "a" })
    static class Lambda_Args1_Local0 {
        Run1 r = (a) -> { };
    }

    @Expect({ "a", "x" })
    static class Lambda_Args1_Local1 {
        Run1 r = (a) -> { int x = a; };
    }

    @Expect({ "a", "x", "v" })
    static class Lambda_Args1_Local1_Captured1 {
        void m() {
            int v = 0;
            Run1 r = (a) -> { int x = a + v; };
        }
    }

    @Expect({ "a1", "a2", "x1", "x2", "this", "v1", "v2" })
    static class Lambda_Args2_Local2_Captured2_this {
        int v;
        void m() {
            int v1 = 0;
            int v2 = 0;
            Run2 r = (a1, a2) -> {
                int x1 = a1 + v1 + v;
                int x2 = a2 + v2 + v;
            };
        }
    }

    @Expect({ "e", "c" })
    static class Lambda_Try_Catch {
        private static Runnable asUncheckedRunnable(Closeable c) {
            return () -> {
                try {
                    c.close();
                } catch (IOException e) {
                   throw new UncheckedIOException(e);
                }
            };
        }
    }
}

