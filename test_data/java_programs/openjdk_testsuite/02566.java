

import java.lang.annotation.ElementType;
import java.lang.annotation.Target;
import java.util.List;

class DeclarationAnnotation {
    List<@DA ? extends Object> bad;
    List<@TA ? extends Object> good;
}

@interface DA { }

@Target(ElementType.TYPE_USE)
@interface TA { }
