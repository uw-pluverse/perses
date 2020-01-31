

public interface Element<E extends Element<E, P, V>,
                         P extends PlainForm<E, P, V>,
                         V extends VariableForm<E, P, V>> {
    State getState();
}
