typedef int veci __attribute__ ( ( vector_size ( 4 * - 1 ) ) ) ;
int c ;
void f ( veci * a )
{
* a = * a + ++ c ;
}
