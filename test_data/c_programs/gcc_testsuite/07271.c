





struct PDATA
{
    unsigned int Dummy:(sizeof(int)*8);
    const char* PName;
};

typedef struct PDATA P_DATA;

struct PLAYBOOK {
        const char * BookName;
        P_DATA Play[0];
};

struct PLAYBOOK playbook =
{
  "BookName",
  {
    { 1, "PName0" },
  }
};
