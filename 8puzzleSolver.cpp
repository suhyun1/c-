#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <queue>
#include <stdlib.h>
#include <time.h>
#include <list>

using namespace std;

enum class Direction {
	south = 2, west = 4, east = 6, north = 8
};

class notMovable {};

class Puzzle {

protected:
	int numbers[3][3];
	int curRow, curCol;
public:
	Puzzle();
	void shuffle(int n);
	bool isDone();
	void move(Direction d);
	void print();
};

class DepthFirstPuzzle : public Puzzle {

protected:
	vector<string> waiting;	// stack 구현 
	unordered_set<string> history;
	string getState();
	void setState(string &state);
	bool isOld(string &state);

	//object 타입 보고 결정
	virtual void addwaiting(string &state);
	virtual string getCurrent();
	virtual bool isWaitingEmpty();

public:
	void solve();

};

bool DepthFirstPuzzle::isWaitingEmpty() {

	return waiting.empty();

}

class BreadthFirstPuzzle :public DepthFirstPuzzle {

protected:
	queue<string> que;

	void addwaiting(string &state);
	string getCurrent();
	bool isWaitingEmpty();

public:


};

//순서 최대한 짧게 하려면 heap이 최선이지만
//linked list 사용해보자 (list T사용)
class BestFirstPuzzle : public BreadthFirstPuzzle {
protected:
	list<string> mylist;

	void addwaiting(string &state);
	string getCurrent();
	bool isWaitingEmpty();
	int countDiff(string &state);
};


void BestFirstPuzzle::addwaiting(string &state) {

	mylist.push_back(state);
	history.insert(state);

}
string BestFirstPuzzle::getCurrent() {

	list<string>::iterator it, itbest;
	int diff;
	int mindiff =10; //모두 다른 상태에서는 9개가 다르므로 

	for (it = mylist.begin(); it != mylist.end(); ++it) {
		diff = countDiff(*it);

		if (diff < mindiff) {
			mindiff = diff;
			itbest = it;
		}

	}
	string found = *itbest;
	mylist.erase(itbest);

	return found;

	
}

int BestFirstPuzzle::countDiff(string &state) {

	int diff = 0;
	string answer = "123804765";
	for (int i = 0; i < 9; i++) {
		if (answer.at(i) != state.at(i))
			diff++;
	}
	return diff;
}
bool BestFirstPuzzle::isWaitingEmpty() {

	return mylist.empty();
}
bool BreadthFirstPuzzle::isWaitingEmpty() {

	return que.empty();

}
string DepthFirstPuzzle::getCurrent() {
	string last = waiting.back();
	waiting.pop_back();
	return last;
}

string BreadthFirstPuzzle::getCurrent() {
	string last = que.back();
	que.pop();
	return last;
}

void DepthFirstPuzzle::setState(string &state) {

	for (int i = 0; i < 9; i++) {
		int row = i / 3;
		int col = i % 3;
		numbers[row][col] = stoi(state.substr(i, 1));
		if (numbers[row][col] == 0) {
			curRow = row;
			curCol = col;
		}
	}
}

void DepthFirstPuzzle::solve() {
	string state = getState();
	addwaiting(state);

	while (!isWaitingEmpty()) {

		string cur = getCurrent();
		setState(cur);
		print();
		cout << endl;

		if (isDone()) {
			break;

		}
		else {
			try {
				move(Direction::north);
				string state = getState();

				if (!isOld(state))
					addwaiting(state);

				move(Direction::south);

			}
			catch (notMovable &e) {}
			try {
				move(Direction::south);
				string state = getState();

				if (!isOld(state))
					addwaiting(state);

				move(Direction::north);
			}
			catch (notMovable &e) {}

			try {

				move(Direction::west);
				string state = getState();

				if (!isOld(state))
					addwaiting(state);

				move(Direction::east);
			}
			catch (notMovable &e) {}

			try {
				move(Direction::east);
				string state = getState();
				if (!isOld(state))
					addwaiting(state);

				move(Direction::west);

			}
			catch (notMovable &e) {}

		}

	}

	cout << "Congratulation~!" << endl;

}



string DepthFirstPuzzle::getState() {

	string state = "";

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			state += to_string(numbers[i][j]);

	return state;

}

bool DepthFirstPuzzle::isOld(string &state) {

	unordered_set<string>::const_iterator got = history.find(state);

	if (got == history.end())
		return false;

	else
		return true;

}

void DepthFirstPuzzle::addwaiting(string &state) {

	waiting.push_back(state);
	history.insert(state);

}
void BreadthFirstPuzzle::addwaiting(string &state) {

	que.push(state);
	history.insert(state);
}

class Random {

public:

	static void init();
	static int getEvenNumber(int max);

};

void Random::init() {

	srand(time(NULL));
}

int Random::getEvenNumber(int max) {

	return rand() % max / 2 * 2 + 2;

}

Puzzle::Puzzle() {

	numbers[0][0] = 1;
	numbers[0][1] = 2;
	numbers[0][2] = 3;
	numbers[1][0] = 8;
	numbers[1][1] = 0;
	numbers[1][2] = 4;
	numbers[2][0] = 7;
	numbers[2][1] = 6;
	numbers[2][2] = 5;
	curRow = 1;
	curCol = 1;

}

void Puzzle::shuffle(int n) {

	int k;
	Random::init();

	for (int i = 0; i < n; ) {

		try {
			k = Random::getEvenNumber(8);
			move((Direction)k);
			i++;
		}

		catch (notMovable &e) {
		}
	}

}

bool Puzzle::isDone() {

	if (numbers[0][0] == 1 &&
		numbers[0][1] == 2 &&
		numbers[0][2] == 3 &&
		numbers[1][0] == 8 &&
		numbers[1][1] == 0 &&
		numbers[1][2] == 4 &&
		numbers[2][0] == 7 &&
		numbers[2][1] == 6 &&
		numbers[2][2] == 5)
		return true;

	else
		return false;

}

void Puzzle::move(Direction d) {

	int newRow, newCol, temp;
	switch (d) {
	case Direction::north:
		if (curRow == 0) throw notMovable();
		newRow = curRow - 1;
		newCol = curCol;
		break;

	case Direction::south:
		if (curRow == 2) throw notMovable();
		newRow = curRow + 1;
		newCol = curCol;
		break;

	case Direction::west:
		if (curCol == 0) throw notMovable();
		newRow = curRow;
		newCol = curCol - 1;
		break;

	case Direction::east:
		if (curCol == 2) throw notMovable();
		newRow = curRow;
		newCol = curCol + 1;
		break;

	default:
		throw notMovable();
	}

	temp = numbers[curRow][curCol];
	numbers[curRow][curCol] = numbers[newRow][newCol];
	numbers[newRow][newCol] = temp;
	curRow = newRow;
	curCol = newCol;

}



void Puzzle::print() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
			cout << numbers[i][j] << ' ';
		cout << endl;
	}
}


