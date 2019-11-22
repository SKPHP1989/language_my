/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   memory.h
 * Author: lij25
 *
 * Created on 2019年11月22日, 下午5:13
 */

#ifndef MEMORY_H
#define MEMORY_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum memory_fail_mode_e{
    memory_fail_mode_exit,
    memory_fail_mode_return
};
void *memory_malloc(int size);
#endif

