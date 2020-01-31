



import java.lang.annotation.Annotation;
import java.util.Collections;
import java.util.Set;
import java.util.HashSet;
import java.util.Arrays;
import javax.annotation.processing.*;
import javax.lang.model.element.*;
import static javax.lang.model.util.ElementFilter.*;


@AnnotatedElementInfo(annotationName="java.lang.SuppressWarnings", expectedSize=0, names={})
public class TestElementsAnnotatedWith extends JavacTestingAbstractProcessor {

    public boolean process(Set<? extends TypeElement> annotations,
                           RoundEnvironment roundEnvironment) {
        TypeElement annotatedElementInfoElement =
            elements.getTypeElement("AnnotatedElementInfo");
        Set<? extends Element> resultsMeta = Collections.emptySet();
        Set<? extends Element> resultsBase = Collections.emptySet();

        if (!roundEnvironment.processingOver()) {
            testNonAnnotations(roundEnvironment);

            
            

            TypeElement firstType = typesIn(roundEnvironment.getRootElements()).iterator().next();

            AnnotatedElementInfo annotatedElementInfo = firstType.getAnnotation(AnnotatedElementInfo.class);

            boolean failed = false;

            if (annotatedElementInfo == null)
                throw new IllegalArgumentException("Missing AnnotatedElementInfo annotation on " +
                                                  firstType);
            else {
                
                

                Set<String> expectedNames = new HashSet<String>(Arrays.asList(annotatedElementInfo.names()));

                resultsMeta =
                    roundEnvironment.
                    getElementsAnnotatedWith(elements.getTypeElement(annotatedElementInfo.annotationName()));

                if (!resultsMeta.isEmpty())
                    System.err.println("Results: " + resultsMeta);

                if (resultsMeta.size() != annotatedElementInfo.expectedSize()) {
                    failed = true;
                    System.err.printf("Bad number of elements; expected %d, got %d%n",
                                      annotatedElementInfo.expectedSize(), resultsMeta.size());
                } else {
                    for(Element element : resultsMeta) {
                        String simpleName = element.getSimpleName().toString();
                        if (!expectedNames.contains(simpleName) ) {
                            failed = true;
                            System.err.println("Name ``" + simpleName + "'' not expected.");
                        }
                    }
                }
            }

            resultsBase = computeResultsBase(roundEnvironment, annotatedElementInfo.annotationName());

            if (!resultsMeta.equals(resultsBase)) {
                failed = true;
                System.err.println("Base and Meta sets unequal;\n meta: " + resultsMeta +
                                   "\nbase: " + resultsBase);
            }

            if (failed) {
                System.err.println("AnnotatedElementInfo: " + annotatedElementInfo);
                throw new RuntimeException();
            }
        } else {
            
            
            resultsMeta = roundEnvironment.getElementsAnnotatedWith(annotatedElementInfoElement);
            resultsBase = roundEnvironment.getElementsAnnotatedWith(AnnotatedElementInfo.class);
            if (!resultsMeta.isEmpty())
                throw new RuntimeException("Nonempty resultsMeta: " + resultsMeta);
            if (!resultsBase.isEmpty())
                throw new RuntimeException("Nonempty resultsBase: " + resultsBase);

        }
        return true;
    }

    private Set<? extends Element> computeResultsBase(RoundEnvironment roundEnvironment, String name) {
        try {
            return roundEnvironment.
                getElementsAnnotatedWith(Class.forName(name).asSubclass(Annotation.class));
        } catch(ClassNotFoundException cnfe) {
            throw new RuntimeException(cnfe);
        }
    }

    
    private void testNonAnnotations(RoundEnvironment roundEnvironment) {
        try {
            Set<? extends Element> elements = roundEnvironment.getElementsAnnotatedWith((Class)Object.class );
            throw new RuntimeException("Illegal argument exception not thrown");
        } catch(IllegalArgumentException iae) {}

        try {
            Set<? extends Element> elements =
                roundEnvironment.getElementsAnnotatedWith(processingEnv.
                                                          getElementUtils().
                                                          getTypeElement("java.lang.Object") );
            throw new RuntimeException("Illegal argument exception not thrown");
        } catch(IllegalArgumentException iae) {}
    }
}
