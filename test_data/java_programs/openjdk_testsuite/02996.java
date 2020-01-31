



interface LambdaInterfaceStaticField {
  interface I {
     int m();
  }
  public static final I fld = () -> 5;
}
