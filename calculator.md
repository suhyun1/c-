### simple calculator

1. 한자리 양의 정수 계산(괄호 없음)

~~~cpp
#include<iostream>
#include<string>
using namespace std;

int findLast(const string &str, char op ){
	int loc =-1;

	for(int i=0;i<str.size();i++){
		if(str[i] == op )
			loc =i;
	}

	return loc;
}

float getNumber(const string &num){

	if(num.size() != 1)	//1의 자리 계산인 경 우  
		throw exception();
	else if(num[0] <'0' || num[0]>'9')
		throw exception();
	else
		return (float)(num[0]-'0');

}

float getPrimary(const string &pri){

	float result;

	result = getNumber(pri);

	return result;

}
float getTerm(const string &term){
	float result;

	int mul = findLast(term, '*');
	int div = findLast(term, '/');

	if(mul ==-1 && div ==-1 )
		result = getPrimary(term);
	else if(mul > -1 && div ==-1)
		result =getTerm(term.substr(0,mul))* getPrimary(term.substr(mul+1));
	else if(mul ==-1 && div > -1)
		result =getTerm(term.substr(0,div))/getPrimary(term.substr(div+1));
	else if(mul > div)
		result =getTerm(term.substr(0,mul))* getPrimary(term.substr(mul+1));
	else
		result =getTerm(term.substr(0,div))/getPrimary(term.substr(div+1));

	return result;
}

float getExpression(const string &exp){

	float result;
	int plus = findLast(exp, '+'); //마지막에 올 +
	int minus =findLast(exp, '-');	//-

	if(plus ==-1 && minus ==-1 )
		result = getTerm(exp);
	else if(plus > -1 && minus ==-1)
		result = getExpression(exp.substr(0,plus))+getTerm(exp.substr(plus+1));
	else if(plus ==-1 && minus > -1)
		result= getExpression(exp.substr(0,minus))-getTerm(exp.substr(minus+1));
	else if(plus > minus)
		result=getExpression(exp.substr(0,plus))+getTerm(exp.substr(plus+1));
	else
		result=getExpression(exp.substr(0,minus))-getTerm(exp.substr(minus+1));

	return result;
}
int main(){

	string expression;
	for(getline(cin, expression); expression != "quit" ; getline(cin, expression) ){

	try{
		cout << getExpression(expression) << endl;

	}catch(exception &e){
		cout << "Syntax Error " << endl;
	}
	}

}

~~~


2. 한 자리 양의 정수 계산 (괄호 있음)

~~~cpp
#include<iostream>
#include<string>
using namespace std;
float getExpression(const string &exp);

int findLast(const string &str, char op ){
	int loc =-1;
	int par =0;  //괄호 카운팅
	for(int i=0;i<str.size();i++){

		if(str[i] == op && par ==0)
			loc =i;
		else if(str[i] == '(')
			par++;

		else if(str[i] ==')')
			par--;
	}
	if(par != 0 ) throw exception();

	return loc;
}

float getNumber(const string &num){

	if(num.size() != 1)	//1의 자리 계산인 경 우  
		throw exception();
	else if(num[0] <'0' || num[0]>'9')
		throw exception();
	else
		return (float)(num[0]-'0');

}

float getPrimary(const string &pri){

	float result;

	if(pri.length()>2 && pri[0] =='(' && pri[pri.length()-1] ==')' )
		return getExpression(pri.substr(1,pri.length()-2));
	else
		return getNumber(pri);

}
float getTerm(const string &term){
	float result;

	int mul = findLast(term, '*');
	int div = findLast(term, '/');

	if(mul ==-1 && div ==-1 )
		result = getPrimary(term);
	else if(mul > -1 && div ==-1)
		result =getTerm(term.substr(0,mul))* getPrimary(term.substr(mul+1));
	else if(mul ==-1 && div > -1)
		result =getTerm(term.substr(0,div))/getPrimary(term.substr(div+1));
	else if(mul > div)
		result =getTerm(term.substr(0,mul))* getPrimary(term.substr(mul+1));
	else
		result =getTerm(term.substr(0,div))/getPrimary(term.substr(div+1));

	return result;
}

float getExpression(const string &exp){

	float result;
	int plus = findLast(exp, '+'); //마지막에 올 +
	int minus =findLast(exp, '-');	//-

	if(plus ==-1 && minus ==-1 )
		result = getTerm(exp);
	else if(plus > -1 && minus ==-1)
		result = getExpression(exp.substr(0,plus))+getTerm(exp.substr(plus+1));
	else if(plus ==-1 && minus > -1)
		result= getExpression(exp.substr(0,minus))-getTerm(exp.substr(minus+1));
	else if(plus > minus)
		result=getExpression(exp.substr(0,plus))+getTerm(exp.substr(plus+1));
	else
		result=getExpression(exp.substr(0,minus))-getTerm(exp.substr(minus+1));

	return result;
}
int main(){

	string expression;
	for(getline(cin, expression); expression != "quit" ; getline(cin, expression) ){

	try{
		cout << getExpression(expression) << endl;

	}catch(exception &e){
		cout << "Syntax Error " << endl;
	}
	}

}
~~~

3. 양의 실수 계산 (괄호 있음)
