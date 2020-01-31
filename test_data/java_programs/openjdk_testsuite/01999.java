

import javax.annotation.processing.*;
import javax.lang.model.*;
import javax.lang.model.element.*;
import java.util.Set;

public class DummyProcessor extends JavacTestingAbstractProcessor {
   public boolean process(Set<? extends TypeElement> annotations,
                  RoundEnvironment roundEnv) {
       return true;
   }
}

