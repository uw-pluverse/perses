

void foo()
{
  int i, j;
  for (i = 0; i < 10; ++i)
    {
#pragma omp for
 for (j = ({ continue; 0; });
    j < ({ continue; 10; });
    j += ({ continue; 1; }))
 continue;

#pragma omp for
 for (j = ({ break; 0; });
    j < ({ break; 10; });
    j += ({ break; 1; }))
 break;
    }
}
