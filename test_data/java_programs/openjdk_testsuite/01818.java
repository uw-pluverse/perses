



@AnnotatedElementInfo(annotationName="TpAnno",
                      expectedSize=4,
                      names={"T", "A", "B", "C"})
public class TypeParameterAnnotations<@TpAnno T>  {
    private <@TpAnno A> TypeParameterAnnotations(A a) {;}

    public <@TpAnno B> void foo(B b) {return;}

    public static <@TpAnno C> void bar(C b) {return;}
}
