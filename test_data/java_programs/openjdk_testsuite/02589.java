

import java.lang.annotation.*;
import java.util.List;

class CantAnnotatePackages {
    
    @TA java.lang.Object of1;

    
    

    List<@TA java.lang.Object> of2;
    java. @TA lang.Object of3;
    List<java. @TA lang.Object> of4;

    
}

@Target(ElementType.TYPE_USE)
@interface TA { }
