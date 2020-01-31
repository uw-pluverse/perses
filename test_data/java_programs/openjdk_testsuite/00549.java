

public interface PlanarVector<S extends Scalar<S, T, U> & Ring<S>,
                              T extends PlainForm<S, T, U>,
                              U extends VariableForm<S, T, U>>
    extends Vector<PlanarVector<S, T, U>,
                   PlainPlanarVector<S, T, U>,
                   PlanarVectorVariable<S, T, U>, S, T, U>,
                   AdditiveClosure<PlanarVector<S, T, U>>
{
}
