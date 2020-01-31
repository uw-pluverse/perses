double fabs (double);


typedef struct {
   int m, n;
   float r;
} myctype_t;


typedef struct particle
{
   double x;
   double vx;
   double y;
   double vy;
   double z;
   double vz;
   double m;
}particle_t;

extern void abort(void);
void types_test(particle_t *my_particles, int num_particles);

extern myctype_t myDerived;

int main(int argc, char **argv)
{
   particle_t my_particles[100];


   my_particles[49].x = 1.0;
   my_particles[49].vx = 1.0;
   my_particles[49].y = 1.0;
   my_particles[49].vy = 1.0;
   my_particles[49].z = 1.0;
   my_particles[49].vz = 1.0;
   my_particles[49].m = 1.0;

   myDerived.m = 1;
   myDerived.n = 2;
   myDerived.r = 3.0;

   types_test(&(my_particles[0]), 100);

   if(fabs(my_particles[49].x - 1.2) > 0.00000000)
      abort();
   if(fabs(my_particles[49].vx - 1.2) > 0.00000000)
      abort();
   if(fabs(my_particles[49].y - 1.2) > 0.00000000)
      abort();
   if(fabs(my_particles[49].vy - 1.2) > 0.00000000)
      abort();
   if(fabs(my_particles[49].z - 1.2) > 0.00000000)
      abort();
   if(fabs(my_particles[49].vz - 1.2) > 0.00000000)
      abort();
   if(fabs(my_particles[49].m - 1.2) > 0.00000000)
      abort();
   if(myDerived.m != 2)
      abort();
   if(myDerived.n != 3)
      abort();
   if(fabs(myDerived.r - 4.0) > 0.00000000)
      abort();
   return 0;
}
