



import java.util.List;

class Foo {}
class Bar extends Foo {}
interface FooList<T extends Foo> extends List<T> {}

class Test {
    <T extends FooList<? super Bar>> void m(T t) {
        Foo f = t.get(0);
    }
}
