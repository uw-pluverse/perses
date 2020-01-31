

class NonStaticFieldExpr3 {
  public int x;
}

class Subclass extends NonStaticFieldExpr3 {
  int a = NonStaticFieldExpr3.x;      
}
