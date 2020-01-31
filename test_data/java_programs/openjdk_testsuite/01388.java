





import java.util.*;

interface Intf {
    List<String> m();
}

interface UncheckedClash extends Intf {
    public List m();
}
