



import java.util.Set;
import javax.annotation.processing.*;
import javax.lang.model.SourceVersion;
import javax.lang.model.element.*;
import javax.lang.model.type.*;
import javax.lang.model.util.*;

import static javax.lang.model.type.TypeKind.*;

public class NoTypes extends JavacTestingAbstractProcessor {
    public boolean process(Set<? extends TypeElement> annoTypes,
                           RoundEnvironment round) {
        if (!round.processingOver())
            doit(annoTypes, round);
        return true;
    }

    private void doit(Set<? extends TypeElement> annoTypes,
                      RoundEnvironment round) {

        
        TypeElement object = elements.getTypeElement("java.lang.Object");
        verifyKind(NONE, object.getSuperclass());

        
        verifyKind(NONE, ((DeclaredType)object.asType()).getEnclosingType());

        
        TypeElement i = elements.getTypeElement("NoTypes.I");
        verifyKind(NONE, i.getSuperclass());

        
        Element pkg = i.getEnclosingElement().getEnclosingElement();
        verifyKind(PACKAGE, pkg.asType());

        
        if (pkg.getEnclosingElement() != null)
            throw new AssertionError();

        verifyKind(VOID, types.getNoType(VOID));
        verifyKind(NONE, types.getNoType(NONE));

        
        class Scanner extends ElementScanner<Void, Void> {
            @Override
            public Void visitExecutable(ExecutableElement e, Void p) {
                verifyKind(VOID, e.getReturnType());
                ExecutableType t = (ExecutableType) e.asType();
                verifyKind(VOID, t.getReturnType());
                return null;
            }
        }
        TypeElement c = elements.getTypeElement("NoTypes.C");
        new Scanner().scan(c);
    }

    
    private void verifyKind(TypeKind kind, TypeMirror type) {
        class Vis extends TypeKindVisitor<TypeKind, Void> {
            @Override
            public TypeKind visitNoTypeAsVoid(NoType t, Void p) {
                return VOID;
            }
            @Override
            public TypeKind visitNoTypeAsPackage(NoType t, Void p) {
                return PACKAGE;
            }
            @Override
            public TypeKind visitNoTypeAsNone(NoType t, Void p) {
                return NONE;
            }
        }
        if (kind != type.getKind() || kind != new Vis().visit(type))
            throw new AssertionError();
    }

    
    interface I {
    }

    class C {
        C() {}
        void m() {}
    }
}
