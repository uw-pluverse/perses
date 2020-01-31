



import java.lang.annotation.*;

@Repeatable(Annos.class)
@interface Anno { }

@interface Annos {}

@Anno
@Anno
class RepeatableNoValue { }
