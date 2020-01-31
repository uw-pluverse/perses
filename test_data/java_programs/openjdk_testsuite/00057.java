



import java.util.Collection;

public class T6359106 {
    interface Request<R extends Request<R, V>,V> {}

    interface DeltaRequest extends Request<DeltaRequest, T6359106> {}

    interface RequestMap<V> {
        <R extends Request<R, W>, W extends V> R test (Collection<R> c);
    }

    public void f () {
        RequestMap<Object> m = null;
        Collection<DeltaRequest> c = null;
        DeltaRequest o = m.<DeltaRequest, T6359106>test(c);
    }
}
