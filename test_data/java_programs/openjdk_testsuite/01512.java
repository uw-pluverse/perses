



import java.util.*;

class CantResolveArgs {
    void m() {
        new Runnable() {
            { unknown(); }
            public void run() { }
        };
    }
}
