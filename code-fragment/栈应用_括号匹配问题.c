/**
* 栈的应用
* 算法的设计思想：
*	a.凡出现左括号，则进栈；
*	b.凡出现右括号，首先检查栈是否空
*		若栈空，则表示该『右括号』多余
*		否则和栈顶元素比较，
*			若相匹配，则『左括号出栈』 
*			否则表明不匹配
*	c.表达式检验结束时，
*		若栈空，则表明表达式匹配正确
*		否则表明『左括号』有余 
*
**/

void match(char * exp){

	InitStack(S);

	char c,int i=0,b=1;
	while(exp[i] != '\0' && b == 1){
		if (exp[i] == '('){
			Push(S,exp[i]);
		}else if (exp[i] == ')'){
			c = Pop(S);
			if (c != '('){
				b = 0;
			}
		}
		i++;
	}
	return(b && StackEmpty(S));
}