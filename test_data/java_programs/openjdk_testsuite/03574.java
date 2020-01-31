



import java.io.File;
import java.io.IOException;
import java.lang.annotation.ElementType;
import java.lang.annotation.Target;
import java.nio.file.Paths;
import java.util.Arrays;

import javax.tools.JavaCompiler;
import javax.tools.JavaFileObject;
import javax.tools.StandardJavaFileManager;
import javax.tools.ToolProvider;

import com.sun.source.tree.CompilationUnitTree;
import com.sun.source.tree.Tree;
import com.sun.source.util.JavacTask;
import com.sun.source.util.TaskEvent;
import com.sun.source.util.TaskListener;
import com.sun.tools.classfile.ClassFile;
import com.sun.tools.classfile.Method;
import com.sun.tools.javac.api.BasicJavacTask;
import com.sun.tools.javac.code.Attribute.Compound;
import com.sun.tools.javac.code.Symbol.ClassSymbol;
import com.sun.tools.javac.code.Symbol.VarSymbol;
import com.sun.tools.javac.tree.JCTree;
import com.sun.tools.javac.tree.TreeScanner;
import com.sun.tools.javac.util.Assert;
import com.sun.tools.javac.util.Context;
import com.sun.tools.javac.util.List;
import com.sun.tools.javac.util.Names;

public class ParameterNamesAreNotCopiedToAnonymousInitTest {

    static final String noParamsErrorMsg =
            "Test most be invoked with at least one parameter: check_class_file " +
            "and/or check_init_symbol";
    static final String wrongParamsErrorMsg =
            "Accepted arguments are: check_class_file and check_init_symbol";
    static final String paramNameNotCopiedAssertionMsg =
            "The param name hasn't been copied to the init method";
    static final String noAnnotationsForParameterMsg =
            "No annotations for seek parameter";
    static final String seekMethodNotFound =
            "The seek init method was not found or conditions were not met";
    static final String nonNullParamPositionsMsg =
            "Parameter positions shold not be null";
    static final String compilationFailed =
            "Compilation failed";
    static final String seekMethodNotFoundMsg =
        "The seek method was not found";

    static final String ParamAnnotationClassName =
            ParameterNamesAreNotCopiedToAnonymousInitTest.class.getSimpleName() + "." +
            ParamAnnotation.class.getSimpleName();

    public static void main(String[] args) throws Exception {
        if (args.length == 0) {
            throw new Error(noParamsErrorMsg);
        }
        new ParameterNamesAreNotCopiedToAnonymousInitTest().run(args);
    }

    void run(String[] args) throws Exception {
        for (String arg : args) {
            if (arg.equals("check_class_file")) {
                checkClassFile(new File(Paths.get(System.getProperty("test.classes"),
                        this.getClass().getName() + "$initParams$1.class").toUri()), 1);
                checkClassFile(new File(Paths.get(System.getProperty("test.classes"),
                        this.getClass().getName() + "$Generics$1.class").toUri()), 2);
            } else if (arg.equals("check_init_symbol")) {
                checkInitSymbol("m1", Arrays.asList(0), Arrays.asList("i"));
                checkInitSymbol("m2", Arrays.asList(0, 1), Arrays.asList("t1", "t2"));
            } else {
                error(wrongParamsErrorMsg);
            }
        }
    }

    void checkClassFile(final File cfile, int numberOfParams) throws Exception {
        ClassFile classFile = ClassFile.read(cfile);
        boolean methodFound = false;
        for (Method method : classFile.methods) {
            if (method.getName(classFile.constant_pool).equals("<init>")) {
                methodFound = true;
            }
        }
        Assert.check(methodFound, seekMethodNotFoundMsg);
    }

    
    void checkInitSymbol(
            final String classOwnerName,
            final java.util.List<Integer> paramsToCheck,
            final java.util.List<String> paramNames)
            throws IOException {
        Assert.checkNonNull(paramsToCheck, nonNullParamPositionsMsg);
        JavaCompiler c = ToolProvider.getSystemJavaCompiler();
        StandardJavaFileManager fm = c.getStandardFileManager(null, null, null);
        Iterable<? extends JavaFileObject> fos =
                fm.getJavaFileObjectsFromFiles(
                Arrays.asList(new File(System.getProperty("test.src"),
                this.getClass().getName() + ".java")));
        JavacTask task = (JavacTask) c.getTask(null, fm, null,
                Arrays.asList("-d", System.getProperty("user.dir")), null, fos);

        BasicJavacTask impl = (BasicJavacTask)task;
        Context context = impl.getContext();
        final Names names = Names.instance(context);

        task.addTaskListener(new TaskListener() {

            @Override
            public void started(TaskEvent e) {}

            @Override
            public void finished(TaskEvent e) {
                class TheTreeScanner extends TreeScanner {
                    boolean foundAndCorrect = false;

                    @Override
                    public void visitMethodDef(JCTree.JCMethodDecl tree) {
                        ClassSymbol clazz = (ClassSymbol)tree.sym.owner;
                        if (clazz.owner.name.toString().equals(classOwnerName) &&
                            tree.sym.name == names.init) {

                            int currentParamPos = 0;
                            int paramArrayIndex = 0;

                            List<VarSymbol> params = tree.sym.params;
                            while (params.nonEmpty() && paramArrayIndex < paramsToCheck.size()) {
                                VarSymbol param = params.head;
                                if (currentParamPos == paramsToCheck.get(paramArrayIndex)) {
                                    if (!param.name.toString()
                                            .equals(paramNames.get(paramArrayIndex))) {
                                        error(paramNameNotCopiedAssertionMsg);
                                    }
                                    paramArrayIndex++;
                                }
                                currentParamPos++;
                                params = params.tail;
                            }
                            foundAndCorrect = paramArrayIndex >= paramsToCheck.size();
                        }
                        super.visitMethodDef(tree);
                    }
                }

                if (e.getKind() == TaskEvent.Kind.ANALYZE) {
                    CompilationUnitTree compUnitTree = e.getCompilationUnit();
                    boolean foundAndCorrect = false;
                    for (Tree tree : compUnitTree.getTypeDecls()) {
                        TheTreeScanner scanner = new TheTreeScanner();
                        scanner.scan((JCTree) tree);
                        foundAndCorrect = foundAndCorrect | scanner.foundAndCorrect;
                    }
                    if (!foundAndCorrect) {
                        error(seekMethodNotFound);
                    }
                }
            }
        });

        if (!task.call()) {
            error(compilationFailed);
        }
    }

    void error(String msg) {
        throw new AssertionError(msg);
    }

    @Target(value = {ElementType.PARAMETER})
    @interface ParamAnnotation {}

    
    public class initParams {
        public initParams(@ParamAnnotation int i) {}

        public void m1() {
            new initParams(2) {};
        }
    }

    class Generics<T1> {
        T1 obj1;
        Object obj2;
        <T2> Generics(@ParamAnnotation T1 t1, @ParamAnnotation T2 t2) {
            obj1 = t1;
            obj2 = t2;
        }

        void m2() {
            Generics<Integer> a = new <String>Generics<Integer>(
                    new Integer(11), "foo") {};
        }
    }
}
