typedef void (*sigcatch_t)( struct sigcontext *);
sigcatch_t sigcatch[50] = {(sigcatch_t) 0};
