



public class AssignmentSameType4 {

    public static void main(String[] args) {
        Ref<B> exact = null;
        Ref<? extends B> ebound = null;
        Ref<? super B> sbound = null;
        Ref<?> unbound = null;

        exact = unbound;        
    }
}

class Ref<A> {}
class B {}
