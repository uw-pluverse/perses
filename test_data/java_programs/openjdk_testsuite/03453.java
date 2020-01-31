



import com.sun.source.doctree.DocCommentTree;
import com.sun.source.doctree.DocTree;
import com.sun.source.tree.MethodTree;
import com.sun.source.util.DocSourcePositions;
import com.sun.source.util.DocTreeScanner;
import com.sun.source.util.DocTrees;
import com.sun.source.util.TreePath;
import com.sun.source.util.TreePathScanner;
import java.io.IOException;
import java.util.Set;
import javax.annotation.processing.*;
import javax.lang.model.*;
import javax.lang.model.element.*;

@SupportedAnnotationTypes("*")
public class TestPosition extends AbstractProcessor {

    @Override
    public boolean process(Set<? extends TypeElement> annotations, RoundEnvironment roundEnv) {
        TypeElement source = processingEnv.getElementUtils().getTypeElement("TestPositionSource");

        if (source == null) throw new IllegalStateException();

        if (!roundEnv.getRootElements().contains(source)) return false;

        final DocTrees trees = DocTrees.instance(processingEnv);
        final TreePath testElement = trees.getPath(source);

        if (testElement == null) throw new IllegalStateException();

        String code;

        try {
            code = testElement.getCompilationUnit().getSourceFile().getCharContent(false).toString();
        } catch ( IOException ex) {
            throw new IllegalStateException(ex);
        }

        new TreePathScanner<Void, Void>() {
            @Override public Void visitMethod(MethodTree node, Void p) {
                final DocCommentTree docCommentTree = trees.getDocCommentTree(getCurrentPath());

                if (docCommentTree != null) {
                    System.out.println(node.getName() + ":");
                    new DocTreeScanner<Void, Void>() {
                        @Override public Void scan(DocTree node, Void p) {
                            if (node != null) {
                                DocSourcePositions sp = (DocSourcePositions) trees.getSourcePositions(); 
                                int start = (int) sp.getStartPosition(testElement.getCompilationUnit(), docCommentTree, node);
                                int end   = (int) sp.getEndPosition(testElement.getCompilationUnit(), docCommentTree, node);
                                String snippet = code.substring(start, end).replace(" \n", "!trailing-whitespace!\n");

                                if (snippet.endsWith(" ")) {
                                    snippet = snippet.substring(0, snippet.length() - 1) + "!trailing-whitespace!";
                                }
                                System.out.println(node.getKind().name() + ":" + snippet);
                            }
                            return super.scan(node, p);
                        }
                    }.scan(docCommentTree, null);
                }

                return super.visitMethod(node, p);
            }
        }.scan(testElement, null);

        return false;
    }

    @Override
    public SourceVersion getSupportedSourceVersion() {
        return SourceVersion.latest();
    }
}
