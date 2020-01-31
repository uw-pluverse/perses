

import java.util.*;
import javax.annotation.processing.*;
import javax.lang.model.element.*;

public class AnnoProc extends AbstractProcessor {
    public boolean process(Set<? extends TypeElement> elems, RoundEnvironment renv) {
        return true;
    }
}
