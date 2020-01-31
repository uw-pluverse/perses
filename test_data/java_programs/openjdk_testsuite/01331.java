

import java.io.*;
import java.util.*;
import javax.annotation.processing.*;
import javax.lang.model.*;
import javax.lang.model.element.*;
import javax.tools.*;

@SupportedAnnotationTypes("*")
public class AnnoProc extends AbstractProcessor {
    public boolean process(Set<? extends TypeElement> elems, RoundEnvironment renv) {
        if (++round == 1) {
            Filer filer = processingEnv.getFiler();
            Messager messager = processingEnv.getMessager();
            try {
                FileObject fo = filer.createSourceFile("HelloWorld.java");
                try (Writer out = fo.openWriter()) {
                    out.write("class HelloWorld {\n");
                    out.write("  public static void main(String[] args) {\n");
                    out.write("    System.out.println(\"Hello World!\");\n");
                    out.write("  }\n");
                    out.write("}\n");
                }
            } catch (IOException e) {
                messager.printMessage(Diagnostic.Kind.ERROR, e.toString());
            }
        }
        return false;
    }

    public SourceVersion getSupportedSourceVersion() {
        return SourceVersion.latest();
    }

    int round = 0;
}
