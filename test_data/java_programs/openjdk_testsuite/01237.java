





class NotDefAccessClassIntfCantAccessFragment {

    private class Private {
        void m() { }
    }

    Private getPrivate() { return new Private(); }
}

class NotDefAccessClassIntfCantAccessFragmentTest {

    interface SAM {
        void m();
    }

    static void test() {
        SAM s = new NotDefAccessClassIntfCantAccessFragment().getPrivate()::m;
    }
}
