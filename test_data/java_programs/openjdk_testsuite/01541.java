





import java.util.*;

interface Intf {
    List<String> m();
}

class UncheckedImplement implements Intf {
    public List m() { return null; }
}
