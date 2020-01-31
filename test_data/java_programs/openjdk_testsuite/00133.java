



public class T5042462 {
    <T, U extends T, V extends T> T cond1(boolean z, U x1, V x2) {
        T t = z? x1: x2;
        return z? x1: x2;
    }
}
