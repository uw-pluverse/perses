




class StaticNotQualifiedByType {
    int m(Other other) {
        return other.i;
    }
}

class Other {
    static int i;
}
