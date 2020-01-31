


float repl1 (float varx)
{
  if (varx < 0.0)
    return 0.0;
  else if (varx > 1.0)
    return 1.0;
  else
    return varx;
}
float repl2 (float vary)
{
  if (vary > 1.0)
    return 1.0;
  else if (vary < 0.0)
    return 0.0;
  else
    return vary;
}
float repl3 (float varz, float vara, float varb)
{
  if (varz > vara)
    return vara;
  else if (varz < varb)
    return varb;
  else
    return varz;
}
