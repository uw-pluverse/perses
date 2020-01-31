


typedef unsigned int DWORD;

static void g(DWORD * p, int n)
{
        int i;

        for (i = 0; i < n && !p[n - 1]; i++);
}

void f() {
        DWORD arr[8];

        g(arr, 4);
}
