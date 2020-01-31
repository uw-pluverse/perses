





import java.util.*;

class InferNoConformingAssignment {
    <X extends Number> List<X> m(String s) { return null; }
    { this.m(1); }
}

