



import java.util.Set;
import javax.annotation.processing.*;
import javax.lang.model.SourceVersion;
import javax.lang.model.element.*;
import javax.lang.model.type.*;
import javax.lang.model.util.*;

import static javax.lang.model.util.ElementFilter.*;

public class OverridesSpecEx extends JavacTestingAbstractProcessor {
    public boolean process(Set<? extends TypeElement> annoTypes,
                           RoundEnvironment round) {
        if (!round.processingOver())
            doit(annoTypes, round);
        return true;
    }

    private void doit(Set<? extends TypeElement> annoTypes,
                      RoundEnvironment round) {
        TypeElement string = elements.getTypeElement("java.lang.String");
        TypeElement object = elements.getTypeElement("java.lang.Object");

        ExecutableElement m1 = null;
        ExecutableElement m2 = null;
        for (ExecutableElement m : methodsIn(string.getEnclosedElements())) {
            if (m.getSimpleName().contentEquals("hashCode")) {
                m1 = m;
                break;
            }
        }
        for (ExecutableElement m : methodsIn(object.getEnclosedElements())) {
            if (m.getSimpleName().contentEquals("hashCode")) {
                m2 = m;
                break;
            }
        }

        boolean res =
            elements.overrides(m1, m2, (TypeElement) m1.getEnclosingElement());
        System.out.println("String.hashCode overrides Object.hashCode?  " + res);
        checkResult(res);

        TypeElement a = elements.getTypeElement("OverridesSpecEx.A");
        TypeElement b = elements.getTypeElement("OverridesSpecEx.B");
        TypeElement c = elements.getTypeElement("OverridesSpecEx.C");

        m1 = null;
        m2 = null;
        for (ExecutableElement m : methodsIn(a.getEnclosedElements()))
            m1 = m;
        for (ExecutableElement m : methodsIn(b.getEnclosedElements()))
            m2 = m;

        res = elements.overrides(m1, m2, a);
        System.out.println("A.m overrides B.m in B?  " + res);
        checkResult(!res);
        res = elements.overrides(m1, m2, c);
        System.out.println("A.m overrides B.m in C?  " + res);
        checkResult(res);
    }

    private static void checkResult(boolean truthiness) {
        if (!truthiness)
            throw new AssertionError("Bogus result");
    }

    
    class A {
        public void m() {}
    }
    interface B {
        void m();
    }
    class C extends A implements B {
    }
}
