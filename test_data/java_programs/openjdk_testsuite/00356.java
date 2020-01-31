



interface Edge<N extends Node<? extends Edge<N>>> {
    void setEndNode(N n);
}
interface Node<E extends Edge<? extends Node<E>>> {
    E getOutEdge();
}

public class T5097548b {
    public static void main(String[] args) {
        Node<?> node = null;
        node.getOutEdge().setEndNode(null);
    }
}
