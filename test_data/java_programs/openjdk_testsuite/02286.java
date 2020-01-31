



package conditional.clazz;

class A{}
class B{}

public class ConditionalClass {
    void foo(){
        boolean b = false;
        Class a =  b ? A.class : B.class;
        System.out.println("a is " + a.getName());
    }

    public static void main(String[] args)
    {
        new ConditionalClass().foo();
    }
}
