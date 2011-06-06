#include <iostream>
#include <vector>
using std::vector;
using namespace std;

    vector< vector<int> > givePosMove(short int *testPos) {
                vector< vector<int> > vec;

                if (testPos[0] + 1 >= 0 && testPos[0] + 1 < 8 && testPos[1] + 2 >= 0 && testPos[1] + 2 <8) {
                vector<int> row1;
                row1.push_back(testPos[0] + 1);
                row1.push_back(testPos[1] + 2);
                vec.push_back(row1);
                }
                if (testPos[0] + 2 >= 0 && testPos[0] + 2 < 8 && testPos[1] + 1 >= 0 && testPos[1] + 1 <8) {
                vector<int> row2;
                row2.push_back(testPos[0] + 2);
                row2.push_back(testPos[1] + 1);
                vec.push_back(row2);
                }
                if (testPos[0] + 2 >= 0 && testPos[0] + 2 < 8 && testPos[1] - 1 >= 0 && testPos[1] - 1 <8) {
                vector<int> row3;
                row3.push_back(testPos[0] + 2);
                row3.push_back(testPos[1] - 1);
                vec.push_back(row3);
                }
                if (testPos[0] + 1 >= 0 && testPos[0] + 1 < 8 && testPos[1] - 2 >= 0 && testPos[1] - 2 <8) {
                vector<int> row4;
                row4.push_back(testPos[0] + 1);
                row4.push_back(testPos[1] - 2);
                vec.push_back(row4);
                }

                if (testPos[0] - 1 >= 0 && testPos[0] - 1 < 8 && testPos[1] - 2 >= 0 && testPos[1] - 2 <8) {
                vector<int> row5;
                row5.push_back(testPos[0] - 1);
                row5.push_back(testPos[1] - 2);
                vec.push_back(row5);
                }
                if (testPos[0] - 2 >= 0 && testPos[0] - 2 < 8 && testPos[1] - 1 >= 0 && testPos[1] - 1 <8) {
                vector<int> row6;
                row6.push_back(testPos[0] - 2);
                row6.push_back(testPos[1] - 1);
                vec.push_back(row6);
                }
                if (testPos[0] - 2 >= 0 && testPos[0] - 2 < 8 && testPos[1] + 1 >= 0 && testPos[1] + 1 <8) {
                vector<int> row7;
                row7.push_back(testPos[0] - 2);
                row7.push_back(testPos[1] + 1);
                vec.push_back(row7);
                }
                if (testPos[0] - 1 >= 0 && testPos[0] - 1 < 8 && testPos[1] + 2 >= 0 && testPos[1] + 2 <8) {
                vector<int> row8;
                row8.push_back(testPos[0] - 1);
                row8.push_back(testPos[1] + 2);
                vec.push_back(row8);
                }
    return vec;
    } // end function

    // funtion returning the number of times squares have been played more than once
    short int checkBoard (short int BoardObj[8][8]) {
        short int numMultMoves = 0;
        for (int i=0; i<8; i++){
            for (int j=0; j <8; j++){
                if (BoardObj[i][j] > 1) {numMultMoves + (BoardObj[i][j] - 1);}
            }
        }
        return (numMultMoves);
    }

    // funtion returning the number of squares that have been played at least once
    short int checkDone (short int BoardObj[8][8]) {
        short int numDoneSqs = 0;
        for (int i=0; i<8; i++){
            for (int j=0; j <8; j++){
                if (BoardObj[i][j] > 0) {numDoneSqs++;}
            }
        }
        return (numDoneSqs);
    }


    // funtion removing possible moves that would land on an already played sqaure
    vector< vector<int> > remPlayedMoves(vector< vector<int> > &PosMoves, short int BoardObj[8][8]) {
        vector< vector<int> > newPosMoves;
        for (int i=0; i<PosMoves.size(); i++){
            if (BoardObj[PosMoves[i][0]][PosMoves[i][1]] <1) {
                vector<int> row;
                 row.push_back(PosMoves[i][0]);
                 row.push_back(PosMoves[i][1]);
                newPosMoves.push_back(row);
            }
        }

        return newPosMoves;
    }

    // funtion to print off Boards
    void printBoard(short int BoardObj[8][8]){
        cout<<"Board:\n";
        for (int x = 0; x < 8;x++ ) {
            for (int y = 0; y < 8; y++ ){
            cout<<BoardObj[x][y]<<" ";
            }
        cout<<"\n";
        }
    }

    int main()
    {
            // ******************
            // Init Variables
            short int xPos;
            short int yPos;
            short int currentPos[2];
            short int newPos[2];
            short int moveNum = 0;
            short int MaxMultMoves;
            short int CheckIfDone;
            short int numMultMoves;
            // Move vector list
            vector<int> allmovesX;
            vector<int> allmovesY;
            vector <vector< vector<int> > > posMoveList;

// ******************
// Create table with all starting positions
short int allStartPos[64][2];
short int StartPos[2];
short int test = 0;
for (int i=0; i < 8; i++){
    for (int j=0; j < 8; j++){
        allStartPos[(i*8 + j)][0] = i;
        allStartPos[(i*8 + j)][1] = j;
    }
}

for (MaxMultMoves = 0; MaxMultMoves < 1; MaxMultMoves++){
    for (int StartPosLoop=0; StartPosLoop<64; StartPosLoop++){

        // ******************
        // establish starting position
        StartPos[0] = allStartPos[StartPosLoop][0];
        StartPos[1] = allStartPos[StartPosLoop][1];
        cout<<"Starting Position:"<<StartPos[0]<<","<<StartPos[1]<<"\n";

        // ******************
        // set up boards
        short int Board[8][8];
        for (int x = 0; x < 8; x++ ) {
            for (int y = 0; y < 8; y++ )
                Board[x][y] = 0; // Set each element to a value
        }

        short int MoveNumBoard[8][8];
        for (int x = 0; x < 8; x++ ) {
            for (int y = 0; y < 8; y++ )
                MoveNumBoard[x][y] = 0; // Set each element to a value
        }

        // ******************
        // Set current pos and x y coords at starting position
        currentPos[0] = StartPos[0];
        currentPos[1] = StartPos[1];
        xPos = currentPos[0];
        yPos = currentPos[1];

        // ******************
        // Set starting position on Boards
        Board[xPos][yPos] = 1;
        MoveNumBoard[xPos][yPos] = 0;
        printBoard(Board);
        printBoard(MoveNumBoard);

        //******************
        //Start infinite loop
        while (true){
        //for (int i = 1; i < 100; i++){
            // get x and y pos from current position
            xPos = currentPos[0];
            yPos = currentPos[1];
            // add current pos to allmoves vector
            allmovesX.push_back(currentPos[0]);
            allmovesY.push_back(currentPos[1]);

            // new vector for possible moves
            vector< vector<int> > AllposMoves;
            // Calculate all possible moves from this position
            AllposMoves = givePosMove(currentPos);
            // calculate amt of squares played more than once on board
            numMultMoves = checkBoard(Board);
            // When the max amt of squares played more than once has been reached, remove any already played sqaures from possible moves
            if (numMultMoves >= MaxMultMoves){
                AllposMoves = remPlayedMoves(AllposMoves, Board);
            }

            /* if the posMoveList does not have a preexisting record of possible moves for this move, it creates it
            and the calculated possible moves are kept for this iteration*/
            if(posMoveList.size() < moveNum +1){
                posMoveList.push_back(AllposMoves);
            }
            /* if the posMoveList already has a record of possible moves for this move,
            but the # of possible moves are the same, posMoveList is unchanged and possible moves from
            posMoveList are kept for the interation. That said, this should never occur, it is merely a protection*/
            else if (AllposMoves.size() == posMoveList[moveNum].size()){
                AllposMoves = posMoveList[moveNum];
                cout<<"AHHHHHHH"<<"\n";
            }
            /* if the posMoveList already has a record of possible moves for this move,
            and the # of possible moves is different from the calculated possible moves, this means that
            the possible moves from posMoveList was truncated by moving backwards and so, to maintain the
            elimination of this possible move, possible moves from posMoveList are kept in this iteration*/
            else {
                AllposMoves = posMoveList[moveNum];
            }
            numMultMoves = checkBoard(Board);
            // what to do if there are no more moves possible
            if(AllposMoves.size() == 0){
                // remove this move from boards
                Board[xPos][yPos]--;
                MoveNumBoard[xPos][yPos] = 0;
                // remove this move from the move lists
                allmovesX.pop_back();
                allmovesY.pop_back();
                // set x and y coords and currentPos to previous move position
                xPos = allmovesX[allmovesX.size()-1];
                yPos = allmovesY[allmovesY.size()-1];
                currentPos[0] = xPos;
                currentPos[1] = yPos;
                // pop back a second time because x and y coords are added again at start of loop
                allmovesX.pop_back();
                allmovesY.pop_back();
                // remove possible moves for this move from posMoveList
                posMoveList.pop_back();
                // roll back move number
                moveNum--;
                // erase this move from possible moves for previous position (now currentPos)
                posMoveList[moveNum].erase(posMoveList[moveNum].begin());
                // if back at start pos, break
                if(currentPos[0] == StartPos[0] &&  currentPos[1] == StartPos[1] ){
                    cout<<"No Dice!";
                    break;
                }
                // return to beginning of loop
                continue;
            }
            // new position becomes 1st possible move
            currentPos[0] = AllposMoves[0][0];
            currentPos[1] = AllposMoves[0][1];
            xPos = currentPos[0];
            yPos = currentPos[1];

            // update board with new position and increase move number
            Board[xPos][yPos]++;
            moveNum++;
            MoveNumBoard[xPos][yPos] = moveNum;

            // Check if board is full
            CheckIfDone = checkDone(Board);
            // if board is full, print board and break
            if(CheckIfDone == 64){
                printBoard(Board);
            break;
            } // end if break
        } // end infinite loop

                if(CheckIfDone == 64){
                cout<<"Max. Mult. Moves:"<<MaxMultMoves<<", Move Number:"<<moveNum<<"\n";
                printBoard(MoveNumBoard);
                cout<<"Move Sequence :"<<"\n";
                for (int i=0; i < allmovesX.size(); i++){
                    cout<<allmovesX[i]<<","<<allmovesY[i]<<" ";
                }
                cout<<"\n";
                break;
                } // end if break

    } //end MaxMultMoves loop

} // end start pos loop

cin.get();
}
