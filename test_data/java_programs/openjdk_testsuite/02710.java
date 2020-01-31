



public class QualifiedOuterThis2 {
    class TableCellEditor extends X {
        TableCellEditor() {
            super(new Object() {
                    public String xyz() {
                        return QualifiedOuterThis2.this.toString();
                    }
                });
        }
    }
}
class X {
    X(Object o) {}
}
