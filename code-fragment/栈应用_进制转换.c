/**
* 栈的应用案例片段
* 
* 进制转化
*
**/
void conversion(){
	InitStack(S);
	while(N){
		Push(S,N%8);
		N= N/8;
	}
	while(!StackEmpty(s)){
		Pop(S,e);
		printf("%d", e);
	}
}//conversion