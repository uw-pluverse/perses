

import java.util.List;
import java.util.Set;

public class T7126754 {
  public static void main(String[] args) {
    List<Set<? extends String>> a = null;
    List<? extends Set<? extends String>> b = a;

    List<? extends Set<? extends String>> c = null;
    List<Set<? extends String>> d = (List<Set<? extends String>>)c;
  }
}
