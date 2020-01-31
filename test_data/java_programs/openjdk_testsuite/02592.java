



import java.lang.annotation.*;

class TypeVariable {
    <TV extends  @TA Object> TV cast(TV p) {
        return (@TA TV) p;
    }
}

@Target({ElementType.TYPE_USE, ElementType.TYPE_PARAMETER})
@interface TA {}

