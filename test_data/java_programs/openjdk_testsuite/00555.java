

class AbstractPlanarVector<S extends Scalar<S, T, U> & Ring<S>,
                           T extends PlainForm<S, T, U>,
                           U extends VariableForm<S, T, U>>
    extends AbstractVector<PlanarVector<S, T, U>,
                           PlainPlanarVector<S, T, U>,
                           PlanarVectorVariable<S, T, U>,
                           S,
                           T,
                           U>
    implements PlanarVector<S, T, U>
{
}
