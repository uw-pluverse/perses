extern int fesetround(int);

void
set_fpu_rounding_mode (int mode)
{
  int rnd_mode;

  switch (mode)
    {
      case 2:
       rnd_mode = 0;
       break;

      case 4:
        rnd_mode = 1;
        break;

      case 1:
        rnd_mode = 2;
        break;

      case 3:
        rnd_mode = 3;
        break;

      default:
        return;
    }

  fesetround (rnd_mode);
}
