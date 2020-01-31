

struct X;
struct Y {
    struct X (*fnptr)(struct X);
};
struct Y foo;
