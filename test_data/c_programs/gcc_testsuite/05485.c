


static int min(int a,int b){return (a<b)?a:b;}
static int max(int a,int b){return (a<b)?b:a;}
int f(int x){return max(x,-2147483647 -1);}
int g(int x){return min(x,2147483647);}
