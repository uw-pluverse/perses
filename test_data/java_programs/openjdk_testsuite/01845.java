



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
import java.nio.charset.Charset;


public class TestFilerConstraints extends JavacTestingAbstractProcessor {
    private int round = 0;

    private PrintWriter  pw_src1 = null;
    private PrintWriter  pw_src2 = null;
    private OutputStream os_classFile1 = null;
    private      Writer  pw_classFile2 = null;

    public boolean process(Set<? extends TypeElement> annotations,
                           RoundEnvironment roundEnv) {
        round++;

        try {
            switch(round) {
                
            case 1:
                pw_src1 = new PrintWriter(filer.createSourceFile("Src1").openWriter());
                pw_src1.println("class Src1 {}");
                pw_src1.close();

                
                pw_src2 = new PrintWriter(new OutputStreamWriter(filer.createSourceFile("Src2").openOutputStream()));
                break;

            case 2:
                testExpectedType(roundEnv, "Src1");

                
                pw_src1.close();

                pw_src2.println("class Src2 {}");
                pw_src2.close();

                break;

            case 3:
                testExpectedType(roundEnv, "Src2");

                
                pw_src2.close();

                os_classFile1 = filer.createClassFile("ClassFile1").openOutputStream();
                for (int value : classFile1Bytes)
                    os_classFile1.write((byte)value);
                os_classFile1.close();

                break;

            case 4:
                testExpectedType(roundEnv, "ClassFile1");

                
                os_classFile1.close();

                testReopening();

                pw_classFile2 = new PrintWriter(filer.createClassFile("ClassFile2",
                                                                      (Element[])null).openWriter());

                for(int byteVal : classFile2Bytes) {
                    
                    
                    
                    
                    pw_classFile2.write((char) (0xff & byteVal));
                }
                pw_classFile2.close();

                break;



            case 5:
                testExpectedType(roundEnv, "ClassFile2");
                
                pw_classFile2.close();


                break;

            case 6:
                if (!roundEnv.processingOver() && !roundEnv.errorRaised())
                    throw new RuntimeException("Bad round state: " + roundEnv);
                break;

            default:
                throw new RuntimeException("Unexpected round number!");
            }
        } catch (IOException ioe) {
            throw new RuntimeException(ioe);
        }

        return true;
    }

    
    private void testExpectedType(RoundEnvironment roundEnv, String name) {
        if (!roundEnv.getRootElements().isEmpty()) {
            for(TypeElement type : typesIn(roundEnv.getRootElements())) {
                if (!name.contentEquals(type.getSimpleName()))
                    throw new RuntimeException("Unexpected type " +  type.getSimpleName());
            }
        } else
            throw new RuntimeException("Unexpected empty root elements.");
    }

    private void testReopening() throws IOException {
        String[] names = {"Src1", "Src2", "ClassFile1"};
        for (String name : names) {
            try {
                filer.createSourceFile(name);
                throw new RuntimeException("Opened a source file for type " + name);
            } catch (FilerException fe) {;}

            try {
                filer.createClassFile(name);
                throw new RuntimeException("Opened a class file for type " + name);
            } catch (FilerException fe) {;}
        }

        
        try {
            filer.createResource(SOURCE_OUTPUT, "", "Src1.java");
            throw new RuntimeException("Opened a text file over Src1.java!");
        } catch (FilerException fe) {;}

        
        try {
            filer.createResource(CLASS_OUTPUT, "", "ClassFile1.class");
            throw new RuntimeException("Opened a text file over Src1.java!");
        } catch (FilerException fe) {;}

    }

    private int[] classFile1Bytes =
    {202, 254, 186, 190,   0,   0,   0,  50,
       0,  13,  10,   0,   3,   0,  10,   7,
       0,  11,   7,   0,  12,   1,   0,   6,
      60, 105, 110, 105, 116,  62,   1,   0,
       3,  40,  41,  86,   1,   0,   4,  67,
     111, 100, 101,   1,   0,  15,  76, 105,
     110, 101,  78, 117, 109,  98, 101, 114,
      84,  97,  98, 108, 101,   1,   0,  10,
      83, 111, 117, 114,  99, 101,  70, 105,
     108, 101,   1,   0,  15,  67, 108,  97,
     115, 115,  70, 105, 108, 101,  49,  46,
     106,  97, 118,  97,  12,   0,   4,   0,
       5,   1,   0,  10,  67, 108,  97, 115,
     115,  70, 105, 108, 101,  49,   1,   0,
      16, 106,  97, 118,  97,  47, 108,  97,
     110, 103,  47,  79,  98, 106, 101,  99,
     116,   0,  33,   0,   2,   0,   3,   0,
       0,   0,   0,   0,   1,   0,   1,   0,
       4,   0,   5,   0,   1,   0,   6,   0,
       0,   0,  29,   0,   1,   0,   1,   0,
       0,   0,   5,  42, 183,   0,   1, 177,
       0,   0,   0,   1,   0,   7,   0,   0,
       0,   6,   0,   1,   0,   0,   0,   1,
       0,   1,   0,   8,   0,   0,   0,   2,
       0,   9,};

    private int[] classFile2Bytes =
    {202, 254, 186, 190,   0,   0,   0,  50,
       0,  13,  10,   0,   3,   0,  10,   7,
       0,  11,   7,   0,  12,   1,   0,   6,
      60, 105, 110, 105, 116,  62,   1,   0,
       3,  40,  41,  86,   1,   0,   4,  67,
     111, 100, 101,   1,   0,  15,  76, 105,
     110, 101,  78, 117, 109,  98, 101, 114,
      84,  97,  98, 108, 101,   1,   0,  10,
      83, 111, 117, 114,  99, 101,  70, 105,
     108, 101,   1,   0,  15,  67, 108,  97,
     115, 115,  70, 105, 108, 101,  50,  46,
     106,  97, 118,  97,  12,   0,   4,   0,
       5,   1,   0,  10,  67, 108,  97, 115,
     115,  70, 105, 108, 101,  50,   1,   0,
      16, 106,  97, 118,  97,  47, 108,  97,
     110, 103,  47,  79,  98, 106, 101,  99,
     116,   0,  33,   0,   2,   0,   3,   0,
       0,   0,   0,   0,   1,   0,   1,   0,
       4,   0,   5,   0,   1,   0,   6,   0,
       0,   0,  29,   0,   1,   0,   1,   0,
       0,   0,   5,  42, 183,   0,   1, 177,
       0,   0,   0,   1,   0,   7,   0,   0,
       0,   6,   0,   1,   0,   0,   0,   1,
       0,   1,   0,   8,   0,   0,   0,   2,
       0,   9,};
}
