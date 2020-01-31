

import java.io.*;
import javax.annotation.processing.*;
import javax.lang.model.element.*;
import javax.lang.model.type.*;
import javax.lang.model.util.*;
import static javax.tools.Diagnostic.Kind.*;

import java.util.Set;

@SupportedAnnotationTypes({"*"})
public class HelloWorldAP extends AbstractProcessor {
    Messager msgr = null;
    Filer filer = null;
    boolean DONE=false;

    @Override
    public void init(ProcessingEnvironment penv) {
        processingEnv = penv;
        msgr=penv.getMessager();
        filer=penv.getFiler();
    }

    public boolean process(Set<? extends TypeElement> tes, RoundEnvironment renv ) {
        boolean ret = true;
        if(!renv.processingOver() && !DONE) {
            msgr.printMessage(NOTE, "running process to create HelloWorld.");
            try {
                Writer pw = filer.createSourceFile("HelloWorld").openWriter();
                pw.write("public class HelloWorld {\n");
                pw.write("  public static void main (String argv[]) {\n");
                pw.write("    System.out.println(\"Hello apt world.\");\n");
                pw.write("  }\n");
                pw.write("}\n");
                pw.flush();
                pw.close();

                OutputStream os = filer.createClassFile("HelloWorldAP").openOutputStream();
                
                InputStream is = getClass().getResourceAsStream("HelloWorldAP.class");
                copy(is, os);
                is.close();
                os.flush();
                os.close();
                DONE=true;
            }
            catch (IOException ioe) {
                msgr.printMessage(ERROR, ioe.getMessage());
                ret = false;
            }
            catch (Exception e) {
                msgr.printMessage(ERROR, e.getMessage());
                ret = false;
            }
        }
        return ret;
    }

    void copy(InputStream is, OutputStream os) throws IOException {
        byte[] buf = new byte[8192];
        int n;
        while ((n = is.read(buf, 0, buf.length)) > 0)
            os.write(buf, 0, n);
    }
}
