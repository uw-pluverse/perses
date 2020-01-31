




static int max(int a,int b){return (a<b)?b:a;}
int f(int x,int y){return max(-x,-y);}
int g(int x,int y){return max(~x,~y);}
double h(double x,double y){return __builtin_fmax(-x,-y);}
