



import java.lang.annotation.*;

@Target({ElementType.TYPE_USE, ElementType.TYPE_PARAMETER})
@interface A {}

class Varargs {

    
    void varargPlain(Object @A... objs) {

    }

    void varargGeneric(Class<?> @A ... clz) {
    }
}
