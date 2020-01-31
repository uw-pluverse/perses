



import java.lang.annotation.*;

@Target(ElementType.METHOD)
@interface Anno { }


@Anno()
class AnnoNotApplicable { }
