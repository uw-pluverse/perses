





import java.util.*;

class InferredDoNotConformToUpper {
    <X> void m(X x, List<? super X> lx) {}
    { this.m("", Arrays.asList(1)); }
}
