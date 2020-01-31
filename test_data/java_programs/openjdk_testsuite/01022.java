

class Super {
    Inner i;
    private class Inner {
        void defaultM() {}
        protected void protectedM() {}
        public void publicM() {}
        private void privateM() {}
    }
}

class Sub extends Super {
    void foo() {
        i.defaultM();
        i.protectedM();
        i.publicM();
        i.privateM();
    }
}
