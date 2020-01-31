



public class AssignmentSameType1 {

    public static void main(String[] args) {
        Ref<B> exact = null;
        Ref<? extends B> ebound = null;
        Ref<? super B> sbound = null;
        Ref<?> unbound = null;

;       exact = exact;          

        ebound = exact;         
        ebound = ebound;        

        sbound = exact;         
        sbound = sbound;        

        unbound = exact;        
        unbound = ebound;       
        unbound = sbound;       
        unbound = unbound;      
    }
}

class Ref<A> {}
class B {}
