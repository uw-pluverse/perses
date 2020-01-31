



import java.util.*;

public class TestMissingGenericInterface1 implements MissingGenericInterface1<String> {
    public static void main(String... args) {
        new TestMissingGenericInterface1().run();
    }

    @Override
    public void run() {
        Class<?> c = getClass();
        System.out.println("class: " + c);
        System.out.println("superclass: " + c.getSuperclass());
        System.out.println("generic superclass: " +c.getGenericSuperclass());
        System.out.println("interfaces: " + Arrays.asList(c.getInterfaces()));
        System.out.println("generic interfaces: " + Arrays.asList(c.getGenericInterfaces()));
    }

}
