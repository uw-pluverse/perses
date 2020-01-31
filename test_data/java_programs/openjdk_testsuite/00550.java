

public interface Scalar<S extends Scalar<S, P, V>,
                        P extends PlainForm<S, P, V>,
                        V extends VariableForm<S, P, V>>
    extends Value<S, P, V>
{
}
