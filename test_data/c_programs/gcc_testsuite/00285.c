







struct fltcom_st {
    short fltbuf[950];
} fltcom_ __attribute__((common)) ;



struct fltcom2_st {
    short fltbuf2[56];
} fltcom2_ __attribute__((common)) ;





struct aidatcm_st {
    double cm_aid, cm_ext, cm_basis;
    short cm_aiday, cm_exday, cm_dperd, cm_aiexf, cm_aidex, cm_aiok,
            cm_aigdo, cm_aildo, cm_prev[3], cm_next[3], cm_aid_pad[2];
    double cm_rvgfact, cm_ai1st, cm_ai2nd;
    int cm_aieurok;
} aidatcm_ __attribute__((common)) ;




struct cshfcm_st {
    short bufff[10862];
} cshfcm_ __attribute__((common)) ;





struct calctsdb_st {
    short calctsdbbuff[115];
} calctsdb_ __attribute__((common)) ;




struct cf600cm_st {
    short bufcf[14404];
} cf600cm_ __attribute__((common)) ;


typedef struct { int id; int type; const char *name; } bregdb_bitinfo_t;

int
bregdb_eval_bbitcxt_bool_rv(const bregdb_bitinfo_t * const bbit,
                            const int bbit_default,
                            const void * const bregucxt);

static const bregdb_bitinfo_t bbit_calc_dr_d33 =
  { 160667, 5, "bbit_calc_dr_d33" };


static const bregdb_bitinfo_t bbit_calc_sx_b24 =
  { 158854, 5, "bbit_calc_sx_b24" };


static const bregdb_bitinfo_t bbit_calc_dr_d36 =
  { 161244, 5, "bbit_calc_dr_d36" };


static const bregdb_bitinfo_t bbit_calc_dr_d37 =
  { 161315, 5, "bbit_calc_dr_d37" };


static const bregdb_bitinfo_t bbit_calc_dr_d47 =
  { 163259, 5, "bbit_calc_dr_d47" };


static const bregdb_bitinfo_t bbit_calc_dr_d46 =
  { 163239, 5, "bbit_calc_dr_d46" };


static const bregdb_bitinfo_t bbit_calc_dr_d62 =
  { 166603, 5, "bbit_calc_dr_d62" };





int dtyp_is_actact_(short *daytyp);
double rnd_trunc_numb(double in, short num_digits, short rnd_or_trunc);
void datetrn_(const short* dt, short* dt2);
short difday_(short* daytyp_in, short* srtdti, short* enddti, short* ercode);


double pow(double x, double y);







void calc_1566(
  short sCalcType,
  short sDayType,
  short sFreq,
  short asSettleDt[3],
  short asMtyDt[3],
  short asIssueDt[3],
  short asFCpnDt[3],
  double dCpn,
  short *psNoPer,
  double *pdExt,
  double *pdAI,
  double *pdAI2,
  double *pdFCpn,
  short *psRcode)
{

    short ercode = 0;
    int isactact;
    short days_to_next_cpn = 0;
    const short discDaytype = (*(((short *)&calctsdb_ + 59)));

    if(bregdb_eval_bbitcxt_bool_rv(&bbit_calc_sx_b24, 0, 0))
        isactact = (dtyp_is_actact_(&sDayType) != 0);
    else
        isactact = (sDayType == 1 || sDayType == 10);

    short days_in_current_period = difday_(&sDayType,((short *)&fltcom2_ + 17),((short *)&fltcom2_ + 20),&ercode);
    const short sfreq1 = ((*(((short *)&calctsdb_ + 16))) == 1 && (*(((short *)&calctsdb_ + 61))) == 1);

    for (int j = 0; j < (*(((short *)&cshfcm_ + 9038))); j++) {

        if(j == 0) {
            days_to_next_cpn = difday_(&sDayType,asSettleDt,((short *)&fltcom2_ + 20),&ercode);

            if(isactact) {
                ((double *)&cshfcm_ + 1)[j] = (*(((double *)&fltcom2_))) / sFreq;
                ((double *)&cshfcm_ + 1201)[j] = (double)days_to_next_cpn / (double)days_in_current_period;
            }
            else {
                ((double *)&cshfcm_ + 1)[j] = (*(((double *)&fltcom2_))) * days_in_current_period;
                ((double *)&cshfcm_ + 1201)[j] = (double)days_to_next_cpn / (double)(1/sfreq1);
            }

            if((*(((short *)&cshfcm_ + 9038))) == 1) {
                ((double *)&cshfcm_ + 1201)[j] = (double)days_to_next_cpn / ((double)1/sfreq1);
            }
        }
        else {

            short days_from_settle, days_in_period;

            if(bregdb_eval_bbitcxt_bool_rv(&bbit_calc_dr_d46, 0, 0)){
             days_from_settle = difday_(&sDayType,asSettleDt,
                                             &((short *)&cshfcm_ + 7230)[j*3],&ercode);
             days_in_period = difday_(&sDayType,&((short *)&cshfcm_ + 7230)[(j-1)*3],
                                            &((short *)&cshfcm_ + 7230)[j*3],&ercode);
            }

            double cpn_rate = (*(((double *)&fltcom_ + 1)));

            if(bregdb_eval_bbitcxt_bool_rv(&bbit_calc_dr_d62, 0, 0)) {
              if(j < (*(((short *)&fltcom2_ + 12))) && ((double *)&cf600cm_ + 600)[j] != 0) cpn_rate = ((double *)&cf600cm_ + 600)[j];
            }
            else {
              if(j < (*(((short *)&fltcom2_ + 12))) ) cpn_rate = ((double *)&cf600cm_ + 600)[j];
            }

            if(bregdb_eval_bbitcxt_bool_rv(&bbit_calc_dr_d37, 0, 0)&& j >= (*(((short *)&fltcom2_ + 12))) && sCalcType == 1570) {
                cpn_rate = (*(((double *)&fltcom_ + 1))) + (*(((double *)&fltcom_ + 2)));

                if(bregdb_eval_bbitcxt_bool_rv(&bbit_calc_dr_d36, 0, 0)){
                double projected_rate = pow((1 + (*(((double *)&fltcom_ + 1)))/100.0),
                                            (days_in_period)) - 1;

                projected_rate = projected_rate + (*(((double *)&fltcom_ + 2)))/100.0 * days_in_period;
                cpn_rate = 100 * projected_rate * (1/days_in_period);
                }
            }


            if(isactact) {
                ((double *)&cshfcm_ + 1)[j] = cpn_rate / sFreq;
                ((double *)&cshfcm_ + 1201)[j] = ((double *)&cshfcm_ + 1201)[j-1] + 1;

                if(bregdb_eval_bbitcxt_bool_rv(&bbit_calc_dr_d46, 0, 0) && discDaytype != 0) {
                    ((double *)&cshfcm_ + 1201)[j] = (double)days_from_settle / (double)(1/sfreq1);
                }
            }
            else {
                if(!bregdb_eval_bbitcxt_bool_rv(&bbit_calc_dr_d46, 0, 0)){
                days_from_settle = difday_(&sDayType,asSettleDt,
                                               &((short *)&cshfcm_ + 7230)[j*3],&ercode);
                days_in_period = difday_(&sDayType,&((short *)&cshfcm_ + 7230)[(j-1)*3],
                                               &((short *)&cshfcm_ + 7230)[j*3],&ercode);

                }

                ((double *)&cshfcm_ + 1)[j] = cpn_rate * days_in_period;
                ((double *)&cshfcm_ + 1201)[j] = (double)days_from_settle / (double)(1/sfreq1);
            }

        }

        if(bregdb_eval_bbitcxt_bool_rv(&bbit_calc_dr_d33, 0, 0) && (*(((short *)&calctsdb_ + 16))) != 0) {
            ((double *)&cshfcm_ + 1)[j] = rnd_trunc_numb (((double *)&cshfcm_ + 1)[j], 0, 0);
        }

    }


    short accrued_days = difday_(&sDayType,((short *)&fltcom2_ + 17),asSettleDt,&ercode);

    if(!bregdb_eval_bbitcxt_bool_rv(&bbit_calc_dr_d47, 0, 0)) {
    if(isactact) {
        *pdAI = ((*(((double *)&fltcom2_))) / sFreq)* accrued_days / ((double)days_in_current_period);
    }
    else{
        *pdAI = ((*(((double *)&fltcom2_))) / sFreq)* accrued_days / ((double)1/sFreq);
    }
    }

    aidatcm_.cm_exday = days_to_next_cpn;
    aidatcm_.cm_basis = days_in_current_period;
    datetrn_(((short *)&fltcom2_ + 17),aidatcm_.cm_prev);
}
