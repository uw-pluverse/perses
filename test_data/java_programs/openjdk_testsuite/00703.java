



import java.io.*;
import java.util.*;
import javax.tools.*;
import javax.lang.model.element.Modifier;
import com.sun.source.tree.*;
import com.sun.source.util.*;
import com.sun.tools.javac.api.JavacTool;
import com.sun.tools.javac.code.Flags;
import com.sun.tools.javac.tree.JCTree.JCModifiers;

public abstract class T6397044 {
    public static void main(String[] args) throws Exception {
        String srcDir = System.getProperty("test.src", ".");
        String self = T6397044.class.getName();
        JavacTool tool = JavacTool.create();
        StandardJavaFileManager fm = tool.getStandardFileManager(null, null, null);
        Iterable<? extends JavaFileObject> files
            = fm.getJavaFileObjectsFromFiles(Arrays.asList(new File(srcDir, self + ".java")));
        JavacTask task = tool.getTask(null, fm, null, null, null, files);
        Iterable<? extends CompilationUnitTree> trees = task.parse();
        Checker checker = new Checker();
        for (CompilationUnitTree tree: trees)
            checker.check(tree);
    }

    public int x_public;
    protected int x_protected;
    private int x_private;
    abstract int x_abstract();
    static int x_static;
    final int x_final = 1;
    transient int x_transient;
    volatile int x_volatile;
    synchronized void x_synchronized() { }
    native int x_native();
    strictfp void x_strictfp() { }

    static class Checker extends TreeScanner<Void,Void> {
        void check(Tree tree) {
            if (tree != null)
                tree.accept(this, null);
        }

        void check(List<? extends Tree> trees) {
            if (trees == null)
                return;
            for (Tree tree: trees)
                check(tree);
        }

        public Void visitCompilationUnit(CompilationUnitTree tree, Void ignore) {
            check(tree.getTypeDecls());
            return null;
        }

        public Void visitClass(ClassTree tree, Void ignore) {
            check(tree.getMembers());
            return null;
        }

        public Void visitMethod(MethodTree tree, Void ignore) {
            check(tree.getName(), tree.getModifiers());
            return null;
        }

        public Void visitVariable(VariableTree tree, Void ignore) {
            check(tree.getName(), tree.getModifiers());
            return null;
        }

        private void check(CharSequence name, ModifiersTree modifiers) {
            long sysflags = ((JCModifiers) modifiers).flags;
            System.err.println(name + ": " + modifiers.getFlags() + " | " + Flags.toString(sysflags));
            if (name.toString().startsWith("x_")) {
                String expected = "[" + name.toString().substring(2) + "]";
                String found = modifiers.getFlags().toString();
                if (!found.equals(expected))
                    throw new AssertionError("expected: " + expected + "; found: " + found);
            }
        }
    }
}
