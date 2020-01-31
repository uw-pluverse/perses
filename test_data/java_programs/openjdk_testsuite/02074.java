

import java.io.*;
import java.lang.reflect.*;
import java.util.*;
import javax.tools.*;

import com.sun.source.tree.CompilationUnitTree;
import com.sun.source.tree.Tree;
import com.sun.source.util.JavacTask;
import com.sun.tools.javac.api.JavacTool;
import com.sun.tools.javac.tree.JCTree;
import com.sun.tools.javac.tree.JCTree.JCCompilationUnit;
import com.sun.tools.javac.util.List;

public abstract class AbstractTreeScannerTest {

    
    boolean run(File baseDir, String... args) {
        if (args.length == 0) {
            usage(System.out);
            return true;
        }

        ArrayList<File> files = new ArrayList<File>();
        for (int i = 0; i < args.length; i++) {
            String arg = args[i];
            if (arg.equals("-q"))
                quiet = true;
            else if (arg.equals("-v"))
                verbose = true;
            else if (arg.equals("-r")) {
                File d = baseDir;
                while (!new File(d, "TEST.ROOT").exists()) {
                    d = d.getParentFile();
                    if (d == null)
                        throw new Error("cannot find TEST.ROOT");
                }
                baseDir = d;
            }
            else if (arg.startsWith("-"))
                throw new Error("unknown option: " + arg);
            else {
                while (i < args.length)
                    files.add(new File(baseDir, args[i++]));
            }
        }

        for (File file: files) {
            if (file.exists())
                test(file);
            else
                error("File not found: " + file);
        }

        if (fileCount != 1)
            System.err.println(fileCount + " files read");
        System.err.println(treeCount + " tree nodes compared");
        if (errors > 0)
            System.err.println(errors + " errors");

        return (errors == 0);
    }

    
    void usage(PrintStream out) {
        out.println("Usage:");
        out.println("  java " + getClass().getName() + " options... files...");
        out.println("");
        out.println("where options include:");
        out.println("-q        Quiet: don't report on inapplicable files");
        out.println("-v        Verbose: report on files as they are being read");
        out.println("");
        out.println("files may be directories or files");
        out.println("directories will be scanned recursively");
        out.println("non java files, or java files which cannot be parsed, will be ignored");
        out.println("");
    }

    
    void test(File file) {
        if (file.isDirectory()) {
            for (File f: file.listFiles()) {
                test(f);
            }
            return;
        }

        if (file.isFile() && file.getName().endsWith(".java")) {
            try {
                if (verbose)
                    System.err.println(file);
                fileCount++;
                treeCount += test(read(file));
            } catch (ParseException e) {
                if (!quiet) {
                    error("Error parsing " + file + "\n" + e.getMessage());
                }
            } catch (IOException e) {
                error("Error reading " + file + ": " + e);
            }
            return;
        }

        if (!quiet)
            error("File " + file + " ignored");
    }

    abstract int test(JCCompilationUnit t);

    
    StringWriter sw = new StringWriter();
    PrintWriter pw = new PrintWriter(sw);
    Reporter r = new Reporter(pw);
    JavacTool tool = JavacTool.create();
    StandardJavaFileManager fm = tool.getStandardFileManager(r, null, null);

    
    JCCompilationUnit read(File file) throws IOException, ParseException {
        JavacTool tool = JavacTool.create();
        r.errors = 0;
        Iterable<? extends JavaFileObject> files = fm.getJavaFileObjects(file);
        JavacTask task = tool.getTask(pw, fm, r, Collections.<String>emptyList(), null, files);
        Iterable<? extends CompilationUnitTree> trees = task.parse();
        pw.flush();
        if (r.errors > 0)
            throw new ParseException(sw.toString());
        Iterator<? extends CompilationUnitTree> iter = trees.iterator();
        if (!iter.hasNext())
            throw new Error("no trees found");
        JCCompilationUnit t = (JCCompilationUnit) iter.next();
        if (iter.hasNext())
            throw new Error("too many trees found");
        return t;
    }

    
    void error(String msg) {
        System.err.println(msg);
        errors++;
    }

    
    void error(JavaFileObject file, String msg) {
        System.err.println(file.getName() + ": " + msg);
        errors++;
    }

    
    void error(JavaFileObject file, Tree tree, String msg) {
        JCTree t = (JCTree) tree;
        error(file.getName() + ":" + getLine(file, t) + ": " + msg + " " + trim(t, 64));
    }

    
    String trim(Tree tree, int len) {
        JCTree t = (JCTree) tree;
        String s = t.toString().replaceAll("\\s+", " ");
        return (s.length() < len) ? s : s.substring(0, len);
    }

    
    int fileCount;
    
    int treeCount;
    
    int errors;
    
    boolean quiet;
    
    boolean verbose;


    
    private static class ParseException extends Exception {
        ParseException(String msg) {
            super(msg);
        }
    }

    
    private static class Reporter implements DiagnosticListener<JavaFileObject> {
        Reporter(PrintWriter out) {
            this.out = out;
        }

        public void report(Diagnostic<? extends JavaFileObject> diagnostic) {
            out.println(diagnostic);
            switch (diagnostic.getKind()) {
                case ERROR:
                    errors++;
            }
        }
        int errors;
        PrintWriter out;
    }

    
    Set<Field> getFields(JCTree tree) {
        Set<Field> fields = map.get(tree.getTag());
        if (fields == null) {
            fields = new HashSet<Field>();
            for (Field f: tree.getClass().getFields()) {
                Class<?> fc = f.getType();
                if (JCTree.class.isAssignableFrom(fc) || List.class.isAssignableFrom(fc))
                    fields.add(f);
            }
            map.put(tree.getTag(), fields);
        }
        return fields;
    }
    
    Map<JCTree.Tag, Set<Field>> map = new HashMap<JCTree.Tag,Set<Field>>();

    
    int getLine(JavaFileObject file, JCTree tree) {
        try {
            CharSequence cs = file.getCharContent(true);
            int line = 1;
            for (int i = 0; i < tree.pos; i++) {
                if (cs.charAt(i) == '\n') 
                    line++;
            }
            return line;
        } catch (IOException e) {
            return -1;
        }
    }
}
