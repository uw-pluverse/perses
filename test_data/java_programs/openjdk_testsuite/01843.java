



import java.util.Set;
import java.util.Map;
import javax.annotation.processing.*;
import javax.lang.model.SourceVersion;
import static javax.lang.model.SourceVersion.*;
import javax.lang.model.element.*;
import javax.lang.model.util.*;
import static javax.lang.model.util.ElementFilter.*;
import static javax.tools.Diagnostic.Kind.*;
import static javax.tools.StandardLocation.*;
import java.io.IOException;
import java.io.PrintWriter;


@SupportedOptions("phase")
public class TestGetResource extends JavacTestingAbstractProcessor {
    private static String CONTENTS = "Hello World.";
    private static String PKG = "";
    private static String RESOURCE_NAME = "Resource1";

    public boolean process(Set<? extends TypeElement> annotations,
                           RoundEnvironment roundEnv) {
        try {
            if (!roundEnv.processingOver()) {
                String phase = options.get("phase");

                if (phase.equals("write")) {
                    PrintWriter pw =
                        new PrintWriter(filer.createResource(CLASS_OUTPUT, PKG, RESOURCE_NAME).openWriter());
                    pw.print(CONTENTS);
                    pw.close();
                } else if (phase.equals("read")) {
                    String contents = filer.getResource(CLASS_OUTPUT,
                                                       PKG,
                                                       RESOURCE_NAME).getCharContent(false).toString();
                    if (!contents.equals(CONTENTS))
                        throw new RuntimeException("Expected \n\t" + CONTENTS +
                                                   "\nbut instead got \n\t" +
                                                   contents);
                    
                    filer.createResource(CLASS_OUTPUT,
                                         PKG,
                                         RESOURCE_NAME);
                } else {
                    throw new RuntimeException("Unexpected phase: " + phase);
                }
            }
        } catch(IOException ioe) {
            throw new RuntimeException(ioe);
        }
        return false;
    }
}
