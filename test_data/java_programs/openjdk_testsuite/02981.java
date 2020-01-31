


import java.util.*;

public class TargetType03 {

    interface Mapper<X,Y> {
        Y myMap(X a);
    }

    static class MapperList<A> extends ArrayList<A> {
        public <B> List<B> myMap(Mapper<A, B> mapper) {
            ArrayList<B> mappedList = new ArrayList<>();
            for (A elem : this) {
                mappedList.add(mapper.myMap(elem));
            }
            return mappedList;
        };
    }

    public static void main(String[] args) {
        MapperList<Integer> numbers = new MapperList<>();
        numbers.add(1);
        numbers.add(2);
        numbers.add(3);
        numbers.add(4);
        numbers.add(5);
        List<Integer> sqNumbers = numbers.myMap(a -> a * a);
        
        if (numbers.size() != sqNumbers.size()) {
            throw new AssertionError();
        }
        for (int i = 0; i < numbers.size() ; i ++) {
            if (sqNumbers.get(i) != Math.pow(numbers.get(i), 2)) {
                throw new AssertionError();
            }
        }
    }
}
