



class Test<T extends Base & Intf> {
    public void foo() {
        T t = null;
        T.Inner inner = null; 
    }

}

class Base {
    static class Inner {}
}

interface Intf {
    class Inner {}
}
