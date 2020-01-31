typedef struct {
 const char *name;
 int flags;
 union {
   int x;
 } u;
} OptionDef;
const OptionDef options[] = {
 { "a", 0, {3} },
 { "b", 0, {4} },
 { 0, },
};
