module top ( clk , in , out ) ;
parameter DEPTH = 10 ;
input wire clk , in ;
output reg out ; module alert_handler_bind ;
bind alert_handler tlul_assert # (
. EndpointType ( "Device" )
) tlul_assert_device (
. clk_i ,
. rst_ni ,
. h2d ( tl_i ) ,
. d2h ( tl_o )
) ;
endmodule
endmodule
