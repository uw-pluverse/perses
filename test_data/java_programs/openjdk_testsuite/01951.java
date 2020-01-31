



import java.util.Set;
import javax.annotation.processing.*;
import javax.lang.model.element.*;
import javax.lang.model.util.*;
import static javax.tools.Diagnostic.Kind.*;

public class T6194785 extends JavacTestingAbstractProcessor {
    public boolean process(Set<? extends TypeElement> annotations,
                           RoundEnvironment roundEnvironment) {
        class Scan extends ElementScanner<Void,Void> {
            @Override
            public Void visitExecutable(ExecutableElement e, Void ignored) {
                for (VariableElement p : e.getParameters())
                    if ("arg0".equals(p.getSimpleName().toString()))
                        throw new AssertionError(e);
                return null;
            }
        }
        Scan scan = new Scan();
        for (Element e : roundEnvironment.getRootElements()) {
            scan.scan(e);
        }
        return true;
    }
}
