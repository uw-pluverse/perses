

package tests;

import java.util.Collection;
import java.util.Collections;

class CompileTest2 {

        class Request<R extends Request<R, V>,V> {}

        class DeltaRequest extends Request<DeltaRequest, double[]> {}

        class RequestMap<V> {
                public <R extends Request<R, W>, W extends V> R test (Collection<R> c) {
                        
                        return null;
                }

        }

        public void f () {
                RequestMap<Object> m = new RequestMap<Object> ();
                Collection<DeltaRequest> c = Collections.singleton (new DeltaRequest ());
                
                DeltaRequest o = m.<DeltaRequest, double[]>test (c);
        }
}
