volatile vector signed char sc, sc2;
volatile vector unsigned char uc, uc2;
volatile vector bool char bc, bc2;
volatile vector signed short ss, ss2;
volatile vector unsigned short us, us2;
volatile vector bool short bs, bs2;
volatile vector signed int si, si2;
volatile vector unsigned int ui, ui2;
volatile vector bool int bi, bi2;
volatile vector signed long long sl, sl2;
volatile vector unsigned long long ul, ul2;
volatile vector bool long long bl, bl2;
volatile vector double fd, fd2;
volatile int cnt;
void test_assign(void) {
  sc = sc2;
  uc = uc2;
  ss = ss2;
  us = us2;
  si = si2;
  ui = ui2;
  sl = sl2;
  ul = ul2;
  fd = fd2;
}
void test_pos(void) {
  sc = +sc2;
  uc = +uc2;
  ss = +ss2;
  us = +us2;
  si = +si2;
  ui = +ui2;
  sl = +sl2;
  ul = +ul2;
  fd = +fd2;
}
void test_neg(void) {
  sc = -sc2;
  ss = -ss2;
  si = -si2;
  sl = -sl2;
  fd = -fd2;
}
void test_preinc(void) {
  ++sc2;
  ++uc2;
  ++ss2;
  ++us2;
  ++si2;
  ++ui2;
  ++sl2;
  ++ul2;
  ++fd2;
}
void test_postinc(void) {
  sc2++;
  uc2++;
  ss2++;
  us2++;
  si2++;
  ui2++;
  sl2++;
  ul2++;
  fd2++;
}
void test_predec(void) {
  --sc2;
  --uc2;
  --ss2;
  --us2;
  --si2;
  --ui2;
  --sl2;
  --ul2;
  --fd2;
}
void test_postdec(void) {
  sc2--;
  uc2--;
  ss2--;
  us2--;
  si2--;
  ui2--;
  sl2--;
  ul2--;
  fd2--;
}
void test_add(void) {
  sc = sc + sc2;
  sc = sc + bc2;
  sc = bc + sc2;
  uc = uc + uc2;
  uc = uc + bc2;
  uc = bc + uc2;
  ss = ss + ss2;
  ss = ss + bs2;
  ss = bs + ss2;
  us = us + us2;
  us = us + bs2;
  us = bs + us2;
  si = si + si2;
  si = si + bi2;
  si = bi + si2;
  ui = ui + ui2;
  ui = ui + bi2;
  ui = bi + ui2;
  sl = sl + sl2;
  sl = sl + bl2;
  sl = bl + sl2;
  ul = ul + ul2;
  ul = ul + bl2;
  ul = bl + ul2;
  fd = fd + fd2;
}
void test_add_assign(void) {
  sc += sc2;
  sc += bc2;
  uc += uc2;
  uc += bc2;
  ss += ss2;
  ss += bs2;
  us += us2;
  us += bs2;
  si += si2;
  si += bi2;
  ui += ui2;
  ui += bi2;
  sl += sl2;
  sl += bl2;
  ul += ul2;
  ul += bl2;
  fd += fd2;
}
void test_sub(void) {
  sc = sc - sc2;
  sc = sc - bc2;
  sc = bc - sc2;
  uc = uc - uc2;
  uc = uc - bc2;
  uc = bc - uc2;
  ss = ss - ss2;
  ss = ss - bs2;
  ss = bs - ss2;
  us = us - us2;
  us = us - bs2;
  us = bs - us2;
  si = si - si2;
  si = si - bi2;
  si = bi - si2;
  ui = ui - ui2;
  ui = ui - bi2;
  ui = bi - ui2;
  sl = sl - sl2;
  sl = sl - bl2;
  sl = bl - sl2;
  ul = ul - ul2;
  ul = ul - bl2;
  ul = bl - ul2;
  fd = fd - fd2;
}
void test_sub_assign(void) {
  sc -= sc2;
  sc -= bc2;
  uc -= uc2;
  uc -= bc2;
  ss -= ss2;
  ss -= bs2;
  us -= us2;
  us -= bs2;
  si -= si2;
  si -= bi2;
  ui -= ui2;
  ui -= bi2;
  sl -= sl2;
  sl -= bl2;
  ul -= ul2;
  ul -= bl2;
  fd -= fd2;
}
void test_mul(void) {
  sc = sc * sc2;
  uc = uc * uc2;
  ss = ss * ss2;
  us = us * us2;
  si = si * si2;
  ui = ui * ui2;
  sl = sl * sl2;
  ul = ul * ul2;
  fd = fd * fd2;
}
void test_mul_assign(void) {
  sc *= sc2;
  uc *= uc2;
  ss *= ss2;
  us *= us2;
  si *= si2;
  ui *= ui2;
  sl *= sl2;
  ul *= ul2;
  fd *= fd2;
}
void test_div(void) {
  sc = sc / sc2;
  uc = uc / uc2;
  ss = ss / ss2;
  us = us / us2;
  si = si / si2;
  ui = ui / ui2;
  sl = sl / sl2;
  ul = ul / ul2;
  fd = fd / fd2;
}
void test_div_assign(void) {
  sc /= sc2;
  uc /= uc2;
  ss /= ss2;
  us /= us2;
  si /= si2;
  ui /= ui2;
  sl /= sl2;
  ul /= ul2;
  fd /= fd2;
}
void test_rem(void) {
  sc = sc % sc2;
  uc = uc % uc2;
  ss = ss % ss2;
  us = us % us2;
  si = si % si2;
  ui = ui % ui2;
  sl = sl % sl2;
  ul = ul % ul2;
}
void test_rem_assign(void) {
  sc %= sc2;
  uc %= uc2;
  ss %= ss2;
  us %= us2;
  si %= si2;
  ui %= ui2;
  sl %= sl2;
  ul %= ul2;
}
void test_not(void) {
  sc = ~sc2;
  uc = ~uc2;
  bc = ~bc2;
  ss = ~ss2;
  us = ~us2;
  bs = ~bs2;
  si = ~si2;
  ui = ~ui2;
  bi = ~bi2;
  sl = ~sl2;
  ul = ~ul2;
  bl = ~bl2;
}
void test_and(void) {
  sc = sc & sc2;
  sc = sc & bc2;
  sc = bc & sc2;
  uc = uc & uc2;
  uc = uc & bc2;
  uc = bc & uc2;
  bc = bc & bc2;
  ss = ss & ss2;
  ss = ss & bs2;
  ss = bs & ss2;
  us = us & us2;
  us = us & bs2;
  us = bs & us2;
  bs = bs & bs2;
  si = si & si2;
  si = si & bi2;
  si = bi & si2;
  ui = ui & ui2;
  ui = ui & bi2;
  ui = bi & ui2;
  bi = bi & bi2;
  sl = sl & sl2;
  sl = sl & bl2;
  sl = bl & sl2;
  ul = ul & ul2;
  ul = ul & bl2;
  ul = bl & ul2;
  bl = bl & bl2;
}
void test_and_assign(void) {
  sc &= sc2;
  sc &= bc2;
  uc &= uc2;
  uc &= bc2;
  bc &= bc2;
  ss &= ss2;
  ss &= bs2;
  us &= us2;
  us &= bs2;
  bs &= bs2;
  si &= si2;
  si &= bi2;
  ui &= ui2;
  ui &= bi2;
  bi &= bi2;
  sl &= sl2;
  sl &= bl2;
  ul &= ul2;
  ul &= bl2;
  bl &= bl2;
}
void test_or(void) {
  sc = sc | sc2;
  sc = sc | bc2;
  sc = bc | sc2;
  uc = uc | uc2;
  uc = uc | bc2;
  uc = bc | uc2;
  bc = bc | bc2;
  ss = ss | ss2;
  ss = ss | bs2;
  ss = bs | ss2;
  us = us | us2;
  us = us | bs2;
  us = bs | us2;
  bs = bs | bs2;
  si = si | si2;
  si = si | bi2;
  si = bi | si2;
  ui = ui | ui2;
  ui = ui | bi2;
  ui = bi | ui2;
  bi = bi | bi2;
  sl = sl | sl2;
  sl = sl | bl2;
  sl = bl | sl2;
  ul = ul | ul2;
  ul = ul | bl2;
  ul = bl | ul2;
  bl = bl | bl2;
}
void test_or_assign(void) {
  sc |= sc2;
  sc |= bc2;
  uc |= uc2;
  uc |= bc2;
  bc |= bc2;
  ss |= ss2;
  ss |= bs2;
  us |= us2;
  us |= bs2;
  bs |= bs2;
  si |= si2;
  si |= bi2;
  ui |= ui2;
  ui |= bi2;
  bi |= bi2;
  sl |= sl2;
  sl |= bl2;
  ul |= ul2;
  ul |= bl2;
  bl |= bl2;
}
void test_xor(void) {
  sc = sc ^ sc2;
  sc = sc ^ bc2;
  sc = bc ^ sc2;
  uc = uc ^ uc2;
  uc = uc ^ bc2;
  uc = bc ^ uc2;
  bc = bc ^ bc2;
  ss = ss ^ ss2;
  ss = ss ^ bs2;
  ss = bs ^ ss2;
  us = us ^ us2;
  us = us ^ bs2;
  us = bs ^ us2;
  bs = bs ^ bs2;
  si = si ^ si2;
  si = si ^ bi2;
  si = bi ^ si2;
  ui = ui ^ ui2;
  ui = ui ^ bi2;
  ui = bi ^ ui2;
  bi = bi ^ bi2;
  sl = sl ^ sl2;
  sl = sl ^ bl2;
  sl = bl ^ sl2;
  ul = ul ^ ul2;
  ul = ul ^ bl2;
  ul = bl ^ ul2;
  bl = bl ^ bl2;
}
void test_xor_assign(void) {
  sc ^= sc2;
  sc ^= bc2;
  uc ^= uc2;
  uc ^= bc2;
  bc ^= bc2;
  ss ^= ss2;
  ss ^= bs2;
  us ^= us2;
  us ^= bs2;
  bs ^= bs2;
  si ^= si2;
  si ^= bi2;
  ui ^= ui2;
  ui ^= bi2;
  bi ^= bi2;
  sl ^= sl2;
  sl ^= bl2;
  ul ^= ul2;
  ul ^= bl2;
  bl ^= bl2;
}
void test_sl(void) {
  sc = sc << sc2;
  sc = sc << uc2;
  sc = sc << cnt;
  sc = sc << 5;
  uc = uc << sc2;
  uc = uc << uc2;
  uc = uc << cnt;
  uc = uc << 5;
  ss = ss << ss2;
  ss = ss << us2;
  ss = ss << cnt;
  ss = ss << 5;
  us = us << ss2;
  us = us << us2;
  us = us << cnt;
  us = us << 5;
  si = si << si2;
  si = si << ui2;
  si = si << cnt;
  si = si << 5;
  ui = ui << si2;
  ui = ui << ui2;
  ui = ui << cnt;
  ui = ui << 5;
  sl = sl << sl2;
  sl = sl << ul2;
  sl = sl << cnt;
  sl = sl << 5;
  ul = ul << sl2;
  ul = ul << ul2;
  ul = ul << cnt;
  ul = ul << 5;
}
void test_sl_assign(void) {
  sc <<= sc2;
  sc <<= uc2;
  sc <<= cnt;
  sc <<= 5;
  uc <<= sc2;
  uc <<= uc2;
  uc <<= cnt;
  uc <<= 5;
  ss <<= ss2;
  ss <<= us2;
  ss <<= cnt;
  ss <<= 5;
  us <<= ss2;
  us <<= us2;
  us <<= cnt;
  us <<= 5;
  si <<= si2;
  si <<= ui2;
  si <<= cnt;
  si <<= 5;
  ui <<= si2;
  ui <<= ui2;
  ui <<= cnt;
  ui <<= 5;
  sl <<= sl2;
  sl <<= ul2;
  sl <<= cnt;
  sl <<= 5;
  ul <<= sl2;
  ul <<= ul2;
  ul <<= cnt;
  ul <<= 5;
}
void test_sr(void) {
  sc = sc >> sc2;
  sc = sc >> uc2;
  sc = sc >> cnt;
  sc = sc >> 5;
  uc = uc >> sc2;
  uc = uc >> uc2;
  uc = uc >> cnt;
  uc = uc >> 5;
  ss = ss >> ss2;
  ss = ss >> us2;
  ss = ss >> cnt;
  ss = ss >> 5;
  us = us >> ss2;
  us = us >> us2;
  us = us >> cnt;
  us = us >> 5;
  si = si >> si2;
  si = si >> ui2;
  si = si >> cnt;
  si = si >> 5;
  ui = ui >> si2;
  ui = ui >> ui2;
  ui = ui >> cnt;
  ui = ui >> 5;
  sl = sl >> sl2;
  sl = sl >> ul2;
  sl = sl >> cnt;
  sl = sl >> 5;
  ul = ul >> sl2;
  ul = ul >> ul2;
  ul = ul >> cnt;
  ul = ul >> 5;
}
void test_sr_assign(void) {
  sc >>= sc2;
  sc >>= uc2;
  sc >>= cnt;
  sc >>= 5;
  uc >>= sc2;
  uc >>= uc2;
  uc >>= cnt;
  uc >>= 5;
  ss >>= ss2;
  ss >>= us2;
  ss >>= cnt;
  ss >>= 5;
  us >>= ss2;
  us >>= us2;
  us >>= cnt;
  us >>= 5;
  si >>= si2;
  si >>= ui2;
  si >>= cnt;
  si >>= 5;
  ui >>= si2;
  ui >>= ui2;
  ui >>= cnt;
  ui >>= 5;
  sl >>= sl2;
  sl >>= ul2;
  sl >>= cnt;
  sl >>= 5;
  ul >>= sl2;
  ul >>= ul2;
  ul >>= cnt;
  ul >>= 5;
}
void test_cmpeq(void) {
  bc = sc == sc2;
  bc = sc == bc2;
  bc = bc == sc2;
  bc = uc == uc2;
  bc = uc == bc2;
  bc = bc == uc2;
  bc = bc == bc2;
  bs = ss == ss2;
  bs = ss == bs2;
  bs = bs == ss2;
  bs = us == us2;
  bs = us == bs2;
  bs = bs == us2;
  bs = bs == bs2;
  bi = si == si2;
  bi = si == bi2;
  bi = bi == si2;
  bi = ui == ui2;
  bi = ui == bi2;
  bi = bi == ui2;
  bi = bi == bi2;
  bl = sl == sl2;
  bl = sl == bl2;
  bl = bl == sl2;
  bl = ul == ul2;
  bl = ul == bl2;
  bl = bl == ul2;
  bl = bl == bl2;
  bl = fd == fd2;
}
void test_cmpne(void) {
  bc = sc != sc2;
  bc = sc != bc2;
  bc = bc != sc2;
  bc = uc != uc2;
  bc = uc != bc2;
  bc = bc != uc2;
  bc = bc != bc2;
  bs = ss != ss2;
  bs = ss != bs2;
  bs = bs != ss2;
  bs = us != us2;
  bs = us != bs2;
  bs = bs != us2;
  bs = bs != bs2;
  bi = si != si2;
  bi = si != bi2;
  bi = bi != si2;
  bi = ui != ui2;
  bi = ui != bi2;
  bi = bi != ui2;
  bi = bi != bi2;
  bl = sl != sl2;
  bl = sl != bl2;
  bl = bl != sl2;
  bl = ul != ul2;
  bl = ul != bl2;
  bl = bl != ul2;
  bl = bl != bl2;
  bl = fd != fd2;
}
void test_cmpge(void) {
  bc = sc >= sc2;
  bc = uc >= uc2;
  bc = bc >= bc2;
  bs = ss >= ss2;
  bs = us >= us2;
  bs = bs >= bs2;
  bi = si >= si2;
  bi = ui >= ui2;
  bi = bi >= bi2;
  bl = sl >= sl2;
  bl = ul >= ul2;
  bl = bl >= bl2;
  bl = fd >= fd2;
}
void test_cmpgt(void) {
  bc = sc > sc2;
  bc = uc > uc2;
  bc = bc > bc2;
  bs = ss > ss2;
  bs = us > us2;
  bs = bs > bs2;
  bi = si > si2;
  bi = ui > ui2;
  bi = bi > bi2;
  bl = sl > sl2;
  bl = ul > ul2;
  bl = bl > bl2;
  bl = fd > fd2;
}
void test_cmple(void) {
  bc = sc <= sc2;
  bc = uc <= uc2;
  bc = bc <= bc2;
  bs = ss <= ss2;
  bs = us <= us2;
  bs = bs <= bs2;
  bi = si <= si2;
  bi = ui <= ui2;
  bi = bi <= bi2;
  bl = sl <= sl2;
  bl = ul <= ul2;
  bl = bl <= bl2;
  bl = fd <= fd2;
}
void test_cmplt(void) {
  bc = sc < sc2;
  bc = uc < uc2;
  bc = bc < bc2;
  bs = ss < ss2;
  bs = us < us2;
  bs = bs < bs2;
  bi = si < si2;
  bi = ui < ui2;
  bi = bi < bi2;
  bl = sl < sl2;
  bl = ul < ul2;
  bl = bl < bl2;
  bl = fd < fd2;
}
