struct BlobSpan {
 int right;
};



void render_blob_line(struct BlobSpan blobdata) {
 int buf[4 * 8];
 int *data = buf;
 int i, n = 0;
 if (blobdata.right)
  n++;
 if (n)
  for (; i < 2 * n;)
   data[i] = 0;
 n *= 2;
 for (; n;) ;
}
