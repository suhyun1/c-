# Objects, types, and values

### Input and Type
~~~cpp
#include <iostream>
#include <string>

using namespace std;

int main() {
	cout << "please enter your name (followed " << "by 'enter'):\n";	//연산의 결과는 cout (string op 계속 붙여도됨)
	string first_name;	//c++에서 string은 사용자정의 타입
	cin >> first_name;	// 연산결과 역시 cin. call by reference 타입
	cout << "hello, " << first_name << '\n';
}
~~~
\*

**c**의 scanf는 값을 바꾸기 위해 주소값에 접근해야했음, c는 call by value만 허용함. call by reference의 효과를 내기 위해 포인터 사용

**c++**은 call by value, reference 둘다 허용(메모리공간 공유)

**java**는 call by value만 허용. built-in 타입은 변수로, 사용자 정의 타입은 사실상 포인터(new 사용)
***
### Simple arithmetic
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

### Types

- char은 1byte, 아스키코드로 읽어짐 (ex. a- 97, A-65, 1-49)
- float, double:
 부동 소수점은 항상 1.xxx 곱하기 2의 x승'의 형식임 <br>ex) 1011.01(2) => 1.01101 곱하기 2의3승 <br>
 이것을 32bit(float)로 나타낼때, exp와 pre의 크기 정해져있음. <br>
 ~~~
 if(1==1/3*3)
 ~~~
 => 연산결과는 false, 1/3에서 소수점 잘림

- char의 array는 끝에 null

### Declaration and initialization
 선언하면 쓰레기값 들어있음 => 초기화
### Objects
실제 점유하고 있는 *메모리* 가 있는 경우에 object라고 할 수 있음
### Type safety
c/c++, java는 strong type check를 추구하지만 <br>
컴파일러가 어느정도의 오용은 허용해줌 => 형변환(암시적, 명시적)

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
