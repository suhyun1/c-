class Sort {

public :	

	virtual void sort(vector<int> &nums) = 0;
	static void print(vector<int> &nums);

};

class Selection : public Sort {
public:
	virtual void sort(vector<int> &nums);	
};



class Counting : public Sort {
protected:
	int maxValue;
	virtual int getValue(int value);

public :	
	Counting(int max);

	virtual void sort(vector<int> &nums);	

};



class Radix : public Counting {
	int maxValue;
	int curDigit;

protected:

	virtual int getValue(int value);
public :

	Radix();
	virtual void sort(vector<int> &nums);		

};
