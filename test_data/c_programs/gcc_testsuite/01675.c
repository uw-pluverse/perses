

typedef struct services
{
   int compId;
   void *globalServices;
}services_t;

typedef struct comp
{
   void *myServices;
   void (*setServices)(struct comp *self, services_t *myServices);
   void *myPort;
}comp_t;


void sub0(comp_t *self, services_t *myServices);

int main(int argc, char **argv)
{
   services_t servicesObj;
   comp_t myComp;

   servicesObj.compId = 17;
   servicesObj.globalServices = 0;
   myComp.myServices = &servicesObj;
   myComp.setServices = 0;
   myComp.myPort = 0;

   sub0(&myComp, &servicesObj);

   return 0;
}
