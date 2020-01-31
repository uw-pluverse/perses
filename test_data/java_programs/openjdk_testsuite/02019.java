



class BreakAcrossClass {
     public static void main(String argv[]) {
        final int i = 6;
    M:  {
            class A {
                {
                    if (i != 5) break M;
                }
            }
            System.out.println("failed : " + i);
        }
        System.out.println("passed : " + i);
    }
}
