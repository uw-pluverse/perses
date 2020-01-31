

import java.lang.annotation.*;
import java.util.Map;



class TopLevelBlocks {
    static Object f;

    {
        f = new @A Object();
    }

    static final Object sf;

    static {
        sf = new @A Object();
    }
}

@Target({ElementType.TYPE_USE, ElementType.TYPE_PARAMETER})
@interface A { }
