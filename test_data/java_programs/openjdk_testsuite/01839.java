



import java.util.Set;
import java.util.HashSet;
import java.util.Map;
import javax.annotation.processing.*;
import javax.lang.model.SourceVersion;
import static javax.lang.model.SourceVersion.*;
import javax.lang.model.element.*;
import javax.lang.model.util.*;
import static javax.lang.model.util.ElementFilter.*;
import static javax.tools.Diagnostic.Kind.*;
import static javax.tools.StandardLocation.*;

import java.io.*;


public class TestPackageInfo extends JavacTestingAbstractProcessor {
    private int round = 0;

    public boolean process(Set<? extends TypeElement> annotations,
                           RoundEnvironment roundEnv) {
        round++;

        
        Set<TypeElement> expectedAnnotations = new HashSet<TypeElement>();
        expectedAnnotations.add(eltUtils.getTypeElement("java.lang.Deprecated"));

        if (!roundEnv.processingOver()) {
            System.out.println("\nRound " + round);
            int rootElementSize = roundEnv.getRootElements().size();

            for(Element elt : roundEnv.getRootElements()) {
                System.out.printf("%nElement %s\tkind: %s%n", elt.getSimpleName(), elt.getKind());
                eltUtils.printElements(new PrintWriter(System.out), elt);
            }

            switch (round) {
            case 1:
                if (rootElementSize != 2)
                    throw new RuntimeException("Unexpected root element size " + rootElementSize);

                
                
                
                if (!expectedAnnotations.equals(annotations)) {
                    throw new RuntimeException("Unexpected annotations: " + annotations);
                }

                try {
                    try {
                        filer.createClassFile("package-info");
                        throw new RuntimeException("Created class file for \"package-info\".");
                    } catch(FilerException fe) {}

                    PrintWriter pw = new PrintWriter(filer.createSourceFile("foo.package-info").openWriter());
                    pw.println("@Deprecated");
                    pw.println("package foo;");
                    pw.close();

                } catch(IOException ioe) {
                    throw new RuntimeException(ioe);
                }
                break;

            case 2:
                

                Set<Element> expectedElement = new HashSet<Element>();
                expectedElement.add(eltUtils.getPackageElement("foo"));
                if (!expectedElement.equals(roundEnv.getRootElements()))
                    throw new RuntimeException("Unexpected root element set " + roundEnv.getRootElements());

                if (!expectedAnnotations.equals(annotations)) {
                    throw new RuntimeException("Unexpected annotations: " + annotations);
                }

                break;

            default:
                throw new RuntimeException("Unexpected round number " + round);
            }
        }
        return false;
    }
}
