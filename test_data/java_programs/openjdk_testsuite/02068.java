



import com.sun.source.tree.IdentifierTree;
import com.sun.source.tree.MemberSelectTree;
import com.sun.source.tree.Tree;
import com.sun.source.util.JavacTask;
import com.sun.source.util.TreeScanner;
import com.sun.tools.javac.api.JavacTaskImpl;
import com.sun.tools.javac.api.JavacTool;
import com.sun.tools.javac.code.Symtab;
import com.sun.tools.javac.tree.TreeMaker;
import com.sun.tools.javac.util.Context;
import java.util.ArrayList;

public class MakeQualIdent {
    public static void main(String... args) throws Exception {
        JavacTool tool = JavacTool.create();
        JavacTask task = tool.getTask(null, null, null, new ArrayList<String>(), null, null);
        Context ctx = ((JavacTaskImpl)task).getContext();
        TreeMaker treeMaker = TreeMaker.instance(ctx);
        Symtab syms = Symtab.instance(ctx);

        String stringTree = printTree(treeMaker.QualIdent(syms.stringType.tsym));

        if (!"java.lang.String".equals(stringTree)) {
            throw new IllegalStateException(stringTree);
        }
    }

    private static String printTree(Tree tree) {
        final StringBuilder result = new StringBuilder();

        new TreeScanner<Void, Void>() {
            @Override public Void visitIdentifier(IdentifierTree node, Void p) {
                result.append(node.getName());
                return super.visitIdentifier(node, p);
            }
            @Override public Void visitMemberSelect(MemberSelectTree node, Void p) {
                scan(node.getExpression(), null);
                result.append(".");
                result.append(node.getIdentifier());
                return null;
            }
        }.scan(tree, null);

        return result.toString();
    }
}
