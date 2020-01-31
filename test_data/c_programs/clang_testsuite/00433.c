struct size8 {
  int i : 4;
  long long l : 60;
};
struct layout0 {
  char l0_ofs0;
  struct size8 l0_ofs8;
  int l0_ofs16 : 1;
};
struct size8_anon {
  int : 4;
  long long : 60;
};
struct layout1 {
  char l1_ofs0;
  struct size8_anon l1_ofs1;
  int l1_ofs9 : 1;
};
#pragma pack(1)
struct size8_pack1 {
  int i : 4;
  long long l : 60;
};
struct layout2 {
  char l2_ofs0;
  struct size8_pack1 l2_ofs1;
  int l2_ofs9 : 1;
};
#pragma pack()
#pragma pack(4)
struct size8_pack4 {
  int i : 4;
  long long l : 60;
};
struct layout3 {
  char l3_ofs0;
  struct size8_pack4 l3_ofs4;
  int l3_ofs12 : 1;
};
#pragma pack()
struct layout3 l3;
struct layout0 l0;
struct layout1 l1;
struct layout2 l2;
