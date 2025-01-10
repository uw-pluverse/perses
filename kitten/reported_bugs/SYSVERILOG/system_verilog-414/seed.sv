















package riscv_signature_pkg;


  typedef enum bit[7:0] {



    CORE_STATUS,


    TEST_RESULT,


    WRITE_GPR,



    WRITE_CSR
  } signature_type_t;

  typedef enum bit[4:0] {
    INITIALIZED,
    IN_DEBUG_MODE,
    IN_MACHINE_MODE,
    IN_HYPERVISOR_MODE,
    IN_SUPERVISOR_MODE,
    IN_USER_MODE,
    HANDLING_IRQ,
    FINISHED_IRQ,
    HANDLING_EXCEPTION,
    INSTR_FAULT_EXCEPTION,
    ILLEGAL_INSTR_EXCEPTION,
    LOAD_FAULT_EXCEPTION,
    STORE_FAULT_EXCEPTION,
    EBREAK_EXCEPTION
  } core_status_t;

  typedef enum bit {
    TEST_PASS,
    TEST_FAIL
  } test_result_t;

endpackage
