int main() {
  int strstart = 0;
  int hash_head = 2;
  int prev_length = 5;
  int ins_h = 1;
  int prev[32<<10] = { 0 };
  int head[32<<10] = { 0 };
  int window[1024] = { 0 };
  do {
      strstart++;
      ((ins_h = (((ins_h)<<((15 +3 -1)/3)) ^ (window[(strstart) + 3 -1])) & 0xFFFF), prev[(strstart) & 0xFFFF] = hash_head = head[ins_h], head[ins_h] = (strstart));
  } while (--prev_length != 0);
}
