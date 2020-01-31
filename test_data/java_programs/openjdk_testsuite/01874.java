

import java.lang.annotation.*;
import java.lang.annotation.Retention;
import java.lang.annotation.RetentionPolicy;

@Retention(RetentionPolicy.RUNTIME)
@Repeatable(BarContainerContainer.class)
public @interface BarContainer {
    Bar[] value();
}
