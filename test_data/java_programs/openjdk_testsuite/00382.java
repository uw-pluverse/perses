



public class RefQueueBug<T> {
    final RefQueue<? super T> queue = new RefQueue<>();
    public static void main(String[] args) {
        RefQueueBug<Object> r = new RefQueueBug<>();
        RefQueue<Object> q = r.queue;
    }
}
