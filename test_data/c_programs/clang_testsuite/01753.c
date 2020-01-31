typedef __builtin_va_list va_list;
void myFunc() {
    va_list values;
    int value;
    while (value = __builtin_va_arg(values, int)) {
    }
}
