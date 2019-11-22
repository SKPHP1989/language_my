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
    param_list_s *paramlist;
    function_t *next;
};

Statement *create_Statement(enum StatementType type);
Statement_list *createStatementList(Statement *statement);
Statement *create_ExpressionStatement(Expression *expression);
Statement *create_IFStatement(Expression *condition, Statement_list *list);
Statement *create_FORStatement(Expression *before, Expression *condition,
                               Expression *after, Statement_list *list);
Statement_list *StatementList_add(Statement_list *list, Statement *statement);

Expression *create_IntergerExpression(int i);
Expression *create_DoubleExpression(double i);
Expression *create_StrExpression(char *p);
Expression *create_IDExpression(char *p);
Binary_Expression *createBinaryExpression(enum ExpressionAction action, Expression *left, Expression *right);
Assign_Expression *createAssignExpression(char *c, Expression *expression);
Expression *binExpressionWarpper(Binary_Expression *expression);
Expression *AssignExpressionWarpper(Assign_Expression *expression);
Expression *create_FuncCallExpression(char *identifier, ParamList *params);

ParamList *createParamList(char *identifier);
ParamList *ParamList_add(ParamList *list, ParamList *param);
Function_t *Functon_define(char *identifier, ParamList *params, Statement_list *list);
Function_t *Function_add(Function_t *functionlist, Function_t *func);
Function_t *Function_find(Function_t *funclist, char *identifier);

void open_charbuffer();
void addc_charbuffer(char c);
char *flush_charbuffer();
char *Interpreter_str_malloc(char *str);
void Interpreter_setlist(Statement_list *list);
Statement_list *Interpreter_getlist();

void Interpreter_setFunclist(Function_t *func);
Function_t *Interpreter_getFunclist();

void Interpreter_printRoot();

#endif /* EXPRESSION_H */

