



void work_hard (void);

void do_something (int shall_i_work)
{
  if (shall_i_work)
    {
      work_hard ();
      work_hard ();
      work_hard ();
      work_hard ();
      work_hard ();
      work_hard ();
      work_hard ();
      work_hard ();
    }
}
int foo (int invariant)
{
  do_something (0);
  do_something (1);
}
