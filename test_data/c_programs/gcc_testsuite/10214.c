




#pragma pack(pop)

#pragma pack(push)
#pragma pack(pop)

#pragma pack(push, foo, 1)
#pragma pack(pop, foo, 1)


#pragma pack(push, foo, 1)
#pragma pack(pop, bar)
#pragma pack(pop)

#pragma pack(push, foo, 1)
#pragma pack(pop)
#pragma pack(pop, foo)

#pragma pack(push, foo, 3)

extern int blah;
