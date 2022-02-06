/*

MIT License

Copyright (c) 2019 Gang ZHANG (gangz@emergentdesign.cn)
(Contributors are welcome!)

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

History: 2019/01/06 Initial version
*/

parser grammar RubyParser;

options { tokenVocab= RubyLexer; }

compilation_unit
:
	statement_list_terms
;

statement_list_terms
:
	statement terms
	| statement_list_terms statement terms
	| terms
;

statement_list_noterms
:
	(statement terms)* statement
;

statement
:
	 begin_block
	| end_block
	| alias_statement
	| undef_statement
	| ENSURE
	| expr
;

undef_statement: UNDEF function_name_or_symbol (',' function_name_or_symbol)*;

alias_statement
: 
	ALIAS function_name_or_symbol function_name_or_symbol   
;

function_name_or_symbol: 
	function_name
	|symbol
;

begin_block
:
	BEGIN_BLOCK LEFT_PAREN statement_list_terms RIGHT_PAREN 
;

end_block
:
	END_BLOCK LEFT_PAREN statement_list_terms RIGHT_PAREN
;

module_definition: 
	MODULE cpath statement_list_terms? END;

class_definition: 
   	class_header statement_list_terms? END
;
superclass: '<' id_symbol terms;

class_header: 
	CLASS cpath superclass? 
	| CLASS BIT_SHL identifier
;

function_definition
:
	function_definition_header statement_list_terms? END
;

function_definition_header
:
	DEF function_name function_definition_params? expr? terms
;

function_name
:   cpath (QUESTION|SIGH|ASSIGN)?
    | literal
	| assignOperator
	| mathOperator AT
	| bitOperator
	| compareOperator
	| equalsOperator
	| logicalOperator
;

function_definition_params
:
	LEFT_RBRACKET ( function_definition_param (',' crlfs? function_definition_param)*)? RIGHT_RBRACKET
	| function_definition_param (',' crlfs?  function_definition_param)*
;

function_definition_param: 
	identifier 
	| MUL identifier
	| EXP identifier
	| BIT_AND identifier
	| hash_asso
	| identifier ASSIGN expr
;

function_call_param:
	expr 
	| hash_asso
;


expr
:
	primary                                              #ExprPrimary
	| expr ',' crlfs? expr                               #ExprList
	| expr dot_ref crlfs? expr                           #ExprDotRef
	| expr postfix=QUESTION                              #ExprQuestion
	| prefix=(PLUS| MINUS|MUL|MOD|BIT_AND) expr          #ExprPrefixCalc
	| expr LEFT_SBRACKET expr RIGHT_SBRACKET 			 #ExprArrayAccess					/* array access */
	| prefix=DEFINED expr                                #ExprDefineTest        	        /* identifier definition test */
	| expr bop=(DOT2|DOT3) expr? 						 #ExprRange		                  	/* range */
	| expr ','? MUL? ASSIGN crlfs? expr                  #ExprBatchAssign          			/* batch assign */
	| expr assignOperator crlfs? expr					 #ExprAssign						/* assign */
	| expr bop=PATTERN_MATCH expr                        #ExprPatternMatch1                 /* pattern match */
	| expr bop=BIT_NOT expr                              #ExprPatternMatch2                 /* pattern match */
	| expr SIGH BIT_NOT expr                             #ExprPatternMatch3                 /* pattern match */
	| (not| BIT_NOT) expr                                #ExprLogicalNot	             	/* logical not */
	| expr (compareOperator) crlfs? expr                 #ExprCompareLogical               	/* compare logical  */
	| expr (logicalOperator) crlfs? expr                 #ExprLogicalJoin	             	/* logical join */
	| expr (equalsOperator) crlfs? expr                  #ExprEqualTest		              	/* equal test */
	| expr (mathOperator|bitOperator) crlfs? expr        #ExprCalcuation                  	/* calcuation */
	| expr QUESTION expr COLON expr                      #ExprConditionStatement   			/* cond?true_part:false_part */
	| expr block                                         #ExprBlock
	| expr expr_statement_suffix                         #ExprWitStatementSuffix
	| expr dot_ref CLASS                                 #ExprDotClass
	| function_name func_call_parameters_no_bracket expr_statement_suffix?                      #ExprFunctionCall1
	| expr dot_ref function_name func_call_parameters_no_bracket expr_statement_suffix?         #ExprFunctionCall2
	| cpath (QUESTION|SIGH)                                                                     #ExprFunctionCall3
	;

expr_statement_suffix:
	IF crlfs? expr
	| UNLESS crlfs? expr 
	| WHILE crlfs? expr 
	| UNTIL crlfs? expr 	
	| RESCUE statement 
    | DO block_params? terms? statement_list_terms? END
;

primary:
	variable_path                                                              #PrimaryVarPath
	| Regex														               #PrimaryRegex
	| symbol                                                                   #PrimarySymbol
	| LEFT_RBRACKET expr RIGHT_RBRACKET                                        #PrimaryBracket
	| block                                                                    #PrimaryBlock
	| BREAK expr?												               #PrimaryStatementBreak
	| RETURN expr?                                                             #PrimaryStatementReturn
	| RAISE expr                                                               #PrimaryStatementRaise
	| RESCUE rescure_param?  else_tail?                                        #PrimaryStatementRescue
	| YIELD expr?												               #PrimaryStatementYield
	| BEGIN terms statement_list_terms? END						               #PrimaryBeginBlock
    | IF expr then_keyword statement (ELSIF expr then_keyword statement)? (ELSE expr)? END  #PrimaryBlockIf2
	| IF crlfs? expr then_keyword statement_list_terms? if_tail* END           #PrimaryBlockIf
	| WHEN expr then_keyword statement_list_noterms END                        #PrimaryBlockWhen
	| UNLESS crlfs? expr then_keyword  statement_list_terms? else_tail? END  #PrimaryBlockUnless
	| CASE statement_list_terms? case_body*  END                               #PrimaryBlockCase1
	| CASE terms case_body*  END                                               #PrimaryBlockCase2
	| WHILE crlfs? expr do_keyword  statement_list_terms? END                  #PrimaryBlockWhile 
	| UNTIL crlfs? expr do_keyword  statement_list_terms?  END                 #PrimaryBlockUntil
	| FOR crlfs? expr IN when_cond terms?  statement_list_terms? END           #PrimaryBlockFor
	| class_definition                                                         #PrimaryBlockClassDef
	| function_definition                                                      #PrimaryBlockFunctionDef
	| module_definition                                                        #PrimaryBlockModelDef
	| function_name func_call_parameters                                       #PrimaryFunctionCall0
	| LEFT_PAREN crlfs? hash_asso crlfs?(',' crlfs? hash_asso)* ','? crlfs? RIGHT_PAREN   	#PrimaryListHash
	| LEFT_SBRACKET  crlfs? expr crlfs? (',' crlfs? expr)* ','? crlfs?  RIGHT_SBRACKET   	#PrimaryListExpr
	| LEFT_RBRACKET expr (DOT2|DOT3) expr? RIGHT_RBRACKET                               	#PrimaryRange
	;


func_call_parameters
:
	LEFT_RBRACKET crlfs? function_call_param  (',' crlfs? function_call_param)* crlfs? RIGHT_RBRACKET
	| LEFT_RBRACKET crlfs? RIGHT_RBRACKET
;
func_call_parameters_no_bracket:
	function_call_param  (',' crlfs? function_call_param)* 
;
rescure_param: id_symbol | hash_asso |ASSOC identifier;

case_body: 
	WHEN when_cond (',' when_cond)* then_keyword statement_list_terms
	|else_tail;
	
when_cond: 
	expr 
	;
	
if_tail: 
	ELSIF crlfs? expr then_keyword statement_list_terms
	| else_tail
;
else_tail: 
	ELSE crlfs? statement_list_terms;


dot_ref: DOT | ANDDOT ;


logicalOperator: OR| AND;

equalsOperator: EQUAL| NOT_EQUAL | EQUAL3;

compareOperator: LESS|GREATER|LESS_EQUAL| GREATER_EQUAL;

bitOperator: BIT_SHL|BIT_SHR|BIT_AND|BIT_OR|BIT_XOR;

mathOperator: MUL|DIV|MOD|PLUS|MINUS|EXP;

assignOperator:
	PLUS_ASSIGN | MINUS_ASSIGN |MUL_ASSIGN|DIV_ASSIGN|MOD_ASSIGN 
	| EXP_ASSIGN  |BIT_OR_ASSIGN|BIT_AND_ASSIGN|OR_ASSIGN|AND_ASSIGN
	| BIT_XOR_ASSIGN | BIT_NOT_ASSIGN |BIT_SHL_ASSIGN | BIT_SHR_ASSIGN;

not: NOT | SIGH;

block: LEFT_PAREN crlfs? block_params? statement_list_noterms crlfs? (',' statement_list_noterms crlfs?)* RIGHT_PAREN;

block_params: BIT_OR expr (',' expr)*  BIT_OR;

id_symbol: 
	cpath
	| 	COLON cpath
	;

symbol: 
	COLON identifier
	COLON string 
	|  COLON function_name
;

hash_asso:
	expr ASSOC expr 
	| expr COLON expr  
;

variable_path:
	identifier                                 			#VarPathId
    |literal                                    		#VarPathLiteral
	| variable_path COLON2 (identifier|literal)        	#VarPathJoin
	| COLON2 variable_path                      		#VarPathGlobalPrefix
	;
cpath:
    identifier ((COLON2|DOT) identifier)*
    ;	
literal: 
	Float
	| string
	| Integer
	|(TRUE| FALSE)
	| NIL 
	| Float DOT
	| ShellCommand
;

	
identifier: Identifier | globalVar | classVar |instanceVar | idArg | NEXT  |REDO |RETRY | BREAK |SELF | SUPER  |NIL | empty;

empty: 
	LEFT_PAREN RIGHT_PAREN																/* empty block  */
	| LEFT_SBRACKET  RIGHT_SBRACKET                                                    	/* empty array */
	;

globalVar:	DOLLAR Identifier;
classVar: AT AT Identifier;
instanceVar: AT Identifier;
idArg: DOLLAR Integer | DollarSpecial;

do_keyword: (DO|COLON) terms | terms ;
then_keyword: (THEN|COLON) terms? | terms;
string: String+;  /* many string can be concatenated  */

crlfs: (SL_COMMENT|CRLF)+;

terms:
	(term)+
;

term: SEMICOLON | CRLF | SL_COMMENT;



	
