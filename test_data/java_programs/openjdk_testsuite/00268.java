



class Test<T extends Base & Intf> {
    public void foo() {
        T t = null;
        t._field = 3;         
    }

}

class Base {
    int _field;
}

interface Intf {}
