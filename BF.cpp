//
#include<iostream>
#include <stdio.h>
#include <fstream>
#include <windows.h>
#include <time.h>
using namespace std;
/*
brainfuck Language compiler
The library used is <fstream>
*/	   
char tape[30000]={0};
int ptr=0;
int num=0;
void BF(char code[5000])
{
	num=0;
	int i=0;
	while(i<5000)
	{
		switch (code[i])
		{
		case '>':
			++ptr;
			break;
		case '<':
			--ptr;
			break;
		case '+':
			++tape[ptr];
			break;
		case '-':
			--tape[ptr];
			break;
		case '.':
			putchar(tape[ptr]);
			break;
		case ',':
			cin.get(tape[ptr]);
			break;
		case '[':
			num=1;
			if(tape[ptr])
			{
				break;
			}
			while (num)  
			{  
				++i;  
				if ( code[i]=='[')  
				{  
					++num;  
				}  
				if (code[i]==']')  
				{  
					--num;  
				}  
			}  
			--i;
			break;
		case ']':
			num = 1;  
			if (!tape[ptr])  
			{  
				break;  
			}  
			while (num)  
			{  
				--i;  
				if (code[i]==']')  
				{  
					++num;  
				}  
				if (code[i]=='[')  
				{  
					--num;  
				}  
			}   	
			break;
		}
		i++;
	}
}
void bf()
{
	char code[5000]={0};
	ifstream fin("D:\\bf.txt");
	cout<<"The document is being opened。。。。"<<endl;
	if( ! fin )
	{
		cerr<<"Open the failure！！！"<<endl;
		getchar();
	}
	cout<<"Open the success！！！"<<endl;
	int i=0;
	while( ! fin.eof() )
	{
		fin>>code[i];
		i++;
	}
	
	fin.close();  
	cout<<code<<endl;
	cout<<"In compile....."<<endl;
	for(int j=0;j<5000;j++)
	{
		if(code[j]=='[')
		{
			num+=1;
		}
		else if(code[j]==']')
		{
			num-=1;
		}
	}
	if(num<0)
	{
		cout<<"] is more"<<endl;
	}
	else if(num>0)
	{
		cout<<"] is less"<<endl;
	}
	BF(code);
}
int main()
{
	while(1)
	{
		cout<<"----------------------------Brainfuck compiler----------------------------"<<endl;
		cout<<"----------Enter 1,start compile------input 2,help------enter 0,exit-------"<<endl;
		cout<<"Please write the source code in a notepad named bf lowercase with a D disk"<<endl;
		cout<<"--------------------------------------------------------------------------"<<endl;
		int b;
		cin>>b;
		if(b==2)
		{
			cout<<"'>'The pointer plus one,'<'pointer minus one"<<endl;
			cout<<"'+'The value of the pointer is plus one, '-'the value of the pointer is minus one"<<endl;
			cout<<"'.'to output the value that the current pointer points to,','input the value that the current pointer points to"<<endl;
			cout<<"'['If the value that the current pointer points to is not zero, the code in front of the '] 'sign is circulated"<<endl;
			cout<<"authorQQ:2112688387"<<endl;
		}
		else if(b==1)
		{
			bf();
		}
		else if(b==0)
		{
			cout<<"Press any key to continue。。。";
			getchar();
			return 0;
		}
	}
	
}
