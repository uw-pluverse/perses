void *myAlloc(long long);
void f(int n) {
  int n_copy;
  int promise;
  __builtin_coro_id(32, &promise, 0, 0);
  __builtin_coro_alloc();
  __builtin_coro_begin(myAlloc(__builtin_coro_size()));
  __builtin_coro_resume(__builtin_coro_frame());
  __builtin_coro_destroy(__builtin_coro_frame());
  __builtin_coro_done(__builtin_coro_frame());
  __builtin_coro_promise(__builtin_coro_frame(), 48, 0);
  __builtin_coro_free(__builtin_coro_frame());
  __builtin_coro_end(__builtin_coro_frame(), 0);
  __builtin_coro_suspend(1);
  __builtin_coro_param(&n, &n_copy);
}
