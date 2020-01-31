

public class PlainPlanarVector<S extends Scalar<S, T, U> & Ring<S>,
                               T extends PlainForm<S, T, U>,
                               U extends VariableForm<S, T, U>>
    extends AbstractPlanarVector<S, T, U>
    implements PlainForm<PlanarVector<S, T, U>,
                         PlainPlanarVector<S, T, U>,
                         PlanarVectorVariable<S, T, U>> {

    @Override
    public State getState() {
        return null;
    }

}
