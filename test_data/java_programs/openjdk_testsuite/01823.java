

import java.io.*;
import java.util.*;
import javax.annotation.processing.*;
import javax.lang.model.*;
import javax.lang.model.element.*;

public class A extends JavacTestingAbstractProcessor {
    public boolean process(Set<? extends TypeElement> tes, RoundEnvironment renv) {
        try {
            OutputStream out = filer.createClassFile(getClass().getName()+"_0").openOutputStream();
            out.close();
        } catch (IOException e) {
            throw new Error(e);
        }
        return true;
    }
}
