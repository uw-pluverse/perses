



import java.util.Set;
import javax.annotation.processing.*;
import javax.lang.model.element.*;
import javax.lang.model.type.*;
import javax.lang.model.util.*;

public class TypesBadArg extends JavacTestingAbstractProcessor {
    boolean success = true;

    public boolean process(Set<? extends TypeElement> tes,
                           RoundEnvironment round) {
        if (round.processingOver()) return true;

        final Elements elements = processingEnv.getElementUtils();
        final Types types = processingEnv.getTypeUtils();

        final TypeMirror javaLang =
            elements.getPackageElement("java.lang").asType();

        makeBadCall(new Runnable() {
            public void run() {
                types.isSubtype(javaLang, javaLang);
            }
        });
        makeBadCall(new Runnable() {
            public void run() {
                types.isAssignable(javaLang, javaLang);
            }
        });
        makeBadCall(new Runnable() {
            public void run() {
                types.contains(javaLang, javaLang);
            }
        });
        makeBadCall(new Runnable() {
            public void run() {
                types.directSupertypes(javaLang);
            }
        });
        makeBadCall(new Runnable() {
            public void run() {
                types.erasure(javaLang);
            }
        });
        makeBadCall(new Runnable() {
            public void run() {
                types.capture(javaLang);
            }
        });
        makeBadCall(new Runnable() {
            public void run() {
                types.unboxedType(javaLang);
            }
        });
        makeBadCall(new Runnable() {
            public void run() {
                types.unboxedType(types.getNoType(TypeKind.VOID));
            }
        });
        if (! success)
            throw new AssertionError("Some test(s) failed.");
        return true;
    }

    private void makeBadCall(Runnable runnable) {
        try {
            runnable.run();
            System.out.println("Failure: IllegalArgumentException expected");
            success = false;
        } catch (IllegalArgumentException e) {
            System.out.println("IllegalArgumentException as expected");
        }
    }
}
