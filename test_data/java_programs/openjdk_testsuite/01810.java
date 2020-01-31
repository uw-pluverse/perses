



@AnnotatedElementInfo(annotationName="java.lang.SuppressWarnings",
                      expectedSize=2,
                      names={"SurfaceAnnotations",
                             "foo"})
@SuppressWarnings("")
public class SurfaceAnnotations {
    @SuppressWarnings("")
    private void foo() {return;};
}
