

import java.lang.annotation.*;
import java.util.*;
import javax.annotation.processing.*;
import javax.lang.model.element.*;
import javax.lang.model.type.DeclaredType;
import javax.lang.model.type.MirroredTypeException;
import javax.lang.model.type.TypeMirror;
import javax.lang.model.type.TypeKind;
import javax.tools.*;

import com.sun.tools.javac.util.Assert;
import com.sun.tools.javac.code.Symbol;
import static com.sun.tools.javac.code.Symbol.TypeSymbol;

public class Processor extends JavacTestingAbstractProcessor {

    @Override
    public boolean process(Set<? extends TypeElement> annotations, RoundEnvironment roundEnv) {
        for (Element e : roundEnv.getElementsAnnotatedWith(A.class)) {
            A rtg = e.getAnnotation(A.class);

            try {
                rtg.a();
                Assert.check(false); 
            } catch (MirroredTypeException ex) {
                TypeMirror tm = ex.getTypeMirror();
                Assert.check(tm.getKind() == TypeKind.ERROR);

                TypeElement elm = (TypeElement)((DeclaredType)tm).asElement();
                Assert.check(elm.getQualifiedName().toString().
                        endsWith("some.path.to.SomeUnknownClass$Inner"));

                TypeSymbol sym = (TypeSymbol)elm;
                Assert.check(sym.name.contentEquals("some.path.to.SomeUnknownClass$Inner"));
            }
        }
        for (Element e : roundEnv.getElementsAnnotatedWith(B.class)) {
            B rtg = e.getAnnotation(B.class);

            try {
                rtg.a();
                Assert.check(false); 
            } catch (MirroredTypeException ex) {
                TypeMirror tm = ex.getTypeMirror();
                Assert.check(tm.getKind() == TypeKind.ERROR);

                TypeElement elm = (TypeElement)((DeclaredType)tm).asElement();
                Assert.check(elm.getQualifiedName().toString().
                        endsWith("SomeUnknownClass"));

                TypeSymbol sym = (TypeSymbol)elm;
                Assert.check(sym.name.contentEquals("SomeUnknownClass"));
            }
        }
        for (Element e : roundEnv.getElementsAnnotatedWith(C.class)) {
            C rtg = e.getAnnotation(C.class);

            try {
                rtg.a();
                Assert.check(false); 
            } catch (AnnotationTypeMismatchException ex) {
                ;
            }
        }
        return true;
    }

    @interface A {
        Class<?> a();
    }
    @interface B {
        Class<?> a();
    }
    @interface C {
        Class<?> a();
    }
}
