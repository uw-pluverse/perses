

import java.lang.reflect.Method;
import static java.lang.reflect.Modifier.*;

public class T6520152 {
    public static void main(String [] args) throws Exception {
        Class clazz = Class.forName("T$1");
        if ((clazz.getModifiers() & FINAL) != 0) {
            throw new RuntimeException("Failed: " + clazz.getName() + " shouldn't be marked final.");
        }
    }
}
