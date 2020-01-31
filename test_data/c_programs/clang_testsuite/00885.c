struct sysctl_req {
  struct aiocblist *p_aio;
};
struct sysctl_oid {
  int (*oid_handler)(struct sysctl_req *req);
};
static struct sysctl_oid sysctl___kern_features_aio;
static void const *const __set_sysctl_set_sym_sysctl___kern_features_aio
    __attribute__((__used__)) = &sysctl___kern_features_aio;
struct aiocblist {
  struct aiocb uaiocb;
};
