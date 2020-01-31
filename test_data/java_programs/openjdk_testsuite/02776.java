

import java.util.Comparator;

public class EqualsHashCodeWarningTest {
    @Override
    public boolean equals(Object o) {
        return o == this;
    }

    @Override
    public int hashCode() {
        return 0;
    }

    public Comparator m() {
        return new Comparator() {
            @Override
            public boolean equals(Object o) {return true;}

            @Override
            public int compare(Object o1, Object o2) {
                return 0;
            }
        };
    }
}

class SubClass extends EqualsHashCodeWarningTest {
    @Override
    public boolean equals(Object o) {
        return true;
    }
}

@SuppressWarnings("overrides")
class DontWarnMe {
    @Override
    public boolean equals(Object o) {
        return true;
    }
}

class DoWarnMe {
    @Override
    public boolean equals(Object o) {
        return o == this;
    }
}

abstract class IamAbstractGetMeOutOfHere {
    public boolean equals(Object o){return true;}
}

interface I {
    public boolean equals(Object o);
}

enum E {
    A, B
}

@interface anno {}
