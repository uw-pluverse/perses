

import java.lang.annotation.Annotation;
import java.util.Arrays;
import java.util.EnumSet;
import java.util.List;
import java.util.Set;
import javax.annotation.processing.*;
import javax.lang.model.element.*;
import javax.lang.model.type.MirroredTypeException;
import javax.lang.model.type.TypeMirror;
import javax.lang.model.util.Elements;

public class ElementRepAnnoTester extends JavacTestingAbstractProcessor {
    
    final EnumSet<TestMethod> ALL_TEST_METHODS = EnumSet.allOf(TestMethod.class);
    int count = 0;
    int error = 0;

    public boolean process(Set<? extends TypeElement> annotations,
            RoundEnvironment roundEnv) {
        if (!roundEnv.processingOver()) {
            List<String> superClass = Arrays.asList("A", "B", "C", "D", "E",
                    "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P");
            
            for (Element element : roundEnv.getRootElements()) {
                
                if (element.getKind() == ElementKind.CLASS
                        && !superClass.contains(element.getSimpleName().toString())) {
                    
                    checkAnnoValues(element, ALL_TEST_METHODS);
                    
                    for (Element elements : element.getEnclosedElements()) {
                        
                        if (elements.getKind() == ElementKind.METHOD
                                && elements.getSimpleName().toString().equals("testMethod")) {
                            checkAnnoValues(elements, ALL_TEST_METHODS);
                        }
                        
                        if (elements.getKind() == ElementKind.FIELD
                                && elements.getSimpleName().toString().equals("testField")) {
                            checkAnnoValues(elements, ALL_TEST_METHODS);
                        }
                    }
                }
            }

            if (error != 0) {
                System.out.println("Total tests : " + count);
                System.out.println("Total test failures : " + error);
                throw new RuntimeException();
            } else {
                System.out.println("ALL TESTS PASSED. " + count);
            }
        }
        return true;
    }

    enum TestMethod {
        getAnnotation,
        getAnnotationsByType,
        getAllAnnotationMirrors,
        getAnnotationMirrors
    }

    protected void checkAnnoValues(Element element, EnumSet<TestMethod> testMethods) {
        boolean baseAnnoPresent = false;
        boolean conAnnoPresent = false;
        ExpectedBase eb = null;
        ExpectedContainer ec = null;
        
        eb = element.getAnnotation(ExpectedBase.class);
        ec = element.getAnnotation(ExpectedContainer.class);

        if (eb == null) {
            System.out.println("Did not find ExpectedBase Annotation in  "
                    + element.getSimpleName().toString() + ", Test will exit");
            throw new RuntimeException();
        }
        if (ec == null) {
            System.out.println("Did not find ExpectedContainer Annotation in "
                    + element.getSimpleName().toString() + " Test will exit");
            throw new RuntimeException();
        }
        
        TypeMirror valueBase = null;
        TypeMirror valueCon = null;

        try {
            eb.value();
        } catch (MirroredTypeException mte) {
            valueBase = mte.getTypeMirror();
        }

        try {
            ec.value();
        } catch (MirroredTypeException mte1) {
            valueCon = mte1.getTypeMirror();
        }

        String expectedBaseAnno = valueBase.toString();
        String expectedConAnno = valueCon.toString();

        if (!expectedBaseAnno.equals("java.lang.annotation.Annotation")) {
            baseAnnoPresent = true;
        }
        if (!expectedConAnno.equalsIgnoreCase("java.lang.annotation.Annotation")) {
            conAnnoPresent = true;
        }

        
        for (TestMethod testMethod : testMethods) {
            boolean isBasePass = true;
            boolean isConPass = true;

            switch (testMethod) {
                case getAnnotation:
                    if (baseAnnoPresent) {
                        count++;
                        Annotation actualAnno = getAnnotationBase(element);
                        String expectedAnno = eb.getAnnotation();
                        isBasePass = compareAnnotation(actualAnno, expectedAnno);
                    }
                    if (conAnnoPresent) {
                        count++;
                        Annotation actualAnno = getAnnotationContainer(element);
                        String expectedAnno = ec.getAnnotation();
                        isConPass = compareAnnotation(actualAnno, expectedAnno);
                    }
                    if (!isBasePass || !isConPass) {
                        System.out.println("FAIL in " + element.getSimpleName()
                                + "-" + element.getKind()
                                + " method: getAnnotation(class <T>)");
                        error++;
                    }
                    break;

                case getAnnotationMirrors:
                    if (baseAnnoPresent) {
                        count++;
                        List<? extends AnnotationMirror> actualDeclAnnos =
                                element.getAnnotationMirrors();
                        String[] expectedAnnos = eb.getAnnotationMirrors();
                        isBasePass = compareArrVals(actualDeclAnnos, expectedAnnos);
                    }
                    if (conAnnoPresent) {
                        isConPass = true;
                    }
                    if (!isBasePass || !isConPass) {
                        System.out.println("FAIL in " + element.getSimpleName()
                                + "-" + element.getKind()
                                + " method: getAnnotationMirrors()");
                        error++;
                    }
                    break;

                case getAnnotationsByType:
                    if (baseAnnoPresent) {
                        count++;
                        Annotation[] actualAnnosArgs = getAnnotationsBase(element);
                        String[] expectedAnnos = eb.getAnnotationsByType();
                        isBasePass = compareArrVals(actualAnnosArgs, expectedAnnos);
                    }
                    if (conAnnoPresent) {
                        count++;
                        Annotation[] actualAnnosArgs = getAnnotationsContainer(element);
                        String[] expectedAnnos = ec.getAnnotationsByType();
                        isConPass = compareArrVals(actualAnnosArgs, expectedAnnos);
                    }
                    if (!isBasePass || !isConPass) {
                        System.out.println("FAIL in " + element.getSimpleName()
                                + "-" + element.getKind()
                                + " method: getAnnotationsByType(class <T>)");
                        error++;
                    }
                    break;

                case getAllAnnotationMirrors:
                    if (baseAnnoPresent) {
                        count++;
                        Elements elements = processingEnv.getElementUtils();
                        List<? extends AnnotationMirror> actualAnnosMirrors =
                                elements.getAllAnnotationMirrors(element);
                        String[] expectedAnnos = eb.getAllAnnotationMirrors();
                        isBasePass = compareArrVals(actualAnnosMirrors, expectedAnnos);
                    }
                    if (conAnnoPresent) {
                        isConPass = true;
                    }
                    if (!isBasePass || !isConPass) {
                        System.out.println("FAIL in " + element.getSimpleName()
                                + "-" + element.getKind()
                                + " method: getAllAnnotationMirrors(e)");
                        error++;
                    }
                    break;
            }
        }
    }
    
    final List<String> singularAnno = Arrays.asList(
            "SingularBasicTest"
            );
    final List<String> singularInheritedAnno = Arrays.asList(
            "SingularInheritedATest"
            );
    final List<String> repeatableAnno = Arrays.asList(
            "RepeatableBasicTest",
            "MixRepeatableAndOfficialContainerBasicTest",
            "OfficialContainerBasicTest",
            "RepeatableOfficialContainerBasicTest"
            );
    final List<String> repeatableInheritedAnno = Arrays.asList(
            "RepeatableInheritedTest",
            "RepeatableOverrideATest",
            "RepeatableOverrideBTest",
            "OfficialContainerInheritedTest",
            "MixRepeatableAndOfficialContainerInheritedA1Test",
            "MixRepeatableAndOfficialContainerInheritedB1Test",
            "MixRepeatableAndOfficialContainerInheritedA2Test",
            "MixRepeatableAndOfficialContainerInheritedB2Test"
            );
    final List<String> repeatableContainerInheritedAnno = Arrays.asList(
            "RepeatableOfficialContainerInheritedTest"
            );
    final List<String> unofficialAnno = Arrays.asList(
            "UnofficialContainerBasicTest",
            "MixSingularAndUnofficialContainerBasicTest"
            );
    final List<String> unofficialInheritedAnno = Arrays.asList(
            "UnofficialContainerInheritedTest",
            "SingularInheritedBTest",
            "MixSingularAndUnofficialContainerInheritedA1Test",
            "MixSingularAndUnofficialContainerInheritedB1Test",
            "MixSingularAndUnofficialContainerInheritedA2Test",
            "MixSingularAndUnofficialContainerInheritedB2Test"
            );
    
    final List<String> repeatableAnnoContainer = repeatableAnno;
    final List<String> repeatableInheritedAnnoContainer = repeatableInheritedAnno;
    final List<String> repeatableContainerInheritedAnnoContainer =
            repeatableContainerInheritedAnno;
    final List<String> unofficialAnnoContainer = unofficialAnno;
    final List<String> unofficialInheritedAnnoContainer = unofficialInheritedAnno;

    
    private Annotation specialAnno = new Annotation() {
       @Override
        public Class annotationType() {
            return null;
        }
    };
    private Annotation[] specialAnnoArray = new Annotation[1];
    private List<AnnotationMirror> specialAnnoMirrors =
            new java.util.ArrayList<AnnotationMirror>(2);

    private Annotation getAnnotationBase(Element e) {
        Annotation actualAnno = specialAnno;

        if (singularAnno.contains(
                e.getEnclosingElement().toString())
                || singularAnno.contains(
                e.getSimpleName().toString())
                || unofficialAnno.contains(
                e.getEnclosingElement().toString())
                || unofficialAnno.contains(
                e.getSimpleName().toString())) {
            actualAnno = e.getAnnotation(Foo.class);
        }
        if (singularInheritedAnno.contains(
                e.getEnclosingElement().toString())
                || singularInheritedAnno.contains(
                e.getSimpleName().toString())
                || unofficialInheritedAnno.contains(
                e.getEnclosingElement().toString())
                || unofficialInheritedAnno.contains(
                e.getSimpleName().toString())) {
            actualAnno = e.getAnnotation(FooInherited.class);
        }
        if (repeatableAnno.contains(
                e.getEnclosingElement().toString())
                || repeatableAnno.contains(
                e.getSimpleName().toString())) {
            actualAnno = e.getAnnotation(Bar.class);
        }
        if (repeatableInheritedAnno.contains(
                e.getEnclosingElement().toString())
                || repeatableInheritedAnno.contains(
                e.getSimpleName().toString())) {
            actualAnno = e.getAnnotation(BarInherited.class);
        }
        if (repeatableContainerInheritedAnno.contains(
                e.getEnclosingElement().toString())
                || repeatableContainerInheritedAnno.contains(
                e.getSimpleName().toString())) {
            actualAnno = e.getAnnotation(BarInheritedContainer.class);
        }
        return actualAnno;
    }

    private Annotation getAnnotationContainer(Element e) {
        Annotation actualAnno = specialAnno;

        if (repeatableAnnoContainer.contains(
                e.getEnclosingElement().toString())
                || repeatableAnnoContainer.contains(
                e.getSimpleName().toString())) {
            actualAnno = e.getAnnotation(BarContainer.class);
        }
        if (repeatableInheritedAnnoContainer.contains(
                e.getEnclosingElement().toString())
                || repeatableInheritedAnnoContainer.contains(
                e.getSimpleName().toString())) {
            actualAnno = e.getAnnotation(BarInheritedContainer.class);
        }
        if (repeatableContainerInheritedAnnoContainer.contains(
                e.getEnclosingElement().toString())
                || repeatableContainerInheritedAnnoContainer.contains(
                e.getSimpleName().toString())) {
            actualAnno = e.getAnnotation(BarInheritedContainerContainer.class);
        }
        if (unofficialAnnoContainer.contains(
                e.getEnclosingElement().toString())
                || unofficialAnnoContainer.contains(
                e.getSimpleName().toString())) {
            actualAnno = e.getAnnotation(UnofficialContainer.class);
        }
        if (unofficialInheritedAnnoContainer.contains(
                e.getEnclosingElement().toString())
                || unofficialInheritedAnnoContainer.contains(
                e.getSimpleName().toString())) {
            actualAnno = e.getAnnotation(UnofficialInheritedContainer.class);
        }
        return actualAnno;
    }

    private Annotation[] getAnnotationsBase(Element e) {
        Annotation[] actualAnnosArgs = specialAnnoArray;

        if (singularAnno.contains(
                e.getEnclosingElement().toString())
                || singularAnno.contains(
                e.getSimpleName().toString())
                || unofficialAnno.contains(
                e.getEnclosingElement().toString())
                || unofficialAnno.contains(
                e.getSimpleName().toString())) {
            actualAnnosArgs = e.getAnnotationsByType(Foo.class);
        }
        if (singularInheritedAnno.contains(
                e.getEnclosingElement().toString())
                || singularInheritedAnno.contains(
                e.getSimpleName().toString())
                || unofficialInheritedAnno.contains(
                e.getEnclosingElement().toString())
                || unofficialInheritedAnno.contains(
                e.getSimpleName().toString())) {
            actualAnnosArgs = e.getAnnotationsByType(FooInherited.class);
        }
        if (repeatableAnno.contains(
                e.getEnclosingElement().toString())
                || repeatableAnno.contains(
                e.getSimpleName().toString())) {
            actualAnnosArgs = e.getAnnotationsByType(Bar.class);
        }
        if (repeatableInheritedAnno.contains(
                e.getEnclosingElement().toString())
                || repeatableInheritedAnno.contains(
                e.getSimpleName().toString())) {
            actualAnnosArgs = e.getAnnotationsByType(BarInherited.class);
        }
        if (repeatableContainerInheritedAnno.contains(
                e.getEnclosingElement().toString())
                || repeatableContainerInheritedAnno.contains(
                e.getSimpleName().toString())) {
            actualAnnosArgs = e.getAnnotationsByType(BarInheritedContainer.class);
        }
        return actualAnnosArgs;
    }

    private Annotation[] getAnnotationsContainer(Element e) {
        Annotation[] actualAnnosArgs = specialAnnoArray;

        if (repeatableAnnoContainer.contains(
                e.getEnclosingElement().toString())
                || repeatableAnnoContainer.contains(
                e.getSimpleName().toString())) {
            actualAnnosArgs = e.getAnnotationsByType(BarContainer.class);
        }
        if (repeatableInheritedAnnoContainer.contains(
                e.getEnclosingElement().toString())
                || repeatableInheritedAnnoContainer.contains(
                e.getSimpleName().toString())) {
            actualAnnosArgs = e.getAnnotationsByType(BarInheritedContainer.class);
        }
        if (repeatableContainerInheritedAnnoContainer.contains(
                e.getEnclosingElement().toString())
                || repeatableContainerInheritedAnnoContainer.contains(
                e.getSimpleName().toString())) {
            actualAnnosArgs = e.getAnnotationsByType(BarInheritedContainerContainer.class);
        }
        if (unofficialAnnoContainer.contains(
                e.getEnclosingElement().toString())
                || unofficialAnnoContainer.contains(
                e.getSimpleName().toString())) {
            actualAnnosArgs = e.getAnnotationsByType(UnofficialContainer.class);
        }
        if (unofficialInheritedAnnoContainer.contains(
                e.getEnclosingElement().toString())
                || unofficialInheritedAnnoContainer.contains(
                e.getSimpleName().toString())) {
            actualAnnosArgs = e.getAnnotationsByType(UnofficialInheritedContainer.class);
        }
        return actualAnnosArgs;
    }

    
    
    private boolean compareArrVals(Annotation[] actualAnnos, String[] expectedAnnos) {
        
        if (actualAnnos == specialAnnoArray) {
            return false; 
        }
        if (actualAnnos.length != expectedAnnos.length) {
            System.out.println("Length not same. "
                    + " actualAnnos length = " + actualAnnos.length
                    + " expectedAnnos length = " + expectedAnnos.length);
            printArrContents(actualAnnos);
            printArrContents(expectedAnnos);
            return false;
        } else {
            int i = 0;
            String[] actualArr = new String[actualAnnos.length];
            for (Annotation a : actualAnnos) {
                actualArr[i++] = a.toString();
            }
            List<String> actualList = Arrays.asList(actualArr);
            List<String> expectedList = Arrays.asList(expectedAnnos);

            if (!actualList.containsAll(expectedList)) {
                System.out.println("Array values are not same");
                printArrContents(actualAnnos);
                printArrContents(expectedAnnos);
                return false;
            }
        }
        return true;
    }

    
    
    private boolean compareArrVals(List<? extends AnnotationMirror> actualAnnos,
            String[] expectedAnnos) {
        
        if (actualAnnos == specialAnnoMirrors) {
            return false; 
        }
        if (actualAnnos.size() != expectedAnnos.length) {
            System.out.println("Length not same. "
                    + " actualAnnos length = " + actualAnnos.size()
                    + " expectedAnnos length = " + expectedAnnos.length);
            printArrContents(actualAnnos);
            printArrContents(expectedAnnos);
            return false;
        } else {
            int i = 0;
            String[] actualArr = new String[actualAnnos.size()];
            String annoTypeName = "";
            for (AnnotationMirror annotationMirror : actualAnnos) {
                if (annotationMirror.getAnnotationType().toString().contains("Expected")) {
                    annoTypeName = annotationMirror.getAnnotationType().toString();
                } else {
                     annoTypeName = annotationMirror.toString();
                }
                actualArr[i++] = annoTypeName;
            }
            List<String> actualList = Arrays.asList(actualArr);
            List<String> expectedList = Arrays.asList(expectedAnnos);

            if (!actualList.containsAll(expectedList)) {
                System.out.println("Array values are not same");
                printArrContents(actualAnnos);
                printArrContents(expectedAnnos);
                return false;
            }
        }
        return true;
    }

    private void printArrContents(Annotation[] actualAnnos) {
        for (Annotation a : actualAnnos) {
            System.out.println("actualAnnos values = " + a);
        }
    }

    private void printArrContents(String[] expectedAnnos) {
        for (String s : expectedAnnos) {
            System.out.println("expectedAnnos values =  " + s);
        }
    }

    private void printArrContents(List<? extends AnnotationMirror> actualAnnos) {
        for (AnnotationMirror annotationMirror : actualAnnos) {
            System.out.println("actualAnnos values = " + annotationMirror);
        }
    }

    private boolean compareAnnotation(Annotation actualAnno, String expectedAnno) {
        
        boolean isSame = true;
        
        if (actualAnno == specialAnno) {
            return false; 
        }
        if (actualAnno != null) {
            if (!actualAnno.toString().equalsIgnoreCase(expectedAnno)) {
                System.out.println("Anno did not match. "
                        + " expectedAnno = " + expectedAnno
                        + " actualAnno = " + actualAnno);
                isSame = false;
            } else {
                isSame = true;
            }
        } else {
            if (expectedAnno.compareToIgnoreCase("null") == 0) {
                isSame = true;
            } else {
                System.out.println("Actual anno is null");
                isSame = false;
            }
        }
        return isSame;
    }
}
