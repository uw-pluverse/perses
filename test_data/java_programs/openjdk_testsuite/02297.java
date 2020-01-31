

package p2;

import static p1.A.*;

class X extends p1.A {
    private static char c = 'X';
}

class B extends X {
    char x = c; 
}
