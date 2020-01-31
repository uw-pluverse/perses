


class FallThrough
{
    int m1(int i) {
        switch (i) {
        case 1: i++; case 2: i++;
        }
        return i;
    }
}


@SuppressWarnings("fallthrough")
class FallThrough1
{
    int m1(int i) {
        switch (i) {
        case 1: i++; case 2: i++;
        }
        return i;
    }
}

class FallThrough2
{
    @SuppressWarnings("fallthrough")
    class Bar {
        int m1(int i) {
            switch (i) {
            case 1: i++; case 2: i++;
            }
            return i;
        }
    }

    @SuppressWarnings("fallthrough")
    void m2(int i) {
        switch (i) {
        case 1: i++; case 2: i++;
        }
    }


    @SuppressWarnings("fallthrough")
    static int x = new FallThrough2() {
            int m1(int i) {
                switch (i) {
                case 1: i++; case 2: i++;
                }
                return i;
            }
        }.m1(0);

}
