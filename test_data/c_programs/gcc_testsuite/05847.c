


struct foo {
        unsigned a1: 1;
        unsigned a2: 3;
        unsigned : 4;
};

extern struct foo thefoo, theotherfoo;

void setup_foo(void)
{
        const struct foo init = {
                .a1 = 1,
                .a2 = 5,
        };
 volatile const struct foo volinit = {
  .a1 = 0,
  .a2 = 6
 };
        thefoo = init;
 theotherfoo = volinit;
}
