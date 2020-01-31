



import java.util.List;

public class T6456971 {

     static <T> T[] makeArray(T... args) {
         return args;
     }

     public static <S> void test() {
         S[] stringLists = makeArray(null, null);
     }

}
