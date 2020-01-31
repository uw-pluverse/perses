



interface Iface {
    <T extends Enum<T> & Iface> void doThis(T e);
}
