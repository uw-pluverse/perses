
class TestNoBridgeInSiblingSuper {
    interface A { Object m(); }
    interface B { String m(); }
    
    interface C extends A, B { }

    @Bridge("m()Ljava/lang/Object;")
    interface D extends C {
        String m();
    }
}

