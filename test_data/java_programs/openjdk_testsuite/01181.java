



import java.lang.annotation.*;

@Repeatable(Annos.class)
@Target(ElementType.METHOD)
@interface Anno { }

@interface Annos { Anno[] value(); }

class RepeatableTargetMismatch { }
