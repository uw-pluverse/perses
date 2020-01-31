#pragma clang diagnostic pop
#pragma clang diagnostic puhs
int a = 'df';
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmultichar"
int b = 'df';
#pragma clang diagnostic pop
int c = 'df';
#pragma clang diagnostic pop
void ppo0(){}
#pragma clang diagnostic push
#pragma clang diagnostic warning "-Weverything"
void ppr1(){}
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Weverything"
void pps2(){}
#pragma clang diagnostic warning "-Weverything"
void ppt2(){}
#pragma clang diagnostic error "-Weverything"
void ppt3(){}
#pragma clang diagnostic pop
void pps1(){}
#pragma clang diagnostic pop
void ppu(){}
