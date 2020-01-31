



class T6956758pos {

    interface I {}

    static class C {
        <T extends C & I> T cloneObject(T object) throws Exception {
            return (T)object.clone();
        }
    }
}
