



class G<N extends G.Node<N>> {
    static class Node<N extends Node<N>> {
    }
}
class F extends G<F.MyNode> {
    static class MyNode extends G.Node<MyNode> {
    }
}
