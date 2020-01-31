public class t {

  private static int counter() {
    return 100;
  }

  public static void main(String[] args) {
    for (int i = 0; i < counter(); ++i) {
      System.out.println("hello world");
    }
  }

}