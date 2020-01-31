typedef int wchar_t;
extern void foo(const wchar_t* p);
int main (int argc, const char * argv[])
{
 foo(L"This is some text");
 return 0;
}
