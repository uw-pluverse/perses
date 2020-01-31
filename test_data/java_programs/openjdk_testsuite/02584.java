


import java.io.File;
import java.io.IOException;
import java.lang.annotation.ElementType;
import java.lang.annotation.Target;
import java.net.URI;
import java.net.URISyntaxException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashSet;
import java.util.List;
import java.util.Set;
import javax.tools.Diagnostic;
import javax.tools.DiagnosticCollector;
import javax.tools.JavaFileObject;
import javax.tools.SimpleJavaFileObject;
import com.sun.source.tree.AnnotationTree;
import com.sun.source.tree.CompilationUnitTree;
import com.sun.source.tree.IdentifierTree;
import com.sun.source.tree.Tree.Kind;
import com.sun.source.util.JavacTask;
import com.sun.source.util.TreePathScanner;
import com.sun.source.util.Trees;
import com.sun.tools.javac.api.JavacTool;
import com.sun.tools.javac.file.JavacFileManager;


public class CheckErrorsForSource7 {
    public static void main(String... args) throws IOException, URISyntaxException {
        new CheckErrorsForSource7().run(args);
    }

    private void run(String... args) throws IOException, URISyntaxException {
        
        if (args.length != 1) throw new IllegalStateException("Must provide source file!");
        File testSrc = new File(System.getProperty("test.src"));
        File testFile = new File(testSrc, args[0]);
        if (!testFile.canRead()) throw new IllegalStateException("Cannot read the test source");
        JavacFileManager fm = JavacTool.create().getStandardFileManager(null, null, null);

        
        JavacTask task = JavacTool.create().getTask(null,
                                                    fm,
                                                    null,
                                                    Collections.<String>emptyList(),
                                                    null,
                                                    fm.getJavaFileObjects(testFile));
        final Trees trees = Trees.instance(task);
        final CompilationUnitTree cut = task.parse().iterator().next();
        final List<int[]> typeAnnotationSpans = new ArrayList<>();

        new TreePathScanner<Void, Void>() {
            @Override
            public Void visitAnnotation(AnnotationTree node, Void p) {
                if (node.getAnnotationType().getKind() == Kind.IDENTIFIER &&
                    ((IdentifierTree) node.getAnnotationType()).getName().contentEquals("TA")) {
                    int start = (int) trees.getSourcePositions().getStartPosition(cut, node);
                    int end = (int) trees.getSourcePositions().getEndPosition(cut, node);
                    typeAnnotationSpans.add(new int[] {start, end});
                }
                return null;
            }
        }.scan(cut, null);

        
        Collections.sort(typeAnnotationSpans, new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                return o2[0] - o1[0];
            }
        });

        
        String originalSource = cut.getSourceFile().getCharContent(false).toString();

        for (int[] toKeep : typeAnnotationSpans) {
            
            String updated = originalSource;

            for (int[] span : typeAnnotationSpans) {
                if (span == toKeep) continue;

                updated = updated.substring(0, span[0]) + updated.substring(span[1]);
            }

            
            JavaFileObject updatedFile = new TestFO(cut.getSourceFile().toUri(), updated);
            DiagnosticCollector<JavaFileObject> errors = new DiagnosticCollector<>();
            JavacTask task2 = JavacTool.create().getTask(null,
                                                         fm,
                                                         errors,
                                                         Arrays.asList("-source", "7"),
                                                         null,
                                                         Arrays.asList(updatedFile));
            task2.parse();

            boolean found = false;

            for (Diagnostic<? extends JavaFileObject> d : errors.getDiagnostics()) {
                if (d.getKind() == Diagnostic.Kind.ERROR && EXPECTED_ERRORS.contains(d.getCode())) {
                    if (found) {
                        throw new IllegalStateException("More than one expected error found.");
                    }
                    found = true;
                }
            }

            if (!found)
                throw new IllegalStateException("Did not produce proper errors for: " + updated);
        }
    }

    static final Set<String> EXPECTED_ERRORS = new HashSet<>(Arrays.asList(
        "compiler.err.type.annotations.not.supported.in.source",
        "compiler.err.annotations.after.type.params.not.supported.in.source"
    ));

    class TestFO extends SimpleJavaFileObject {
        private final String content;
        public TestFO(URI uri, String content) {
            super(uri, Kind.SOURCE);
            this.content = content;
        }

        @Override public CharSequence getCharContent(boolean ignoreEncodingErrors) throws IOException {
            return content;
        }

        @Override public boolean isNameCompatible(String simpleName, Kind kind) {
            return true;
        }
    }
}


class CheckErrorsForSource7Data {
    @Target(ElementType.TYPE_USE)
    @interface TA { }

    Object n1 = new @TA ArrayList<@TA String>();
    Object n2 = new @TA Object() {};
    Object [] @TA [] arr @TA[];
    <T> @TA int @TA[] ret(Object obj) @TA[] throws @TA Exception {
        this.<@TA String>ret(null);
        Object c1 = new @TA String[1];

        int val = obj instanceof @TA String ? ((@TA String) obj).length() : 0;
        List<@TA ?> l;
        return null;
    }
    void vararg(String @TA ... args) { }

    abstract class C<@TA T extends @TA Number & @TA Runnable>
               extends @TA ArrayList<@TA String>
               implements java.util. @TA Comparator<@TA T> { }

    interface I extends java.util. @TA Comparator<@TA String> { }

}
