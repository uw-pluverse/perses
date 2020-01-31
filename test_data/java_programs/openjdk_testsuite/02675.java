



class DALoop1 {

    String className() {
        do {
            try {
                Class.forName("");
            } catch (ClassNotFoundException e) {}
        } while (true);
    }

    static class QualName {
        public final int X;
        QualName() {
            throw new Error();
        }
    }
}
