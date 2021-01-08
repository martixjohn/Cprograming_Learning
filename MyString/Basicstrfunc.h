#pragma once
#include <stdio.h>
#include <assert.h>
#define SUCCESS 100
#define FAIL -100

char* MyErrorCode(int code) {
	switch (code) {
		case SUCCESS:return "SUCCESS RUNNING"; break;
		case FAIL: return "FAIL TO RUN"; break;
		default:
			return "NO SUCH A CODE";
	}
}

int my_strcpy(char* dst,const char* src) {
	if (!dst||!src) return FAIL;
//	assert(dst != NULL);
//	assert(src != NULL);
	while (*dst++=*src++);
	return SUCCESS;
}
int my_strcat(char* dst,const char* src) {
	if (!dst || !src) return FAIL;
	while (*dst!='\0') dst++;
//	while (*dst++);//WARING 详见陷阱分支Pointer
	while (*dst++=*src++);
	return SUCCESS;
}
int my_strcmp(const char* str1, const char* str2) {
	int gap = *str1 - *str2;
	assert(str1&&str2);
	while (!gap&&*str1&&*str2) {
		str1++;
		str2++;
		gap = *str1 - *str2;
		if (gap) break;
	}
	return gap;
}
