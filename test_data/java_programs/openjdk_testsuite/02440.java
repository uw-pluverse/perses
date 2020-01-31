



package annotation.scope;

@A(red) 
enum E {
    red, green, blue;
}

@interface A {
    E value();
}
