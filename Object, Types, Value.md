# Objects, types, and values

#####  C++의 call by reference
>c++ 은 call by value, reference 둘다 허용(메모리공간 공유)

C의 scanf는 값을 바꾸기 위해 주소값에 접근해야했음, c는 엄밀히 말해 call by value만 허용함. call by reference의 효과를 내기 위해 포인터 사용

JAVA는 call by value만 허용. built-in 타입은 변수로, 사용자 정의 타입은 사실상 포인터(new 사용)
### Input and Type
~~~cpp
#include <iostream>
#include <string>

using namespace std;

int main() {
	cout << "please enter your name (followed " << "by 'enter'):\n";
	//연산의 결과는 cout -> string op 계속 붙여쓸 수 있음
	string first_name;	//c++에서 string은 사용자정의 타입
	int age;
	cin >> first_name >> age;	// 연산결과 cin. call by reference 타입
	cout << "hello, " << first_name << "age" << age << '\n';
}
~~~
##### Operations in Integers and Strings
- '+' : string에선 이어붙이기, integer에선 더하기
- '++' ,'-' : string에선 둘다 error , integer에선 1 증가와 빼기
- '+=s' : string에선 끝에 s 붙이기, integer에선 int s 만큼 증가

> 변수의 타입은 어떤 operation이 유효하고 어떤 의미를 지니는지 결정해줌 <br>
=> 이것을 연선자 오버로딩


#### Simple arithmetic
~~~cpp
int main()
{
double n;
cin >> n;
cout << "n == " << n
<< "\nn+1 == " << n+1
//  연산자의 우선순위 '+'가 string op보다 높음
<< "\nthree times n == " << 3*n
// 연산자 우선순위 마찬가지
<< "\ntwice n == " << n+n
<< "\nn squared == " << n*n
<< "\nhalf of n == " << n/2
<< "\nsquare root of n == " << sqrt(n) // library function
<< '\n';
}
~~~
***
### Types

- char은 1byte, 아스키코드로 읽어짐 (ex. a- 97, A-65, 1-49)
- float, double:
 부동 소수점은 항상 1.xxx 곱하기 2의 x승'의 형식임 <br>ex) 1011.01(2) => 1.01101 곱하기 2의3승 <br>
 이것을 32bit(float)로 나타낼때, exponent(지수)와 fraction(가수)의 크기 정해져있음. => 아래와 같은 문제 발생
 ~~~
 if(1==1/3*3)	// 괄호안의 연산결과는 false
 // 1/3에서 소수점 잘리기 때문
 ~~~
- char의 array는 끝에 null

선언하면 쓰레기값 들어있음 => 초기화해라
#### Objects
실제 점유하고 있는 *메모리* 가 있는 경우에 object라고 할 수 있음
#### Type safety
> 모든 객체는 그 타입에 따라 사용됨.
<br>변수는 초기화 된 후 사용가능하고, 변수에 정의된 연산만이 가능하고, 모든 연산들은 그 변수에 유효한 값을 남긴다.

c/c++, java는 strong type check를 추구하지만 <br>
컴파일러가 어느정도의 오용은 허용해줌 => 형변환(암시적, 명시적) 가능

~~~cpp
//암시적 형변환
int main() {  
	int a = 20000;  char c = a;  int b = c;  
	if (a != b)    
		cout << "oops!: " << a << "!=" << b << '\n';  //이 줄 출력
	else   
		cout << "Wow! We have large characters\n";
}
~~~
결과
~~~
oops!: 20000!=32
~~~
