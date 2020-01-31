



import com.sun.source.doctree.DocCommentTree;
import com.sun.source.doctree.DocTree;
import com.sun.source.doctree.LinkTree;
import com.sun.source.doctree.ReferenceTree;
import com.sun.source.doctree.SeeTree;
import com.sun.source.doctree.TextTree;
import com.sun.source.util.DocTreePath;
import com.sun.source.util.DocTreePathScanner;
import com.sun.source.util.DocTreeScanner;
import com.sun.source.util.DocTrees;
import com.sun.source.util.TreePath;

import java.util.List;
import java.util.Set;
import javax.annotation.processing.AbstractProcessor;
import javax.annotation.processing.ProcessingEnvironment;
import javax.annotation.processing.RoundEnvironment;
import javax.annotation.processing.SupportedAnnotationTypes;
import javax.lang.model.SourceVersion;
import javax.lang.model.element.Element;
import javax.lang.model.element.TypeElement;
import javax.tools.Diagnostic.Kind;


@SupportedAnnotationTypes("*")
public class ReferenceTest extends AbstractProcessor {
    DocTrees trees;

    @Override
    public SourceVersion getSupportedSourceVersion() {
        return SourceVersion.latest();
    }

    @Override
    public void init(ProcessingEnvironment pEnv) {
        super.init(pEnv);
        trees = DocTrees.instance(pEnv);
    }

    @Override
    public boolean process(Set<? extends TypeElement> annotations, RoundEnvironment roundEnv) {
        for (Element e: roundEnv.getRootElements()) {
            new DocCommentScanner(trees.getPath(e)).scan();
        }
        return true;
    }

    class DocCommentScanner extends DocTreePathScanner<Void, Void> {
        TreePath path;
        DocCommentTree dc;

        DocCommentScanner(TreePath path) {
            this.path = path;
        }

        void scan() {
            dc = trees.getDocCommentTree(path);
            scan(new DocTreePath(path, dc), null);
        }

        @Override
        public Void visitLink(LinkTree tree, Void ignore) {
            checkReference(tree.getReference(), tree.getLabel());
            return null;
        }

        @Override
        public Void visitSee(SeeTree tree, Void ignore) {
            List<? extends DocTree> refLabel = tree.getReference();
            if (refLabel.size() > 1 && (refLabel.get(0) instanceof ReferenceTree)) {
                ReferenceTree ref = (ReferenceTree) refLabel.get(0);
                List<? extends DocTree> label = refLabel.subList(1, refLabel.size());
                checkReference(ref, label);
            }
            return null;
        }

        void checkReference(ReferenceTree tree, List<? extends DocTree> label) {
            String sig = tree.getSignature();

            Element found = trees.getElement(new DocTreePath(getCurrentPath(), tree));
            if (found == null) {
                System.err.println(sig + " NOT FOUND");
            } else {
                System.err.println(sig + " found " + found.getKind() + " " + found);
            }

            String expect = "UNKNOWN";
            if (label.size() > 0 && label.get(0) instanceof TextTree)
                expect = ((TextTree) label.get(0)).getBody();

            if (!expect.equalsIgnoreCase(found == null ? "bad" : found.getKind().name())) {
                error(tree, "Unexpected value found: " + found +", expected: " + expect);
            }
        }

        void error(DocTree tree, String msg) {
            trees.printMessage(Kind.ERROR, msg, tree, dc, path.getCompilationUnit());
        }
    }
}


class ReferenceTestExtras {
    int ReferenceTestExtras;            
    ReferenceTestExtras() { }           
    void ReferenceTestExtras() { }      

    int X;
    void X() { }
    static class X { }

    void m() { }
    void m(int i) { }
    void m(int i, int j) { }

    void varargs(int... args) { }
}


