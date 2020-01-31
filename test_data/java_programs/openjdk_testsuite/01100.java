



public class FinalInitializer extends Object {
    private static final java.beans.PropertyChangeListener listener =
        new java.beans.PropertyChangeListener() {
            public void propertyChange (java.beans.PropertyChangeEvent ev) { }
            public void xwait(javax.swing.JComponent obj) {
                obj.removePropertyChangeListener(listener);
            }
    };
}
