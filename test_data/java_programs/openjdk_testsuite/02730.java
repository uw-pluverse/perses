

import java.util.HashSet;
import java.util.Set;

class Warning
{
    static void useUnchecked() {
        Set s = new HashSet<String>();
        s.add("abc");
    }
}
