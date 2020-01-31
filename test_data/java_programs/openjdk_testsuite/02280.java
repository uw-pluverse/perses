

import java.util.*;
import javax.annotation.processing.*;
import javax.lang.model.SourceVersion;
import javax.lang.model.util.*;
import static javax.lang.model.SourceVersion.*;


public abstract class JavacTestingAbstractProcessor extends AbstractProcessor {
    private static final Set<String> allAnnotations;

    static {
        Set<String> tmp = new HashSet<>();
        tmp.add("*");
        allAnnotations = Collections.unmodifiableSet(tmp);
    }

    protected Elements eltUtils;
    protected Elements elements;
    protected Types    typeUtils;
    protected Types    types;
    protected Filer    filer;
    protected Messager messager;
    protected Map<String, String> options;

    
    protected JavacTestingAbstractProcessor() {
        super();
    }

    
    @Override
    public SourceVersion getSupportedSourceVersion() {
        SupportedSourceVersion ssv = this.getClass().getAnnotation(SupportedSourceVersion.class);
        if (ssv != null)
            throw new IllegalStateException("SupportedSourceVersion annotation not supported here.");

        return SourceVersion.latest();
    }

    
    @Override
    public Set<String> getSupportedAnnotationTypes() {
        SupportedAnnotationTypes sat = this.getClass().getAnnotation(SupportedAnnotationTypes.class);
        if (sat != null)
            return super.getSupportedAnnotationTypes();
        else
            return allAnnotations;
    }

    @Override
    public void init(ProcessingEnvironment processingEnv) {
        super.init(processingEnv);
        elements = eltUtils  = processingEnv.getElementUtils();
        types = typeUtils = processingEnv.getTypeUtils();
        filer     = processingEnv.getFiler();
        messager  = processingEnv.getMessager();
        options   = processingEnv.getOptions();
    }

    

    @SupportedSourceVersion(RELEASE_8)
    public static abstract class AbstractAnnotationValueVisitor<R, P> extends AbstractAnnotationValueVisitor8<R, P> {

        
        protected AbstractAnnotationValueVisitor() {
            super();
        }
    }

    @SupportedSourceVersion(RELEASE_8)
    public static abstract class AbstractElementVisitor<R, P> extends AbstractElementVisitor8<R, P> {
        
        protected AbstractElementVisitor(){
            super();
        }
    }

    @SupportedSourceVersion(RELEASE_8)
    public static abstract class AbstractTypeVisitor<R, P> extends AbstractTypeVisitor8<R, P> {
        
        protected AbstractTypeVisitor() {
            super();
        }
    }

    @SupportedSourceVersion(RELEASE_8)
    public static class ElementKindVisitor<R, P> extends ElementKindVisitor8<R, P> {
        
        protected ElementKindVisitor() {
            super(null);
        }

        
        protected ElementKindVisitor(R defaultValue) {
            super(defaultValue);
        }
    }

    @SupportedSourceVersion(RELEASE_8)
    public static class ElementScanner<R, P> extends ElementScanner8<R, P> {
        
        protected ElementScanner(){
            super(null);
        }

        
        protected ElementScanner(R defaultValue){
            super(defaultValue);
        }
    }

    @SupportedSourceVersion(RELEASE_8)
    public static class SimpleAnnotationValueVisitor<R, P> extends SimpleAnnotationValueVisitor8<R, P> {
        
        protected SimpleAnnotationValueVisitor() {
            super(null);
        }

        
        protected SimpleAnnotationValueVisitor(R defaultValue) {
            super(defaultValue);
        }
    }

    @SupportedSourceVersion(RELEASE_8)
    public static class SimpleElementVisitor<R, P> extends SimpleElementVisitor8<R, P> {
        
        protected SimpleElementVisitor(){
            super(null);
        }

        
        protected SimpleElementVisitor(R defaultValue){
            super(defaultValue);
        }
    }

    @SupportedSourceVersion(RELEASE_8)
    public static class SimpleTypeVisitor<R, P> extends SimpleTypeVisitor8<R, P> {
        
        protected SimpleTypeVisitor(){
            super(null);
        }

        
        protected SimpleTypeVisitor(R defaultValue){
            super(defaultValue);
        }
    }

    @SupportedSourceVersion(RELEASE_8)
    public static class TypeKindVisitor<R, P> extends TypeKindVisitor8<R, P> {
        
        protected TypeKindVisitor() {
            super(null);
        }

        
        protected TypeKindVisitor(R defaultValue) {
            super(defaultValue);
        }
    }
}
