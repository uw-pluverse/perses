



import java.util.*;

public class TestMissingInterface implements MissingInterface {
    public static void main(String... args) {
        new TestMissingInterface().run();
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
