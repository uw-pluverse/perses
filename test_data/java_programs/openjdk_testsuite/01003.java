



package capture3;

class Q<T> {
    void enqueue(Ref<? extends T> r) {
    }
}

class Ref<T> {
    Q<? super T> queue;

    void enqueue() {
        this.queue.enqueue(this);
    }
}
