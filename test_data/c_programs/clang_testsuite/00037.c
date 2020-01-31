#pragma clang system_header
typedef struct {
 void *foo;
} pthread_mutex_t;
typedef struct {
 void *foo;
} pthread_mutexattr_t;
typedef struct {
 void *foo;
} lck_grp_t;
typedef pthread_mutex_t lck_mtx_t;
extern int pthread_mutex_lock(pthread_mutex_t *);
extern int pthread_mutex_unlock(pthread_mutex_t *);
extern int pthread_mutex_trylock(pthread_mutex_t *);
extern int pthread_mutex_destroy(pthread_mutex_t *);
extern int pthread_mutex_init(pthread_mutex_t *mutex, const pthread_mutexattr_t *mutexattr);
extern int lck_mtx_lock(lck_mtx_t *);
extern int lck_mtx_unlock(lck_mtx_t *);
extern int lck_mtx_try_lock(lck_mtx_t *);
extern void lck_mtx_destroy(lck_mtx_t *lck, lck_grp_t *grp);
pthread_mutex_t mtx1, mtx2;
pthread_mutex_t *pmtx;
lck_mtx_t lck1, lck2;
lck_grp_t grp1;
void
ok1(void)
{
 pthread_mutex_lock(&mtx1);
}
void
ok2(void)
{
 pthread_mutex_unlock(&mtx1);
}
void
ok3(void)
{
 pthread_mutex_lock(&mtx1);
 pthread_mutex_unlock(&mtx1);
 pthread_mutex_lock(&mtx1);
 pthread_mutex_unlock(&mtx1);
}
void
ok4(void)
{
 pthread_mutex_lock(&mtx1);
 pthread_mutex_unlock(&mtx1);
 pthread_mutex_lock(&mtx2);
 pthread_mutex_unlock(&mtx2);
}
void
ok5(void)
{
 if (pthread_mutex_trylock(&mtx1) == 0)
  pthread_mutex_unlock(&mtx1);
}
void
ok6(void)
{
 lck_mtx_lock(&lck1);
}
void
ok7(void)
{
 if (lck_mtx_try_lock(&lck1) != 0)
  lck_mtx_unlock(&lck1);
}
void
ok8(void)
{
 pthread_mutex_lock(&mtx1);
 pthread_mutex_lock(&mtx2);
 pthread_mutex_unlock(&mtx2);
 pthread_mutex_unlock(&mtx1);
}
void
ok9(void)
{
 pthread_mutex_unlock(&mtx1);
 if (pthread_mutex_trylock(&mtx1) == 0)
  pthread_mutex_unlock(&mtx1);
}
void
ok10(void)
{
 if (pthread_mutex_trylock(&mtx1) != 0)
  pthread_mutex_lock(&mtx1);
 pthread_mutex_unlock(&mtx1);
}
void
ok11(void)
{
 pthread_mutex_destroy(&mtx1);
}
void
ok12(void)
{
 pthread_mutex_destroy(&mtx1);
 pthread_mutex_destroy(&mtx2);
}
void
ok13(void)
{
 pthread_mutex_unlock(&mtx1);
 pthread_mutex_destroy(&mtx1);
}
void
ok14(void)
{
 pthread_mutex_unlock(&mtx1);
 pthread_mutex_destroy(&mtx1);
 pthread_mutex_unlock(&mtx2);
 pthread_mutex_destroy(&mtx2);
}
void
ok15(void)
{
 pthread_mutex_lock(&mtx1);
 pthread_mutex_unlock(&mtx1);
 pthread_mutex_destroy(&mtx1);
}
void
ok16(void)
{
 pthread_mutex_init(&mtx1, 0);
}
void
ok17(void)
{
 pthread_mutex_init(&mtx1, 0);
 pthread_mutex_init(&mtx2, 0);
}
void
ok18(void)
{
 pthread_mutex_destroy(&mtx1);
 pthread_mutex_init(&mtx1, 0);
}
void
ok19(void)
{
 pthread_mutex_destroy(&mtx1);
 pthread_mutex_init(&mtx1, 0);
 pthread_mutex_destroy(&mtx2);
 pthread_mutex_init(&mtx2, 0);
}
void
ok20(void)
{
 pthread_mutex_unlock(&mtx1);
 pthread_mutex_destroy(&mtx1);
 pthread_mutex_init(&mtx1, 0);
 pthread_mutex_destroy(&mtx1);
 pthread_mutex_init(&mtx1, 0);
}
void
ok21(void) {
  pthread_mutex_lock(pmtx);
  pthread_mutex_unlock(pmtx);
}
void
ok22(void) {
  pthread_mutex_lock(pmtx);
  pthread_mutex_unlock(pmtx);
  pthread_mutex_lock(pmtx);
  pthread_mutex_unlock(pmtx);
}
void ok23(void) {
  if (pthread_mutex_destroy(&mtx1) != 0)
    pthread_mutex_destroy(&mtx1);
}
void ok24(void) {
  if (pthread_mutex_destroy(&mtx1) != 0)
    pthread_mutex_lock(&mtx1);
}
void ok25(void) {
  if (pthread_mutex_destroy(&mtx1) != 0)
    pthread_mutex_unlock(&mtx1);
}
void ok26(void) {
  pthread_mutex_unlock(&mtx1);
  if (pthread_mutex_destroy(&mtx1) != 0)
    pthread_mutex_lock(&mtx1);
}
void ok27(void) {
  pthread_mutex_unlock(&mtx1);
  if (pthread_mutex_destroy(&mtx1) != 0)
    pthread_mutex_lock(&mtx1);
  else
    pthread_mutex_init(&mtx1, 0);
}
void ok28(void) {
  if (pthread_mutex_destroy(&mtx1) != 0) {
    pthread_mutex_lock(&mtx1);
    pthread_mutex_unlock(&mtx1);
    pthread_mutex_destroy(&mtx1);
  }
}
void
bad1(void)
{
 pthread_mutex_lock(&mtx1);
 pthread_mutex_lock(&mtx1);
}
void
bad2(void)
{
 pthread_mutex_lock(&mtx1);
 pthread_mutex_unlock(&mtx1);
 pthread_mutex_lock(&mtx1);
 pthread_mutex_lock(&mtx1);
}
void
bad3(void)
{
 pthread_mutex_lock(&mtx1);
 pthread_mutex_lock(&mtx2);
 pthread_mutex_unlock(&mtx1);
 pthread_mutex_unlock(&mtx2);
}
void
bad4(void)
{
 if (pthread_mutex_trylock(&mtx1))
  return;
 pthread_mutex_lock(&mtx2);
 pthread_mutex_unlock(&mtx1);
}
void
bad5(void)
{
 lck_mtx_lock(&lck1);
 lck_mtx_lock(&lck1);
}
void
bad6(void)
{
 lck_mtx_lock(&lck1);
 lck_mtx_unlock(&lck1);
 lck_mtx_lock(&lck1);
 lck_mtx_lock(&lck1);
}
void
bad7(void)
{
 lck_mtx_lock(&lck1);
 lck_mtx_lock(&lck2);
 lck_mtx_unlock(&lck1);
 lck_mtx_unlock(&lck2);
}
void
bad8(void)
{
 if (lck_mtx_try_lock(&lck1) == 0)
  return;
 lck_mtx_lock(&lck2);
 lck_mtx_unlock(&lck1);
}
void
bad9(void)
{
 lck_mtx_unlock(&lck1);
 lck_mtx_unlock(&lck1);
}
void
bad10(void)
{
 lck_mtx_lock(&lck1);
 lck_mtx_unlock(&lck1);
 lck_mtx_unlock(&lck1);
}
static void
bad11_sub(pthread_mutex_t *lock)
{
 lck_mtx_unlock(lock);
}
void
bad11(int i)
{
 lck_mtx_lock(&lck1);
 lck_mtx_unlock(&lck1);
 if (i < 5)
  bad11_sub(&lck1);
}
void
bad12(void)
{
 pthread_mutex_lock(&mtx1);
 pthread_mutex_unlock(&mtx1);
 pthread_mutex_lock(&mtx1);
 pthread_mutex_unlock(&mtx1);
 pthread_mutex_unlock(&mtx1);
}
void
bad13(void)
{
 pthread_mutex_lock(&mtx1);
 pthread_mutex_unlock(&mtx1);
 pthread_mutex_lock(&mtx2);
 pthread_mutex_unlock(&mtx2);
 pthread_mutex_unlock(&mtx1);
}
void
bad14(void)
{
 pthread_mutex_lock(&mtx1);
 pthread_mutex_lock(&mtx2);
 pthread_mutex_unlock(&mtx2);
 pthread_mutex_unlock(&mtx1);
 pthread_mutex_unlock(&mtx2);
}
void
bad15(void)
{
 pthread_mutex_lock(&mtx1);
 pthread_mutex_lock(&mtx2);
 pthread_mutex_unlock(&mtx2);
 pthread_mutex_unlock(&mtx1);
 pthread_mutex_lock(&mtx1);
 pthread_mutex_unlock(&mtx2);
}
void
bad16(void)
{
 pthread_mutex_destroy(&mtx1);
 pthread_mutex_lock(&mtx1);
}
void
bad17(void)
{
 pthread_mutex_destroy(&mtx1);
 pthread_mutex_unlock(&mtx1);
}
void
bad18(void)
{
 pthread_mutex_destroy(&mtx1);
 pthread_mutex_destroy(&mtx1);
}
void
bad19(void)
{
 pthread_mutex_lock(&mtx1);
 pthread_mutex_destroy(&mtx1);
}
void
bad20(void)
{
 lck_mtx_destroy(&mtx1, &grp1);
 lck_mtx_lock(&mtx1);
}
void
bad21(void)
{
 lck_mtx_destroy(&mtx1, &grp1);
 lck_mtx_unlock(&mtx1);
}
void
bad22(void)
{
 lck_mtx_destroy(&mtx1, &grp1);
 lck_mtx_destroy(&mtx1, &grp1);
}
void
bad23(void)
{
 lck_mtx_lock(&mtx1);
 lck_mtx_destroy(&mtx1, &grp1);
}
void
bad24(void)
{
 pthread_mutex_init(&mtx1, 0);
 pthread_mutex_init(&mtx1, 0);
}
void
bad25(void)
{
 pthread_mutex_lock(&mtx1);
 pthread_mutex_init(&mtx1, 0);
}
void
bad26(void)
{
 pthread_mutex_unlock(&mtx1);
 pthread_mutex_init(&mtx1, 0);
}
void bad27(void) {
  pthread_mutex_unlock(&mtx1);
  int ret = pthread_mutex_destroy(&mtx1);
  if (ret != 0)
    pthread_mutex_lock(&mtx1);
  else
    pthread_mutex_unlock(&mtx1);
}
void bad28(void) {
  pthread_mutex_unlock(&mtx1);
  int ret = pthread_mutex_destroy(&mtx1);
  if (ret != 0)
    pthread_mutex_lock(&mtx1);
  else
    pthread_mutex_lock(&mtx1);
}
void bad29(void) {
  pthread_mutex_lock(&mtx1);
  pthread_mutex_unlock(&mtx1);
  if (pthread_mutex_destroy(&mtx1) != 0)
    pthread_mutex_init(&mtx1, 0);
  else
    pthread_mutex_init(&mtx1, 0);
}
void bad30(void) {
  pthread_mutex_lock(&mtx1);
  pthread_mutex_unlock(&mtx1);
  if (pthread_mutex_destroy(&mtx1) != 0)
    pthread_mutex_init(&mtx1, 0);
  else
    pthread_mutex_destroy(&mtx1);
}
void bad31(void) {
  int ret = pthread_mutex_destroy(&mtx1);
  pthread_mutex_lock(&mtx1);
  if (ret != 0)
    pthread_mutex_lock(&mtx1);
}
