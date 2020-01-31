


int SAD_Block(int *);
void MBMotionEstimation(int *act_block, int block)
{
    SAD_Block(act_block + ( (8 * (block == 1 || block == 3))
                          + (8 * (block == 2 || block == 3))));
}
