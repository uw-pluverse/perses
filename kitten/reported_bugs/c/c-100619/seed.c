







void fmn_a1n_axn (int n, int[1][n]);
void fmn_a1n_axn (int n, int[*][n]);


void fmn_axn_a2n (int n, int[*][n]);
void fmn_axn_a2n (int n, int[2][n]);


void fmn_amn_axn (int m, int n, int[m][n]);
void fmn_amn_axn (int m, int n, int[*][n]);


void gmn_amn_axn (int m, int n, int[m][n]);
void gmn_amn_axn (int m, int n, int[*][n]);

typedef int A7[7];

void fm_A7_m_5 (int m, A7[m][5]);
void fm_A7_m_5 (int n, A7[n][5]);

void fm_A7_m_5 (int n, A7[n + 1][5]);


int n1, n2, n3, n4, n5, n6, n7, n8, n9;
void f (int[n1][2][n3][4][n5][6][n7][8][n9]);

void f (int[n1][2][n3][4][n5][6][n7][8][n9]);




void f (int[n1][2][n3][4][n5][6][n7][8][*]);

void f (int[n1][2][n3][4][n5][6][*][8][n9]);

void f (int[n1][2][n3][4][*][6][n7][8][n9]);

void f (int[n1][2][*][4][n5][6][n7][8][n9]);

void f (int[*][2][n3][4][n5][6][n7][8][n9]);

void f (int[n1][n2][n3][n4][n5][n6][n7][n8][n9]);


void a2pampan (int (*(*(*[2])[n1])[n2]));

void a2pampan (int (*(*(*[2])[n1])[1]));

void a2pampan (int (*(*(*[2])[1])[n2]));

void a2pampan (int (*(*(*[2])[n1])[n1]));

void a2pampan (int (*(*(*[2])[n1])[n2]));





int f2ia1_1 (int n, int [n][n]);
int f2ia1_1 (int n, int[static n][n]);
int f2ia1_1 (int n, int a[static n][n]) { return sizeof *a; }
int f2ia1_1 (int n, int[static n + 1][n]);

int f2ias1_1 (int n, int [static n][n]);
int f2ias1_1 (int n, int[n][n]);
int f2ias1_1 (int n, int a[++n][n])
{ return sizeof *a; }
