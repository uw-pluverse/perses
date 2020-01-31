typedef struct __CFError * CFErrorRef;
void junk(int, ...);
int main()
{
 CFErrorRef error;
 junk(1, *error, (void)0);
}
