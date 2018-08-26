#include "Board.h"

#include <limits>
#include <cstring>
#include "math.h"

using namespace std;

Board::Board()
{
}

Board::Board(char symbolPlayer1, char symbolPlayer2){

    this->playerSymbol1=symbolPlayer1;
    this->playerSymbol2=symbolPlayer2;

    createFieldForGame();
    setCountWinCharacters();

}
void Board::setCountWinCharacters(){
    bool  error = false;

    do
    {
        error=false;
        cout <<  "Please insert count of win characters:";
        cin >> countWinCharacters;

        if (cin.fail()||countWinCharacters<3||countWinCharacters>fieldSize)
        {
            cout << "Please enter a valid integer" << endl;
            error = 1;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cerr <<  "Input was not an integer!Input muss be >= 3." << endl;

        }
    }while(error);
}

void Board::printCurrentField(){
    cleanStream();
    cout<<"    ";
    for(int i=0;i<fieldSize;i++)
        cout<<i<<"   ";
    cout<<"\n";
    bool val = false;
    for(int i = 0; i < fieldSize; ++i){
        cout<<i << " | ";
        for(int j = 0; j < fieldSize; ++j){
            if(!val)
                cout << (char)board[i][j]<<" | ";

        }
        cout <<"\n";
    }
}
void Board::createFieldForGame(){
    bool error=false;
    do{

        error=false;
        cout <<  "Please insert size of field for playing NxN :";
        cin >> fieldSize;

        if (cin.fail())
        {
            cout << "Please enter a valid integer." << endl;
            error =true;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cerr <<  "Input was not an integer!Input muss be >= 10 !" << endl;

        }
        if(!error){


            board = new char*[this->fieldSize];
            for(int i = 0; i < this->fieldSize; ++i)
                board[i] = new char[this->fieldSize];
            for(int i=0; i<this->fieldSize; i++)
                for(int j=0; j<this->fieldSize; j++)
                    board[i][j] = Blank;
        }
    }while(error);
}
void Board::clearField(){
    for(int i = 0; i < this->fieldSize; i++)
        for(int j=0; j<this->fieldSize; j++)
            board[i][j]=Blank;
}
int Board::getFieldSize()
{
    return fieldSize;
}
bool Board::isWinnerByColumns(){
    bool isWinnerByColumn=false;
    int countSymbol=0;
    for(int column = 0; column < fieldSize; ++column){
        countSymbol=1;
        for(int row = 0; row < fieldSize; ++row){
            char symbol=board[row][column];
            int newrow=row+1;
            if(newrow<fieldSize&& newrow>=0 && symbol!=Blank){
                if((board[newrow][column]==symbol)){
                    countSymbol++;
                    if(countSymbol==countWinCharacters)
                        return true;
                }
                else
                    countSymbol=1;
            }
        }
        if(countSymbol==3)
            isWinnerByColumn=true;
    }
    return isWinnerByColumn;
}
bool Board::isWinnerByRows(){
    bool isWinnerByRows=false;
    int countSymbol=0;
    for(int row = 0; row < fieldSize; ++row){
        countSymbol=1;
        for(int column = 0; column < fieldSize; ++column){

            char symbol=board[row][column];
            if((column+1)<=fieldSize&& (column+1)>=0 && symbol!=Blank){
                if((board[row][column+1]==symbol)){
                    countSymbol++;
                    if(countSymbol==countWinCharacters)
                        return true;
                }  else
                    countSymbol=1;

            }

        }
        if(countSymbol==3)
            isWinnerByRows=true;
    }
    return isWinnerByRows;
}
bool Board::isSpaceAlreadyPlayed(int x,int y) {
    bool ret =false;

    char charInSpace= board[x][y];
    if( charInSpace ==this->playerSymbol1 ||  charInSpace == this->playerSymbol2)
        ret=true;

    return ret;
}
void Board::placeMoveOnPlayField(char playerSymbol, int x,int y){
    board[x][y]=playerSymbol;
}

bool Board::isWinnerByTopRigthToBottomLeftDiagonal() {
    bool ret = false;
    int countSymbol=1;

    for (int slice = 0; slice < 2 * fieldSize - 1; ++slice) {
        int z = (slice < fieldSize) ? 0 : slice - fieldSize + 1;
        for (int j = z; j <= slice - z; ++j) {
            char symbol= board[j][fieldSize-slice+j];
            int col=(fieldSize-slice+j+1);
            int row=j+1;
            if(col>=0&&col<fieldSize&&row<fieldSize){
                if(symbol==board[row][col]&&board[row][col]!=Blank){
                    countSymbol++;
                    if(countSymbol==countWinCharacters)
                        return true;
                }
                else{
                    countSymbol=1;
                }

            }

        }

    }





    return ret;
}

bool Board::isWinnerByBottemLeftToTopRightDiagonal() {
    bool ret = false;
    int countSymbol=1;
    for (int slice = 0; slice < 2 * fieldSize - 1; ++slice) {
        int z = (slice < fieldSize) ? 0 : slice - fieldSize + 1;
        for (int j = z; j <= slice - z; ++j) {
            char symbol=board[j][slice - j];
            int col=(slice-j-1);
            int row=j+1;
            if(col>=0 && col<fieldSize && row<fieldSize){
                if(symbol==board[row][col]&&board[row][col]!=Blank){
                    countSymbol++;
                    if(countSymbol==countWinCharacters)
                        return true;
                }
                else{
                    countSymbol=1;
                }

            }
        }
    }
    return ret;
}
bool Board::isWinner(){

    return isWinnerByColumns() || isWinnerByRows()||
            isWinnerByTopRigthToBottomLeftDiagonal()||
            isWinnerByBottemLeftToTopRightDiagonal();


}

//vec_tup Board::getAllAvailablePosition(){
//    vec_tup ret_vec;
//    for(int row=0;row<fieldSize;row++){
//        for(int column=0;column<fieldSize;column++){
//            if(board[row][column]!=Blank)
//                ret_vec.push_back(make_tuple(row,column));
//        }
//    }
//    return ret_vec;
//}
void Board::cleanStream() {
    //    while (getchar() != '\n');
    cout << "\x1B[2J\x1B[H";//vycistim konzolu
}

