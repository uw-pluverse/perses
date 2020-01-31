

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
                FileObject fo1 = filer.createResource(
                    StandardLocation.CLASS_OUTPUT, "", "HelloWorld.txt");
                Writer out = fo1.openWriter();
                out.write("Hello World!");
                out.close();
                FileObject fo2 = filer.createResource(
                    StandardLocation.CLASS_OUTPUT, "", "HelloWorld.txt");
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
