
class VoidCompatibility {

    interface Runnable { void run(); } 
    interface Thunk<T> { T get(); } 

    void schedule(Runnable r) { }
    void schedule(Thunk<?> t) { }

    void test() {
        schedule(() -> System.setProperty("done", "true")); 
        schedule(() -> { System.setProperty("done", "true"); }); 
        schedule(() -> { return System.setProperty("done", "true"); }); 
        schedule(() -> System.out.println("done")); 
        schedule(() -> { System.out.println("done"); }); 
        schedule(Thread::yield); 
        schedule(Thread::getAllStackTraces); 
        schedule(Thread::interrupted); 
    }
}
