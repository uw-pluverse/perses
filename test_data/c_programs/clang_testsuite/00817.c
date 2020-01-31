__declspec(dllexport) int export_int;
__declspec(dllimport) int import_int;
__declspec(dllexport) void export_declared_function();
__declspec(dllexport) void export_implemented_function() {
}
__declspec(dllimport) void import_function(int);
void call_imported_function() {
  export_declared_function();
  return import_function(import_int);
}
