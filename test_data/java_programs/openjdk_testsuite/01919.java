



import java.util.Set;
import javax.annotation.processing.*;
import javax.lang.model.SourceVersion;
import static javax.lang.model.SourceVersion.*;
import javax.lang.model.element.*;
import javax.lang.model.util.*;
import static javax.lang.model.util.ElementFilter.*;
import static javax.tools.Diagnostic.Kind.*;
import static javax.tools.StandardLocation.*;

import java.io.*;


public class TestNames extends JavacTestingAbstractProcessor {
    private int round = 0;

    String stringStringName = "java.lang.String";
    Name stringName = null;

    public boolean process(Set<? extends TypeElement> annotations,
                           RoundEnvironment roundEnv) {
        round++;
        if (!roundEnv.processingOver()) {
            boolean failed = false;

            switch(round) {
            case 1:

            TypeElement stringMirror = eltUtils.getTypeElement(stringStringName);
            stringName = stringMirror.getQualifiedName();
            Name stringPseudoName = Pseudonym.getName(stringName.toString());


            if (stringName.equals(stringPseudoName))
                failed = true;
            if (!stringName.contentEquals(stringStringName))
                failed = true;
            if (!stringName.contentEquals(stringPseudoName))
                failed = true;


            try {
                
                PrintWriter pw = new PrintWriter(filer.createSourceFile("Foo").openWriter());
                pw.println("public class Foo {}");
                pw.close();
            } catch (IOException ioe) {
                throw new RuntimeException();
            }
            break;

            case 2:
                Name stringStringAsName = eltUtils.getName(stringStringName);
                TypeElement stringMirror2 = eltUtils.getTypeElement(stringStringName);
                Name stringName2 = stringMirror2.getQualifiedName();

                if (stringStringAsName != stringName ||
                    stringName != stringName2)
                    failed = true;
                break;

            default:
                throw new RuntimeException("Unexpected round " + round);
            }

            if (failed)
                throw new RuntimeException("Invalid name equality checks.");
        }
        return true;
    }

    private static class Pseudonym implements Name {
        private String name;

        private Pseudonym(String name) {
            this.name = name;
        }

        public static Pseudonym getName(String name) {
            return new Pseudonym(name);
        }

        public boolean contentEquals(CharSequence cs) {
            return name.contentEquals(cs);
        }

        public char charAt(int index) {
            return name.charAt(index);
        }

        public int length() {
            return name.length();
        }

        public CharSequence subSequence(int start, int end) {
            return name.subSequence(start, end);
        }

        public String toString() {
            return name;
        }
    }
}
