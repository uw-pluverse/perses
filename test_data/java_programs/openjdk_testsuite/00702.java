

@TraceResolve
class BoxedReturnTypeInference {
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
        Byte b = m_byte();
        Short s = m_short();
        Integer i = m_int();
        Long l = m_long();
        Float f = m_float();
        Double d = m_double();
        Character c= m_char();
        Boolean z = m_bool();
    }
}
