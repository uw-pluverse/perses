
class DeclarationAnnotation {
    Object e1 = new @DA int[5];
    Object e2 = new @DA String[42];
    Object e3 = new @DA Object();
    Object ok = new @DA Object() { };
}

@interface DA { }
