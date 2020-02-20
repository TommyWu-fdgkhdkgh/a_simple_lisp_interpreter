%{
#include <stdio.h>
#include <string.h>
#include "c.h"
void yyerror(const char *message);
struct EXP *global_variable=NULL;/*point to head*/
struct EXP *global_variable_tail=NULL;/* point to tail */

int calc(exp *target,exp *table);/* 遍尋樹，算出該樹的值 */
exp *create_formula(char *operator,exp *p1,exp *p2);
exp *look_symbol_table(exp *which_table,char *variableName);/* 遍尋symbol_table，並返回symbol */
exp *copy_to_new_node(exp *target);
%}
%union{
	int ival;
	char* word;
	struct NODE  *n;
	struct EXP *e;
	struct symbol_node *symp;

}
%token <ival> number
%token <word> id
%token <word> boolVal
%token mod
%token and
%token or
%token not
%token define
%token fun
%token IF
%token print_num
%token print_bool

%type <e> IDs
%type <e> EXP
%type <e> MORE_EXP
%type <e> NUM_OP
%type <e> LOGICAL_OP
%type <e> AND_OP
%type <e> OR_OP
%type <e> NOT_OP
%type <e> FUN_EXP
%type <e> FUN_CALL
%type <e> PLUS
%type <e> MINUS
%type <e> MULTIPLY
%type <e> DIVIDE
%type <e> MODULUS
%type <e> GREATER
%type <e> SMALLER
%type <e> EQUAL
%type <e> VARIABLE
%type <e> FUN_IDs FUN_BODY
%type <e> MORE_STMT STMT
%type <e> IF_EXP TEXT_EXP THEN_EXP ELSE_EXP
%type <e> PRINT_STMT
%type <e> MORE_DEF
%type <word> FUN_NAME
%type <e> DEF_STMT
%%
	PROGRAM	:	MORE_STMT {
						}
					;
	MORE_STMT	:	STMT MORE_STMT
						| {$$=NULL;}
						;
	STMT	:	EXP { calc($1,global_variable); }
				|	DEF_STMT {
								if(global_variable==NULL){
									global_variable=$1;
									global_variable_tail=$1;
								}else{
									global_variable_tail->next=$1;
									global_variable_tail=$1;
								}
					}
				|	PRINT_STMT
				;
	MORE_DEF	:	DEF_STMT {
								$$=$1;
							}
						| MORE_DEF DEF_STMT {
								exp *wp=$1;
								for(;wp->next;wp=wp->next){}
								wp->next=$2;
								$$=$1;
							}
						;
	PRINT_STMT	:	'('print_num	EXP')' {
									int type_check;
									type_check=calc($3,global_variable);
									if(type_check==-1){
										return 0;
									}
									if(strcmp($3->type,"int")==0){
											printf("%d\n",$3->value);
									}else{
											printf("not int!\n");
									}
								}
							|	'('print_bool	EXP')'{
									int type_check;
									type_check=calc($3,global_variable);
									if(type_check==-1){
										return 0;
									}
									if(strcmp($3->type,"boolVal")==0){
											if($3->value==1){
												printf("#t\n");
											}
											else if($3->value==0){
												printf("#f\n");
											}
									}
								}
							;
	EXP	:	boolVal {
					int a;
					if(strcmp($1,"#t")==0){
						a=1;
					}else if(strcmp($1,"#f")==0){
						a=0;
					}
					$$=(exp *)malloc(sizeof(exp));
					$$->type="boolVal";
					$$->type_2="const";
					$$->value=a;
					$$->next=NULL;
					$$->parameters=NULL;
				}
			|	number {
					$$=(exp *)malloc(sizeof(exp));
					$$->type="int";
					$$->type_2="const";
					$$->value=$1;
					$$->next=NULL;
					$$->parameters=NULL;
				}
			|	VARIABLE {
					$$=$1;
				}
			|	NUM_OP {
					$$=$1;
				}
			|	LOGICAL_OP {
					$$=$1;
				}
			|	FUN_EXP {
					$$=$1;
				}
			|	FUN_CALL {
					$$=$1;
				}
			|	IF_EXP {
					$$=$1;
				}
			;
	MORE_EXP	:	EXP MORE_EXP {
								if($2==NULL){
									$1->next=NULL;
									$$=$1;
								}else{
									$1->next=$2;
									$$=$1;
								}
							}
						| {$$=NULL;}
						;
	NUM_OP	:	PLUS {
							$$=$1;
						}
					|	MINUS {
							$$=$1;
						}
					|	MULTIPLY {
							$$=$1;
						}
					|	DIVIDE {
							$$=$1;
						}
					|	MODULUS {
							$$=$1;
						}
					|	GREATER {
							$$=$1;
						}
					|	SMALLER {
							$$=$1;
						}
					|	EQUAL {
							$$=$1;
						}
					;
	PLUS	:	'('	'+'	EXP	MORE_EXP	')' {
						$$=create_formula("+",$3,$4);
					}
				;
	MINUS	:	'('	'-'	EXP	EXP	')' {
						$$=create_formula("-",$3,$4);
					}
				;
	MULTIPLY	:	'('	'*'	EXP MORE_EXP	')' {
						$$=create_formula("*",$3,$4);
							}
						;
	DIVIDE	:	'('	'/'	EXP	EXP	')' {
						$$=create_formula("/",$3,$4);
						}
					;
	MODULUS	:	'('	mod EXP	EXP	')' {
						$$=create_formula("mod",$3,$4);
						}
					;
	GREATER	:	'('	'>'	EXP	EXP ')' {
						$$=create_formula(">",$3,$4);
						}
					;
	SMALLER	:	'('	'<'	EXP	EXP	')' {
						$$=create_formula("<",$3,$4);
						}
					;
	EQUAL	:	'('	'='	EXP	MORE_EXP	')'	{
						$$=create_formula("=",$3,$4);
						}
				;
	LOGICAL_OP	:	AND_OP {
									$$=$1;
								}
							|	OR_OP {
									$$=$1;;
								}
							|	NOT_OP {
									$$=$1;
								}
							;
	AND_OP	:	'('	and	EXP	MORE_EXP	')' {
								$$=create_formula("and",$3,$4);
						}
					;
	OR_OP		:	'('	or	EXP	MORE_EXP	')' {
								$$=create_formula("or",$3,$4);
						}
					;
	NOT_OP	:	'('	not	EXP	')'	{
							$$=create_formula("not",$3,NULL);
						}
					;
	DEF_STMT	:	'('	define	VARIABLE	EXP	')' {
								$4->variableName=$3->variableName;
								$$=$4;
							}
						;
	VARIABLE	:	id {
								$$=(exp *)malloc(sizeof(exp));
								$$->type="unInit";
								$$->type_2="variable";
								$$->isVariable=1;
								$$->variableName=$1;
								$$->value=0;
								$$->next=NULL;
								$$->funbody=NULL;
								$$->parameters=NULL;
							}
						;
	IDs	:	id {
						$$=(exp *)malloc(sizeof(exp));
						$$->type="unInit";
						$$->type_2="variable";
						$$->variableName=$1;
						$$->value=0;
						$$->next=NULL;
						$$->parameters=NULL;
				}
			|	IDs	id {
						exp *p=(exp *)malloc(sizeof(exp));
						p->type="unInit";
						p->type_2="variable";
						p->variableName=$2;
						p->value=0;
						p->next=NULL;
						p->parameters=NULL;

						exp *wp=$1;
						for(;wp->next;wp=wp->next){}
						wp->next=p;
						$$=$1;
				}
			;
	FUN_EXP	:	'('	fun	FUN_IDs	FUN_BODY	')' {
							$$=(exp *)malloc(sizeof(exp));
							$$->type=$4->type;
							$$->type_2="fun";
							$$->next=NULL;
							$$->funbody=$4;
							$$->local_variable=$3;

							if($4->temp_variable!=NULL){
								exp *p=$$->local_variable;
								for(;p->next;p=p->next){}
								p->next=$4->temp_variable;
								$4->temp_variable=NULL;
							}
							exp *a=$$->local_variable;
						}
					;
	FUN_IDs	:	'('	IDs	')' {
							$$=$2;
						}
					|	'('	')' {
							$$=NULL;
						}
					;
	FUN_BODY:	MORE_DEF EXP{
							/*
								用一個新的欄位:temp_variable
								暫時存放定義的變數
								在reduce成fun_exp的時候，再放到fun_exp的
								local_variable裡，並把temp_variable設成null
							*/

							$$=$2;
							$$->temp_variable=$1;
						}
					| EXP {
							$$=$1;
							$$->temp_variable=NULL;
						}
					;
	FUN_CALL:	'('	FUN_EXP	MORE_EXP	')'	{
							$$=(exp *)malloc(sizeof(exp));
							$$->type=$2->type;
							$$->type_2="fun_call";
							$$->next=NULL;
							$$->funbody=$2->funbody;
							$$->local_variable=$2->local_variable;
							$$->local_exp=$3;
							$$->variableName=NULL;
						}
					|	'('	FUN_NAME	MORE_EXP	')' {
							exp *f;
							exp *i;
							$$=(exp *)malloc(sizeof(exp));
							f=look_symbol_table(global_variable,$2);
							if(f!=NULL &&  f->funbody!=NULL && strcmp(f->funbody->type_2,"fun")==0){
									$$->type="unInit";
									$$->type_2="fun";
									$$->isVariable=1;
									$$->next=NULL;
									$$->funbody=f->funbody->funbody;
									if(f->local_exp==NULL){
										$$->local_exp=$3;
									}else{
										$$->local_exp=$3;
										i=$$->local_exp;
										for(;i->next;i=i->next){}
										i->next=f->local_exp;
									}
									if(f->funbody->local_variable!=NULL){
										$$->local_variable=f->funbody->local_variable;
										i=$$->local_variable;
										if(f->local_variable!=NULL){
											for(;i->next;i=i->next){}
											i->next=f->local_variable;
										}
									}else{
										if(f->local_variable!=NULL){
											$$->local_variable=f->local_variable;
										}
									}
							}else{
									$$=(exp *)malloc(sizeof(exp));
									$$->type="unInit";
									$$->type_2="fun_call";
									$$->isVariable=1;
									$$->variableName=$2;
									$$->next=NULL;
									$$->funbody=NULL;
									$$->local_variable=NULL;
									$$->local_exp=$3;
							}
						}
					;
	FUN_NAME	:	id {
								$$=$1;
							}
						;
	IF_EXP	:	'('	IF	TEXT_EXP THEN_EXP	ELSE_EXP	')' {
							$$=(exp *)malloc(sizeof(exp));
							$$->next=NULL;
							$$->type="unInit";
							$$->type_2="if";
							$$->parameters=NULL;
							$$->text=$3;
							$$->then=$4;
							$$->el=$5;
						}
					;
	TEXT_EXP	:	EXP {
							$$=$1;
						}
						;
	THEN_EXP	:	EXP {
							$$=$1;
						}
						;
	ELSE_EXP	:	EXP {
							$$=$1;
						}
						;


%%

void tra_table(exp *table){
	for(;table;table=table->next){
		printf("name:%s\n",table->variableName);
	}
}


exp *look_symbol_table(exp *which_table,char *variableName){
	exp *wp=which_table;
	for(;wp;wp=wp->next){
		if(strcmp(wp->variableName,variableName)==0){
			return wp;
		}
	}
	return NULL;
}
exp *create_formula(char *operator,exp *p1,exp *p2){

	exp *n;
	n=(exp *)malloc(sizeof(exp));
	n->next=NULL;
	n->parameters=NULL;
	if(strcmp(operator,"and")==0 ||
		strcmp(operator,"or")==0 	||
		strcmp(operator,"not")==0 ||
		strcmp(operator,"<")==0 ||
		strcmp(operator,">")==0 ||
		strcmp(operator,"=")==0
	){
		n->type="boolVal";
	}else{
		n->type="int";
	}

	p1->next=p2;
	exp *wp=p1;
	exp *new_node;
	exp *last_parameter;
	for(;wp;wp=wp->next){
		new_node=(exp *)malloc(sizeof(exp));
		new_node->type=wp->type;
		new_node->type_2=wp->type_2;
		new_node->variableName=wp->variableName;
		new_node->isVariable=wp->isVariable;
		new_node->value=wp->value;
		new_node->next=NULL;
		new_node->funbody=wp->funbody;
		new_node->local_exp=wp->local_exp;
		new_node->local_variable=wp->local_variable;
		new_node->operator=wp->operator;
		new_node->parameters=wp->parameters;
		new_node->text=wp->text;
		new_node->then=wp->then;
		new_node->el=wp->el;

		if(n->parameters==NULL){
			n->parameters=new_node;
			last_parameter=new_node;
		}
		else{
			last_parameter->next=new_node;
			last_parameter=new_node;
		}
	}
	n->type_2="formula";
	n->operator=operator;
	n->value=0;

	return n;
}
int calc(exp *t , exp *table){
	int type_check;


	if(t->isVariable==1){
		exp *p=look_symbol_table(table,t->variableName);
		if(strcmp(t->type_2,"fun_call")!=0){
			t->value=p->value;
			t->type=p->type;
			t->type_2=p->type_2;
			t->operator=p->operator;
			t->parameters=p->parameters;
			t->funbody=p->funbody;
			t->local_variable=p->local_variable;
			t->local_exp=p->local_exp;
			t->text=p->text;
			t->then=p->then;
			t->el=p->el;

		}else{
			t->type=p->type;
			t->funbody=p->funbody;
			t->local_variable=NULL;
			exp *a=p->local_variable;
			int j=0;
			exp *k;
			/*錯在這裡，fun sqare的區域變數離奇地變成NULL*/
			/*這裡是將查到的fun的local_variable，複製到我的fun_call上*/
			for(;a;a=a->next){
				exp *n=(exp *)malloc(sizeof(exp));
				n->type=a->type;
				n->type_2=a->type_2;
				n->local_variable=a->local_variable;
				//錯的，local_variable要用複製的
				/*
					這裡其實可以用另一個解法
					只要紀錄區域變數有幾個，再做一些變化，就可以解決這個問題。
				*/
				n->funbody=a->funbody;
				n->variableName=a->variableName;
				if(t->local_variable==NULL){
					t->local_variable=n;
				}else{
					for(k=t->local_variable;k->next;k=k->next){}
					k->next=n;
				}
			}
			if(p->local_exp!=NULL){
				k=t->local_exp;
				for(;k->next;k=k->next){}
				k->next=p->local_exp;
			}

		}

	}
	if(strcmp(t->type_2,"formula")==0){
		if(strcmp(t->operator,"+")==0){
			int sum=0;
			exp *p=t->parameters;
			for(;p;p=p->next){
				type_check=calc(p,table);
				if(type_check==-1){
					return -1;
				}
				if(strcmp(p->type,"int")!=0){
					printf("type error , should be number in operate +!\n");
					return -1;
				}
				sum+=p->value;
			}
			t->value=sum;
		}
		else if(strcmp(t->operator,"*")==0){
			int sum=1;
			exp *p=t->parameters;

			p=t->parameters;
			for(;p;p=p->next){
				type_check=calc(p,table);
				if(type_check==-1){
					return -1;
				}

				if(strcmp(p->type,"int")!=0){
					printf("type error , should be number in operate *!\n");
					return -1;
				}
				sum*=p->value;
			}
			t->value=sum;
		}else if(strcmp(t->operator,"-")==0){
			int sum;
			exp *p=t->parameters;
			exp *a,*b;
			a=p;
			b=p->next;
			type_check=calc(a,table);
			if(type_check==-1){
				return -1;
			}

			type_check=calc(b,table);
			if(type_check==-1){
				return -1;
			}
			if(strcmp(a->type,"int")!=0 || strcmp(b->type,"int")!=0){
				printf("type error , should be number in operate -!\n");
				return -1;
			}
			sum=a->value-b->value;
			t->value=sum;
		}else if(strcmp(t->operator,"/")==0){
			int sum;
			exp *p=t->parameters;
			exp *a,*b;
			a=p;
			b=p->next;
			type_check=calc(a,table);
			if(type_check==-1){
				return -1;
			}
			type_check=calc(b,table);
			if(type_check==-1){
				return -1;
			}
			if(strcmp(a->type,"int")!=0 || strcmp(b->type,"int")!=0){
				printf("type error , should be number in operate /!\n");
				return -1;
			}
			sum=a->value/b->value;
			t->value=sum;
		}else if(strcmp(t->operator,"mod")==0){
			int sum;
			exp *p=t->parameters;
			exp *a,*b;
			a=p;
			b=p->next;
			type_check=calc(a,table);
			if(type_check==-1){
				return -1;
			}
			type_check=calc(b,table);
			if(type_check==-1){
				return -1;
			}
			if(strcmp(a->type,"int")!=0 || strcmp(b->type,"int")!=0){
				printf("type error , should be number in operate mod!\n");
				return -1;
			}
			sum=a->value%b->value;
			t->value=sum;
		}else if(strcmp(t->operator,">")==0){
			int sum;
			exp *p=t->parameters;
			exp *a,*b;
			a=p;
			b=p->next;
			type_check=calc(a,table);
			if(type_check==-1){
				return -1;
			}
			type_check=calc(b,table);
			if(type_check==-1){
				return -1;
			}
			if(strcmp(a->type,"int")!=0 || strcmp(b->type,"int")!=0){
				printf("type error , should be number in operate >!\n");
				return -1;
			}
			if(a->value>b->value)
				sum=1;
			else
				sum=0;
			t->value=sum;
		}else if(strcmp(t->operator,"<")==0){
			int sum;
			exp *p=t->parameters;
			exp *a,*b;
			a=p;
			b=p->next;
			type_check=calc(a,table);
			if(type_check==-1){
				return -1;
			}
			type_check=calc(b,table);
			if(type_check==-1){
				return -1;
			}
			if(strcmp(a->type,"int")!=0 || strcmp(b->type,"int")!=0){
				printf("type error , should be number in operate <!\n");
				return -1;
			}
			if(a->value<b->value)
				sum=1;
			else
				sum=0;
			t->value=sum;
		}else if(strcmp(t->operator,"=")==0){
			int sum=1;
			int a;
			int flag=0;
			exp *p=t->parameters;
			for(;p;p=p->next){
				type_check=calc(p,table);
				if(type_check==-1){
					return -1;
				}
				if(strcmp(p->type,"int")!=0){
					printf("type error , should be number in operate -1!\n");
					return -1;
				}
				if(flag==0){
					a=p->value;
					flag=1;
				}else{
					if(a!=p->value){
						sum=0;
					}
				}
			}
			t->value=sum;
		}else if(strcmp(t->operator,"and")==0){
			int sum=1;
			exp *p=t->parameters;
			for(;p;p=p->next){
				type_check=calc(p,table);
				if(type_check==-1){
					return -1;
				}
				if(strcmp(p->type,"boolVal")!=0){
					printf("type error , should be bool in operate and!\n");
					return -1;
				}
				sum&=p->value;
			}
			t->value=sum;
		}else if(strcmp(t->operator,"or")==0){
			int sum=0;
			int a;
			exp *p=t->parameters;
			for(;p;p=p->next){
				type_check=calc(p,table);
				if(type_check==-1){
					return -1;
				}
				if(strcmp(p->type,"boolVal")!=0){
					printf("type error , should be bool in operate or!\n");
					return -1;
				}
				sum|=p->value;
			}
			t->value=sum;
		}else if(strcmp(t->operator,"not")==0){
			int sum=0;
			int a;
			exp *p=t->parameters;
			type_check=calc(p,table);
			if(type_check==-1){
				return -1;
			}
			if(strcmp(p->type,"boolVal")!=0){
				printf("type error , should be bool in operate not!\n");
				return -1;
			}
			if(p->value==1)
				sum=0;
			else
				sum=1;
			t->value=sum;
		}
	}else if(strcmp(t->type_2,"if")==0){
		exp *p=table;
		type_check=calc(t->text,table);
		if(type_check==-1){
			return -1;
		}
		if(strcmp(t->text->type,"boolVal")!=0){
			printf("type errpr , should be bool in if's text!\n");
			return -1;
			}


		if(t->text->value==1){
		/*then*/
			type_check=calc(t->then,table);
			if(type_check==-1){
				return -1;
			}
			t->type=t->then->type;
			t->value=t->then->value;
		}else if(t->text->value==0){
		/*else*/
			type_check=calc(t->el,table);
			if(type_check==-1){
				return -1;
			}
			t->type=t->el->type;
			t->value=t->el->value;
		}
	}else if(strcmp(t->type_2,"fun_call")==0){

		exp *q=t->local_variable;
		exp *p=t->local_exp;
		exp *new_table;
		q=t->local_variable;
		for(;p;p=p->next,q=q->next){
			type_check=calc(p,table);
			if(type_check==-1){
				return -1;
			}
			q->type=p->type;
			//q->type_2=p->type_2;
			q->value=p->value;
			q->operator=p->operator;
		  q->parameters=p->parameters;
			q->funbody=p->funbody;
			q->local_variable=p->local_variable;
			q->local_exp=p->local_exp;
			q->text=p->text;
			q->then=p->then;
			q->el=p->el;
		}

		q=t->local_variable;
		if(q!=NULL){
			for(;q->next;q=q->next){}
			q->next=global_variable;
			q=t->local_variable;
			new_table=q;
		}else{
			new_table=global_variable;
		}
		/*
			假如funbody是fun，就沒辦法calc出值。
			所以需要多作處理，形成閉包
		*/
		type_check=calc(t->funbody,new_table);
		if(type_check==-1){
			return -1;
		}
		t->value=t->funbody->value;
		t->type=t->funbody->type;
	}
	return 1;
}

void yyerror(const char *message)
{
	fprintf(stderr, "%s\n",message);
}

int main(int argc, char *argv[])
{
    yyparse();
    return(0);
}
/*
	1.
	在FUN_CALL的時候檢查funbody的type是不是fun
	假如是的話，就要多做處理

	a.把exp塞到區域變數裡
  b.把區域變數塞到funbody的區域變數的後面
	c.回傳fun


*/
