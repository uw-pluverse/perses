



import java.io.*;
import java.util.*;
import javax.annotation.processing.*;
import javax.lang.model.*;
import javax.lang.model.element.*;
import javax.lang.model.util.*;
import javax.tools.*;

public class Test extends JavacTestingAbstractProcessor {
    final int MAX_ROUNDS = 3;
    int round = 0;

    @Override
    public boolean process(Set<? extends TypeElement> annotations, RoundEnvironment roundEnv) {
        round++;
        messager.printMessage(Diagnostic.Kind.NOTE, "round " + round);
        if (round <= MAX_ROUNDS)
            generateSource("Gen" + round);
        if (roundEnv.processingOver())
            messager.printMessage(Diagnostic.Kind.WARNING, "last round");
        return true;
    }

    void generateSource(String name) {
        String text = "class " + name + " { }\n";

        
        try {
            Writer out = filer.createSourceFile(name).openWriter();
            try {
                out.write(text);
            } finally {
                out.close();
            }
        } catch (IOException e) {
            throw new Error(e);
        }
    }
}



