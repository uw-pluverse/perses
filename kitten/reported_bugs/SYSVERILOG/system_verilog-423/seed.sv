




package sensor_ctrl_pkg;

  parameter int NumAlerts   = sensor_ctrl_reg_pkg::NumAlerts;
  parameter int NumIoRails  = sensor_ctrl_reg_pkg::NumIoRails;


  typedef enum logic {
    ImmAck = 0,
    SwAck  = 1
  } ast_ack_mode_e;

endpackage
