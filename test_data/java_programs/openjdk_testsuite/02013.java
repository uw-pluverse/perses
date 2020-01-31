

import java.util.*;
import javax.annotation.processing.*;
import javax.lang.model.*;
import javax.lang.model.element.*;
import static javax.tools.Diagnostic.Kind.*;

public class TestProcessor extends JavacTestingAbstractProcessor {
   private int round = 0;

   public boolean process(Set<? extends TypeElement> annotations,
                  RoundEnvironment roundEnv) {
        if (++round == 1)
            messager.printMessage(ERROR, "Deliberate Error");
        return false;
   }
}

