



@AnnotatedElementInfo(annotationName="java.lang.SuppressWarnings",
                      expectedSize=4,
                      names={"foo",
                             "bar",
                             "<init>"})
public class BuriedAnnotations {
    @SuppressWarnings("")
    private BuriedAnnotations() {}

    class Nested {
        @SuppressWarnings("")
        private Nested() {}

        @SuppressWarnings("")
        private void foo() {return;};

        @SuppressWarnings("")
        private void bar() {return;};
    }
}
