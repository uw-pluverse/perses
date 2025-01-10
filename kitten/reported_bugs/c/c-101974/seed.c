





int  __attribute__ ((access))
access_v (void);

int  __attribute__ ((access ()))
access___v (void);

int  __attribute__ ((access (rdonly)))
rdonly_spelling (void);

int  __attribute__ ((access (read_only)))
rdonly_v_all (void);

int  __attribute__ ((access (read_only ())))
rdonly___v_all (void);



int rdonly (void);

int  __attribute__ ((access (rdonly ())))
rdonly___v_all (void);


int  __attribute__ ((access (read_only)))
rdonly_i_all (int);
