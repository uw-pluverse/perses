


import java.lang.annotation.*;

class TypeAndField {
    @TA Integer i;
    @TA int j;
}

@Retention(RetentionPolicy.CLASS)
@Target({ElementType.TYPE_USE, ElementType.FIELD})
@interface TA { }
