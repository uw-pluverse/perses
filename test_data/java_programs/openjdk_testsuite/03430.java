



import java.lang.ref.*;

public class T6256789 {

    public ExtraRef prob(ReferenceQueue<Object> refQ) throws InterruptedException {
        return ((ExtraRef)refQ.remove());
    }

    public static class ExtraRef extends WeakReference<Object> {
        public ExtraRef(Object value) {
            super(value);
        }
    }
}
