

@TraceResolve(keys={"compiler.err.ref.ambiguous"})
class PrimitiveOverReferenceVarargsAmbiguous {
    @Candidate(applicable=Phase.VARARGS, mostSpecific=false)
    static void m_byte(byte... b) {}
    @Candidate(applicable=Phase.VARARGS, mostSpecific=false)
    static void m_byte(Byte... b) {}

    @Candidate(applicable=Phase.VARARGS, mostSpecific=false)
    static void m_short(short... s) {}
    @Candidate(applicable=Phase.VARARGS, mostSpecific=false)
    static void m_short(Short... s) {}

    @Candidate(applicable=Phase.VARARGS, mostSpecific=false)
    static void m_int(int... i) {}
    @Candidate(applicable=Phase.VARARGS, mostSpecific=false)
    static void m_int(Integer... i) {}

    @Candidate(applicable=Phase.VARARGS, mostSpecific=false)
    static void m_long(long... l) {}
    @Candidate(applicable=Phase.VARARGS, mostSpecific=false)
    static void m_long(Long... l) {}

    @Candidate(applicable=Phase.VARARGS, mostSpecific=false)
    static void m_float(float... f) {}
    @Candidate(applicable=Phase.VARARGS, mostSpecific=false)
    static void m_float(Float... f) {}

    @Candidate(applicable=Phase.VARARGS, mostSpecific=false)
    static void m_double(double... d) {}
    @Candidate(applicable=Phase.VARARGS, mostSpecific=false)
    static void m_double(Double... d) {}

    @Candidate(applicable=Phase.VARARGS, mostSpecific=false)
    static void m_char(char... c) {}
    @Candidate(applicable=Phase.VARARGS, mostSpecific=false)
    static void m_char(Character... c) {}

    @Candidate(applicable=Phase.VARARGS, mostSpecific=false)
    static void m_bool(boolean... z) {}
    @Candidate(applicable=Phase.VARARGS, mostSpecific=false)
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
