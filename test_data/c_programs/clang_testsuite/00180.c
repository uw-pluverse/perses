#pragma pack 10
#pragma pack()
#pragma pack(8)
#pragma pack(hello)
#pragma pack(push)
#pragma pack(pop)
#pragma pack(push,)
#pragma pack(push,)
#pragma pack(pop,)
#pragma pack(push,i)
#pragma pack(push,i,
#pragma pack(push,i,)
#pragma pack(push,i,help)
#pragma pack(push,8)
#pragma pack(push,8,
#pragma pack(push,8,)
#pragma pack(push,i,8
#pragma pack(push,i,8)
#pragma pack(push

#pragma pack(push)

                                                                          
#pragma pack(push,)
                                                                          
struct S
{
  char a[3];
#pragma pack(1)
  struct T
  {
    char b;
    int c;
  } d;
#pragma pack()
  int e;
};

#pragma pack(push, 1)
 struct PR28094 {
  int a;
}
#pragma pack(pop)
 ;
