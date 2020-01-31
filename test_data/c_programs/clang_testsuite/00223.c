typedef __builtin_va_list va_list_2;
void test(const char* format, ...) { va_list args; va_start( args, format ); }
