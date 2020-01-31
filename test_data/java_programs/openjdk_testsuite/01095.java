



class A {
    B b = new B();
    {
        System.out.println(b.value);
    }
}

class B {
    final B value = this;
}
