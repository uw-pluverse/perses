

extern void link_error (void);

int main()
{
  if (!__builtin_constant_p(1.0))
    link_error ();
  if (!__builtin_constant_p(__builtin_fma (1.0, 1.0, 1.0)))
    link_error ();

  if (__builtin_constant_p(__builtin_fmaf (3.40282347e+38F, 3.40282347e+38F, 0.0F)))
    link_error ();
  if (__builtin_constant_p(__builtin_fmaf (3.40282347e+38F, 1.0F, 3.40282347e+38F)))
    link_error ();
  if (__builtin_constant_p(__builtin_fmaf (1.17549435e-38F, 1.17549435e-38F, 0.0F)))
    link_error ();

  if (__builtin_constant_p(__builtin_fma (1.7976931348623157e+308, 1.7976931348623157e+308, 0.0)))
    link_error ();
  if (__builtin_constant_p(__builtin_fma (1.7976931348623157e+308, 1.0, 1.7976931348623157e+308)))
    link_error ();
  if (__builtin_constant_p(__builtin_fma (2.2250738585072014e-308, 2.2250738585072014e-308, 0.0)))
    link_error ();

  if (__builtin_constant_p(__builtin_fmal (1.18973149535723176502e+4932L, 1.18973149535723176502e+4932L, 0.0L)))
    link_error ();
  if (__builtin_constant_p(__builtin_fmal (1.18973149535723176502e+4932L, 1.0L, 1.18973149535723176502e+4932L)))
    link_error ();
  if (__builtin_constant_p(__builtin_fmal (3.36210314311209350626e-4932L, 3.36210314311209350626e-4932L, 0.0L)))
    link_error ();

  return 0;
}
