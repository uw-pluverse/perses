



import java.lang.annotation.*;


class AnnotationTest {

    @Repeatable(Annos.class)
    @interface Anno {
        Class f() default int.class;
    }

    @interface Annos { Anno[] value(); String foo() default "hello"; }

    interface I {
        int m(@Anno @Anno int i, @Anno int ji);
    }

    public AnnotationTest(@Anno @Anno I i, @Anno int ji) { }
    public @Anno String foo(@Anno @Anno I i, int ji) { return null; }
}



