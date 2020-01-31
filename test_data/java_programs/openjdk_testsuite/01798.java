



import java.io.*;
import java.net.URISyntaxException;
import java.util.*;
import javax.tools.*;
import javax.tools.JavaCompiler.CompilationTask;
import com.sun.source.tree.*;
import com.sun.source.util.*;

public class T6956462 {
    public static void main(String[] args) throws Exception {
        JavaCompiler compiler = ToolProvider.getSystemJavaCompiler();
        if (compiler == null) {
            throw new RuntimeException("can't get javax.tools.JavaCompiler!");
        }
        StandardJavaFileManager fm = compiler.getStandardFileManager(null, null, null);
        List<File> files = new ArrayList<File>();
        files.add(new File(T6956462.class.getResource("TestClass.java").toURI()));
        final CompilationTask task = compiler.getTask(null, fm, null,
            null, null, fm.getJavaFileObjectsFromFiles(files));
        JavacTask javacTask = (JavacTask) task;
        for (CompilationUnitTree cu : javacTask.parse()) {
            cu.accept(new MyVisitor(javacTask), null);
        }
    }

    private static class MyVisitor extends SimpleTreeVisitor<Tree, Void> {
        private final Trees trees;
        private CompilationUnitTree file;

        private MyVisitor(JavacTask javac) {
            this.trees = Trees.instance(javac);
        }

        @Override
        public Tree visitCompilationUnit(CompilationUnitTree file, Void v) {
            this.file = file;
            for (Tree typeDecl : file.getTypeDecls()) {
                typeDecl.accept(this, v);
            }
            return null;
        }

        @Override
        public Tree visitImport(ImportTree imp, Void v) {
            return null;
        }

        @Override
        public Tree visitMethodInvocation(MethodInvocationTree invoke, Void v) {
            invoke.getMethodSelect().accept(this, v);
            return null;
        }

        @Override
        public Tree visitBlock(BlockTree block, Void v) {
            for (StatementTree stat : block.getStatements()) {
                stat.accept(this, v);
            }
            return null;
        }

        @Override
        public Tree visitClass(ClassTree clazz, Void v) {
            for (Tree member : clazz.getMembers()) {
                member.accept(this, v);
            }
            return null;
        }

        @Override
        public Tree visitIdentifier(IdentifierTree ident, Void v) {
            trees.getScope(trees.getPath(file, ident));
            return null;
        }

        @Override
        public Tree visitMethod(MethodTree method, Void v) {
            method.getBody().accept(this, v);
            return null;
        }

        @Override
        public Tree visitMemberSelect(MemberSelectTree select, Void v) {
            select.getExpression().accept(this, v);
            return null;
        }

        @Override
        public Tree visitVariable(VariableTree var, Void v) {
            var.getInitializer().accept(this, v);
            return null;
        }
    }
}
