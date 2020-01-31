



class T6390045b {
    short s;
    Object o;
    Object p = choose(o, s);
    <T> T choose(T t1, T t2) { return t1; }
}
