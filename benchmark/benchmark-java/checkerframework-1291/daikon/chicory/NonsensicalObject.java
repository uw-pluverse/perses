package daikon.chicory;

public class NonsensicalObject {

    public static NonsensicalObject getInstance() {
        throw new java.lang.Error();
    }
}
