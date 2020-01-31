



public class T6295056 {
    interface Foo {}
    interface Bar<X> {}

    Object m(Foo f) {
        return (Bar<Object>)f;
    }

}
