



import java.lang.annotation.*;

@interface TestAnnotation {
    SuppressWarnings[] value() default {@SuppressWarnings({"",})};
}


@TestAnnotation({@SuppressWarnings({}),
                 @SuppressWarnings({"Beware the ides of March.",}),
                 @SuppressWarnings({"Look both ways", "Before Crossing",}), })
public class TrailingComma {
}
