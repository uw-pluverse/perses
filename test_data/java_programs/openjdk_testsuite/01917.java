

package p;

import java.lang.annotation.Repeatable;

public class R {

    @Repeatable(RR.class)
    public @interface Q {}
}
