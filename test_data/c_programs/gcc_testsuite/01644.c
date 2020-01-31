



int copyNextDtaToAtari(void);
char fsnextIsForUs;

int custom_fsnext( void *sp )
{
        int res;

        if(!fsnextIsForUs) {
            return 0;
        }

        res = copyNextDtaToAtari();
        return res;
}
