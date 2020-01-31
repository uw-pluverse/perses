

@TraceResolve
class PrimitiveReturnTypeInference {
    @Candidate(applicable=Phase.BASIC, sig="()java.lang.Byte", mostSpecific=true)
    static <B> B m_byte() { return null; }

    @Candidate(applicable=Phase.BASIC, sig="()java.lang.Short", mostSpecific=true)
    static <S> S m_short() { return null; }

    @Candidate(applicable=Phase.BASIC, sig="()java.lang.Integer", mostSpecific=true)
    static <I> I m_int() { return null; }

    @Candidate(applicable=Phase.BASIC, sig="()java.lang.Long", mostSpecific=true)
    static <L> L m_long() { return null; }

    @Candidate(applicable=Phase.BASIC, sig="()java.lang.Float", mostSpecific=true)
    static <F> F m_float() { return null; }

    @Candidate(applicable=Phase.BASIC, sig="()java.lang.Double", mostSpecific=true)
    static <D> D m_double() { return null; }

    @Candidate(applicable=Phase.BASIC, sig="()java.lang.Character", mostSpecific=true)
    static <C> C m_char() { return null; }

    @Candidate(applicable=Phase.BASIC, sig="()java.lang.Boolean", mostSpecific=true)
    static <Z> Z m_bool() { return null; }

    {
        byte b = m_byte();
        short s = m_short();
        int i = m_int();
        long l = m_long();
        float f = m_float();
        double d = m_double();
        char c= m_char();
        boolean z = m_bool();
    }
}
