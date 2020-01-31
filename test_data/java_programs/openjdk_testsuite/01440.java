



import java.lang.annotation.*;

@Repeatable(Annos.class)
@interface Anno { }

@interface Annos { String value(); }

@Anno
@Anno
class RepeatableWrongValueType { }
