



import java.io.*;
import java.util.*;
import javax.annotation.processing.*;
import javax.lang.model.*;
import javax.lang.model.element.*;
import javax.tools.*;

public class TestLastRound extends JavacTestingAbstractProcessor {
    @Override
    public boolean process(Set<? extends TypeElement> annotations,
                           RoundEnvironment roundEnv) {
        if (roundEnv.processingOver()) {
            try {
                JavaFileObject fo = filer.createSourceFile("LastRound.java");
                Writer out = fo.openWriter();
                out.write("class LastRound { }");
                out.close();
            } catch (IOException e) {
            }
        }
        return true;
    }
}
