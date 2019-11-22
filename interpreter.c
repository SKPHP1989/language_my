/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   interpreter.c
 * Author: lij25
 *
 * Created on 2019年11月22日, 下午3:43
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "interpreter.h"
#include "memory.h"

interpreter_t *interpreter;

interpreter_t get_interpreter_instance(){
    if(interpreter){
        return interpreter;
    }
    interpreter = memory_malloc(sizeof(interpreter_t));
    interpreter->statement_list = NULL;
    interpreter->func_list = NULL;
    interpreter->global_env.storage = mem_open_storage(0);
    interpreter->global_env.list = NULL;
    interpreter->global_env.outer_var = NULL;
    return interpreter;
}

void *interpreter_malloc(int size){
    interpreter_t *interpreter = get_interpreter_instance();
    void *p = memory_malloc(size);
    return p;
}

void *interpreter_str_malloc(char *s){
    interpreter_t *interpreter = get_interpreter_instance();
    char *p = memory_malloc(strlen(s)+1);
    strcpy(p,s);
    return p;
}
void interpreter_set_statemnet_list(statement_list_t *list){
    get_interpreter_instance()->statement_list = list;
}
statement_list_t *interpreter_get_statemnet_list(){
    return get_interpreter_instance()->statement_list;
}
void interpreter_set_func_list(function_t *list){
    get_interpreter_instance()->func_list = list;
}
function_t *interpreter_get_func_list(){
    return get_interpreter_instance()->func_list;
}
void interpreter_print_root(){
    interpreter_t *interpreter= get_interpreter_instance();
}
void execute(){
    interpreter_t *interpreter= get_interpreter_instance();
    statement_list_t *list = interpreter->statement_list;
    execute_statement_list(interpreter ,NULL,list);
}