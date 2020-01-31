void foo() {
    void *ptr;
  label:
    ptr = &&label;
    goto *ptr;
  }
