


void bar (int);
int
foo (int argc, char *argv[])
{
  if (argc != 1 || argc != 2) return 1;
  if (argc < 0 && argc > 10) return 1;
  if (argc || !argc) return 1;
  if (argc && !argc) return 1;
  bar (argc != 1 || argc != 2);
  bar (argc < 0 && argc > 10);
  bar (argc || !argc);
  bar (argc && !argc);
  return (argc != 1 || argc != 2) ? 1 : 0 ;
  return (argc < 0 && argc > 10) ? 1 : 0;
  return (argc || !argc) ? 1 : 0;
  return (argc && !argc) ? 1 : 0;

  if (argc == 2 && argc == 1) return 1;
  if (argc < 0 && argc > 10) return 1;
  if (argc || !argc) return 1;
  if (argc && !argc) return 1;
  bar (argc == 2 && argc == 1);
  bar (argc < 0 && argc > 10);
  bar (argc || !argc);
  bar (argc && !argc);
  return (argc == 2 && argc == 1) ? 1 : 0 ;
  return (argc < 0 && argc > 10) ? 1 : 0;
  return (argc || !argc) ? 1 : 0;
  return (argc && !argc) ? 1 : 0;

  if (argc == 2 && argc == 1) return 1;
  if (argc < 0 && argc > 10) return 1;
  if (!argc || argc) return 1;
  if (!argc && argc) return 1;
  bar (argc == 2 && argc == 1);
  bar (argc < 0 && argc > 10);
  bar (!argc || argc);
  bar (!argc && argc);
  return (argc == 2 && argc == 1) ? 1 : 0 ;
  return (argc < 0 && argc > 10) ? 1 : 0;
  return (!argc || argc) ? 1 : 0;
  return (!argc && argc) ? 1 : 0;

  return 0;
}

int
foo2 (int argc)
{
  if (5 != 1 || 5 != 2) return 1;
  if (5 < 0 && 5 > 10) return 1;
  if (1 || 0) return 1;
  if (0 && 1) return 1;
  if (2 || !2) return 1;
  if (2 && !2) return 1;
  if (!(!2) || !(2)) return 1;
  if (!(!2) && !(2)) return 1;
  bar (5 != 1 || 5 != 2);
  bar (5 < 0 && 5 > 10);
  bar (1 || 0);
  bar (0 && 1);
  bar (2 || !2);
  bar (2 && !2);
  return (5 != 1 || 5 != 2) ? 1 : 0 ;
  return (5 < 0 && 5 > 10) ? 1 : 0;
  return (1 || 0) ? 1 : 0 ;
  return (0 && 1) ? 1 : 0;
  return (2 || !2) ? 1 : 0;
  return (2 && !2) ? 1 : 0;

  return 0;
}
