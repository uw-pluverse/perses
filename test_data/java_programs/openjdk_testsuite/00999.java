




import java.lang.annotation.*;

@Anno(req = true)
@Anno()
public class CannotCompileRepeatedAnnoTest {
}

@Repeatable(Container.class)
@interface Anno {
    boolean req() default false;
}

@interface Container{
    Anno[] value();
}
