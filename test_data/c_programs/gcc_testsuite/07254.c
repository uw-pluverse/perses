


extern void __attribute__((dllimport, visibility("hidden")))
  f1();
extern void __attribute__((visibility("hidden"), dllimport))
  f2();
extern void __attribute__((dllexport, visibility("hidden")))
  f3();
extern void __attribute__((visibility("hidden"), dllexport))
  f4();
extern void __attribute__((visibility("default"), dllimport))
  f5();
extern void __attribute__((dllimport, visibility("default")))
  f6();
extern void __attribute__((visibility("default"), dllexport))
  f7();
extern void __attribute__((dllexport, visibility("default")))
  f8();
