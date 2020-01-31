



@Test(4)
class AnnoTreeTests {
    
    
    long i2 = (@TA("long") long) 0;

    
    
    byte @TA("byte[]") [] a2;
    float[] a3 = (@TA("float") float[]) null;
    double[] a4 = (double @TA("double[]") []) null;

    
    
}
