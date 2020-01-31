



class Base<T> {
    void m(T t) {  }
    void m(String s) { }
}

class ConcreteInheritanceConflict extends Base<String> { }
