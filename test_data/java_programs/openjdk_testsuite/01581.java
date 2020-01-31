



class CascadedInnerNewInstance {

    Object createInner1InnerInnerMost() {
        return new Inner1().new InnerMost().new InnerInnerMost();
    }

    class Inner1 {
        class InnerMost {
            class InnerInnerMost { }
        }
    }

    Inner2.InnerMost createInner2InnerMost() {
        return new Inner2().new InnerMost();
    }

    Object createInner2InnerInnerMost() {
        return createInner2InnerMost().new InnerInnerMost();
    }

    class Inner2 {
        class InnerMost {
            class InnerInnerMost { }
        }
    }

}
