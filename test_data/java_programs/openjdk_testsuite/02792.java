

import java.lang.reflect.Constructor;
import java.lang.annotation.Documented;

class T6400189a {
    Constructor c = null;
    Documented d = c.getAnnotation(Documented.class);
}
