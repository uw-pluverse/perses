

import com.sun.tools.classfile.*;
import com.sun.tools.classfile.ConstantPool.CONSTANT_Class_info;
import com.sun.tools.classfile.ConstantPool.CONSTANT_Utf8_info;
import com.sun.tools.classfile.ConstantPool.CPInfo;
import java.io.*;
import java.util.*;
import javax.annotation.processing.*;
import javax.lang.model.*;
import javax.lang.model.element.*;
import javax.tools.*;


@SupportedAnnotationTypes("*")
public class CreateBadClassFile extends AbstractProcessor {
    public boolean process(Set<? extends TypeElement> elems, RoundEnvironment renv) {
        if (++round == 1) {
            ConstantPool cp = new ConstantPool(new CPInfo[] {
                new CONSTANT_Utf8_info(""),                     
                new CONSTANT_Utf8_info("Test"),                 
                new CONSTANT_Class_info(null, 1),               
                new CONSTANT_Utf8_info("java/lang/Object"),     
                new CONSTANT_Class_info(null, 3),               
                new CONSTANT_Utf8_info("test"),                 
                new CONSTANT_Utf8_info("()V"),                  
            });
            ClassFile cf = new ClassFile(0xCAFEBABE,
                          0,
                          51,
                          cp,
                          new AccessFlags(AccessFlags.ACC_ABSTRACT |
                                          AccessFlags.ACC_INTERFACE |
                                          AccessFlags.ACC_PUBLIC),
                          2,
                          4,
                          new int[0],
                          new Field[0],
                          new Method[] {
                              
                              new Method(new AccessFlags(AccessFlags.ACC_PUBLIC |
                                                         AccessFlags.ACC_STATIC),
                                         5,
                                         new Descriptor(6),
                                         new Attributes(cp, new Attribute[0]))
                          },
                          new Attributes(cp, new Attribute[0]));
            try {
                JavaFileObject clazz = processingEnv.getFiler().createClassFile("Test");
                try (OutputStream out = clazz.openOutputStream()) {
                    new ClassWriter().write(cf, out);
                }
            } catch (IOException ex) {
                ex.printStackTrace();
            }
        }
        return false;
    }

    public SourceVersion getSupportedSourceVersion() {
        return SourceVersion.latest();
    }

    int round = 0;
}
