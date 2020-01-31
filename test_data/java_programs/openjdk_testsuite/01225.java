

import java.io.*;
import java.util.*;
import javax.annotation.processing.*;
import javax.lang.model.*;
import javax.lang.model.element.*;
import javax.tools.*;

@SupportedAnnotationTypes("*")
public class AnnoProc extends AbstractProcessor {
    public boolean process(Set<? extends TypeElement> elems, RoundEnvironment renv) {
        if (renv.processingOver()) {
            Filer filer = processingEnv.getFiler();
            Messager messager = processingEnv.getMessager();
            try {
                JavaFileObject fo = filer.createSourceFile("Gen");
                Writer out = fo.openWriter();
                out.write("class Gen { }");
                out.close();
            } catch (IOException e) {
                messager.printMessage(Diagnostic.Kind.ERROR, e.toString());
            }
        }
        return false;
    }

    public SourceVersion getSupportedSourceVersion() {
        return SourceVersion.latest();
    }
}
