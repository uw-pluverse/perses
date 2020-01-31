



import java.util.Set;
import java.lang.annotation.*;
import javax.annotation.processing.*;
import javax.lang.model.SourceVersion;
import static javax.lang.model.SourceVersion.*;
import javax.lang.model.element.*;
import javax.lang.model.util.*;
import static javax.lang.model.util.ElementFilter.*;
import static javax.tools.Diagnostic.Kind.*;
import static javax.tools.StandardLocation.*;
import com.sun.tools.javac.util.Assert;

@Target({ElementType.TYPE_PARAMETER, ElementType.TYPE})
@Inherited
@Retention(RetentionPolicy.RUNTIME)
@Repeatable(Foos.class)
@interface Foo {
    int value();
}

@Target({ElementType.TYPE_PARAMETER, ElementType.TYPE})
@Inherited
@Retention(RetentionPolicy.RUNTIME)
@interface Foos {
    Foo[] value();
}

@Foos({@Foo(0), @Foo(1)}) @Foo(2)
class Base {}

class Sub extends Base {}

public class EnsureOrder<@Foos({@Foo(0), @Foo(1)}) @Foo(2)T> extends JavacTestingAbstractProcessor {
    public boolean process(Set<? extends TypeElement> annotations,
                           RoundEnvironment roundEnv) {
        if (!roundEnv.processingOver()) {
            int hasRun = 0;
            for (Element element : roundEnv.getRootElements()) {
                Name elemName = element.getSimpleName();
                if (elemName.contentEquals("Base")) {
                    hasRun++;
                    Foo[] foos = element.getAnnotationsByType(Foo.class);
                    Assert.check(foos.length == 3);
                    Assert.check(foos[0].value() == 0);
                    Assert.check(foos[1].value() == 1);
                    Assert.check(foos[2].value() == 2);
                }
                if (elemName.contentEquals("Sub")) {
                    hasRun++;
                    Foo[] foos = element.getAnnotationsByType(Foo.class);
                    Assert.check(foos.length == 3);
                    Assert.check(foos[0].value() == 0);
                    Assert.check(foos[1].value() == 1);
                    Assert.check(foos[2].value() == 2);
                }
                if (elemName.contentEquals("EnsureOrder")) {
                    for (TypeParameterElement t : ((TypeElement)element).getTypeParameters()) {
                        if (t.getSimpleName().contentEquals("T")) {
                            hasRun++;
                            Foo[] foos = t.getAnnotationsByType(Foo.class);
                            Assert.check(foos.length == 3);
                            Assert.check(foos[0].value() == 0);
                            Assert.check(foos[1].value() == 1);
                            Assert.check(foos[2].value() == 2);
                        }
                    }
                }
            }
            if (hasRun != 3)
                throw new RuntimeException("Couldn't find elements");
        }
        return true;
    }
}
