




class NotAFunctionalIntf {

    abstract class SAM {
        abstract <Z> void m();
    }

    SAM s = x-> { };
}
