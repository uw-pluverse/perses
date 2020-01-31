



import java.io.File;
import java.net.URI;
import java.util.Arrays;
import java.util.Collections;
import java.util.Set;
import javax.annotation.processing.AbstractProcessor;
import javax.annotation.processing.RoundEnvironment;
import javax.annotation.processing.SupportedAnnotationTypes;
import javax.annotation.processing.SupportedSourceVersion;
import javax.lang.model.SourceVersion;
import javax.lang.model.element.TypeElement;
import javax.lang.model.element.TypeParameterElement;
import javax.lang.model.type.DeclaredType;
import javax.lang.model.type.TypeVariable;
import javax.tools.SimpleJavaFileObject;

import static javax.tools.JavaFileObject.Kind.SOURCE;

public class T6421111 extends ToolTester {
    void test(String... args) {
        class Test1 extends SimpleJavaFileObject {
            Test1() {
                super(URI.create("myfo:///Test1.java"), SOURCE);
            }
            @Override
            public String getCharContent(boolean ignoreEncodingErrors) {
                return "class Test1<T extends Thread & Runnable> {}";
            }
        }
        class Test2 extends SimpleJavaFileObject {
            Test2() {
                super(URI.create("myfo:///Test2.java"), SOURCE);
            }
            @Override
            public String getCharContent(boolean ignoreEncodingErrors) {
                return "class Test2<T extends Test2<T> & Runnable> {}";
            }
        }
        task = tool.getTask(null, fm, null, Collections.singleton("-Xlint:all"), null,
                            Arrays.asList(new Test1(), new Test2()));
        task.setProcessors(Collections.singleton(new MyProcessor()));
        if (!task.call())
            throw new AssertionError("Annotation processor failed");
    }
    @SupportedAnnotationTypes("*")
    static class MyProcessor extends AbstractProcessor {
        void test(TypeElement element, boolean fbound) {
            TypeParameterElement tpe = element.getTypeParameters().iterator().next();
            tpe.getBounds().getClass();
            if (fbound) {
                DeclaredType type = (DeclaredType)tpe.getBounds().get(0);
                if (type.asElement() != element)
                    throw error("%s != %s", type.asElement(), element);
                TypeVariable tv = (TypeVariable)type.getTypeArguments().get(0);
                if (tv.asElement() != tpe)
                    throw error("%s != %s", tv.asElement(), tpe);
            }
        }
        public boolean process(Set<? extends TypeElement> annotations,
                               RoundEnvironment roundEnv) {
            test(processingEnv.getElementUtils().getTypeElement("Test1"), false);
            test(processingEnv.getElementUtils().getTypeElement("Test2"), true);
            return false;
        }
        @Override
        public SourceVersion getSupportedSourceVersion() {
            return SourceVersion.latest();
        }
    }
    public static void main(String... args) {
        new T6421111().test(args);
    }
    public static AssertionError error(String format, Object... args) {
        return new AssertionError(String.format(format, args));
    }
}
