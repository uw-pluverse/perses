





struct floppy_raw_cmd {
  int flags, track;
} *raw_cmd, default_raw_cmd;

void
setup_format_params (void)
{
  raw_cmd = &default_raw_cmd;
  raw_cmd->track = 0;
  raw_cmd->flags = 0;
}
