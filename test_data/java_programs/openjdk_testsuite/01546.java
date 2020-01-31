



import java.lang.annotation.*;

class CantAnnotateNestedType {
    @Target(ElementType.TYPE_USE)
    @interface TA {}

    interface Outer {
        interface Inner {}
    }

    
    @TA Outer.Inner f;

    
    @TA Outer g;
}
