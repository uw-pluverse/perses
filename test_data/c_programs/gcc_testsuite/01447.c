





void
__attribute__ ((target ("arm")))
bar()
{
}

void
__attribute__ ((target ("thumb")))
__attribute__ ((optimize ("Os")))
foo()
{
}

void
__attribute__ ((target ("thumb")))
__attribute__ ((optimize ("O2")))
rab()
{
}
