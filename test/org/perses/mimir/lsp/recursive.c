void f1();

void f2();

void f1() {
    f2 ();//call
}

void f2() {
    f1();//call
}

int f3() {
    return f1() + f2();
}