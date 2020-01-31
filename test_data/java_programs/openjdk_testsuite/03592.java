



import mypackage.Superclass;

public class Outerclass extends Superclass {
    Innerclass innerclass = new Innerclass();

    private class Innerclass extends Superclass {
        InnermostClass innermostClass = new InnermostClass();

        private class InnermostClass {
            public void doAnything() {
                Outerclass.this.doStuff();
            }
        }
    }

    public static void main(String[] args) {
        new Outerclass();
    }
}
