# 5. Errors

### Error의 종류
- Compile-time error (syntax error, type error) - 여기서는 선언 있으면 ok
- Link-time error - 선언은 있는데 그 실체가 없는 경우
- Runtime error
- Logic error - 코드는 돌아가지만 잘못된 아웃풋 발생

#### Bad Function Arguments
~~~cpp
int area(int length, int width){
  return length*width;
}
int main(){
  int x1=area(7); //컴파일에러
  int x2=area("seven", 10); //컴파일에러

  //아래는 컴파일러가 못걸러줌
  int x3=area(7.5,10) //강제 형변환 이루어짐(7.5->7)
  int x4=area(-7,10) //타입은 맞지만 make no sense
}
~~~
컴파일러로 거를 수 없는 이 코드는 어떻게 해야할까
~~~cpp
  int x4=area(-7,10)
~~~
1. function(callee)이 내부적으로 체크하는 것이 안전
2. 외부에게 input이 잘못되었음을 알려야함.<br>
=> 어떻게 알릴까?<br>
1) 'return -1'과 같이 error value를 리턴<br>
2) 전역변수로 error status에 대한 지표 설정
<br> 1)과 2)의 단점: 1.caller가 체크하지 않으면 무시되고 2. 정상적인 흐름과 error가 발생했을 때의 흐름의 구분이 어려워진다.

 3) ** throw an exception ** <br>
 앞의 단점을 해결할 수 있음. 가독성 증가

 ~~~cpp
 class Bad_area{};
 int area(int length, int width){
   if(length<=0 || width <=0) throw Bad_area{};
   //throw 되는 순간 함수 종료, 모든 정상적인 흐름 종료됨
   return length*width;
 }
 ~~~

***
#### 예외처리 예제
ex01
~~~cpp
void function3() {
	cout << "function3 start" << endl;
	throw(exception());                                                                                  
	cout << "function3 end" << endl;
}

void function2() {
	cout << "function2 start" << endl;
	function3();
	cout << "function2 end" << endl;
}

void function1() {
	cout << "function1 start" << endl;
	function2();
	cout << "function1 end" << endl;
}

int main() {
	cout << "main start" << endl;
	function1();
	cout << "main end" << endl;
}           
~~~
결과
~~~
main start
function1 start
function2 start
function3 start
~~~
예외를 던진 이후 모두 종료됨

ex02
~~~cpp

~~~
