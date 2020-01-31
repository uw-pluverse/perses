



import java.util.*;
import javax.annotation.processing.*;
import javax.lang.model.element.*;

public class TestParseErrors extends JavacTestingAbstractProcessor {

    public boolean process(Set<? extends TypeElement> annotations,
                           RoundEnvironment roundEnvironment) {
        throw new Error("Should not be called");
    }
}
