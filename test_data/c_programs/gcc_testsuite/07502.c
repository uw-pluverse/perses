


typedef struct {
  int iatom[3];
  int blocknr;
} t_sortblock;



void foo (int ncons, t_sortblock *sb, int *iatom)
{
 int i, m;

 for(i=0; (i<ncons); i++,iatom+=3)
   for(m=0; (m<3); m++)
     iatom[m]=sb[i].iatom[m];
}
