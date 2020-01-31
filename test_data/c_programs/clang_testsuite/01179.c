void __declspec(dllexport) export_function(void) {}
void __attribute__((dllexport)) export_gnu_attribute(void) {}
void __declspec(dllimport) import_function(void);
void __attribute__((dllimport)) import_gnu_attribute(void);
