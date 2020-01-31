



import java.io.*;
import java.util.*;
import javax.annotation.processing.*;
import javax.lang.model.*;
import javax.lang.model.element.*;
import javax.tools.*;

import com.sun.source.tree.*;
import com.sun.source.util.*;
import javax.tools.JavaCompiler.CompilationTask;








@SupportedAnnotationTypes("*")
public class TreePosRoundsTest extends AbstractProcessor {
    public static void main(String... args) throws Exception {
        String testSrc = System.getProperty("test.src");
        String testClasses = System.getProperty("test.classes");
        JavaCompiler c = ToolProvider.getSystemJavaCompiler();
        StandardJavaFileManager fm = c.getStandardFileManager(null, null, null);
        String thisName = TreePosRoundsTest.class.getName();
        File thisFile = new File(testSrc, thisName + ".java");
        Iterable<? extends JavaFileObject> files = fm.getJavaFileObjects(thisFile);
        List<String> options = Arrays.asList(
                "-proc:only",
                "-processor", thisName,
                "-processorpath", testClasses);
        CompilationTask t = c.getTask(null, fm, null, options, null, files);
        boolean ok = t.call();
        if (!ok)
            throw new Exception("processing failed");
    }

    Filer filer;
    Messager messager;
    Trees trees;

    @Override
    public SourceVersion getSupportedSourceVersion() {
        return SourceVersion.latest();
    }

    @Override
    public void init(ProcessingEnvironment pEnv) {
        super.init(pEnv);
        filer = pEnv.getFiler();
        messager = pEnv.getMessager();
        trees = Trees.instance(pEnv);
    }

    int round = 0;

    @Override
    public boolean process(Set<? extends TypeElement> annotations, RoundEnvironment roundEnv) {
        round++;

        
        for (Element e: roundEnv.getRootElements()) {
            try {
                TreePath p = trees.getPath(e);
                new TestTreeScanner(p.getCompilationUnit(), trees).scan(trees.getPath(e), null);
            } catch (IOException ex) {
                messager.printMessage(Diagnostic.Kind.ERROR,
                        "Cannot get source: " + ex, e);
            }
        }

        final int MAXROUNDS = 3;
        if (round < MAXROUNDS)
            generateSource("Gen" + round);

        return true;
    }

    void generateSource(String name) {
        StringBuilder text = new StringBuilder();
        text.append("class ").append(name).append("{\n");
        text.append("    int one = 1;\n");
        text.append("    int two = 2;\n");
        text.append("    int three = one + two;\n");
        text.append("}\n");

        try {
            JavaFileObject fo = filer.createSourceFile(name);
            Writer out = fo.openWriter();
            try {
                out.write(text.toString());
            } finally {
                out.close();
            }
        } catch (IOException e) {
            throw new Error(e);
        }
    }

    class TestTreeScanner extends TreePathScanner<Void,Void> {
        TestTreeScanner(CompilationUnitTree unit, Trees trees) throws IOException {
            this.unit = unit;
            JavaFileObject sf = unit.getSourceFile();
            source = sf.getCharContent(true).toString();
            sourcePositions = trees.getSourcePositions();
        }

        @Override
        public Void visitVariable(VariableTree tree, Void _) {
            check(getCurrentPath());
            return super.visitVariable(tree, _);
        }

        void check(TreePath tp) {
            Tree tree = tp.getLeaf();

            String expect = tree.toString();
            if (tree.getKind() == Tree.Kind.VARIABLE) {
                
                
                Tree.Kind enclKind = tp.getParentPath().getLeaf().getKind();
                
                if (enclKind == Tree.Kind.CLASS || enclKind == Tree.Kind.BLOCK)
                    expect += ";";
            }
            

            int start = (int)sourcePositions.getStartPosition(unit, tree);
            if (start == Diagnostic.NOPOS) {
                messager.printMessage(Diagnostic.Kind.ERROR, "start pos not set for " + trim(tree));
                return;
            }

            int end = (int)sourcePositions.getEndPosition(unit, tree);
            if (end == Diagnostic.NOPOS) {
                messager.printMessage(Diagnostic.Kind.ERROR, "end pos not set for " + trim(tree));
                return;
            }

            String found = source.substring(start, end);
            

            
            
            boolean equal;
            if (found.contains("\n")) {
                String head = found.substring(0, found.indexOf("\n"));
                String tail = found.substring(found.lastIndexOf("\n")).trim();
                equal = expect.startsWith(head) && expect.endsWith(tail);
            } else {
                equal = expect.equals(found);
            }

            if (!equal) {
                messager.printMessage(Diagnostic.Kind.ERROR,
                        "unexpected value found: '" + found + "'; expected: '" + expect + "'");
            }
        }

        String trim(Tree tree) {
            final int MAXLEN = 32;
            String s = tree.toString().replaceAll("\\s+", " ").trim();
            return (s.length() < MAXLEN) ? s : s.substring(0, MAXLEN);

        }

        CompilationUnitTree unit;
        SourcePositions sourcePositions;
        String source;
    }

}
