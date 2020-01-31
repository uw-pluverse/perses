




class Finally
{
    int m1(int i) {
        try {
            return 0;
        }
        finally {
            throw new IllegalArgumentException();
        }
    }
}


@SuppressWarnings("finally")
class Finally1
{
    int m1(int i) {
        try {
            return 0;
        }
        finally {
            throw new IllegalArgumentException();
        }
    }
}

class Finally2
{
    @SuppressWarnings("finally")
    class Bar {
        int m1(int i) {
            try {
                return 0;
            }
            finally {
                throw new IllegalArgumentException();
            }
        }
    }

    @SuppressWarnings("finally")
    int m2(int i) {
        try {
            return 0;
        }
        finally {
            throw new IllegalArgumentException();
        }
    }


    @SuppressWarnings("finally")
    static int x = new Finally2() {
            int m1(int i) {
                try {
                    return 0;
                }
                finally {
                    throw new IllegalArgumentException();
                }
            }
        }.m1(0);

}
