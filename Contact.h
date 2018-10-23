#pragma once
#ifndef __CONTACT_H__
#define __CONTACT_H__


#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>


#define NAME_MAX 20
#define SEX_MAX 10
#define TELE_MAX 20
#define ADDRE_MAX 20
#define DEFAULT_CAPACITY 3
#define ADD_CAPACITY 2

typedef struct PeoInfo {         //联系人信息
	char name[NAME_MAX];
	int age;
	char sex[SEX_MAX];
	char tele[TELE_MAX];
	char addre[ADDRE_MAX];
}PeoInfo,*pPeoInfo;

typedef struct Contact {         //通讯录信息
	pPeoInfo data;
	int size;
	int capacity;
}Contact,*pContact;


void menu();   
void InitContact(pContact pCon);     
void ChooseOption(pContact pCon);
void Add(pContact pCon);
void Delete(pContact pCon);
void Search(const pContact pCon);
void Modify(pContact pCon);
void Show(const pContact pCon);
void Sort(pContact pCon);
void Empty(pContact pCon);
void Destroy(pContact pCon);

#endif //__CONTACT_H__