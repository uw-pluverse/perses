




public class Nonlinear {

    
    

    
    
    

    
    
    

    public static void main (String [] args) {
        Integer x = new Integer (5);
        String y = castit (x);
        System.out.println (y);
    }

    static <A,B> A castit (B x) {
        
        
        
        
        final RWRef<A,B> r = build ();
        r.set (x);
        return r.get ();
    }

    static <A> Ref<A> build () {
        return new Ref<A> ();
    }

    
    
    
    
    
    
    
    
    
    
    
    
    
    
    

    static <A,B extends Ref<A>> Pair<Ref<A>,B> duplicate (B x) {
        return new Pair<Ref<A>,B> (x,x);
    }

    
    

    
    

    static <A,B> A castit2 (B x) {
        Pair <Ref<A>, Ref<B>> p = duplicate (build ());
        p.snd.set (x);
        return p.fst.get ();
    }


}

interface RWRef<A,B> {

    public A get ();
    public void set (B x);

}

class Ref<A> implements RWRef <A,A> {

    A contents;

    public void set (A x) { contents = x; }
    public A get () { return contents; }

}

class Pair<A,B> {

    final A fst;
    final B snd;

    Pair (A fst, B snd) { this.fst = fst; this.snd = snd; }

}
