#include "stdafx.h"
#include "W32.h"
char* pchar()
{
	return "从静态链接库取得的字符串";

}

int F1::GetA(){
	return a + 1;
}