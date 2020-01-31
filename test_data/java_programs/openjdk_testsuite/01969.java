



import java.util.Set;
import javax.annotation.processing.*;
import javax.lang.model.SourceVersion;
import static javax.lang.model.SourceVersion.*;
import javax.lang.model.element.*;
import javax.lang.model.util.*;
import static javax.tools.Diagnostic.Kind.*;

import java.io.PrintWriter;
import java.io.IOException;


public class TestFatalityOfParseErrors extends JavacTestingAbstractProcessor {
    int round = 0;

    public boolean process(Set<? extends TypeElement> annotations,
                           RoundEnvironment roundEnvironment) {
        try {
            PrintWriter pw = null;
            round++;

            switch (round) {
            case 1:
                pw = new PrintWriter(filer.createSourceFile("SyntaxError").openWriter());
                pw.println("class SyntaxError {");
                pw.close();
                break;

            case 2:
                pw = new PrintWriter(filer.createSourceFile("SimpleClass").openWriter());
                pw.println("class SimpleClass {}");
                pw.close();

                if (!roundEnvironment.errorRaised() || !roundEnvironment.processingOver() ) {
                    System.err.println(roundEnvironment);
                    throw new RuntimeException("Second round not erroneous as expected.");
                }
                if (!roundEnvironment.getRootElements().isEmpty()) {
                    System.err.println(roundEnvironment);
                    throw new RuntimeException("Root elements not empty as expected.");
                }
                break;

            default:
                throw new RuntimeException("Unexpected round number " + round);
            }
        } catch (IOException ioException) {
            throw new RuntimeException(ioException);
        }
        return true;
    }
}
