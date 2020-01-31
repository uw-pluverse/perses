



import java.lang.annotation.*;

@Repeatable(Annos.class)
@interface Anno { }

@interface Annos { Anno[] value(); }

@Anno
@Anno
@Annos(@Anno)
class RepeatingAnnotationAndContainer { }
