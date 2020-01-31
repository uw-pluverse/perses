import java.lang.annotation.*;


class MissingAnnotationValue<K extends @A Object> {
}

@Target(ElementType.TYPE_USE)
@interface A { int field(); }
