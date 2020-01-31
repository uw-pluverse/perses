



import java.lang.annotation.Repeatable;
import java.util.Set;
import javax.annotation.processing.*;
import javax.lang.model.element.*;
import static javax.lang.model.util.ElementFilter.*;

import com.sun.tools.javac.util.Assert;

import java.util.Arrays;

public class TestQualifiedNameUsed extends JavacTestingAbstractProcessor {
    @Q
    @p.Q
    @p.R.Q
    public boolean process(Set<? extends TypeElement> annotations,
                           RoundEnvironment roundEnv) {
        if (!roundEnv.processingOver()) {
            boolean hasRun = false;
            for (Element element : roundEnv.getRootElements()) {
                for (ExecutableElement e : methodsIn(element.getEnclosedElements())) {
                    if (e.getSimpleName().contentEquals("value"))
                        continue; 

                    hasRun = true;
                    Q[] qs = e.getAnnotationsByType(Q.class);
                    Assert.check(qs.length == 1);
                    Assert.check(qs[0] instanceof Q);

                    p.Q[] ps = e.getAnnotationsByType(p.Q.class);
                    Assert.check(ps.length == 1);
                    Assert.check(ps[0] instanceof p.Q);

                    p.R.Q[] rs = e.getAnnotationsByType(p.R.Q.class);
                    Assert.check(rs.length == 1);
                    Assert.check(rs[0] instanceof p.R.Q);
                }
            }
            if (!hasRun) throw new RuntimeException("No methods!");
        }
        return true;
    }
}

@Repeatable(QQ.class)
@interface Q {}

@interface QQ {
    Q[] value();
}
