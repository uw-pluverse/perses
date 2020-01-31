

import java.lang.annotation.*;


class AnonymousClass {
    Object o1 = new @TA Object() { };
    Object o2 = new @TA Object() { };
}

@Target({ElementType.TYPE_USE, ElementType.TYPE_PARAMETER})
@interface TA { }

@Target({ElementType.TYPE_USE, ElementType.TYPE_PARAMETER})
@interface TB { }
