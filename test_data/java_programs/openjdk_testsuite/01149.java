








import java.util.*;

class WhereFreshTvar {
    <T extends List<T>> T m() {}

    { Object o = (List<String>)m(); }
}
