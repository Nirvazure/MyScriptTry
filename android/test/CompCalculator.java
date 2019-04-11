package com.lfr.firstcodetestUtil;

import java.util.Stack;

public class CompCalculator {

	public static double Calculator(String f)
	{
		int i=0,j=0;
		char c;
		StringBuffer s=new StringBuffer();
		s.append(f);
		s.append('=');
		String formula=s.toString();
		char[] anArray;
		anArray=new char[50];
		Stack<Character> mystack=new Stack<Character>();
		while(formula.charAt(i)!='=')
		{
			c=formula.charAt(i);
			switch(c)
			{
			case '(': mystack.push(new Character(c));
			i++;
			break;
			case ')':
				while(mystack.peek().charValue()!='(')
				{
					anArray[j++]=mystack.pop().charValue();
				}
				mystack.pop();
				i++;
				break;
			case '+':
			case '-':
				while(!mystack.empty()&&mystack.peek().charValue()!='(') {
					anArray[j++]=mystack.pop().charValue();
				}
				mystack.push(new Character(c));
				i++;
				break;
			case '*':
			case '/':
				while(!mystack.empty()&&(mystack.peek().charValue()=='*'||mystack.peek().charValue()=='/'))
				{
					anArray[j++]=mystack.pop().charValue();
				}
				mystack.push(new Character(c));
				i++;
				break;
			case' ': i++;
			break;
			default: while((c>='0'&&c<='9')||c=='.')
			{
				anArray[j++]=c;
				i++;
				c=formula.charAt(i);
			}
			anArray[j++]='#';
			break;
			}
		}
		while(!(mystack.empty()))
			anArray[j++]=mystack.pop().charValue();
		i=0;
		int count;
		double a,b,d;
		Stack<Double> mystack1 =new Stack<Double>(); while(i<j)
		{
			c=anArray[i];
			switch(c)
			{
			case '+':
				a=mystack1.pop().doubleValue(); b=mystack1.pop().doubleValue(); d=b+a;
				mystack1.push(new Double(d));
				i++;
				break;
			case '-':
				a=mystack1.pop().doubleValue(); b=mystack1.pop().doubleValue(); d=b-a;
				mystack1.push(new Double(d));
				i++;
				break;
			case '*':
				a=mystack1.pop().doubleValue(); b=mystack1.pop().doubleValue(); d=b*a;
				mystack1.push(new Double(d));
				i++;
				break;
			case '/':
				a=mystack1.pop().doubleValue(); b=mystack1.pop().doubleValue(); if(a!=0)
				{
					d=b/a;
					mystack1.push(new Double(d)); i++;
				}
				else
				{
					System.out.println("Error!"); }
				break;
			default:
				d=0;count=0;
				while((c>='0'&&c<='9'))
				{
					d=10*d+c-'0';
					i++;
					c=anArray[i];
				}
				if(c=='.')
				{
					i++;
					c=anArray[i];
					while((c>='0'&&c<='9'))
					{
						count++;
						d=d+(c-'0')/Math.pow(10,count); i++;
						c=anArray[i];
					}
				}
				if(c=='#')
					mystack1.push(new Double(d)); i++;
					break;
			}
		}
		return(mystack1.peek().doubleValue()); }
	
}
