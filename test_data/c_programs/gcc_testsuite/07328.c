




int
foo (){
  int i,j;
  int diff = 0;

  for (i = 0; i < 40; i++) {
    for (j = 0; j < 40; j++) {
      diff += j;
    }
  }
  return diff;
}
