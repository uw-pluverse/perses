



import java.util.*;
import javax.annotation.processing.*;
import javax.lang.model.element.*;
import javax.lang.model.util.*;
import javax.tools.*;

public class TestTypeParameter<T> extends JavacTestingAbstractProcessor {
    int round = 0;

    public boolean process(Set<? extends TypeElement> annotations, RoundEnvironment roundEnv) {
        if (++round == 1) {
            int found = (new Scanner()).scan(roundEnv.getRootElements(), null);
            if (found == expect) {
                note("generic elements found and verified: " + found);
            } else {
                error("unexpected number of results: expected " + expect
                        + ", found " + found);
            }

        }
        return true;
    }

    class Scanner extends ElementScanner7<Integer,Void> {
        @Override
        public Integer visitExecutable(ExecutableElement e, Void p) {
            super.visitExecutable(e, p);
            found += check(e, e.getTypeParameters());
            return found;
        }

        @Override
        public Integer visitType(TypeElement e, Void p) {
            super.visitType(e, p);
            found += check(e, e.getTypeParameters());
            return found;
        }

        int found;
    }

    
    int check(Element e, List<? extends TypeParameterElement> typarams) {
        note("checking " + e, e);
        if (typarams.isEmpty()) {
            note("no type parameters found", e);
            return 0;
        }
        for (TypeParameterElement tpe: typarams) {
            note("checking type parameter " + tpe, tpe);
            if (tpe.getEnclosingElement() != e) {
                error("unexpected owner; expected: " + e
                        + ", found " + tpe.getEnclosingElement(),
                        tpe);
                return 0;
            }
            if (tpe.getEnclosingElement() != tpe.getGenericElement()) {
                error("unexpected generic element; expected: " + tpe.getGenericElement()
                        + ", found " + tpe.getEnclosingElement(),
                        tpe);
                return 0;
            }
        }
        note("verified " + e, e);
        return 1;
    }

    void note(String msg) {
        messager.printMessage(Diagnostic.Kind.NOTE, msg);
    }

    void note(String msg, Element e) {
        messager.printMessage(Diagnostic.Kind.NOTE, msg, e);
    }

    void error(String msg, Element e) {
        messager.printMessage(Diagnostic.Kind.ERROR, msg, e);
    }

    void error(String msg) {
        messager.printMessage(Diagnostic.Kind.ERROR, msg);
    }

    
    <X> X m(X x) { return x; }

    interface Intf<X> { X m() ; }

    class Class<X> {
        <Y> Class() { }
    }

    final int expect = 5;  
}
