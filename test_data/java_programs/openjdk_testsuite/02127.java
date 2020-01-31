



class Tclass<T> {
    T data;
    public Tclass(T... t){}
}

public class BadSyntax2 {
    String s = null;
    Tclass<String> tc = new Tclass<String>(s);  
    public BadSyntax2() {}
}
