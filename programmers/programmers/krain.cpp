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
			//�ش� ĭ�� ���� ����
			if (board[j][classify] != 0) {
				if (!st.empty()) {
					//stack �� ���� ���ҿ� ���� ���� ������ ���� ���
					if (st.top() == board[j][classify]) {
						answer += 2;
						st.pop();
						board[j][classify] = 0;
						break;
					}
					//�ٸ� ���
					else {
						st.push(board[j][classify]);
						board[j][classify] = 0;
						break;
					}

				}
				//���ÿ� ���� ���� ���
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