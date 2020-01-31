__declspec(dllimport) void initialise(signed char buffer[4096]);
__declspec(dllexport) signed char function(unsigned index) {
  signed char buffer[4096];
  initialise(buffer);
  return buffer[index];
}
