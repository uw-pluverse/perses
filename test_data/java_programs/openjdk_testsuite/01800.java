



import java.util.*;
import javax.annotation.processing.*;
import javax.lang.model.element.*;
import com.sun.source.util.*;

public class T7196462 extends JavacTestingAbstractProcessor {
    public boolean process(Set<? extends TypeElement> annos,RoundEnvironment rEnv) {
        JavacTask t = JavacTask.instance(processingEnv);
        System.err.println(t);
        return true;
    }
}
