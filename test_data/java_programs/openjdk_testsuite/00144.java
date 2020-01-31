



import java.util.*;

public class NewTest<A,B> {
    private List<A> toAdd;

    public NewTest(List<A> toAdd) {
        this.toAdd = toAdd;
    }

    private List<A> getRelated(B b) {
        
        
        return toAdd;
    }

    @SuppressWarnings("unchecked")
    public <L extends List<? super A>,LF extends Factory<L>> L addOrCreate4(B b,L l,LF lf) {
        if (l == null) {
            l = lf.create();
        }
        ((List<? super A>)l).addAll(getRelated(b)); 
        return l;
    }

    public static class ListFactory<T>  implements Factory<List<T>>{
        public List<T> create() {
            return new ArrayList<T>();
        }
    }
    public static interface Factory<T> {
        public T create();
    }

    public static void main(String ... args) {
        ListFactory<Number> lf = new ListFactory<Number>();
        List<Long> longs = new ArrayList<Long>();
        longs.add(new Long(1));
        NewTest<Long,Number> test = new NewTest<Long,Number>(longs);

        List<Number> ret4 = null;

        ret4 = test.addOrCreate4(1, ret4,lf);

    }
}
