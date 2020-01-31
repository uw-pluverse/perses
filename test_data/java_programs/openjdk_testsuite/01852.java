



import java.io.PrintWriter;
import java.lang.annotation.Annotation;
import java.lang.annotation.ElementType;
import java.lang.annotation.Target;
import java.util.Map;
import java.util.Set;

import javax.annotation.processing.ProcessingEnvironment;
import javax.annotation.processing.RoundEnvironment;
import javax.lang.model.AnnotatedConstruct;
import javax.lang.model.element.AnnotationMirror;
import javax.lang.model.element.AnnotationValue;
import javax.lang.model.element.Element;
import javax.lang.model.element.ExecutableElement;
import javax.lang.model.element.TypeElement;
import javax.lang.model.type.ArrayType;
import javax.lang.model.type.ExecutableType;
import javax.lang.model.type.TypeMirror;
import javax.lang.model.type.TypeVariable;
import javax.lang.model.type.WildcardType;
import javax.tools.Diagnostic.Kind;

import com.sun.tools.javac.code.Symbol;
import com.sun.tools.javac.code.Type;
import com.sun.tools.javac.processing.JavacProcessingEnvironment;


public class BasicAnnoTests extends JavacTestingAbstractProcessor {
    DPrinter dprinter;
    PrintWriter out;
    boolean verbose = true;

    @Override
    public void init(ProcessingEnvironment pEnv) {
        super.init(pEnv);
        dprinter = new DPrinter(((JavacProcessingEnvironment) pEnv).getContext());
        out = dprinter.out;
    }

    @Override
    public boolean process(Set<? extends TypeElement> annotations, RoundEnvironment roundEnv) {
        TestElementScanner s = new TestElementScanner();
        for (Element e: roundEnv.getRootElements()) {
            s.scan(e);
        }
        return true;
    }

    void error(Element e, String msg) {
        messager.printMessage(Kind.ERROR, msg, e);
        errors++;
    }

    int errors;

    
    class TestElementScanner extends ElementScanner<Void,Void> {
        public Void scan(Element elem, Void ignore) {
            AnnotationMirror test = getAnnotation(elem, Test.class.getName().replace('$', '.'));
            if (test != null) {
                out.println("Test: " + elem + " " + test);
                TestTypeScanner s = new TestTypeScanner(elem, test);
                s.scan(elem.asType(), null);
                if (getPosn(test) >= s.count)
                    error(elem, "position " + getPosn(test) + " not found");
                if (!s.found) {
                    dprinter.printSymbol("element", (Symbol) elem);
                    dprinter.printType("type", (Type) elem.asType());
                }
                out.println();
            }
            return super.scan(elem, ignore);
        }
    }

    
    class TestTypeScanner extends TypeScanner<Void, Void> {
        Element elem;
        AnnotationMirror test;
        int count = 0;
        boolean found = false;

        TestTypeScanner(Element elem, AnnotationMirror test) {
            this.elem = elem;
            this.test = test;
        }

        @Override
        Void scan(TypeMirror t, Void ignore) {
            if (t == null)
                return DEFAULT_VALUE;
            if (verbose)
                out.println("scan " + count + ": " + t);
            if (count == getPosn(test)) {
                String annoType = getAnnoType(test);
                AnnotationMirror anno = getAnnotation(t, annoType);
                if (anno == null) {
                    error(elem, "annotation not found on " + count + ": " + t);
                } else {
                    String v = getValue(anno, "value").toString();
                    if (v.equals(getExpect(test))) {
                        out.println("found " + anno + " as expected");
                        found = true;
                    } else {
                        error(elem, "Unexpected value: " + v + ", expected: " + getExpect(test));
                    }
                }
            }
            count++;
            return super.scan(t, ignore);
        }
    }

    
    static int getPosn(AnnotationMirror test) {
        AnnotationValue v = getValue(test, "posn");
        return (Integer) v.getValue();
    }

    
    static String getExpect(AnnotationMirror test) {
        AnnotationValue v = getValue(test, "expect");
        return (String) v.getValue();
    }

    
    static String getAnnoType(AnnotationMirror test) {
        AnnotationValue v = getValue(test, "annoType");
        TypeMirror m = (TypeMirror) v.getValue();
        return m.toString();
    }

    
    static AnnotationMirror getAnnotation(AnnotatedConstruct e, String name) {
        for (AnnotationMirror m: e.getAnnotationMirrors()) {
            TypeElement te = (TypeElement) m.getAnnotationType().asElement();
            if (te.getQualifiedName().contentEquals(name)) {
                return m;
            }
        }
        return null;
    }

    
    static AnnotationValue getValue(AnnotationMirror anno, String name) {
        Map<? extends ExecutableElement, ? extends AnnotationValue> map = anno.getElementValues();
        for (Map.Entry<? extends ExecutableElement, ? extends AnnotationValue> e: map.entrySet()) {
            if (e.getKey().getSimpleName().contentEquals(name)) {
                return e.getValue();
            }
        }
        return null;
    }

    
    static class TypeScanner<R, P> extends SimpleTypeVisitor<R, P> {
        @Override
        public R visitArray(ArrayType t, P p) {
            scan(t.getComponentType(), p);
            return super.visitArray(t, p);
        }

        @Override
        public R visitExecutable(ExecutableType t, P p) {
            scan(t.getReceiverType());
            
            scan(t.getParameterTypes(), p);
            
            scan(t.getReturnType(), p);
            
            scan(t.getThrownTypes(), p);
            return super.visitExecutable(t, p);
        }

        @Override
        public R visitTypeVariable(TypeVariable t, P p) {
            scan(t.getLowerBound(), p);
            scan(t.getUpperBound(), p);
            return super.visitTypeVariable(t, p);
        }

        @Override
        public R visitWildcard(WildcardType t, P p) {
            scan(t.getExtendsBound(), p);
            scan(t.getSuperBound(), p);
            return super.visitWildcard(t, p);
        }

        R scan(TypeMirror t) {
            return scan(t, null);
        }

        R scan(TypeMirror t, P p) {
            return (t == null) ? DEFAULT_VALUE : t.accept(this, p);
        }

        R scan(Iterable<? extends TypeMirror> iter, P p) {
            if (iter == null)
                return DEFAULT_VALUE;
            R result = DEFAULT_VALUE;
            for (TypeMirror t: iter)
                result = scan(t, p);
            return result;
        }
    }

    
    @interface Test {
        
        int posn();
        
        Class<? extends Annotation> annoType();
        
        String expect();
    }

    
    @Target(ElementType.TYPE_USE)
    public @interface TA {
        int value();
    }

    @Test(posn=0, annoType=TA.class, expect="1")
    public @TA(1) int f1;

    @Test(posn=0, annoType=TA.class, expect="2")
    public int @TA(2) [] f2;

    @Test(posn=1, annoType=TA.class, expect="3")
    public @TA(3) int [] f3;

    @Test(posn=1, annoType=TA.class, expect="4")
    public int m1(@TA(4) float a) throws Exception { return 0; }

    @Test(posn=2, annoType=TA.class, expect="5")
    public @TA(5) int m2(float a) throws Exception { return 0; }

    @Test(posn=3, annoType=TA.class, expect="6")
    public int m3(float a) throws @TA(6) Exception { return 0; }
}
