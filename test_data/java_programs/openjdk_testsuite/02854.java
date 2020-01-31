



import java.io.*;
import java.lang.reflect.Modifier;

public class T6557865 {
  public static void main(String... args) throws Exception {
    Class pkginfo_cls = Class.forName("T6232928.package-info");
    int mod = pkginfo_cls.getModifiers();
    if ((mod & 0x1000) != 0) {
      throw new AssertionError("Test failed: interface package-info shouldn't be synthetic in -target 5.");
    }
  }
}
