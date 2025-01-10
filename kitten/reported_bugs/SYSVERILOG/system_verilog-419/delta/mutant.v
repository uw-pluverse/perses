bit a_finished ;
bit b_finished ;
module t (
clk
) ;
input clk ;
wire [ 31 : 0 ] o ;
wire si = 1'b0 ;
ExampInst i
(
. o ( o [ 31 : 0 ] ) ,
. i ( 1'b0 )
) ;
Prog p (
. si ( si ) ) ;
always @ ( posedge clk ) begin
if ( ! a_finished ) $ stop ;
if ( ! b_finished ) $ stop ;
$ write ( "*-* All Finished *-*\n" ) ;
$ finish ;
end
endmodule
module InstModule (
output logic [ 31 : 0 ] so ,
input si
) ;
assign so = { 32 { si } } ;
endmodule
program Prog ( input si ) ;
initial a_finished = 1'b1 ;
endprogram
module ExampInst ( o , i ) ;
output logic [ 31 : 0 ] o ;
input i ;
InstModule instName
(
. so ( o [ 31 : 0 ] ) ,
. si ( i )
) ;
bind b_finished Prog instProg
(
. si ( si ) ) ;
endmodule
bind InstModule Prog2 instProg2
(
. si ( si ) ) ;
program Prog2 ( input si ) ;
initial b_finished = 1'b1 ;
endprogram
