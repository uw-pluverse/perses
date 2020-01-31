



import java.util.Collection;
import java.util.Collections;

public class T6650759c {

  static interface A {}

  static interface B<X extends A> {}

  static interface C<X extends A, Y extends B<X>> {}

  public static <T extends A, U extends B<T>> Collection<C<T,U>> get(U u) {
    return null;
  }

  public <T extends A, U extends B<T>> Collection<C<T,U>> test(U u) {
    return Collections.unmodifiableCollection(get(u));
  }
}
