#include <string.h>
void yyerror(char const *s);
#define SYMBOL_INTEGER 1
#define SYMBOL_BOOLEAN 2

struct ArgStruct
{
   int TYPE;
   char *NAME;
};
/* Sample Global and Local Symbol Table Structure */

/** Symbol Table Entry is required for variables, arrays and functions**/

struct Gsymbol {

char *NAME; // Name of the Identifier

int TYPE; // TYPE can be INTEGER or BOOLEAN

/***The TYPE field must be a TypeStruct if user defined types are allowed***/

int SIZE; // Size field for arrays

int* BINDING; // Address of the Identifier in Memory

struct ArgStruct *ARGLIST; // Argument List for functions

/***Argstruct must store the name and type of each argument ***/

struct Gsymbol *NEXT; // Pointer to next Symbol Table Entry */

};

struct Gsymbol * Glookup(char* NAME); // Look up for a global identifier

void Ginstall(char* NAME,int TYPE,int  SIZE,struct ArgStruct * ARGLIST); // Installation

struct Gsymbol *Ghead, *Gtail;



 ///////////////////////////////////////////////////////////////////////////////////////////////////////////

struct Lsymbol {

/* Here only name, type, binding and pointer to next entry needed */
char *NAME; // Name of the Identifier

int TYPE; // TYPE can be INTEGER or BOOLEAN

/***The TYPE field must be a TypeStruct if user defined types are allowed***/


int* BINDING; // Address of the Identifier in Memory

struct Lsymbol *NEXT; // Pointer to next Symbol Table Entry */


};

struct Lsymbol *Lhead, *Ltail;

struct Lsymbol *Llookup(char* NAME);

void Linstall(char* NAME,int TYPE);
