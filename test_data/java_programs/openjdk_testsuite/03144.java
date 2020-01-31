


import java.util.*;
import java.util.function.*;
import java.util.stream.*;

class TargetType59 {

    <T, R> Collector<T, String, R> m(Supplier<? extends R> supplier, BiConsumer<R, T> accumulator) {
        return null;
    }

    <T, C extends Collection<T>> Collector<T, String, C> test1(Supplier<C> collectionFactory) {
        return m(collectionFactory, Collection::add);
    }

    Collector<String, String, StringBuilder> test2(Supplier<StringBuilder> sb) {
        return m(sb, StringBuilder::append);
    }
}
