


typedef struct symbol_node{
	char *type;
	char *variableName;
	int int_value;
	int boolean_value;
	struct NODE *treepoint;

	struct symbol_node *next;


}symNode;

typedef struct symNode *symP;

typedef struct NODE{
	char *type;
	char *type_2;
	char *variableName;
	int value;
	char *operatorValue;

	struct NODE *leftChild;
	struct NODE *rightChild;

}node;

typedef struct EXP{
	char *type;
	char *type_2;
	char *variableName;
	int value;
	struct EXP *next;
	/* for recognize whether variable */
	int isVariable;

	/*for type_2 formula*/
	char *operator;/*operator:+,-,*...*/
	struct EXP *parameters;

	/*for type_2 fun*/
	struct EXP *funbody;
	struct EXP *local_variable;
	struct EXP *local_exp;
	int para_number;//參數的個數

	/*for type_2 if*/
	struct EXP *text;
	struct EXP *then;
	struct EXP *el;

	/*for definition in funbody*/
	struct EXP *temp_variable;

}exp;
