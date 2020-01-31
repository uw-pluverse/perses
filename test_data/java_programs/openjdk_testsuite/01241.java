



import java.lang.annotation.*;

@Inherited
@Repeatable(Annos.class)
@interface Anno { }

@interface Annos { Anno[] value(); }

@Anno
@Anno
class RepeatableInheritedMismatch { }
