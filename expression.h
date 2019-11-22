/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   expression.h
 * Author: lij25
 *
 * Created on 2019年11月22日, 下午5:50
 */

#ifndef EXPRESSION_H
#define EXPRESSION_H

typedef struct primary_expression_s primary_expression_t;
typedef struct binary_expression_s binary_expression_t;
typedef struct expression_s expression_t;
typedef union expression_uni expression_u;
typedef struct assign_expression_s assign_expression_t;
typedef struct func_call_expression_s func_call_expression_t;

typedef struct expression_statement_s expression_statement_t;
typedef struct for_statement_s for_statement_t;
typedef struct if_statement_s if_statement_t;
typedef struct statement_s statement_t;
typedef struct statement_list_s statement_list_t;

typedef struct param_list_s param_list_t;
typedef struct function_s function_t;
typedef struct mstring_s mstring_t;

union expression_uni {
    primary_expression_t *p;
    binary_expression_t *b;
    assign_expression_t *a;
    expression_t *e;
    func_call_expression_t *func;
};

enum expression_type_e
{
    expression_type_primary,
    expression_type_binary,
    expression_type_assign,
    expression_type_inv,
    expression_type_func
};

struct expression_s
{
    enum expression_type_e type;
    expression_u u;
};

enum value_type_e
{
    value_type_int = 1,
    value_type_double,
    value_type_string,
    value_type_id,
    value_type_invalid
};

struct func_call_expression_s
{
    char *funname;
    function_t *func;
    param_list_t *params;
};

struct primary_expression_s
{
    enum value_type_e type;
    union {
        int i;
        double d;
        // char *str;
        mstring_t *string;
        char *id;
    } u;
};

enum expression_action_e
{
    expression_action_add = 1,
    expression_action_sub,
    expression_action_mul,
    expression_action_div,
    expression_action_gt,
    expression_action_ge,
    expression_action_lt,
    expression_action_le,
    expression_action_eq,
    expression_action_ne
};

struct binary_expression_s
{
    enum expression_action_e action;
    expression_t *left;
    expression_t *right;
};

struct assign_expression_s
{
    char *id;
    expression_t *expression;
};

enum statement_type_e
{
    statement_type_expression = 1,
    statement_type_iF,
    statement_type_for,
    statement_type_break,
    statement_type_continue,
    statement_type_rtn
};

struct expression_statement_s
{
    expression_t *expression;
};
struct for_statement_s
{
    expression_t *before;
    expression_t *condition;
    expression_t *after;
    statement_list_t *statementlist;
};
struct if_statement_s
{
    expression_t *expression;
    statement_list_t *statementlist;
};

struct statement_s
{
    enum statement_type_e type;
    union {
        expression_statement_s *e;
        for_statement_s *f;
        if_statement_s *i;
    } u;
};
struct statement_list_s
{
    statement_list_t *next;
    statement_t *statement;
};

struct param_list_s
{
    char *identifier;
    param_list_t *next;
};

struct function_s
{
    char *id;
    int is_native;
    void *func_addr;
    statement_list_t *list;
    param_list_t *paramlist;
    function_t *next;
};
struct mstring_s
{
    char *str;
    int is_src;
    int ref_count;
};

statement_t *create_statement(enum statement_type_e type);
statement_list_t *create_statement_list(statement_t *statement);
statement_t *create_expression_statement(expression_t *expression);
statement_t *create_if_statement(expression_t *condition, statement_list_t *list);
statement_t *create_for_statement(expression_t *before, expression_t *condition,
                               expression_t *after, statement_list_t *list);
statement_list_t *statement_list_add(statement_list_t *list, statement_t *statement);

expression_t *create_int_expression(int i);
expression_t *create_double_expression(double i);
expression_t *create_str_expression(char *p);
expression_t *create_id_expression(char *p);
binary_expression_t*create_binary_expression(enum expression_action_e action, expression_t *left, expression_t *right);
assign_expression_t *create_assign_expression(char *c, expression_t *expression);
expression_t *binary_expression_warpper(binary_expression_t*expression);
expression_t *assign_expression_warpper(assign_expression_t *expression);
expression_t *create_func_call_expression(char *identifier, param_list_t *params);

param_list_t *create_param_list(char *identifier);
param_list_t *param_list_add(param_list_t *list, param_list_t *param);
function_t *functon_define(char *identifier, param_list_t *params, statement_list_t *list);
function_t *function_add(function_t *functionlist, function_t *func);
function_t *function_find(function_t *funclist, char *identifier);

#endif /* EXPRESSION_H */

