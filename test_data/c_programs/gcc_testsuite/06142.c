


void q(void);
inline int t(void)
{
 int ret;
 q();
 ret = t();

 q();
 return ret;
}
