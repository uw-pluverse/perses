



import java.util.Set;
import javax.annotation.processing.*;
import javax.lang.model.SourceVersion;
import static javax.lang.model.SourceVersion.*;
import javax.lang.model.element.*;
import javax.lang.model.util.*;
import static javax.lang.model.util.ElementFilter.*;
import static javax.tools.Diagnostic.Kind.*;
import static javax.tools.StandardLocation.*;


public class TestPackageElement extends JavacTestingAbstractProcessor {
    public boolean process(Set<? extends TypeElement> annotations,
                           RoundEnvironment roundEnv) {
        if (!roundEnv.processingOver()) {
            PackageElement unnamedPkg = eltUtils.getPackageElement("");

            if (!unnamedPkg.getQualifiedName().contentEquals(""))
                throw new RuntimeException("The unnamed package is named!");

            
            
            if (!unnamedPkg.toString().equals("unnamed package"))
                throw new RuntimeException(
                                "toString on unnamed package: " + unnamedPkg);

            if (!unnamedPkg.isUnnamed())
                throw new RuntimeException("The isUnnamed method on the unnamed package returned false!");

            PackageElement javaLang = eltUtils.getPackageElement("java.lang");
            if (javaLang.isUnnamed())
                throw new RuntimeException("Package java.lang is unnamed!");
        }
        return true;
    }
}
