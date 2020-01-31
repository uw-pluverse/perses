void f(unsigned char *src, unsigned char *dst, int num, unsigned char *pos, unsigned char *diffuse, int hasdiffuse, unsigned char *specular, int hasspecular) {
    int i;

    for(i=num;i--;) {
 float *p = (float *) ((long unsigned int) dst + (long unsigned int) pos);
        if(hasdiffuse) {
            unsigned int *dstColor = (unsigned int *) (dst + i + (long unsigned int) diffuse);
            *dstColor = * (unsigned int *) ( ((long unsigned int) src + (long unsigned int) diffuse) + i);
        }
        if(hasspecular) {
            unsigned int *dstColor = (unsigned int *) (dst + i + (long unsigned int) specular);
            *dstColor = * (unsigned int *) ( ((long unsigned int) src + (long unsigned int) specular) + i);
        }
    }
}
