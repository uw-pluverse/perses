package java.util.concurrent.atomic;

import java.util.Arrays;
import java.util.concurrent.ThreadLocalRandom;
import java.util.function.LongBinaryOperator;
import javax.annotation.Nullable;

@SuppressWarnings("serial")
abstract class Striped64 extends Number {

    @jdk.internal.vm.annotation.Contended
    static final class Cell {

        volatile long value;

        Cell(long x) {
            throw new java.lang.Error();
        }

        final boolean cas(long cmp, long val) {
            throw new java.lang.Error();
        }
    }

    static final int NCPU = 0;

    @Nullable
    transient volatile Cell[] cells;

    transient volatile long base;

    transient volatile int cellsBusy;

    final boolean casBase(long cmp, long val) {
        throw new java.lang.Error();
    }

    final boolean casCellsBusy() {
        throw new java.lang.Error();
    }

    static final int getProbe() {
        throw new java.lang.Error();
    }

    static final int advanceProbe(int probe) {
        throw new java.lang.Error();
    }

    final void longAccumulate(long x, LongBinaryOperator fn, boolean wasUncontended) {
        int h;
        if ((h = getProbe()) == 0) {
            ThreadLocalRandom.current();
            h = getProbe();
            wasUncontended = true;
        }
        boolean collide = false;
        done: for (; ; ) {
            Cell[] cs;
            Cell c;
            int n;
            long v;
            if ((cs = cells) != null && (n = cs.length) > 0) {
                if ((c = cs[(n - 1) & h]) == null) {
                    if (cellsBusy == 0) {
                        Cell r = new Cell(x);
                        if (cellsBusy == 0 && casCellsBusy()) {
                            try {
                                Cell[] rs;
                                int m, j;
                                if ((rs = cells) != null && (m = rs.length) > 0 && rs[j = (m - 1) & h] == null) {
                                    rs[j] = r;
                                    break done;
                                }
                            } finally {
                                cellsBusy = 0;
                            }
                            continue;
                        }
                    }
                    collide = false;
                } else if (!wasUncontended)
                    wasUncontended = true;
                else if (c.cas(v = c.value, (fn == null) ? v + x : fn.applyAsLong(v, x)))
                    break;
                else if (n >= NCPU || cells != cs)
                    collide = false;
                else if (!collide)
                    collide = true;
                else if (cellsBusy == 0 && casCellsBusy()) {
                    try {
                        if (cells == cs)
                            cells = Arrays.copyOf(cs, n << 1);
                    } finally {
                        cellsBusy = 0;
                    }
                    collide = false;
                    continue;
                }
                h = advanceProbe(h);
            } else if (cellsBusy == 0 && cells == cs && casCellsBusy()) {
                try {
                    if (cells == cs) {
                        Cell[] rs = new Cell[2];
                        rs[h & 1] = new Cell(x);
                        cells = rs;
                        break done;
                    }
                } finally {
                    cellsBusy = 0;
                }
            } else if (casBase(v = base, (fn == null) ? v + x : fn.applyAsLong(v, x)))
                break done;
        }
    }
}
