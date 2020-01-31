



import java.lang.annotation.*;

@Retention(RetentionPolicy.RUNTIME)
@Repeatable(Annos.class)
@interface Anno { }

@interface Annos { Anno[] value(); }

@Anno
@Anno
class RepeatableRetentionMismatch { }
