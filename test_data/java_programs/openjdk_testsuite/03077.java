






import java.io.IOException;
import java.net.URI;
import java.util.Arrays;
import javax.tools.Diagnostic;
import javax.tools.JavaCompiler;
import javax.tools.JavaFileObject;
import javax.tools.SimpleJavaFileObject;
import javax.tools.ToolProvider;
import com.sun.source.util.JavacTask;

public class FunctionalInterfaceConversionTest
    extends JavacTestingAbstractThreadedTest
    implements Runnable {

    enum PackageKind {
        NO_PKG(""),
        PKG_A("a");

        String pkg;

        PackageKind(String pkg) {
            this.pkg = pkg;
        }

        String getPkgDecl() {
            return this == NO_PKG ?
                "" :
                "package " + pkg + ";";
        }

        String getImportStat() {
            return this == NO_PKG ?
                "" :
                "import " + pkg + ".*;";
        }
    }

    enum SamKind {
        CLASS("public class Sam {  }"),
        ABSTACT_CLASS("public abstract class Sam {  }"),
        ANNOTATION("public @interface Sam {  }"),
        ENUM("public enum Sam { }"),
        INTERFACE("public interface Sam { \n #METH; \n }");

        String sam_str;

        SamKind(String sam_str) {
            this.sam_str = sam_str;
        }

        String getSam(String methStr) {
            return sam_str.replaceAll("#METH", methStr);
        }
    }

    enum ModifierKind {
        PUBLIC("public"),
        PACKAGE("");

        String modifier_str;

        ModifierKind(String modifier_str) {
            this.modifier_str = modifier_str;
        }

        boolean stricterThan(ModifierKind that) {
            return this.ordinal() > that.ordinal();
        }
    }

    enum TypeKind {
        EXCEPTION("Exception"),
        PKG_CLASS("PackageClass");

        String typeStr;

        private TypeKind(String typeStr) {
            this.typeStr = typeStr;
        }
    }

    enum ExprKind {
        LAMBDA("x -> null"),
        MREF("this::m");

        String exprStr;

        private ExprKind(String exprStr) {
            this.exprStr = exprStr;
        }
    }

    enum MethodKind {
        NONE(""),
        NON_GENERIC("public abstract #R m(#ARG s) throws #T;"),
        GENERIC("public abstract <X> #R m(#ARG s) throws #T;");

        String methodTemplate;

        private MethodKind(String methodTemplate) {
            this.methodTemplate = methodTemplate;
        }

        String getMethod(TypeKind retType, TypeKind argType, TypeKind thrownType) {
            return methodTemplate.replaceAll("#R", retType.typeStr).
                    replaceAll("#ARG", argType.typeStr).
                    replaceAll("#T", thrownType.typeStr);
        }
    }

    public static void main(String[] args) throws Exception {
        for (PackageKind samPkg : PackageKind.values()) {
            for (ModifierKind modKind : ModifierKind.values()) {
                for (SamKind samKind : SamKind.values()) {
                    for (MethodKind samMeth : MethodKind.values()) {
                        for (MethodKind clientMeth : MethodKind.values()) {
                            for (TypeKind retType : TypeKind.values()) {
                                for (TypeKind argType : TypeKind.values()) {
                                    for (TypeKind thrownType : TypeKind.values()) {
                                        for (ExprKind exprKind : ExprKind.values()) {
                                            pool.execute(
                                                new FunctionalInterfaceConversionTest(
                                                    samPkg, modKind, samKind,
                                                    samMeth, clientMeth, retType,
                                                    argType, thrownType, exprKind));
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        checkAfterExec(false);
    }

    PackageKind samPkg;
    ModifierKind modKind;
    SamKind samKind;
    MethodKind samMeth;
    MethodKind clientMeth;
    TypeKind retType;
    TypeKind argType;
    TypeKind thrownType;
    ExprKind exprKind;
    DiagnosticChecker dc;

    SourceFile samSourceFile = new SourceFile("Sam.java", "#P \n #C") {
        @Override
        public String toString() {
            return template.replaceAll("#P", samPkg.getPkgDecl()).
                    replaceAll("#C", samKind.getSam(
                    samMeth.getMethod(retType, argType, thrownType)));
        }
    };

    SourceFile pkgClassSourceFile =
            new SourceFile("PackageClass.java",
                           "#P\n #M class PackageClass extends Exception { }") {
        @Override
        public String toString() {
            return template.replaceAll("#P", samPkg.getPkgDecl()).
                    replaceAll("#M", modKind.modifier_str);
        }
    };

    SourceFile clientSourceFile =
            new SourceFile("Client.java",
                           "#I\n abstract class Client { \n" +
                           "  Sam s = #E;\n" +
                           "  #M \n }") {
        @Override
        public String toString() {
            return template.replaceAll("#I", samPkg.getImportStat())
                    .replaceAll("#E", exprKind.exprStr)
                    .replaceAll("#M", clientMeth.getMethod(retType, argType, thrownType));
        }
    };

    FunctionalInterfaceConversionTest(PackageKind samPkg, ModifierKind modKind,
            SamKind samKind, MethodKind samMeth, MethodKind clientMeth,
            TypeKind retType, TypeKind argType, TypeKind thrownType,
            ExprKind exprKind) {
        this.samPkg = samPkg;
        this.modKind = modKind;
        this.samKind = samKind;
        this.samMeth = samMeth;
        this.clientMeth = clientMeth;
        this.retType = retType;
        this.argType = argType;
        this.thrownType = thrownType;
        this.exprKind = exprKind;
        this.dc = new DiagnosticChecker();
    }

    @Override
    public void run() {
        final JavaCompiler tool = ToolProvider.getSystemJavaCompiler();

        JavacTask ct = (JavacTask)tool.getTask(null, fm.get(), dc, null, null,
                Arrays.asList(samSourceFile, pkgClassSourceFile, clientSourceFile));
        try {
            ct.analyze();
        } catch (IOException ex) {
            throw new AssertionError("Test failing with cause", ex.getCause());
        }
        if (dc.errorFound == checkSamConversion()) {
            throw new AssertionError(samSourceFile + "\n\n" +
                pkgClassSourceFile + "\n\n" + clientSourceFile);
        }
    }

    boolean checkSamConversion() {
        if (samKind != SamKind.INTERFACE) {
            
            return false;
        } else if (samMeth == MethodKind.NONE) {
            
            return false;
        } else if (exprKind == ExprKind.LAMBDA &&
                samMeth != MethodKind.NON_GENERIC) {
            
            return false;
        } else if (exprKind == ExprKind.MREF &&
                clientMeth == MethodKind.NONE) {
            return false;
        } else if (samPkg != PackageKind.NO_PKG &&
                modKind != ModifierKind.PUBLIC &&
                (retType == TypeKind.PKG_CLASS ||
                argType == TypeKind.PKG_CLASS ||
                thrownType == TypeKind.PKG_CLASS)) {
            
            return false;
        } else {
            return true;
        }
    }

    abstract class SourceFile extends SimpleJavaFileObject {

        protected String template;

        public SourceFile(String filename, String template) {
            super(URI.create("myfo:/" + filename), JavaFileObject.Kind.SOURCE);
            this.template = template;
        }

        @Override
        public CharSequence getCharContent(boolean ignoreEncodingErrors) {
            return toString();
        }

        @Override
        public abstract String toString();
    }

    static class DiagnosticChecker
        implements javax.tools.DiagnosticListener<JavaFileObject> {

        boolean errorFound = false;

        @Override
        public void report(Diagnostic<? extends JavaFileObject> diagnostic) {
            if (diagnostic.getKind() == Diagnostic.Kind.ERROR) {
                errorFound = true;
            }
        }
    }
}
