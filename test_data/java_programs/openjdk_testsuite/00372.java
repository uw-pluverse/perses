



class InstanceOf<T> {
    static interface I1<T> {
        public T[] toArray();
    }
    static interface I2<T> extends I1<T> {
        public T[] toArray();
    }
    static interface I3<T> extends I2<T> {    }
    InstanceOf() {
        I1<T> inv = null;
        I1<? extends T> cov = null;
        I1<? super T> con = null;
        boolean b;
        b = inv instanceof I3; 
        b = cov instanceof I3; 
        b = con instanceof I3; 
    }
}
