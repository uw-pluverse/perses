



class Anon {
    Anon() {
        Fox fox1 = new Fox(1) {};
        Fox fox2 = new Fox(new String[] { "hello" }) {};
        Fox fox3 = new Fox(null) {};
        Fox fox4 = new Fox() {};
        Fox fox5 = new Fox("hello") {};
        Fox fox6 = new Fox("hello", "bye") {};
    }
}

class Fox {
    Fox(int a) {
        _keys = new String[0];
    }

    Fox(String... keys) {
        _keys = keys;
    }

    final String[] _keys;

}
