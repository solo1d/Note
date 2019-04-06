/* 栈的应用:  就近匹配 */#include <stdio.h>#include <string.h>#include <stdlib.h>#include "LinkStack.h"typedef struct MYCHAR{    LinkNode node;    char* pAddres;  // 字符地址  (不是字符串)    int index;}MyChar;int IsLeft(char c){    return  c == '(';}int IsRight(char c){    return c ==')';}MyChar* CreatemyChar(char* p, int index){    MyChar* mychar = (MyChar*)malloc(sizeof(MyChar));    mychar->index = index;    mychar->pAddres = p;        return mychar;}void ShowError(char* str, int pos){    printf("%s\n",str);    for(int i = 0; i < pos; i++){        printf(" ");    }    printf("A");}int main(void){        LinkStack* stack = Init_LinkStack();    char* str = "1+2+6(ad)a) sdjia(saj)";    char* p   = str;        int index = 0;        while( *p != '\0'){                // 如果左括号 直接进栈        if(IsLeft(*p)){            Push_LinkStack(stack, (LinkNode*)CreatemyChar(p,index));        }                //如果右括号  从栈顶弹出元素  判断是不是左括号        if(IsRight(*p)){            if(Size_LinkStack(stack) > 0){                MyChar* mychar = (MyChar*)Top_LinkStack(stack);                if( IsLeft(*(mychar->pAddres))){                    Pop_LinkStack(stack);                    free(mychar);                }            }            else{                printf("右括号没有匹配到左括号:\n");                ShowError(str, index);                break;            }        }        p++;        index++;    }        while(Size_LinkStack(stack) > 0){        MyChar* mychar = (MyChar*)Top_LinkStack(stack);        printf("左括号没有匹配的右括号:\n");        ShowError(str, mychar->index);        Pop_LinkStack(stack);        free(mychar);    }        Free_LinkStack(stack);    printf("\n");    return 0;}