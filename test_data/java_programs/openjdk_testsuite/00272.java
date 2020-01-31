



class IntersectionSubVar {

    interface Box<T> {
        void set(T arg);
        T get();
    }

    <I> Box<I> glb(Box<? super I> arg1, Box<? super I> arg2) {
        return null;
    }

    <E extends Cloneable> void takeBox(Box<? super E> box) {}

    <T> void test(Box<T> arg1, Box<Cloneable> arg2, Box<? super T> arg3) {
        T t = glb(arg1, arg2).get(); 
        takeBox(arg3); 
    }

}
