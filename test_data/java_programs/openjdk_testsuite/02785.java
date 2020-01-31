



class T6738538b {
    interface I1 {
        Object m();
    }

    interface I2 {}

    class C1<T> implements I1 {
        public T m() {
            return null;
        }
    }

    class C2<T extends C1<?> & I2> {}
}
