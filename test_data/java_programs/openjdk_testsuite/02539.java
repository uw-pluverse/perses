
import java.lang.annotation.*;

@InnerTA
class Scopes<@InnerTA T extends @InnerTA Object> {
    
    
    @Target(ElementType.TYPE_USE)
    @interface InnerTA { };
}
