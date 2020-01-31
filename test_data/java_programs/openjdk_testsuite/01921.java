



import com.sun.tools.javac.util.Assert;

import java.lang.annotation.*;
import java.util.Arrays;
import java.util.Set;
import javax.annotation.processing.*;
import javax.lang.model.element.Element;
import javax.lang.model.element.TypeElement;

import static javax.lang.model.util.ElementFilter.*;

@TestEmptyContainer.Foo(1)
public class TestEmptyContainer extends JavacTestingAbstractProcessor {
    public boolean process(Set<? extends TypeElement> annotations,
                           RoundEnvironment roundEnv) {
        if (!roundEnv.processingOver()) {
            boolean hasRun = false;
            for (Element element : roundEnv.getRootElements())
                for (TypeElement te : typesIn(element.getEnclosedElements()))
                    if (te.getQualifiedName().contentEquals("TestEmptyContainer.T2")) {
                        hasRun = true;
                        Foo[] foos = te.getAnnotationsByType(Foo.class);
                        System.out.println("  " + te);
                        System.out.println("  " + Arrays.asList(foos));
                        Assert.check(foos.length == 1, "Should find one @Foo");
                        Assert.check(foos[0].value() == 1, "Should find @Foo(1)");
                    }
            if (!hasRun)
                throw new RuntimeException("Annotation processor couldn't find class T2, test broken!");
        }
        return true;
    }

    
    @TestEmptyContainer.FooContainer({})
    public static class T2 extends TestEmptyContainer {
    }

    @Repeatable(FooContainer.class)
    @Inherited
    public static @interface Foo {
        int value();
    }

    @Inherited
    public static @interface FooContainer {
        Foo[] value();
    }
}
