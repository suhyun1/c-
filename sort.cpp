using namespace std;

#include <iostream>
#include <vector>
#include "sort.hpp"

//abstract Ŭ������ sort Ŭ���� 
//selection�� count�� sort ����ϰ�, radix�� count���

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
	//counting���� 0 ���� �����ϹǷ� radix���� �����������  
	
	for (int k = 1; k <= maxValue; k++) {
		temp = count[k];
		count[k] = count[k-1] + prev;
		prev = temp;

	}

	for (int i = 0; i < copy.size(); i++) 
		nums[count[getValue(copy[i])]++] =copy[i];
//	print(nums);

}	



Radix::Radix() :Counting(1){	//������ �ִ�  

	
}
int Radix::getValue(int value){
	
	value >>= curDigit; //curDigit��ŭ shift  
	return value %2;
	
	
}

void Radix::sort(vector<int> &nums) {
		
	
	int digits = sizeof(int)*8; //�������� �� ��Ʈ ����  
	for(curDigit=0;curDigit<digits ;curDigit++){
		
		Counting::sort(nums);
		print(nums);
		
	}
	
}
 

