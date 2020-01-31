



public class T5094318 {

    
    public static void method(int[] array){
        System.out.println("You gave me an array of ints");
        throw new RuntimeException();
    }

    
    public static void method(Object obj){
        System.out.println("You gave me an object");
    }

    public static void main(String[] args){
        method(new int[0].clone());
    }

}
