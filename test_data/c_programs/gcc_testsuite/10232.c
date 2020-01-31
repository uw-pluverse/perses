





void ** newElements;

__attribute__((transaction_safe))
long
TMqueue_push (void** queuePtr)
{
   long src;
   for (src = 1; src < 9; src++) {
     newElements[src+1] = queuePtr[src];
   }
   return 1;
}
