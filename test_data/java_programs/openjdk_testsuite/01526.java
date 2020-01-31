





import java.util.*;

class UncheckedCast {
    <T,U> List<U> m(List<T> l) {
        return (List<U>) l;
    }
}
