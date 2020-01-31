


class TargetType61 {

    interface Stream<T> {
        void forEach(Sink<? super T> sink);
    }

    interface Sink<T> {
        void put(T t);
    }

    public boolean add(CharSequence s) { return false; }

    public void addAll(Stream<? extends CharSequence> stream) {
        stream.forEach(this::add);
        stream.forEach(e -> { add(e); });
    }
}
