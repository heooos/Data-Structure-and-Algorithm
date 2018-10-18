/**
* 行编辑存储问题
* 
* 设立一个输入缓冲区，用以接受用户输入的一行字符，然后逐行存入用户数据区；并假设
* "#"为退格符，"@"为退行符。	 
*
**/

#define EOF -1


void char_store(){
	while(ch != EOF){
		while(ch != EOF && ch != '\n'){
		switch(ch){
			case '#':
				Pop(S,c);break;
				
			case '@':
				ClearStack(S);break; //清空栈
			
			default:
				Push(S,ch);break;
			}
			scanf('%c',ch); //终端读入
		}
		//将从栈底到栈顶的字符传送到调用过程的数据区；
		ClearStack(S); //重置栈
		if (ch != EOF){
			scanf('%c',ch);
		}
	}
}