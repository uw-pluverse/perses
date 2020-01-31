
import com.sun.source.tree.CompilationUnitTree;
import com.sun.source.tree.IdentifierTree;
import com.sun.source.tree.MemberSelectTree;
import com.sun.source.util.JavacTask;
import com.sun.source.util.TreePathScanner;
import com.sun.source.util.Trees;
import com.sun.tools.javac.api.JavacTool;
import com.sun.tools.javac.file.JavacFileManager;
import java.io.File;
import java.io.IOException;
import java.net.URISyntaxException;
import java.util.Collections;
import javax.lang.model.element.Element;
import javax.lang.model.element.ElementKind;

public class VerifyAnnotationsAttributed {
    public static void main(String... args) throws IOException, URISyntaxException {
        if (args.length != 1) throw new IllegalStateException("Must provide class name!");
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
        task.analyze();

        
        
        
        new TreePathScanner<Void, Void>() {
            @Override
            public Void visitIdentifier(IdentifierTree node, Void p) {
                verifyAttributedMeaningfully();
                return super.visitIdentifier(node, p);
            }
            @Override
            public Void visitMemberSelect(MemberSelectTree node, Void p) {
                verifyAttributedMeaningfully();
                return super.visitMemberSelect(node, p);
            }
            private void verifyAttributedMeaningfully() {
                Element el = trees.getElement(getCurrentPath());

                if (el == null || el.getKind() == ElementKind.OTHER) {
                    throw new IllegalStateException("Not attributed properly: " + getCurrentPath().getParentPath().getLeaf());
                }
            }
        }.scan(cut, null);
    }
}
