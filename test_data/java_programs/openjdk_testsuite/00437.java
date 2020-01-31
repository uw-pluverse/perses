



public class AssignmentSameType3 {

    public static void main(String[] args) {
        Ref<B> exact = null;
        Ref<? extends B> ebound = null;
        Ref<? super B> sbound = null;
        Ref<?> unbound = null;

        exact = sbound;         
    }
}

class Ref<A> {}
class B {}
