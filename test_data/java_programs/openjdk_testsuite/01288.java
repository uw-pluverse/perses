







import java.lang.annotation.*;

@Repeatable(Annos.class)
@interface Anno { }

@interface Annos { Anno[] value(); String foo(); }

@Anno
@Anno
class InvalidDuplicateAnnotation { }
