#ifndef _CONSTANTS_H
#define _CONSTANTS_H

#include <stddef.h>
#include "structures.h"
#include "base_util.h"

extern struct String functions;
extern struct String numbers;
extern struct String letters;
extern struct String print_const;
extern struct String concat_const;
extern struct String if_const;
extern struct String def_const;
extern struct String let_const;

extern const char bool_true;
extern const char bool_false;
extern const char bool_undefined;
extern const char open_parens_const;
extern const char close_parens_const;
extern const char root_type_const;
extern const char quote_const;

int is_a_open_parens(char ch);
int is_a_close_parens(char ch);
int is_a_root_type(char ch);
int is_a_quote(char ch);
int is_a_letter(char ch);
int is_a_number(char ch);
int is_a_function(char ch);

#endif
