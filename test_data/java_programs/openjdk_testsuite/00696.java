

@TraceResolve
class ReferenceOverload {

    static class A {}
    static class B extends A {}
    static class C extends B {}
    static class D extends C {}
    static class E extends D {}

    @Candidate(applicable=Phase.BASIC, mostSpecific=true)
    static void m_A(A a) {}
    @Candidate
    static void m_A(B a) {}
    @Candidate
    static void m_A(C a) {}
    @Candidate
    static void m_A(D a) {}
    @Candidate
    static void m_A(E a) {}

    @Candidate(applicable=Phase.BASIC, mostSpecific=false)
    static void m_B(A b) {}
    @Candidate(applicable=Phase.BASIC, mostSpecific=true)
    static void m_B(B b) {}
    @Candidate
    static void m_B(C b) {}
    @Candidate
    static void m_B(D b) {}
    @Candidate
    static void m_B(E b) {}

    @Candidate(applicable=Phase.BASIC, mostSpecific=false)
    static void m_C(A c) {}
    @Candidate(applicable=Phase.BASIC, mostSpecific=false)
    static void m_C(B c) {}
    @Candidate(applicable=Phase.BASIC, mostSpecific=true)
    static void m_C(C c) {}
    @Candidate
    static void m_C(D c) {}
    @Candidate
    static void m_C(E c) {}

    @Candidate(applicable=Phase.BASIC, mostSpecific=false)
    static void m_D(A d) {}
    @Candidate(applicable=Phase.BASIC, mostSpecific=false)
    static void m_D(B d) {}
    @Candidate(applicable=Phase.BASIC, mostSpecific=false)
    static void m_D(C d) {}
    @Candidate(applicable=Phase.BASIC, mostSpecific=true)
    static void m_D(D d) {}
    @Candidate
    static void m_D(E d) {}

    @Candidate(applicable=Phase.BASIC, mostSpecific=false)
    static void m_E(A e) {}
    @Candidate(applicable=Phase.BASIC, mostSpecific=false)
    static void m_E(B e) {}
    @Candidate(applicable=Phase.BASIC, mostSpecific=false)
    static void m_E(C e) {}
    @Candidate(applicable=Phase.BASIC, mostSpecific=false)
    static void m_E(D e) {}
    @Candidate(applicable=Phase.BASIC, mostSpecific=true)
    static void m_E(E e) {}

    {
        m_A((A)null);
        m_B((B)null);
        m_C((C)null);
        m_D((D)null);
        m_E((E)null);
    }
}
