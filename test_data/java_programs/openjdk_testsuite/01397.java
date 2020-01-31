



import java.lang.annotation.*;

class CantAnnotateScoping {
    @Target(ElementType.TYPE_USE)
    @interface TA {}
    @Target(ElementType.TYPE_USE)
    @interface TB {}

    interface Outer {
        interface Inner {}
    }

    
    @TA @TB Outer.Inner f;

    
    @TA @TB Outer g;
}
