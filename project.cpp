#include<bits/stdc++.h>
using namespace std;
bool check(vector<vector<char>>&board, int i, int j, char idx){
        for(int id=0; id<=8 ; id++){
            if(board[id][j]==idx) return 0;    
            
            if(board[i][id]==idx) return 0;
            
            int one=3*(i/3)+id/3,two=3*(j/3)+id%3;

            if(board[one][two]==idx) return 0;   
        }
        return 1;
}
bool solve(vector<vector<char>>&ch){
    for(int i=0 ; i<9 ; i++){
        for( int j=0 ; j<9 ; j++){
            if(ch[i][j]=='.'){
                for(char idx='1' ; idx<='9' ; idx++){
                    if(check(ch,i,j,idx)){
                        ch[i][j]=idx;
                        if(solve(ch)) return true;
                        else ch[i][j]='.';
                    }
                }
                return false;
            }
        }
    }
    return true;    
}
int main(){
    cout<<"Welcome to SODUKU SOLVER \n";
    cout<<"Giver me some Puzzle \n";
    while(1){
        cout<<"Press 1 to start and 0 for exit \n";
        int f; cin>>f;
        if(f==1){
            cout<<"# Note:\nFill the cell values between 1 to 9 and for empty cell fill '.' \n";
            vector<vector<char>>ch(9,vector<char>(9));
            for(int i=0 ; i<9 ; i++){
                for(int j=0 ; j<9 ; j++){
                    cin>>ch[i][j];
                }
            }
            solve(ch);
            cout<<"-------------------------------------------------------SOLVED--------------------------------------------------------------"<<"\n";
            for(int i=0; i<9 ; i++){
                for(int j=0 ; j<9 ; j++){
                    cout<<ch[i][j]<<" ";
                }
                cout<<"\n";
            }
        }
        else if(f==0) break;
    }
    return 0;
}