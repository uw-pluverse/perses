



public class T6213818 {
    static interface Edge<N extends Node<? extends Edge<N>>> { }
    static interface Node<E extends Edge<? extends Node<E>>> { }
    static class BasicNode<E extends BasicEdge<N, E> & Edge<N>, N extends BasicNode<E, N> & Node<E>> implements Node<E> { }
    static class BasicEdge<N extends BasicNode<E, N> & Node<E>, E extends BasicEdge<N, E> & Edge<N>> implements Edge<N> { }
}
