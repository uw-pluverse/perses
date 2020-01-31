

import java.io.*;
import java.util.*;
import javax.lang.model.util.*;
import javax.tools.*;
import com.sun.tools.javac.api.*;
import com.sun.source.tree.*;
import com.sun.source.util.*;
import com.sun.tools.javac.tree.JCTree;
import com.sun.tools.javac.tree.JCTree.*;
import com.sun.tools.javac.util.Position;


abstract class Checker {
    
    void check(String... fileNames) throws IOException {
        File testSrc = new File(System.getProperty("test.src"));

        DiagnosticListener<JavaFileObject> dl = new DiagnosticListener<JavaFileObject>() {
            public void report(Diagnostic d) {
                System.err.println(d);
                if (d.getKind() == Diagnostic.Kind.ERROR)
                    errors = true;
                new Exception().printStackTrace();
            }
        };

        JavacTool tool = JavacTool.create();
        StandardJavaFileManager fm = tool.getStandardFileManager(dl, null, null);
        Iterable<? extends JavaFileObject> files =
            fm.getJavaFileObjectsFromFiles(getFiles(testSrc, fileNames));
        task = tool.getTask(null, fm, dl, null, null, files);
        Iterable<? extends CompilationUnitTree> units = task.parse();

        if (errors)
            throw new AssertionError("errors occurred creating trees");

        ScopeScanner s = new ScopeScanner();
        for (CompilationUnitTree unit: units) {
            TreePath p = new TreePath(unit);
            s.scan(p, getTrees());
        }
        task = null;

        if (errors)
            throw new AssertionError("errors occurred checking scopes");
    }

    
    protected boolean check(Scope s, String ref) {
        
        
        if (s == null && (ref == null || ref.trim().length() == 0))
            return true;

        if (s == null) {
            error(s, ref, "scope missing");
            return false;
        }

        if (ref == null) {
            error(s, ref, "scope unexpected");
            return false;
        }

        String local;
        String encl;
        int semi = ref.indexOf(';');
        if (semi == -1) {
            local = ref;
            encl = null;
        } else {
            local = ref.substring(0, semi);
            encl = ref.substring(semi + 1);
        }

        return checkLocal(s, local.trim())
            & check(s.getEnclosingScope(), encl);
    }

    
    boolean checkLocal(Scope s, String ref) {
        throw new IllegalStateException();
    }

    void error(Scope s, String ref, String msg) {
        System.err.println("Error: " + msg);
        System.err.println("Scope: " + (s == null ? null : asList(s.getLocalElements())));
        System.err.println("Expect: " + ref);
        System.err.println("javac: " + (s == null ? null : ((JavacScope) s).getEnv()));
        errors = true;
    }

    protected Elements getElements() {
        return task.getElements();
    }

    protected Trees getTrees() {
        return Trees.instance(task);
    }

    boolean errors = false;
    protected JavacTask task;

    
    
    class ScopeScanner extends TreePathScanner<Boolean,Trees> {
        public Boolean  visitLiteral(LiteralTree tree, Trees trees) {
            TreePath path = getCurrentPath();
            CompilationUnitTree unit = path.getCompilationUnit();
            Position.LineMap lineMap = ((JCCompilationUnit)unit).lineMap;


            Scope s = trees.getScope(path);
            if (tree.getKind() == Tree.Kind.STRING_LITERAL)
                check(s, tree.getValue().toString().trim());
            return null;
        }

        private String abbrev(Tree tree) {
            int max = 48;
            String s = tree.toString().replaceAll("[ \n]+", " ");
            return (s.length() < max ? s : s.substring(0, max-3) + "...");
        }
    }

    
    static Iterable<File> getFiles(File dir, String... names) {
        List<File> files = new ArrayList<File>(names.length);
        for (String name: names)
            files.add(new File(dir, name));
        return files;
    }

    static private <T> List<T> asList(Iterable<T> iter) {
        List<T> l = new ArrayList<T>();
        for (T t: iter)
            l.add(t);
        return l;
    }
}
