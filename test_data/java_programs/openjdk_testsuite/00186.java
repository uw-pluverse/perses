



package rare9;

class A<T> {
    class B {
        public T rett() { return null; }
    }
}

class C extends A<String> {
    static class D {
        {
            B b = null;
            String s = b.rett();
        }
    }
}
