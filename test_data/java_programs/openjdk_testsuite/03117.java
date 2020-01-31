


public class T8023558a {
    interface SAM<T> {
        T get();
    }

    static class K<T> implements SAM<T> {
        public T get() {
            return (T)this;
        }
    }

    public static void main(String[] args) {
        SAM<SAM> sam = new SAM<SAM>() { public SAM get() { return new K<>(); } };
        SAM temp = sam.get()::get;
    }
}
