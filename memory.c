/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   memory.c
 * Author: lij25
 *
 * Created on 2019年11月22日, 下午5:12
 */

#include <stdio.h>
#include <stdlib.h>

void *memory_malloc(int size){
    return (void *)malloc(size);
}

