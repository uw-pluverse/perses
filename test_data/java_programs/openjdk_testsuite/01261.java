





import java.util.*;

class InferredDoNotConformToEq {
    <X> void m(List<X> lx1, List<X> lx2) {}
    { this.m(Arrays.asList(""), Arrays.asList(1)); }
}
