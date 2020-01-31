



interface Edge<N extends Node<? extends Edge<? extends N>>> {}
interface Node<E extends Edge<? extends Node<? extends E>>> {}

public class T5097548 {
    public static void main(String[] args) {
        System.out.println("FISK");
    }
}
