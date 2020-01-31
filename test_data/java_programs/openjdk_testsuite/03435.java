

import java.util.List;

class T7126754 {
    List<? extends List<? extends String>> c = null;
    List<List<? extends String>> d = (List<List<? extends String>>)c;
}
