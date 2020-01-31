



import java.lang.annotation.*;

@Documented
@Repeatable(Annos.class)
@interface Anno { }

@interface Annos { Anno[] value(); }

@Anno
@Anno
class RepeatableDocumentedMismatch { }
