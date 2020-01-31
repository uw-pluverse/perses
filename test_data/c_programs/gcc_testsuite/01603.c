typedef long double LD;

LD L0(LD x, LD y, LD z) { return __builtin_fmal(x,y,z); }
LD L1(LD x, LD y, LD z) { return __builtin_fmal(x,y,-z); }
LD L2(LD x, LD y, LD z) { return __builtin_fmal(-x,y,z); }
LD L3(LD x, LD y, LD z) { return __builtin_fmal(x,-y,z); }
LD L4(LD x, LD y, LD z) { return __builtin_fmal(-x,-y,z); }
