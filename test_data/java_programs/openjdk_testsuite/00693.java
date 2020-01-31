

@TraceResolve
class PrimitiveOverReference {
    @Candidate(applicable=Phase.BASIC, mostSpecific=true)
    static void m_byte(byte b) {}
    @Candidate
    static void m_byte(Byte b) {}
    @Candidate
    static void m_byte(byte... b) {}
    @Candidate
    static void m_byte(Byte... b) {}

    @Candidate(applicable=Phase.BASIC, mostSpecific=true)
    static void m_short(short s) {}
    @Candidate
    static void m_short(Short s) {}
    @Candidate
    static void m_short(short... s) {}
    @Candidate
    static void m_short(Short... s) {}

    @Candidate(applicable=Phase.BASIC, mostSpecific=true)
    static void m_int(int i) {}
    @Candidate
    static void m_int(Integer i) {}
    @Candidate
    static void m_int(int... i) {}
    @Candidate
    static void m_int(Integer... i) {}

    @Candidate(applicable=Phase.BASIC, mostSpecific=true)
    static void m_long(long l) {}
    @Candidate
    static void m_long(Long l) {}
    @Candidate
    static void m_long(long... l) {}
    @Candidate
    static void m_long(Long... l) {}

    @Candidate(applicable=Phase.BASIC, mostSpecific=true)
    static void m_float(float f) {}
    @Candidate
    static void m_float(Float f) {}
    @Candidate
    static void m_float(float... f) {}
    @Candidate
    static void m_float(Float... f) {}

    @Candidate(applicable=Phase.BASIC, mostSpecific=true)
    static void m_double(double d) {}
    @Candidate
    static void m_double(Double d) {}
    @Candidate
    static void m_double(double... d) {}
    @Candidate
    static void m_double(Double... d) {}

    @Candidate(applicable=Phase.BASIC, mostSpecific=true)
    static void m_char(char c) {}
    @Candidate
    static void m_char(Character c) {}
    @Candidate
    static void m_char(char... c) {}
    @Candidate
    static void m_char(Character... c) {}

    @Candidate(applicable=Phase.BASIC, mostSpecific=true)
    static void m_bool(boolean z) {}
    @Candidate
    static void m_bool(Boolean z) {}
    @Candidate
    static void m_bool(boolean... z) {}
    @Candidate
    static void m_bool(Boolean... z) {}

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
