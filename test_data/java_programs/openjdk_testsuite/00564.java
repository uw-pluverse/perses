

public abstract class AbstractElement<E extends Element<E, P, V>,
                                      P extends PlainForm<E, P, V>,
                                      V extends VariableForm<E, P, V>>
    implements Element<E, P, V>
{
    
    public State getState() {
        throw new AssertionError();
    }
}
