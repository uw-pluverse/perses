



class Dummy {
    Dummy(String s) {
        System.out.println(s);
    }
}

class AnonymousNull {
    void method() {
        new Dummy(null) {
            {
                System.out.println("etc.");
            }
        };
    }
}
