struct iphdr {
  unsigned char pad1: 2, ihl:4, pad2: 2;
};
int raw_send_hdrinc(unsigned long int length) {
  struct iphdr iph;
  if (iph.ihl * 4 > length) {
    return 1;
  }
  return 0;
}
int main(int argc, char *argv[]) {
  return raw_send_hdrinc(12);
}
