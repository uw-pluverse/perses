

@TraceResolve(keys={"compiler.err.ref.ambiguous"})
class PrimitiveVsReferenceSamePhase {
    @Candidate(applicable=Phase.BOX, mostSpecific=false)
    static void m_byte(Byte b1, byte b2) {}
    @Candidate(applicable=Phase.BOX, mostSpecific=false)
    static void m_byte(Byte b1, Byte b2) {}

    @Candidate(applicable=Phase.BOX, mostSpecific=false)
    static void m_short(Short s1, short s2) {}
    @Candidate(applicable=Phase.BOX, mostSpecific=false)
    static void m_short(Short s1, Short s2) {}

    @Candidate(applicable=Phase.BOX, mostSpecific=false)
    static void m_int(Integer i1, int i2) {}
    @Candidate(applicable=Phase.BOX, mostSpecific=false)
    static void m_int(Integer i1, Integer i2) {}

    @Candidate(applicable=Phase.BOX, mostSpecific=false)
    static void m_long(Long l1, long l2) {}
    @Candidate(applicable=Phase.BOX, mostSpecific=false)
    static void m_long(Long l1, Long l2) {}

    @Candidate(applicable=Phase.BOX, mostSpecific=false)
    static void m_float(Float f1, float f2) {}
    @Candidate(applicable=Phase.BOX, mostSpecific=false)
    static void m_float(Float f1, Float f2) {}

    @Candidate(applicable=Phase.BOX, mostSpecific=false)
    static void m_double(Double d1, double d2) {}
    @Candidate(applicable=Phase.BOX, mostSpecific=false)
    static void m_double(Double d1, Double d2) {}

    @Candidate(applicable=Phase.BOX, mostSpecific=false)
    static void m_char(Character c1, char c2) {}
    @Candidate(applicable=Phase.BOX, mostSpecific=false)
    static void m_char(Character c1, Character c2) {}

    @Candidate(applicable=Phase.BOX, mostSpecific=false)
    static void m_bool(Boolean z1, boolean z2) {}
    @Candidate(applicable=Phase.BOX, mostSpecific=false)
    static void m_bool(Boolean z1, Boolean z2) {}

    {
        m_byte((byte)0, (byte)0);
        m_short((short)0, (short)0);
        m_int(0, 0);
        m_long(0L, 0L);
        m_float(0.0f, 0.0f);
        m_double(0.0, 0.0);
        m_char('?', '?');
        m_bool(false, false);
    }
}
