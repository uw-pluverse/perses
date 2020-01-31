struct _IO_FILE { int _flags;
};
typedef struct _IO_FILE FILE;
extern struct _IO_FILE *stderr;
void foo ();
void debug_optab_libfuncs (void) {
foo (stderr, 4 );
}
