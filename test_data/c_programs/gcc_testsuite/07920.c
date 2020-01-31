






struct s {
  int a;
};

struct t {
  struct s a;
  int b[2];
};



enum e {
  E1 = ((long unsigned int)(long unsigned int) &((struct s *)0)->a),
  E2 = ((long unsigned int)(long unsigned int) &((struct t *)0)->a.a),
  E3 = ((long unsigned int)(long unsigned int) &((struct t *)0)->b[1]),
  E4 = __builtin_offsetof (struct s, a),
  E5 = __builtin_offsetof (struct t, a.a),
  E6 = __builtin_offsetof (struct t, b[1])
};
