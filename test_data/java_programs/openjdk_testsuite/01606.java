

class QualifiedNew {
    class Y {}
    class Z {
        Y[] a;
        Object tmp1 = null.new Y();
        Object tmp2 = a.new Y();
    }
}
