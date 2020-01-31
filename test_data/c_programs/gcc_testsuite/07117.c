







extern void link_error (int, double, double);






int main()
{
  do { if (sizeof (double) == 8 && __builtin_sin(-0x1.c0016155c4da3p-1) != -0x1.88fc58bcf030dp-1) link_error(18, __builtin_sin(-0x1.c0016155c4da3p-1), -0x1.88fc58bcf030dp-1); } while (0);;

  do { if (sizeof (double) == 8 && __builtin_sin(0x1.30654d85c2756p-2) != 0x1.2beeb9de27a79p-2) link_error(20, __builtin_sin(0x1.30654d85c2756p-2), 0x1.2beeb9de27a79p-2); } while (0);;

  do { if (sizeof (double) == 8 && __builtin_sin(0x1.fe68ccaa8e201p+2) != 0x1.fc3f0c54e97a7p-1) link_error(22, __builtin_sin(0x1.fe68ccaa8e201p+2), 0x1.fc3f0c54e97a7p-1); } while (0);;


  do { if (sizeof (double) == 8 && __builtin_sin(0.0) != 0.0) link_error(25, __builtin_sin(0.0), 0.0); } while (0);;

  return 0;
}
