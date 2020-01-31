
import java.lang.annotation.Repeatable;

@Repeatable(Bridges.class)
@interface Bridge {
    String value();
}
