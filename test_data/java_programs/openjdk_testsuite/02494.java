
import java.util.HashSet;
import java.util.Set;

import javax.annotation.processing.*;
import javax.lang.model.SourceVersion;
import javax.lang.model.element.*;
import javax.lang.model.util.ElementFilter;

import com.sun.source.util.JavacTask;
import com.sun.source.util.TaskEvent;
import com.sun.source.util.TaskListener;
import com.sun.tools.javac.main.JavaCompiler;
import com.sun.tools.javac.processing.JavacProcessingEnvironment;
import com.sun.tools.javac.util.Context;

import static com.sun.tools.javac.comp.CompileStates.CompileState;



@SupportedAnnotationTypes("*")
public class PackageProcessor extends AbstractProcessor {

    private final AttributionTaskListener listener = new AttributionTaskListener();
    private final Set<Name> elements = new HashSet<Name>();

    @Override
    public final void init(ProcessingEnvironment env) {
        super.init(env);
        JavacTask.instance(env).addTaskListener(listener);
        Context ctx = ((JavacProcessingEnvironment)processingEnv).getContext();
        JavaCompiler compiler = JavaCompiler.instance(ctx);
        compiler.shouldStopPolicyIfNoError = CompileState.max(compiler.shouldStopPolicyIfNoError,
                CompileState.FLOW);
    }

    @Override
    public final boolean process(Set<? extends TypeElement> annotations,
            RoundEnvironment roundEnv) {
        for (TypeElement elem : ElementFilter.typesIn(roundEnv.getRootElements())) {
            elements.add(elem.getQualifiedName());
        }
        return false;
    }

    @Override
    public SourceVersion getSupportedSourceVersion() {
        return SourceVersion.latest();
    }

    private final class AttributionTaskListener implements TaskListener {
        @Override
        public void started(TaskEvent e) { }

        @Override
        public void finished(TaskEvent e) {
            if (e.getKind() != TaskEvent.Kind.ANALYZE)
                return;

            if (!elements.remove(e.getTypeElement().getQualifiedName()))
                return;

            if (e.getTypeElement().getSimpleName().contentEquals("MyClass")) {
                Element owner = e.getTypeElement().getEnclosingElement();
                if (owner.getKind() != ElementKind.PACKAGE)
                    throw new RuntimeException("class owner should be a package: " + owner);
                if (owner.getAnnotationMirrors().size() != 1)
                    throw new RuntimeException("the owner package should have one annotation: " + owner);
            }
        }
    }

}
