



interface A extends Cloneable
{
  public Object clone() throws CloneNotSupportedException;
}
interface B extends A
{ }
interface C extends A
{ }
interface D extends B, C
{ }

public class CloneableProblem implements D
{
  private int i;
  public CloneableProblem(int i)
  {
    this.i = i;
  }
  public Object clone()
  {
    CloneableProblem theCloneableProblem = null;
    try
      {
        theCloneableProblem = (CloneableProblem) super.clone();
        theCloneableProblem.i = i;
      }
    catch (CloneNotSupportedException cnse)
      { }
    return theCloneableProblem;
  }
  public static void main(String argv[])
  {
    try
      {
        A a0 = new CloneableProblem(0);
        A a1 = (A) a0.clone();
        B b0 = new CloneableProblem(0);
        B b1 = (B) b0.clone();
        C c0 = new CloneableProblem(0);
        C c1 = (C) c0.clone();
        D d0 = new CloneableProblem(0);
        D d1 = (D) d0.clone();
      }
    catch (CloneNotSupportedException cnse)
      { }
      }
}
