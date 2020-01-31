void Get16u();
typedef struct { int ThumbnailSize; } ImageInfo_t;

double ConvertAnyFormat(void)
{
  return 0;
}

void ProcessExifDir(ImageInfo_t *ImageInfoP, int NumDirEntries)
{
  unsigned int ThumbnailSize;

  for (; NumDirEntries;) {
    Get16u();
    switch (NumDirEntries) {
      case 0x0201:
      case 0x0202:
        ThumbnailSize = ConvertAnyFormat();
    }
  }

  ImageInfoP->ThumbnailSize = ThumbnailSize;
}
