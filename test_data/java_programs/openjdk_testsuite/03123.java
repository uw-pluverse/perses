



class NakedThis {

    interface SAM {
        NakedThis m(int x);
    }

    SAM s1 = (int x) -> this;
    SAM s2 = (int x) -> NakedThis.this;
}
