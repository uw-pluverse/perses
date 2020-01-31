



class B {
    interface K {}
}

class A extends B implements A.I {

    interface I extends K {
        class J {}
    }

    J j;
}
