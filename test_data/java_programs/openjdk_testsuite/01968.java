



import java.util.Set;
import javax.annotation.processing.*;
import javax.lang.model.element.*;


public class TestClassNames extends JavacTestingAbstractProcessor {
    public boolean process(Set<? extends TypeElement> annotations,
                           RoundEnvironment roundEnvironment) {
        return true;
    }
}
