




void* test_builtin_address (unsigned i)
{
  void* const ba[] = {
    __builtin_frame_address (4),
    __builtin_return_address (4)
  };

  return ba [i];
}
