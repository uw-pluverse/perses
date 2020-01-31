


public class ConditionalWithVoid {
    public int test(Object o) {
        
        System.out.println(o instanceof String ? o.hashCode() : o.wait());
    }
}
