/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: lij25
 *
 * Created on 2019年11月22日, 下午3:19
 */
#include "main.h"
void yyerror(char *s){
    printf("Error:%s\n" ,s);
}
/*
 * 
 */
int main(int argc, char** argv) {
    FILE *fp;
    setvbuf(stdout,NULL ,_IONBF,0);
    if(argc != 2){
        fprintf(stderr ,"usage:%s filename" ,argv[0]);
        exit(1);
    }
    fp = fopen(argv[1],"r");
    if(fp == NULL){
        fprintf(stderr ,"file:%s not found" ,argv[1]);
        exit(1);
    }
    yyin = fp;
    if(yyparse()){
        fprintf(stderr ,"file:%s parse fail" ,argv[1]);
        exit(1);
    }
    init_process();
    interpreter_print_root();
    execute();
    return (EXIT_SUCCESS);
}

