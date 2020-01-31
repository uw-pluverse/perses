

@TraceResolve
class PrimitiveBinopOverload {

    @Candidate(applicable=Phase.BASIC, mostSpecific=true)
    int _plus(int x, int y) { return -1; }
    @Candidate(applicable=Phase.BASIC)
    long _plus(long x, long y) { return -1; }
    @Candidate(applicable=Phase.BASIC)
    float _plus(float x, float y) { return -1; }
    @Candidate(applicable=Phase.BASIC)
    double _plus(double x, double y) { return -1; }
    
    Object _plus(Object x, Object y) { return -1; }

    @Candidate(applicable= { Phase.BASIC, Phase.BOX }, mostSpecific=true)
    int _minus(int x, int y) { return -1; }
    @Candidate(applicable= { Phase.BASIC, Phase.BOX })
    long _minus(long x, long y) { return -1; }
    @Candidate(applicable= { Phase.BASIC, Phase.BOX })
    float _minus(float x, float y) { return -1; }
    @Candidate(applicable= { Phase.BASIC, Phase.BOX })
    double _minus(double x, double y) { return -1; }

    @Candidate(applicable= { Phase.BASIC, Phase.BOX }, mostSpecific=true)
    int _mul(int x, int y) { return -1; }
    @Candidate(applicable= { Phase.BASIC, Phase.BOX })
    long _mul(long x, long y) { return -1; }
    @Candidate(applicable= { Phase.BASIC, Phase.BOX })
    float _mul(float x, float y) { return -1; }
    @Candidate(applicable= { Phase.BASIC, Phase.BOX })
    double _mul(double x, double y) { return -1; }

    @Candidate(applicable= { Phase.BASIC, Phase.BOX }, mostSpecific=true)
    int _div(int x, int y) { return -1; }
    @Candidate(applicable= { Phase.BASIC, Phase.BOX })
    long _div(long x, long y) { return -1; }
    @Candidate(applicable= { Phase.BASIC, Phase.BOX })
    float _div(float x, float y) { return -1; }
    @Candidate(applicable= { Phase.BASIC, Phase.BOX })
    double _div(double x, double y) { return -1; }

    {
        int i1 = 1 + 1;
        int i2 = 5 - new Integer(3);
        int i3 = new Integer(5) * 3;
        int i4 = new Integer(6) / new Integer(2);
    }
}
