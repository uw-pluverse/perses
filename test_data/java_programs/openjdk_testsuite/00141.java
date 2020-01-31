



import java.util.Collections;
import java.util.List;


public class Test<A,B> {

    private List<A> getRelated(B b) {
        return Collections.emptyList();
    }

    public <L extends List<? super A>> L addOrCreate(B b,L l) {
        l.addAll(getRelated(b));
        return l;
    }

}
