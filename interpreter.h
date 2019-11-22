/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   interpreter.h
 * Author: lij25
 *
 * Created on 2019年11月22日, 下午3:50
 */

#ifndef INTERPRETER_H
#define INTERPRETER_H
typedef struct interpreter_s interpreter_t;
struct interpreter_s {
    statement_list_t *statement_list;
    function_list_t *func_list;
    env_t global_env;
};
interpreter_t get_interpreter_instance();
void *interpreter_malloc(int size);
char *interpreter_str_malloc(char *s);
#endif /* INTERPRETER_H */

