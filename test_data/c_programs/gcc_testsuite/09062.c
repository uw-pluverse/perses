





__thread int i __attribute__((section("foo")));

__thread int j __attribute__((section(".data")));

int k __attribute__((section("bar")));
__thread int l __attribute__((section("bar")));
