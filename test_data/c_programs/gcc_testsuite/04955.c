





typedef struct A1 {
  char a1[1];
  char c;
} A1;

typedef struct A1_x_2 {
  char a1[1];
  char a[][2];
} A1_x_2;

typedef struct A1_1_x {
  char a1_1[1][1];
  char a[];
} A1_1_x;

typedef struct Ax_2_3 {
  int i;
  char a_x_2_3[][2][3];
} Ax_2_3;

typedef struct A1_1 {
  char a1_1[1][1];
  char c;
} A1_1;

typedef struct B {
  A1_1 a2_3[2][3];
  char a1_1[3][5];
  char a[];
} B;



typedef struct C {
  A1_1_x a5_7 [5][7];
  int a;
} C;


typedef struct FA0 {
  int i;
  char a0 [0];
} FA0;

typedef struct FA1 {
  int i;
  char a1 [1];
} FA1;

typedef struct FA3 {
  int i;
  char a3 [3];
} FA3;


typedef struct FA5_7 {
  int i;
  char a5_7 [5][7];
} FA5_7;

static void test (void)
{




  int a[] = {
    __builtin_offsetof (A1, a1),
    __builtin_offsetof (A1, a1 [0]),



    __builtin_offsetof (A1, a1 [1]),

    __builtin_offsetof (A1, a1 [2]),

    __builtin_offsetof (A1_x_2, a1),
    __builtin_offsetof (A1_x_2, a1 [0]),
    __builtin_offsetof (A1_x_2, a1 [1]),
    __builtin_offsetof (A1_x_2, a1 [2]),

    __builtin_offsetof (A1_x_2, a),
    __builtin_offsetof (A1_x_2, a [0]),
    __builtin_offsetof (A1_x_2, a [1]),
    __builtin_offsetof (A1_x_2, a [99]),

    __builtin_offsetof (A1_x_2, a),
    __builtin_offsetof (A1_x_2, a [0][0]),
    __builtin_offsetof (A1_x_2, a [0][1]),




    __builtin_offsetof (A1_x_2, a [0][2]),



    __builtin_offsetof (A1_x_2, a [0][3]),

    __builtin_offsetof (A1_x_2, a [1][0]),
    __builtin_offsetof (A1_x_2, a [1][1]),
    __builtin_offsetof (A1_x_2, a [1][2]),
    __builtin_offsetof (A1_x_2, a [99][0]),
    __builtin_offsetof (A1_x_2, a [99][1]),
    __builtin_offsetof (A1_x_2, a [99][2]),

    __builtin_offsetof (A1_1_x, a),
    __builtin_offsetof (A1_1_x, a [0]),
    __builtin_offsetof (A1_1_x, a [1]),
    __builtin_offsetof (A1_1_x, a [99]),

    __builtin_offsetof (A1_1_x, a1_1 [0][0]),
    __builtin_offsetof (A1_1_x, a1_1 [0][1]),
    __builtin_offsetof (A1_1_x, a1_1 [0][2]),
    __builtin_offsetof (A1_1_x, a1_1 [1][0]),
    __builtin_offsetof (A1_1_x, a1_1 [1][1]),

    __builtin_offsetof (Ax_2_3, a_x_2_3 [0][1][3]),
    __builtin_offsetof (Ax_2_3, a_x_2_3 [0][1][4]),
    __builtin_offsetof (Ax_2_3, a_x_2_3 [0][2]),
    __builtin_offsetof (Ax_2_3, a_x_2_3 [0][2][0]),

    __builtin_offsetof (B, a2_3 [0][0].c),
    __builtin_offsetof (B, a2_3 [0][0].a1_1 [0][0]),
    __builtin_offsetof (B, a2_3 [1][3]),
    __builtin_offsetof (B, a2_3 [1][4]),
    __builtin_offsetof (B, a2_3 [0][0].a1_1 [0][1]),
    __builtin_offsetof (B, a2_3 [0][0].a1_1 [0][2]),

    __builtin_offsetof (B, a2_3 [0][0].a1_1 [1][0]),
    __builtin_offsetof (B, a2_3 [0][0].a1_1 [1][1]),

    __builtin_offsetof (B, a2_3 [1][2].a1_1 [0][0]),


    __builtin_offsetof (B, a2_3 [1][2].a1_1 [0][1]),
    __builtin_offsetof (B, a2_3 [1][2].a1_1 [1][0]),
    __builtin_offsetof (B, a2_3 [1][2].a1_1 [1][1]),


    __builtin_offsetof (B, a2_3 [1][3]),


    __builtin_offsetof (B, a2_3 [1][3].a1_1 [0][0]),
    __builtin_offsetof (B, a2_3 [1][3].a1_1 [0][0]),
    __builtin_offsetof (B, a2_3 [1][3].a1_1 [0][1]),
    __builtin_offsetof (B, a2_3 [1][3].a1_1 [1][0]),
    __builtin_offsetof (B, a2_3 [1][3].a1_1 [1][1]),



    __builtin_offsetof (B, a2_3 [1][3].c),
    __builtin_offsetof (B, a2_3 [1][3].c),


    __builtin_offsetof (B, a2_3 [2][0].a1_1 [0][0]),
    __builtin_offsetof (B, a2_3 [2][0].a1_1 [0][1]),
    __builtin_offsetof (B, a2_3 [2][0].a1_1 [1][0]),
    __builtin_offsetof (B, a2_3 [2][0].a1_1 [1][1]),
    __builtin_offsetof (B, a2_3 [2][0].c),

    __builtin_offsetof (C, a5_7 [4][6]),
    __builtin_offsetof (C, a5_7 [4][6].a),
    __builtin_offsetof (C, a5_7 [4][6].a [0]),
    __builtin_offsetof (C, a5_7 [4][6].a [99]),

    __builtin_offsetof (C, a5_7 [4][7]),


    __builtin_offsetof (C, a5_7 [4][7].a),
    __builtin_offsetof (C, a5_7 [4][7].a [0]),
    __builtin_offsetof (C, a5_7 [4][7].a [99]),




    __builtin_offsetof (FA0, a0 [0]),
    __builtin_offsetof (FA0, a0 [1]),
    __builtin_offsetof (FA0, a0 [99]),

    __builtin_offsetof (FA1, a1 [0]),
    __builtin_offsetof (FA1, a1 [1]),
    __builtin_offsetof (FA1, a1 [99]),

    __builtin_offsetof (FA3, a3 [0]),
    __builtin_offsetof (FA3, a3 [3]),
    __builtin_offsetof (FA3, a3 [99]),

    __builtin_offsetof (FA5_7, a5_7 [0][0]),






    __builtin_offsetof (FA5_7, a5_7 [0][7]),
    __builtin_offsetof (FA5_7, a5_7 [1][7]),



    __builtin_offsetof (FA5_7, a5_7 [5][0]),
    __builtin_offsetof (FA5_7, a5_7 [5][7]),



    __builtin_offsetof (FA5_7, a5_7 [0][8]),
    __builtin_offsetof (FA5_7, a5_7 [6][8])
  };

  (void)&a;
}
