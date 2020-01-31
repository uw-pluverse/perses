

abstract class AbstractVector<E extends Vector<E, P, V, S, T, U>,
                              P extends PlainForm<E, P, V>,
                              V extends VariableForm<E, P, V>,
                              S extends Scalar<S, T, U> & Ring<S>,
                              T extends PlainForm<S, T, U>,
                              U extends VariableForm<S, T, U>>
    extends AbstractElement<E, P, V>
    implements Vector<E, P, V, S, T, U>
{
}
