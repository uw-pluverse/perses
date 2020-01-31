



package ntype;

import java.lang.annotation.*;

@Retention(RetentionPolicy.RUNTIME)
@interface NestedEnum1 {
    enum Quality { GOOD, BAD, AVERAGE }
    Quality value();
}

@NestedEnum1(NestedEnum1.Quality.GOOD)
class AnnotationDriverTest {
    public void assertion1() {
    }
    public static void main(String args[]) {
        AnnotationDriverTest ref = new AnnotationDriverTest();
        ref.assertion1();
    }
}
