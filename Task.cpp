#include<bits/stdc++.h>
using namespace std;

class Task {
public:
    char chessBoard[5][5];
    int life[] = {5, 5};

    void F_Board(string value) {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                chessBoard[i][j] = "-\t";
            }
        }
    }

    void Print_Res() {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                cout<<chessBoard[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    void Update_Board(int pos_[], char* key, char* move, int turn) {
        chessBoard[pos_[0]][pos_[1]] = "-";
        switch (move) {
            case "L":
                pos_[0] = pos_[0] - 1;
                pos_[1] = pos_[1] + 0;
                break;
            case "R":
                pos_[0] = pos_[0] + 1;
                pos_[1] = pos_[1] + 0;
                break;
            case "F":
                pos_[0] = pos_[0] + 0;
                pos_[1] = pos_[1] + 1;
                break;
            case "B":
                pos_[0] = pos_[0] + 0;
                pos_[1] = pos_[1] - 1;
                break;
            default: cout<<"Invalid Move"<<endl;
        }

        if (chessBoard[pos_[0]][pos_[1]] != "-") {
            if (turn == 1)
                life[1]--;
            else
                life[0]--;
        }

        chessBoard[pos_[0]][pos_[1]] = key;
        PrintMatrix();
    }

    void In_put() {
        for (int i = 0; i < 2; i++) {
            cout<<"Player "<< (i + 1)<<" Input:";
            char data[5];
            for (int j = 0; j < 5; j++) {
                cin>>data[j];
            }

            string temp = "";
            int index = 0;
            if (i == 0) {
                temp = "A";
                index = 4;
            } else {
                temp = "B";
                index = 0;
            }

            for (int k = 0; k < 5; k++) {
                chessBoard[index][k] = temp + "-" + data[k]+"\t";
            }
            PrintMatrix();
        }
    }

    int findpos_(string key) {
        int pos_[2];
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (strcmp(chessBoard[i][j],key)) {
                    pos_[0] = i;
                    pos_[1] = j;
                    return pos_;
                }
            }
        }
        return pos_;
    }
  };

  int main() {
      F_Board("-");
      In_put();

      int turn = 1;

      while(life[0] > 0 && life[1] > 0) {
          if (turn == 1) {
              cout<<"Player A's Move:\n";
              char* move;
              cin>>move;
              char* breakInput[] = strtok(move, ":");
              string key = "A-" + breakInput[0];
              int pos_[] = findpos_(key);
              Update_Board(pos_, key, breakInput[1], 1);
              if (life[1] == 0)
                  cout<<"A is winner";
              turn = 2;
          } else {
              cout<<"Player B's Move:";
              char* move;
              cin>>move;
              char* breakInput[] = strtok(move, ":");
              string key = "B-" + breakInput[0];
              int pos_[] = findpos_(key);
              Update_Board(pos_, key, breakInput[1], 1);
              if (life[0] == 0)
                  cout<<"B is winner";
              turn = 1;
          }
      }
  }
