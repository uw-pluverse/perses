






class VisibleBridge {
    static {
        Object o = "b";
        if ("a".compareTo(o) > 0) {}
    }
}
