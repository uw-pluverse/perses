

import java.io.*;
import java.util.*;
import javax.annotation.processing.*;
import javax.lang.model.element.*;
import javax.lang.model.type.*;
import javax.lang.model.util.*;
import javax.tools.*;

public class Generator extends JavacTestingAbstractProcessor {

    @Override
    public boolean process(Set<? extends TypeElement> annotations, RoundEnvironment roundEnv) {
        for (TypeElement te: ElementFilter.typesIn(roundEnv.getRootElements())) {
            System.err.println(te);
            generateIfMissing(te.getSuperclass());
            generateIfMissing(te.getInterfaces());
        }
        return true;
    }

    void generateIfMissing(List<? extends TypeMirror> ts) {
        for (TypeMirror t: ts)
            generateIfMissing(t);
    }

    void generateIfMissing(TypeMirror t) {
        if (t == null)
            return;
        if (t.getKind() == TypeKind.ERROR) {
            Element e = ((ErrorType) t).asElement();
            if (e == null)
                return;
            if (e.asType().getKind() == TypeKind.ERROR)
                createFile((TypeElement) e);
        }
    }

    void createFile(TypeElement e) {
        try {
            JavaFileObject fo = filer.createSourceFile(e.getSimpleName());
            Writer out = fo.openWriter();
            try {
                switch (e.getKind()) {
                    case CLASS:
                        out.write("import java.util.*;\n");
                        out.write("class " + signature(e) + " {\n");
                        out.write("    public void run() {\n");
                        out.write("        Class<?> c = getClass();\n");
                        out.write("        System.out.println(\"class: \" + c);\n");
                        out.write("        System.out.println(\"superclass: \" + c.getSuperclass());\n");
                        out.write("        System.out.println(\"generic superclass: \" +c.getGenericSuperclass());\n");
                        out.write("        System.out.println(\"interfaces: \" + Arrays.asList(c.getInterfaces()));\n");
                        out.write("        System.out.println(\"generic interfaces: \" + Arrays.asList(c.getGenericInterfaces()));\n");
                        out.write("    }\n");
                        out.write("}\n");
                        break;
                    case INTERFACE:
                        out.write("interface " + signature(e) + " {\n");
                        out.write("    void run();\n");
                        out.write("}\n");
                        break;
                }
            } finally {
                out.close();
            }
        } catch (IOException ex) {
            messager.printMessage(Diagnostic.Kind.ERROR, "problem writing file: " + ex);
        }
    }

    String signature(TypeElement e) {
        System.err.println("signature: " + e + " " + e.getTypeParameters());
        StringBuilder sb = new StringBuilder();
        sb.append(e.getSimpleName());
        if (!e.getTypeParameters().isEmpty()) {
            sb.append("<");
            String sep = "";
            for (TypeParameterElement t : e.getTypeParameters()) {
                sb.append(sep);
                sb.append(t);
                sep = ",";
            }
            sb.append(">");
        }
        return sb.toString();
    }
}

