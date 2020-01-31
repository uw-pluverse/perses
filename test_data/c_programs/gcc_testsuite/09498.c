inline int dontgenerate1 (void)
{
  return 1;
}

inline int dontgenerate2 (void);
inline int dontgenerate2 (void)
{
  return 2;
}

inline int dontgenerate3 (void)
{
  return 3;
}
inline int dontgenerate3 (void);

extern inline int func1 (void) { return 1; }

extern inline int func2 (void);
inline int func2 (void) { return 2; }

inline int func3 (void) { return 3; }
extern inline int func3 (void);

inline int func4 (void);
extern inline int func4 (void) { return 4; }

extern inline int func5 (void) { return 5; }
inline int func5 (void);

extern int func6 (void);
inline int func6 (void) { return 6; }

inline int func7 (void) { return 7; }
extern int func7 (void);

inline int func8 (void);
extern int func8 (void) { return 8; }

extern int func9 (void) { return 9; }
inline int func9 (void);
