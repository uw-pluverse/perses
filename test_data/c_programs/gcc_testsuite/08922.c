


extern int t();

static inline void __attribute__((__noinline__)) function_definition(void) {t();}

static inline void __attribute__((__noinline__)) function_declaration_both_before(void);

static void function_declaration_both_before(void) {t();}

static void function_declaration_both_after(void);

static inline void __attribute__((__noinline__)) function_declaration_both_after(void);

static void function_declaration_both_after(void) {t();}

static void function_declaration_noinline_before(void) __attribute__((__noinline__));

static inline void function_declaration_noinline_before(void) {t();}

static inline void function_declaration_noinline_after(void) {t();}

static void function_declaration_noinline_after(void) __attribute__((__noinline__));

static inline void function_declaration_inline_before(void);

static void __attribute__((__noinline__)) function_declaration_inline_before(void) {t();}

static inline void function_declaration_inline_noinline_before(void);

static void function_declaration_inline_noinline_before(void) __attribute__((__noinline__));

static void function_declaration_inline_noinline_before(void) {t();}

static inline void function_declaration_inline_noinline_after(void);

static void function_declaration_inline_noinline_after(void) {t();}

static void function_declaration_inline_noinline_after(void) __attribute__((__noinline__));

static void function_declaration_noinline_inline_before(void) __attribute__((__noinline__));

static inline void function_declaration_noinline_inline_before(void);

static void function_declaration_noinline_inline_before(void) {t();}

void f () {
  function_definition ();
  function_declaration_both_before ();
  function_declaration_both_after ();
  function_declaration_noinline_before ();
  function_declaration_noinline_after ();
  function_declaration_inline_before ();
  function_declaration_inline_noinline_before ();
  function_declaration_inline_noinline_after ();
  function_declaration_noinline_inline_before ();
}
