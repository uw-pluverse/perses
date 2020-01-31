int open(const char *, int, ...);
int openat(int, const char *, int, ...);
int close(int fildes);
void open_1(const char *path) {
  int fd;
  fd = open(path, 0);
  if (fd > -1)
    close(fd);
}
void open_2(const char *path) {
  int fd;
  int mode = 0x0;
  fd = open(path, 0, mode, ((void*) 0));
  if (fd > -1)
    close(fd);
}
void openat_2(int base_fd, const char *path) {
  int fd;
  int mode = 0x0;
  fd = openat(base_fd, path, 0, mode, ((void*) 0));
  if (fd > -1)
    close(fd);
}
void open_3(const char *path) {
  int fd;
  fd = open(path, 0, ((void*) 0));
  if (fd > -1)
    close(fd);
}
void openat_3(int base_fd, const char *path) {
  int fd;
  fd = openat(base_fd, path, 0, ((void*) 0));
  if (fd > -1)
    close(fd);
}
void open_4(const char *path) {
  int fd;
  fd = open(path, 0, "");
  if (fd > -1)
    close(fd);
}
void open_5(const char *path) {
  int fd;
  struct {
    int val;
  } st = {0};
  fd = open(path, 0, st);
  if (fd > -1)
    close(fd);
}
void open_6(const char *path) {
  int fd;
  struct {
    int val;
  } st = {0};
  fd = open(path, 0, st.val);
  if (fd > -1)
    close(fd);
}
void open_7(const char *path) {
  int fd;
  fd = open(path, 0, &open);
  if (fd > -1)
    close(fd);
}
void open_8(const char *path) {
  int fd;
  fd = open(path, 0, 0.0f);
  if (fd > -1)
    close(fd);
}
