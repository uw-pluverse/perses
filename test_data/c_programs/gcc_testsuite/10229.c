


int funky();
int global;

void SeqfileGetLine()
{
  funky();
}

__attribute__((transaction_callable)) void readLoop()
{
 SeqfileGetLine();
 if (global)
   funky();

}
