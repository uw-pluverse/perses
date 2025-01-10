int test ( void )
{
int __seg_fs * f = ( int __seg_fs * ) 16 ;
int __seg_gs * g = { abort } ;
return * f + * g ;
}
