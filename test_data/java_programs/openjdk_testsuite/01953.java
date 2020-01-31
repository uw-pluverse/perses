



import java.io.File;
import java.util.*;
import javax.lang.model.element.Element;
import javax.lang.model.element.ElementKind;
import javax.lang.model.element.PackageElement;
import javax.lang.model.element.TypeElement;
import javax.lang.model.util.Elements;
import javax.tools.*;
import com.sun.source.util.JavacTask;

import static javax.tools.StandardLocation.CLASS_PATH;
import static javax.tools.StandardLocation.PLATFORM_CLASS_PATH;
import static javax.tools.JavaFileObject.Kind.CLASS;


public class Main {

    public static PackageElement getPackage(TypeElement type) {
        Element owner = type;
        while (owner.getKind() != ElementKind.PACKAGE)
            owner = owner.getEnclosingElement();
        return (PackageElement)owner;
    }

    static int progress = 0;
    static JavaCompiler tool;
    static JavacTask javac;
    static Elements elements;

    public static void main(String[] args) throws Exception {
        if (haveAltRt()) {
            System.out.println("Warning: alt-rt.jar detected, test skipped");
            return;
        }
        JavaCompiler tool = ToolProvider.getSystemJavaCompiler();
        StandardJavaFileManager fm = tool.getStandardFileManager(null, null, null);
        fm.setLocation(CLASS_PATH, Collections.<File>emptyList());
        JavacTask javac = (JavacTask)tool.getTask(null, fm, null, null, null, null);
        Elements elements = javac.getElements();

        final Set<String> packages = new LinkedHashSet<String>();

        int nestedClasses = 0;
        int classes = 0;

        for (JavaFileObject file : fm.list(PLATFORM_CLASS_PATH, "", EnumSet.of(CLASS), true)) {
            String type = fm.inferBinaryName(PLATFORM_CLASS_PATH, file);
            if (type.endsWith("package-info"))
                continue;
            try {
                TypeElement elem = elements.getTypeElement(type);
                if (elem == null && type.indexOf('$') > 0) {
                    nestedClasses++;
                    type = null;
                    continue;
                }
                classes++;
                packages.add(getPackage(elem).getQualifiedName().toString());
                elements.getTypeElement(type).getKind(); 
                type = null;
            } finally {
                if (type != null)
                    System.err.println("Looking at " + type);
            }
        }
        javac = null;
        elements = null;

        javac = (JavacTask)tool.getTask(null, fm, null, null, null, null);
        elements = javac.getElements();

        for (String name : packages) {
            PackageElement pe = elements.getPackageElement(name);
            for (Element e : pe.getEnclosedElements()) {
                e.getSimpleName().getClass();
            }
        }
        
        System.out.format("packages: %s, classes: %s + %s%n",
                          packages.size(), classes, nestedClasses);
        if (classes < 9000)
            throw new AssertionError("Too few classes in PLATFORM_CLASS_PATH ;-)");
        if (packages.size() < 530)
            throw new AssertionError("Too few packages in PLATFORM_CLASS_PATH ;-)");
        if (nestedClasses < 3000)
            throw new AssertionError("Too few nested classes in PLATFORM_CLASS_PATH ;-)");
    }
    
    static boolean haveAltRt() {
        String bootClassPath = System.getProperty("sun.boot.class.path");
        for (String cp : bootClassPath.split(File.pathSeparator)) {
            if (cp.endsWith("alt-rt.jar")) {
                System.err.println("Warning: detected alt-rt.jar in "
                        + "sun.boot.class.path");
                return true;
            }
        }
        return false;
    }
}
