


class TargetType67 {

    interface Func<A, B> {
        B f(A a);
    }

    class List<X> {

        <M> List<M> map(Func<X, M> f) {
            return null;
        }

        <A> List<A> apply(final List<Func<X, A>> lf) {
            return null;
        }

        <B, C> List<C> bind(final List<B> lb, final Func<X, Func<B, C>> f) {
            return lb.apply(map(f));
        }
    }
}
