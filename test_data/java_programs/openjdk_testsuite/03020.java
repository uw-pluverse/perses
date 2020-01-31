
class EffectivelyFinal01 {

    interface SAM {
        Integer m(Integer i);
    }

    void test(Integer nefPar) {
        SAM s = (Integer h) ->  { Integer k = 0; return k + h + nefPar; };
        nefPar++;  
    }
}
