using namespace std;

#include <iostream>
#include <vector>
#include "sort.hpp"

//abstract 클래스인 sort 클래스 
//selection과 count가 sort 상속하고, radix가 count상속

// Sort class
void Sort::print(vector<int> &nums) {
	for (int i = 0; i < nums.size(); i++)
		cout << nums[i] << " ";
	cout << endl;

}

// Selection class

void Selection::sort(vector<int> &nums) {

	for (int i = 0; i < nums.size()-1; i++) {
		int min = nums[i];
		int minIndex = i;

		for (int j = i+1; j < nums.size(); j++) {
			if (nums[j] < min) {
				min = nums[j];
				minIndex = j;

			}

		}

		if (i != minIndex) {
			int temp = nums[i];
			nums[i] = nums[minIndex];
			nums[minIndex] = temp;

		}	
	}
}

Counting::Counting(int max) {
	maxValue = max;

}

int Counting::getValue(int value){
	return value;
	
}
void Counting::sort(vector<int> &nums) {
	cout << "radix max :" << maxValue << endl;
	
	int *count = new int[maxValue+1]();
	vector<int> copy(nums);	

	for (int i = 0; i < copy.size(); i++){
		count[getValue(copy[i])]++;

	}
		
		
	int prev = count[0];
	int temp;
	count[0] =0;
	//counting에선 0 등장 무시하므로 radix에서 고쳐줘야했음  
	
	for (int k = 1; k <= maxValue; k++) {
		temp = count[k];
		count[k] = count[k-1] + prev;
		prev = temp;

	}

	for (int i = 0; i < copy.size(); i++) 
		nums[count[getValue(copy[i])]++] =copy[i];
//	print(nums);

}	



Radix::Radix() :Counting(1){	//이진수 최댓값  

	
}
int Radix::getValue(int value){
	
	value >>= curDigit; //curDigit만큼 shift  
	return value %2;
	
	
}

void Radix::sort(vector<int> &nums) {
		
	
	int digits = sizeof(int)*8; //이진수로 몇 비트 볼지  
	for(curDigit=0;curDigit<digits ;curDigit++){
		
		Counting::sort(nums);
		print(nums);
		
	}
	
}
 

