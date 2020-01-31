



import java.io.*;
import java.util.*;
import javax.annotation.processing.*;
import javax.lang.model.*;
import javax.lang.model.element.*;
import javax.tools.*;

public class WError1 extends JavacTestingAbstractProcessor {
    @Override
    public boolean process(Set<? extends TypeElement> annotations,
                           RoundEnvironment roundEnv) {
        if (++round == 1) {
            messager.printMessage(Diagnostic.Kind.WARNING, "round 1");
        }
        return true;
    }

    int round = 0;
}
