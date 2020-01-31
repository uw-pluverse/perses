


struct GTeth_desc
{
  unsigned ed_cmdsts;
};
struct GTeth_softc
{
  struct GTeth_desc txq_desc[32];
};

void foo(struct GTeth_softc *sc)
{


  volatile struct GTeth_desc *p = &sc->txq_desc[0];
  p->ed_cmdsts = 0;
}
