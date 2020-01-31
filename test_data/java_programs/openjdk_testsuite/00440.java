



public class AssignmentDifferentTypes8 {

    public static void main(String[] args) {
        Ref<Der> derexact = null;
        Ref<Base> baseexact = null;
        Ref<? extends Der> derext = null;
        Ref<? extends Base> baseext = null;
        Ref<? super Der> dersuper = null;
        Ref<? super Base> basesuper = null;

        basesuper = dersuper;   
    }
}

class Ref<T> {}
class Base {}
class Der extends Base {}
