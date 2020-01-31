
import java.util.stream.Stream;

class StaticInvoke {
    void test() {
        Stream.empty();
        java.util.stream.Stream.empty();
    }
}
