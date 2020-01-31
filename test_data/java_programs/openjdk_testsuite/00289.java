



class SelfImplement {
    static abstract class A<T> {
        abstract void f(T t);
        public int f(Integer t) { return 3; }
    }
    static abstract class B extends A<Integer> {
        
        
    }
}
