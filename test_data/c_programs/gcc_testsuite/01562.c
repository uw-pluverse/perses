




typedef struct {char a;} one;
typedef struct {short a;} two;
typedef struct {int a;} four;
typedef struct {long long a;} eight;
typedef struct {int a, b[12];} big;


void dcl_aone (one);


void dcl_atwo (two);


void dcl_afour (four);


void dcl_aeight (eight);


void dcl_abig (big);



void test_1 (void)
{
  dcl_aone (({one t; t.a = 1; t;}));
  dcl_atwo (({two t; t.a = 2; t;}));
  dcl_afour (({four t; t.a = 3; t;}));
  dcl_aeight (({eight t; t.a = 4; t;}));
  dcl_abig (({big t; t.a = 5; t;}));
}


void dfn_aone (one one)
{
}


void dfn_atwo (two two)
{
}


void dfn_afour (four four)
{
}


void dfn_aeight (eight eight)
{
}


void dfn_abig (big big)
{
}
