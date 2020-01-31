



package rawClient;

import java.util.*;


class Vend {
    static void cs(Collection<String> cs) {}
}


class Main {
    void f(Collection c) {
        Vend.cs(Collections.unmodifiableCollection(c));
    }
}
