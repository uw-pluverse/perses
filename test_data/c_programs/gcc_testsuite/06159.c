


struct barstruct { char const* some_string; };

void changethepointer(struct barstruct**);

void baz()
{
        struct barstruct bar1;
        struct barstruct* barptr = &bar1;
        changethepointer(&barptr);
        barptr->some_string = "Everything OK";
}
