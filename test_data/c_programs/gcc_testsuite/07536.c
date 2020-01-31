





int
t_run_test(void);

int
t_run_test()
{
     int k_1,i_1, j_1;
     static signed char f_1[8][8] ;
     static long F_1[8][8] ;
     long cosMatrixA[8][8] ;

     for( k_1 = 0 ; k_1 < 8 ; k_1++ )
        {
            for( i_1 = 0 ; i_1 < 8 ; i_1++ )
            {
                for( j_1 = 0 ; j_1 < 8 ; j_1++ )
                    F_1[i_1][j_1] += f_1[i_1][k_1] * cosMatrixA[k_1][j_1] ;
            }
        }

  return 0;
}
