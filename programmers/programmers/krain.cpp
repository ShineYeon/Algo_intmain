#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0;
	stack<int> st;

	for (int i = 0; i < moves.size(); i++) {
		int classify = moves[i] - 1;
		
		for (int j = 0; j < board.size(); j++) {
			//해당 칸에 인형 있음
			if (board[j][classify] != 0) {
				if (!st.empty()) {
					//stack 맨 위의 원소와 현재 보는 인형이 같은 경우
					if (st.top() == board[j][classify]) {
						answer += 2;
						st.pop();
						board[j][classify] = 0;
						break;
					}
					//다른 경우
					else {
						st.push(board[j][classify]);
						board[j][classify] = 0;
						break;
					}

				}
				//스택에 인형 없는 경우
				else {
					st.push(board[j][classify]);
					board[j][classify] = 0;
					break;
				}
			}
		}
	}
	return answer;
}

int main() {
	vector<vector<int>> board;
	vector<int> a1;
	a1.push_back(0);
	a1.push_back(0);
	a1.push_back(0);
	a1.push_back(0);
	a1.push_back(0);
	vector<int> a2;
	a2.push_back(0);
	a2.push_back(0);
	a2.push_back(1);
	a2.push_back(0);
	a2.push_back(3);
	vector<int> a3;
	a3.push_back(0);
	a3.push_back(2);
	a3.push_back(5);
	a3.push_back(0);
	a3.push_back(1);
	vector<int> a4;
	a4.push_back(4);
	a4.push_back(2);
	a4.push_back(4);
	a4.push_back(4);
	a4.push_back(2);
	vector<int> a5;
	a5.push_back(3);
	a5.push_back(5);
	a5.push_back(1);
	a5.push_back(3);
	a5.push_back(1);
	board.push_back(a1);
	board.push_back(a2);
	board.push_back(a3);
	board.push_back(a4);
	board.push_back(a5);

	vector<int> moves;
	moves.push_back(1);
	moves.push_back(5);
	moves.push_back(3);
	moves.push_back(5);
	moves.push_back(1);
	moves.push_back(2);
	moves.push_back(1);
	moves.push_back(4);

	cout << solution(board, moves);
}