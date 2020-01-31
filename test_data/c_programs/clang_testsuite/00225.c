int f(int) __attribute__((visibility("default"), overloadable));
int g(int) __attribute__((abi_tag("foo", "bar", "baz"), no_sanitize("address", "memory")));
