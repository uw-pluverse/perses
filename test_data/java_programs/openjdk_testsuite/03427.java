



public class T6286112 {
    public Object saveA (AbstractClass<?> busObj) {
        return (ConcreteClass) busObj;
    }
    abstract class AbstractClass<B> {}
    class ConcreteClass extends AbstractClass<String> {}
}
