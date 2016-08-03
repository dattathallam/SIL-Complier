#include <string.h>
void yyerror(char const *s);
#define SYMBOL_INTEGER 1
#define SYMBOL_BOOLEAN 2
#define SYMBOL_ARRAY_INT 3
#define SYMBOL_ARRAY_BOOLEAN 4
#define SYMBOL_AMP_INTEGER 5
#define SYMBOL_AMP_BOOLEAN 6

///////////////////////////////////////////////////////////////////
struct FieldList 
{
	char *NAME;
	struct TypeTable *type;
	struct FieldList *NEXT; 
};
struct FieldList *FieldHead,*FieldTail;
struct FieldList* FieldLookup(char* NAME,struct FieldList *list);
void FieldInstall(struct TypeTable *type,char* NAME);

/////////////////////////////////////////////////////////////////////
struct TypeTable
{
	char *NAME;
	struct FieldList *fields;
	struct TypeTable *NEXT;
};
struct TypeTable *Typehead,*Typetail;
struct TypeTable* TypeLookup(char* NAME);
void TypeInstall(char* NAME,struct FieldList *fields);

////////////////////////////////////////////////////////////////////////
struct ArgStruct
{
   struct TypeTable* TYPE;
   char *NAME;
   int amp;
int dsize;
   
   struct ArgStruct *NEXT;
};

struct ArgStruct *Arghead = NULL,*Argtail = NULL;

void ArgInstall(char* NAME,struct TypeTable* TYPE,int amp);

struct ArgStruct* Arglookup(char* NAME);

/* Sample Global and Local Symbol Table Structure */

/** Symbol Table Entry is required for variables, arrays and functions**/

struct Gsymbol {

char *NAME; // Name of the Identifier

// int TYPE; // TYPE can be INTEGER or BOOLEAN
struct TypeTable* TYPE;

/***The TYPE field must be a TypeStruct if user defined types are allowed***/

int SIZE; // Size field for arrays

int BINDING; // Address of the Identifier in Memory
int dsize;


struct ArgStruct *Arglist; // Argument List for functions

/***Argstruct must store the name and type of each argument ***/

struct Gsymbol *NEXT; // Pointer to next Symbol Table Entry */

};

struct Gsymbol * Glookup(char* NAME); // Look up for a global identifier

void Ginstall(char* NAME,struct TypeTable* TYPE,int  SIZE,struct ArgStruct * Arglist); // Installation

struct Gsymbol *Ghead, *Gtail;

int totalCount = 257;

int fbind = 0;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct Lsymbol {

/* Here only name, type, binding and pointer to next entry needed */
char *NAME; // Name of the Identifier

// int TYPE; // TYPE can be INTEGER or BOOLEAN
struct TypeTable* TYPE;
/***The TYPE field must be a TypeStruct if user defined types are allowed***/

int BINDING; // Address of the Identifier in Memory
int dsize;

struct Lsymbol *NEXT; // Pointer to next Symbol Table Entry */


};

struct Lsymbol *Lhead, *Ltail;

struct Lsymbol *Llookup(char* NAME);

void Linstall(char* NAME,struct TypeTable* TYPE);
///////////////////////////////////////////////////////////////////////////

