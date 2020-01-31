

@TraceResolve
class PrimitiveOverInferred {
    @Candidate(applicable=Phase.BOX, mostSpecific=true)
    static void m_byte(Byte b) {}
    @Candidate(applicable=Phase.BOX, sig="(java.lang.Byte)void")
    static <B> void m_byte(B b) {}

    @Candidate(applicable=Phase.BOX, mostSpecific=true)
    static void m_short(Short s) {}
    @Candidate(applicable=Phase.BOX, sig="(java.lang.Short)void")
    static <S> void m_short(S s) {}

    @Candidate(applicable=Phase.BOX, mostSpecific=true)
    static void m_int(Integer i) {}
    @Candidate(applicable=Phase.BOX, sig="(java.lang.Integer)void")
    static <I> void m_int(I i) {}

    @Candidate(applicable=Phase.BOX, mostSpecific=true)
    static void m_long(Long l) {}
    @Candidate(applicable=Phase.BOX, sig="(java.lang.Long)void")
    static <L> void m_long(L l) {}

    @Candidate(applicable=Phase.BOX, mostSpecific=true)
    static void m_float(Float f) {}
    @Candidate(applicable=Phase.BOX, sig="(java.lang.Float)void")
    static <F> void m_float(F f) {}

    @Candidate(applicable=Phase.BOX, mostSpecific=true)
    static void m_double(Double d) {}
    @Candidate(applicable=Phase.BOX, sig="(java.lang.Double)void")
    static <D> void m_double(D d) {}

    @Candidate(applicable=Phase.BOX, mostSpecific=true)
    static void m_char(Character c) {}
    @Candidate(applicable=Phase.BOX, sig="(java.lang.Character)void")
    static <C> void m_char(C c) {}

    @Candidate(applicable=Phase.BOX, mostSpecific=true)
    static void m_bool(Boolean z) {}
    @Candidate(applicable=Phase.BOX, sig="(java.lang.Boolean)void")
    static <Z> void m_bool(Z z) {}

    {
        m_byte((byte)0);
        m_short((short)0);
        m_int(0);
        m_long(0L);
        m_float(0.0f);
        m_double(0.0);
        m_char('?');
        m_bool(false);
    }
}
