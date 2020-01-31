



package cycle2;

@interface Bar {
    Baz baz();
}

@interface Baz {
    Bar bar();
}
