

public class PlanarVectorVariable<S extends Scalar<S, T, U> & Ring<S>,
                                  T extends PlainForm<S, T, U>,
                                  U extends VariableForm<S, T, U>>
    extends AbstractPlanarVector<S, T, U>
    implements VariableForm<PlanarVector<S, T, U>,
                            PlainPlanarVector<S, T, U>,
                            PlanarVectorVariable<S, T, U>>
{
}
