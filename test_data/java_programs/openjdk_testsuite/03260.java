

class BadConv03 {

    interface A {
        void a();
    }

    interface B extends A { 
        void a(int i);
    }

    B b = ()-> { };
}
