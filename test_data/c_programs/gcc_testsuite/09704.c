





void foo (int *a, int i, int j, int k, int l, int m)
{
#pragma omp parallel for num_threads (3 * i) schedule (dynamic, i * 4)
 for (j = 0; j <= (6 * l + 4 * k); j++)
    a[j] = 1;
#pragma omp parallel for num_threads (3 * i) schedule (dynamic, i * 4)
 for (j = m; j <= l; j += (k + l - m))
    a[j] = 1;
}
