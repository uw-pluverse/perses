



@AnnotatedElementInfo(annotationName="Anno",
                      expectedSize=1,
                      names={"annotatedParameter"})
public class ParameterAnnotations {
    private void foo(@Anno Object annotatedParameter) {}
}
