%{
#include "c.tab.h"
#include "c.h"


%}

separator [\t\n\r ]
letter [a-z]
digit [0-9]


print_num print-num
print_bool print-bool
mod	mod
and and
or or
not not
define define
fun fun
IF if
number (0|[0-9]{digit}*|-[0-9]{digit}*)
id {letter}({letter}|{digit}|-)*
boolVal #t|#f


%%
{print_num} {
							/*printf("hi print_num!\n");*/
							return(print_num);
						}
{print_bool} {
							/*printf("hi print_bool!\n");*/
							return(print_bool);
						}
{mod}	{
				/*printf("hi mod!\n");*/
				return(mod);
			}
{and} {
				/*printf("hi and!\n");*/
				return(and);
			}
{or}	{
				/*printf("hi or!\n");*/
				return(or);
			}
{not} {
				/*printf("hi not!\n");*/
				return(not);
			}
{define}	{
						/*printf("hi define!\n");*/
						return(define);
					}
{fun} {
				/*printf("hi fun!\n");*/
				return(fun);
			}
{IF} {
				/*printf("hi if!\n");*/
				return(IF);
		}
{separator} {
							/*printf("hi separator!\n");  EOF */
						}
{number} {
					/*printf("hi number!\n");*/
					yylval.ival=atoi(yytext);
					return(number);}
{id}  {
				//printf("hi id\n");
				yylval.word=strdup(yytext);
				return(id);
			}
{boolVal} {
						/*printf("hi boolVal!\n");*/
						yylval.word=yytext;
						return(boolVal);
					}

.	{
		/*printf("hi else!\n");*/
		return(yytext[0]);
	}

%%

