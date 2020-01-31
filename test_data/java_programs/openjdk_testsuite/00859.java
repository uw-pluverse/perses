



import java.util.Set;
import javax.annotation.processing.AbstractProcessor;
import javax.annotation.processing.RoundEnvironment;
import javax.annotation.processing.SupportedAnnotationTypes;
import javax.lang.model.element.*;
import javax.lang.model.util.*;
import static javax.tools.Diagnostic.Kind.*;

public class T6350057 extends JavacTestingAbstractProcessor {
    static class LocalVarAllergy extends ElementKindVisitor<Boolean, Void> {
        @Override
        public Boolean visitTypeAsEnum(TypeElement e, Void v) {
            System.out.println("visitTypeAsEnum: " + e.getSimpleName().toString());
            for(Element el: e.getEnclosedElements() )
                this.visit(el);
            return true;
        }

        @Override
        public Boolean visitVariableAsLocalVariable(VariableElement e, Void v){
            throw new IllegalStateException("Should not see any local variables!");
        }

        @Override
        public Boolean visitVariableAsParameter(VariableElement e, Void v){
            String senclm=e.getEnclosingElement().getEnclosingElement().getSimpleName().toString();
            String sEncl = senclm+"."+e.getEnclosingElement().getSimpleName().toString();
            String stype = e.asType().toString();
            String name =  e.getSimpleName().toString();
            System.out.println("visitVariableAsParameter: " +sEncl+"." + stype + " " + name);
            return true;
        }

        @Override
        public Boolean visitExecutableAsMethod(ExecutableElement e, Void v){
            String name=e.getEnclosingElement().getSimpleName().toString();
            name = name + "."+e.getSimpleName().toString();
            System.out.println("visitExecutableAsMethod: " + name);
            for (VariableElement ve: e.getParameters())
                this.visit(ve);
            return true;
        }
    }

    public boolean process(Set<? extends TypeElement> annotations,
                           RoundEnvironment roundEnvironment) {
        if (!roundEnvironment.processingOver())
            for(Element element : roundEnvironment.getRootElements())
                element.accept(new LocalVarAllergy(), null);
        return true;
    }
}
