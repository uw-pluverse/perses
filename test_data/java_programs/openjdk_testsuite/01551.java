

import java.util.*;

import javax.annotation.processing.*;
import javax.lang.model.*;
import javax.lang.model.element.*;

import com.sun.source.doctree.DocCommentTree;
import com.sun.source.doctree.ErroneousTree;
import com.sun.source.tree.ClassTree;
import com.sun.source.tree.MethodTree;
import com.sun.source.tree.VariableTree;
import com.sun.source.util.DocTreeScanner;
import com.sun.source.util.DocTrees;
import com.sun.source.util.TreePath;
import com.sun.source.util.TreePathScanner;
import com.sun.source.util.TreeScanner;
import com.sun.tools.javac.tree.DocPretty;
import java.io.PrintWriter;
import javax.tools.Diagnostic;


@SupportedAnnotationTypes("*")
public class DocCommentProcessor extends AbstractProcessor {
    @Override
    public SourceVersion getSupportedSourceVersion() {
        return SourceVersion.latest();
    }

    @Override
    public void init(ProcessingEnvironment pEnv) {
        super.init(pEnv);
        trees = DocTrees.instance(pEnv);
        messager = pEnv.getMessager();
    }

    @Override
    public boolean process(Set<? extends TypeElement> annos, RoundEnvironment rEnv) {
        for (Element e : rEnv.getRootElements()) {
            new DocCommentScanner().scan(e);
        }
        return true;
    }

    class DocCommentScanner extends TreePathScanner<Void,Void> {
        public void scan(Element e) {
            scan(trees.getPath(e), null);
        }

        @Override
        public Void visitClass(ClassTree tree, Void ignore) {
            check();
            return super.visitClass(tree, ignore);
        }

        @Override
        public Void visitMethod(MethodTree tree, Void ignore) {
            check();
            return super.visitMethod(tree, ignore);
        }

        @Override
        public Void visitVariable(VariableTree tree, Void ignore) {
            check();
            return super.visitVariable(tree, ignore);
        }

        private void check() {
            DocCommentTree dc = trees.getDocCommentTree(getCurrentPath());
            if (dc == null)
                return;

            DocTreeScanner<Void, Void> s = new DocTreeScanner<Void, Void>() {
                @Override
                public Void visitErroneous(ErroneousTree tree, Void ignore) {
                    messager.printMessage(Diagnostic.Kind.NOTE, tree.getDiagnostic().getMessage(null));
                    return null;
                }
            };

            s.scan(dc, null);
        }

    }

    private DocTrees trees;
    private Messager messager;
}
