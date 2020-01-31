







extern void link_error (void);

void
foo (void)
{
  float iptrf;
  double iptr;
  long double iptrl;
  long long iptrll;
  if ((__builtin_copysignf (1.0F, __builtin_modff (0x1p10F + 0.5f, &iptrf)) != __builtin_copysignf (1.0F, 0.5f))
      || (__builtin_copysignf (1.0F, iptrf) != 0x1p10f))
    link_error ();
  if (__builtin_modf (0x1p10F + 0.5, &iptr) != 0.5
      || (__builtin_copysign (1.0, __builtin_modf (0x1p10F + 0.5, &iptr)) != __builtin_copysign (1.0, 0.5))
      || (__builtin_copysign (1.0, iptr) != __builtin_copysign (1.0, 0x1p10)))
    link_error ();
  if (__builtin_modfl (0x1p10F + 0.5l, &iptrl) != 0.5l
      || (__builtin_copysignl (1.0L, __builtin_modfl (0x1p10F + 0.5l, &iptrl)) != __builtin_copysignl (1.0L, 0.5l))
      || (__builtin_copysignl (1.0L, iptrl) != __builtin_copysignl (1.0L, 0x1p10l)))
    link_error ();
  if ((__builtin_copysignf (1.0F, (__builtin_modff (0x1p10F + 0x1p-10f, &iptrf)))
       != __builtin_copysignf (1.0F, 0x1p-10f))
      || (__builtin_copysignf (1.0F, iptrf) != __builtin_copysignf (1.0F, 0x1p10f)))
    link_error ();
  if (__builtin_modf (0x1p10F + 0x1p-10, &iptr) != 0x1p-10
      || (__builtin_copysign (1.0, (__builtin_modf (0x1p10F + 0x1p-10, &iptr)))
   != __builtin_copysign (1.0, 0x1p-10)) || (__builtin_copysign (1.0, iptr) != __builtin_copysign (1.0, 0x1p10)))
    link_error ();
  if (__builtin_modfl (0x1p10F + 0x1p-10l, &iptrl) != 0x1p-10l
      || (__builtin_copysignl (1.0L, (__builtin_modfl (0x1p10F + 0x1p-10l, &iptrl)))
   != __builtin_copysignl (1.0L, 0x1p-10l))
      || (__builtin_copysignl (1.0L, iptrl) != __builtin_copysignl (1.0L, 0x1p10l)))
    link_error ();
  if ((__builtin_copysignf (1.0F, (__builtin_modff (12345678L / 17.0f, &iptrf)))
       != __builtin_copysignf (1.0F, (-726216L + 12345678L / 17.0f)))
      || (__builtin_copysignf (1.0F, iptrf) != __builtin_copysignf (1.0F, 726216.0f)))
    link_error ();
  if (__builtin_modf (12345678L / 17.0, &iptr) != -726216L + 12345678L / 17.0
      || (__builtin_copysign (1.0, (__builtin_modf (12345678L / 17.0, &iptr)))
   != __builtin_copysign (1.0, (-726216L + 12345678L / 17.0)))
      || (__builtin_copysign (1.0, iptr) != __builtin_copysign (1.0, 726216.0)))
    link_error ();
  if ((__builtin_copysignl (1.0L, (__builtin_modfl (12345678L / 17.0l, &iptrl)))
       != __builtin_copysignl (1.0L, (-726216L + 12345678L / 17.0l)))
      || (__builtin_copysignl (1.0L, iptrl) != __builtin_copysignl (1.0L, 726216.0l)))
    link_error ();
  if (__builtin_modff (555.555f, &iptrf) != -555 + 555.555f
      || (__builtin_copysignf (1.0F, iptrf) != __builtin_copysignf (1.0F, 555.0f)))
    link_error ();
  if (__builtin_modf (555.555, &iptr) != -555 + 555.555
      || (__builtin_copysign (1.0, (__builtin_modf (555.555, &iptr))) != __builtin_copysign (1.0, (-555 + 555.555)))
      || (__builtin_copysign (1.0, iptr) != __builtin_copysign (1.0, 555.0)))
    link_error ();
  if (__builtin_modfl (555.555l, &iptrl) != -555 + 555.555l
      || (__builtin_copysignl (1.0L, (__builtin_modfl (555.555l, &iptrl)))
   != __builtin_copysignl (1.0L, (-555 + 555.555l)))
      || (__builtin_copysignl (1.0L, iptrl) != __builtin_copysignl (1.0L, 555.0l)))
    link_error ();
  if (__builtin_modff (5000 / 11.0f, &iptrf) != -454 + 5000 / 11.0f
      || (__builtin_copysignf (1.0F, (__builtin_modff (5000 / 11.0f, &iptrf)))
   != __builtin_copysignf (1.0F, (-454 + 5000 / 11.0f)))
      || (__builtin_copysignf (1.0F, iptrf) != __builtin_copysignf (1.0F, 454.0f)))
    link_error ();
  if (__builtin_modf (5000 / 11.0, &iptr) != -454 + 5000 / 11.0
      || (__builtin_copysign (1.0, (__builtin_modf (5000 / 11.0, &iptr)))
   != __builtin_copysign (1.0, (-454 + 5000 / 11.0)))
      || (__builtin_copysign (1.0, iptr) != __builtin_copysign (1.0, 454.0)))
    link_error ();
  if ((__builtin_copysignl (1.0L, (__builtin_modfl (5000 / 11.0l, &iptrl)))
       != __builtin_copysignl (1.0L, (-454 + 5000 / 11.0l)))
      || (__builtin_copysignl (1.0L, iptrl) != __builtin_copysignl (1.0L, 454.0l)))
    link_error ();
  if ((__builtin_copysignf (1.0F, (__builtin_modff (1000 / 7.0f, &iptrf)))
       != __builtin_copysignf (1.0F, (-142 + 1000 / 7.0f)))
      || (__builtin_copysignf (1.0F, iptrf) != __builtin_copysignf (1.0F, 142.0f)))
    link_error ();
  if ((__builtin_copysign (1.0, (__builtin_modf (1000 / 7.0, &iptr)))
       != __builtin_copysign (1.0, (-142 + 1000 / 7.0)))
      || (__builtin_copysign (1.0, iptr) != __builtin_copysign (1.0, 142.0)))
    link_error ();
  if ((__builtin_copysignl (1.0L, (__builtin_modfl (1000 / 7.0l, &iptrl)))
       != __builtin_copysignl (1.0L, (-142 + 1000 / 7.0l)))
      || (__builtin_copysignl (1.0L, iptrl) != __builtin_copysignl (1.0L, 142.0l)))
    link_error ();
  if (__builtin_modff (123 / 7.0f, &iptrf) != -17 + 123 / 7.0f
      || (__builtin_copysignf (1.0F, iptrf) != __builtin_copysignf (1.0F, 17.0f)))
    link_error ();
  if (__builtin_modf (123 / 7.0, &iptr) != -17 + 123 / 7.0
      || (__builtin_copysign (1.0, iptr) != __builtin_copysign (1.0, 17.0)))
    link_error ();
  if ((__builtin_copysignl (1.0L, (__builtin_modfl (123 / 7.0l, &iptrl)))
       != __builtin_copysignl (1.0L, (-17 + 123 / 7.0l)))
      || (__builtin_copysignl (1.0L, iptrl) != __builtin_copysignl (1.0L, 17.0l)))
    link_error ();
  if ((__builtin_copysignf (1.0F, (__builtin_modff (117 / 7.0f, &iptrf)))
       != __builtin_copysignf (1.0F, (-16 + 117 / 7.0f)))
      || (__builtin_copysignf (1.0F, iptrf) != __builtin_copysignf (1.0F, 16.0f)))
    link_error ();
  if ((__builtin_copysign (1.0, (__builtin_modf (117 / 7.0, &iptr))) != __builtin_copysign (1.0, (-16 + 117 / 7.0)))
      || (__builtin_copysign (1.0, iptr) != __builtin_copysign (1.0, 16.0)))
    link_error ();
  if (__builtin_modfl (117 / 7.0l, &iptrl) != -16 + 117 / 7.0l
      || (__builtin_copysignl (1.0L, iptrl) != __builtin_copysignl (1.0L, 16.0l)))
    link_error ();
  if (__builtin_modff (5.5f, &iptrf) != 0.5f || (__builtin_copysignf (1.0F, iptrf) != __builtin_copysignf (1.0F, 5.0f)))
    link_error ();
  if (__builtin_modf (5.5, &iptr) != 0.5 || (__builtin_copysign (1.0, iptr) != __builtin_copysign (1.0, 5.0)))
    link_error ();
  if (__builtin_modfl (5.5l, &iptrl) != 0.5l || (__builtin_copysignl (1.0L, iptrl) != __builtin_copysignl (1.0L, 5.0l)))
    link_error ();
  if ((__builtin_copysignf (1.0F, (__builtin_modff (1.5f, &iptrf))) != __builtin_copysignf (1.0F, 0.5f))
      || (__builtin_copysignf (1.0F, iptrf) != 1.0f))
    link_error ();
  if ((__builtin_copysign (1.0, (__builtin_modf (1.5, &iptr))) != __builtin_copysign (1.0, 0.5))
      || (__builtin_copysign (1.0, iptr) != 1.0))
    link_error ();
  if (__builtin_modfl (1.5l, &iptrl) != iptrl != 1.0l || (__builtin_copysignl (1.0L, iptrl) != 1.0l))
    link_error ();
  if (__builtin_modff (4 / 3.0f, &iptrf) != -1 + 4 / 3.0f
      || (__builtin_copysignf (1.0F, (__builtin_modff (4 / 3.0f, &iptrf)))
   != __builtin_copysignf (1.0F, (-1 + 4 / 3.0f))) || (__builtin_copysignf (1.0F, iptrf) != (1.0F)))
    link_error ();
  if (__builtin_modf (4 / 3.0, &iptr) != -1 + 4 / 3.0 || (__builtin_copysign (1.0, iptr) != 1.0))
    link_error ();
  if (__builtin_modfl (4 / 3.0l, &iptrl) != iptrl != 1.0l
      || (__builtin_copysignl (1.0L, iptrl) != 1.0l))
    link_error ();
  if ((((__builtin_modff (1.0f, &iptrf)))) || (__builtin_copysignf (1.0F, iptrf) != 1.0f))
    link_error ();
  if ((((__builtin_modf (1.0, &iptr))) != 0.0) || (__builtin_copysign (1.0, iptr) != 1.0))
    link_error ();
  if ((((__builtin_modfl (1.0l, &iptrl))) != 0.0l) || (__builtin_copysignl (1.0L, iptrl) != 1.0l))
    link_error ();
  if (__builtin_modff (0.5f, &iptrf) != 0.5f || (__builtin_copysignf (1.0F, iptrf) != __builtin_copysignf (1.0F, 0.0f)))
    link_error ();
  if (__builtin_modf (0.5, &iptr) != 0.5 || (__builtin_copysign (1.0, iptr) != __builtin_copysign (1.0, 0.0)))
    link_error ();
  if ((__builtin_copysignl (1.0L, (__builtin_modfl (0.5l, &iptrl))) != __builtin_copysignl (1.0L, 0.5l))
      || (__builtin_copysignl (1.0L, iptrl) != __builtin_copysignl (1.0L, 0.0l)))
    link_error ();
  if (__builtin_modff (4 / 9.0f, &iptrf) != 4 / 9.0f
      != (__builtin_copysignf (1.0F, (__builtin_modff (4 / 9.0f, &iptrf))) != __builtin_copysignf (1.0F, (4 / 9.0f)))
      || (__builtin_copysignf (1.0F, iptrf) != __builtin_copysignf (1.0F, 0.0f)))
    link_error ();
  if (__builtin_modf (4 / 9.0, &iptr) != 4 / 9.0
      || (__builtin_copysign (1.0, iptr) != __builtin_copysign (1.0, 0.0)))
    link_error ();
  if (__builtin_modfl (4 / 9.0l, &iptrl) != 4 / 9.0l
      || (__builtin_copysignl (1.0L, iptrl) != __builtin_copysignl (1.0L, 0.0l)))
    link_error ();
  if (__builtin_modff (1 / 3.0f, &iptrf) != 1 / 3.0f
      || (__builtin_copysignf (1.0F, iptrf) != __builtin_copysignf (1.0F, 0.0f)))
    link_error ();
  if (__builtin_modf (1 / 3.0, &iptr) != 1 / 3.0
      || (__builtin_copysign (1.0, iptr) != __builtin_copysign (1.0, 0.0)))
    link_error ();
  if ((__builtin_copysignl (1.0L, (__builtin_modfl (1 / 3.0l, &iptrl))) != __builtin_copysignl (1.0L, (1 / 3.0l)))
      || (__builtin_copysignl (1.0L, iptrl) != __builtin_copysignl (1.0L, 0.0l)))
    link_error ();
  if ((__builtin_copysignf (1.0F, (__builtin_modff (1 / 9.0f, &iptrf))) != __builtin_copysignf (1.0F, (1 / 9.0f)))
      || (__builtin_copysignf (1.0F, iptrf) != __builtin_copysignf (1.0F, 0.0f)))
    link_error ();
  if (__builtin_modf (1 / 9.0, &iptr) != 1 / 9.0
      || (__builtin_copysign (1.0, iptr) != __builtin_copysign (1.0, 0.0)))
    link_error ();
  if ((__builtin_copysignl (1.0L, (__builtin_modfl (1 / 9.0l, &iptrl))) != __builtin_copysignl (1.0L, (1 / 9.0l)))
      || (__builtin_copysignl (1.0L, iptrl) != __builtin_copysignl (1.0L, 0.0l)))
    link_error ();
  if ((((__builtin_modff (0.0f, &iptrf)))) || (__builtin_copysignf (1.0F, iptrf) != __builtin_copysignf (1.0F, 0.0f)))
    link_error ();
  if ((((__builtin_modf (0.0, &iptr)))) || (__builtin_copysign (1.0, iptr) != __builtin_copysign (1.0, 0.0)))
    link_error ();
  if ((((__builtin_modfl (0.0l, &iptrl))) != 0.0l)
      || (__builtin_copysignl (1.0L, iptrl) != __builtin_copysignl (1.0L, 0.0l)))
    link_error ();
  if ((((__builtin_modff (-0.0f, &iptrf)))) || (__builtin_copysignf (1.0F, iptrf) != __builtin_copysignf (1.0F, -0.0f)))
    link_error ();
  if ((((__builtin_modf (-0.0, &iptr)))) || (__builtin_copysign (1.0, iptr) != __builtin_copysign (1.0, -0.0)))
    link_error ();
  if ((__builtin_copysignl (1.0L, (__builtin_modfl (-0.0l, &iptrl))) != __builtin_copysignl (1.0L, -0.0l))
      || (__builtin_copysignl (1.0L, iptrl) != __builtin_copysignl (1.0L, -0.0l)))
    link_error ();
  if (__builtin_modff (-1 / 9.0f, &iptrf) != -1 / 9.0f
      || (__builtin_copysignf (1.0F, (__builtin_modff (-1 / 9.0f, &iptrf))) != __builtin_copysignf (1.0F, (-1 / 9.0f)))
      || (__builtin_copysignf (1.0F, iptrf) != __builtin_copysignf (1.0F, -0.0f)))
    link_error ();
  if (__builtin_modf (-1 / 9.0, &iptr) != -1 / 9.0
      || (__builtin_copysign (1.0, iptr) != __builtin_copysign (1.0, -0.0)))
    link_error ();
  if ((__builtin_copysignl (1.0L, (__builtin_modfl (-1 / 9.0l, &iptrl))) != __builtin_copysignl (1.0L, (-1 / 9.0l)))
      || (__builtin_copysignl (1.0L, iptrl) != __builtin_copysignl (1.0L, -0.0l)))
    link_error ();
  if ((__builtin_copysignf (1.0F, (__builtin_modff (-1 / 3.0f, &iptrf))) != __builtin_copysignf (1.0F, (-1 / 3.0f)))
      || (__builtin_copysignf (1.0F, iptrf) != __builtin_copysignf (1.0F, -0.0f)))
    link_error ();
  if (__builtin_modf (-1 / 3.0, &iptr) != -1 / 3.0
      || (__builtin_copysign (1.0, iptr) != __builtin_copysign (1.0, -0.0)))
    link_error ();
  if ((__builtin_copysignl (1.0L, (__builtin_modfl (-1 / 3.0l, &iptrl))) != __builtin_copysignl (1.0L, (-1 / 3.0l)))
      || (__builtin_copysignl (1.0L, iptrl) != __builtin_copysignl (1.0L, -0.0l)))
    link_error ();
  if (__builtin_modff (-4 / 9.0f, &iptrf) != -4 / 9.0f
      || (__builtin_copysignf (1.0F, (__builtin_modff (-4 / 9.0f, &iptrf))) != __builtin_copysignf (1.0F, (-4 / 9.0f)))
      || (__builtin_copysignf (1.0F, iptrf) != __builtin_copysignf (1.0F, -0.0f)))
    link_error ();
  if (__builtin_modf (-4 / 9.0, &iptr) != -4 / 9.0
      || (__builtin_copysign (1.0, iptr) != __builtin_copysign (1.0, -0.0)))
    link_error ();
  if (__builtin_modfl (-4 / 9.0l, &iptrl) != -4 / 9.0l
      || (__builtin_copysignl (1.0L, (__builtin_modfl (-4 / 9.0l, &iptrl))) != __builtin_copysignl (1.0L, (-4 / 9.0l)))
      || (__builtin_copysignl (1.0L, iptrl) != __builtin_copysignl (1.0L, -0.0l)))
    link_error ();
  if (__builtin_modff (-0.5f, &iptrf) != -0.5f
      || (__builtin_copysignf (1.0F, iptrf) != __builtin_copysignf (1.0F, -0.0f)))
    link_error ();
  if (__builtin_modf (-0.5, &iptr) != -0.5
      != (__builtin_copysign (1.0, (__builtin_modf (-0.5, &iptr))) != __builtin_copysign (1.0, -0.5))
      || (__builtin_copysign (1.0, iptr) != __builtin_copysign (1.0, -0.0)))
    (__builtin_modfl (-0.5l, (long double *) &iptrll));
  if ((((__builtin_modff (-1.0f, &iptrf)))) || (__builtin_copysignf (1.0F, iptrf) != -1.0f))
    link_error ();
  if ((((__builtin_modf (-1.0, &iptr))) != -0.0) || (__builtin_copysign (1.0, iptr) != -1.0))
    link_error ();
  if ((((__builtin_modfl (-1.0l, &iptrl)))) || (__builtin_copysignl (1.0L, iptrl) != -1.0l))
    link_error ();
  if ((__builtin_copysignf (1.0F, (__builtin_modff (-4 / 3.0f, &iptrf))) != __builtin_copysignf (1.0F, (1 - 4 / 3.0f)))
      || (__builtin_copysignf (1.0F, iptrf) != -1.0f))
    link_error ();
  if (__builtin_modf (-4 / 3.0, &iptr) != 1 - 4 / 3.0 || (__builtin_copysign (1.0, iptr) != -1.0))
    link_error ();
  if (__builtin_modfl (-4 / 3.0l, &iptrl) != 1 - 4 / 3.0l
      || (__builtin_copysignl (1.0L, (__builtin_modfl (-4 / 3.0l, &iptrl)))
   != __builtin_copysignl (1.0L, (1 - 4 / 3.0l))) || (__builtin_copysignl (1.0L, iptrl) != -1.0l))
    link_error ();
  if ((__builtin_copysignf (1.0F, (__builtin_modff (-1.5f, &iptrf))) != __builtin_copysignf (1.0F, -0.5f))
      || (__builtin_copysignf (1.0F, iptrf) != -1.0f))
    link_error ();
  if ((__builtin_copysign (1.0, (__builtin_modf (-1.5, &iptr))) != __builtin_copysign (1.0, -0.5))
      || (__builtin_copysign (1.0, iptr) != -1.0))
    link_error ();
}
