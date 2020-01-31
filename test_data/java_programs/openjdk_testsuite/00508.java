



import java.util.ArrayList;
import java.util.List;
import java.util.Iterator;

class Bug2<T> implements Iterable<T> {
   private List<T> data;

   public Bug2() {
      data = new ArrayList<T>();
   }

   public Iterator<T> iterator() {
      return data.iterator();
   }
}
