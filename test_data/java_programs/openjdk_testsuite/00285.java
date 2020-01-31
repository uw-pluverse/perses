
class TestNoDuplicateBridges01 {
    interface A1 { Object m(); }
    interface A2 { Object m(); }

    @Bridge("m()Ljava/lang/Object;")
    interface B extends A1, A2 { B m(); }
}
