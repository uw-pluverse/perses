




class Value<T> {
    public T value;
}

class IntegerValue extends Value<Integer> {
    void increment() {
        value = value + 1;
        value += 1;
    }
}
