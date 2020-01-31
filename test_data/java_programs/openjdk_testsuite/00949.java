



package p1;
class NonStaticFieldExpr4a {
    protected int i;
}
interface NonStaticFieldExpr4b {
    static int i = 1;
}
public class NonStaticFieldExpr4c extends NonStaticFieldExpr4a implements NonStaticFieldExpr4b {}
