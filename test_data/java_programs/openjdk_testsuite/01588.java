



class T {
    boolean bb;
}

class T6356217 {

    public void f(T t1, T t2) {
        boolean b = false;

        do {
            break;
        } while ((b ? t1 : t2).bb);
    }
}
