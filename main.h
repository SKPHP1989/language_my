/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.h
 * Author: lij25
 *
 * Created on 2019年11月22日, 下午5:46
 */

#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>

extern int yyparse(void);
extern FILE *yyin;

void interpreter_print_root();
void execute();
void init_process();

#endif /* MAIN_H */

