

class VarargsInferredPrivateType {
    interface I {
        <T> void m(T... t);
    }

    void m(I i) {
        i.m(otherpackage.OtherPackage.getPrivate());
    }
}
