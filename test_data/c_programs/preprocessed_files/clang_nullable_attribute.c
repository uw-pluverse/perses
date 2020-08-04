// Copied from https://clang.llvm.org/docs/AttributeReference.html

// No meaningful result when 'ptr' is null (here, it happens to be undefined behavior).
int fetch(int * _Nonnull ptr) { return *ptr; }

// 'ptr' may be null.
int fetch_or_zero(int * _Nullable ptr) {
  return ptr ? *ptr : 0;
}

// A nullable pointer to non-null pointers to const characters.
const char *join_strings(const char * _Nonnull * _Nullable strings, unsigned n);