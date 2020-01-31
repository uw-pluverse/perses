



public class T5043020 {
    <T, U extends T, V extends T> T cond1(boolean z, U x1, V x2) {
        return (z? (T) x1: x2);
    }
}
