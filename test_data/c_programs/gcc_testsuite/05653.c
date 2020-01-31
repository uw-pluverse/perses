


int nem1_phi (unsigned long a) { return a ? -1 : 0; }
int eqm1_phi (unsigned long a) { return a ? 0 : -1; }

int spaceship1 (long a) { return a > 0 ? 1 : a < 0 ? -1 : 0; }
int spaceship2 (long a) { return a > 0 ? 1 : a == 0 ? 0 : -1; }
