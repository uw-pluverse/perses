module foo
# ( parameter real bar = 2.0 )
( ) ;
endmodule
module t ( ) ;
genvar m , r ;
generate
for ( m = 10 ; m <= 20 ; m += 10 ) begin : gen_m
for ( r = 0 ; r <= 1 ; r ++ ) begin : gen_r
localparam real m = m + ( r + 0.5 ) ;
initial begin
if ( lparam != foo_inst . bar ) begin
$ display ( "%m: lparam != foo_inst.bar (%f, %f)" ,
lparam , foo_inst . bar ) ;
$ stop ( ) ;
end
end
foo # ( . bar ( lparam ) ) foo_inst ( ) ;
end
end
endgenerate
initial begin
$ write ( "*-* All Finished *-*\n" ) ;
$ finish ;
end
endmodule
