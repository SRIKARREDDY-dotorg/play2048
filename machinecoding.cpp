#include<bits/stdc++.h>
using namespace std;

class Slide{
    public:
        int matrix[4][4];
        //a constructor to initialize the matrix elements to 0
        Slide();
        // member functions to place the slide in a matrix
        void placeslide(int x,int y);    
        //check if the cell is empty
        bool issafe(int x,int y);
        //print the slides in a matrix
        void print_matrix();
        //check if the matrix has empty cell
        bool checkempty();
        //slide the matrix elements in a matrix
        bool movement(int dir);

        bool Gamestatus();
};


Slide::Slide(){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            matrix[i][j]=0;
            //cout<<matrix[i][j]<<" ";
        }
        //cout<<endl;
    }
}

void Slide::placeslide(int x,int y){
    matrix[x][y]=2;
}

bool Slide::issafe(int x,int y){
    if(matrix[x][y]){
        return 0;
    }
    return 1;
}

void Slide::print_matrix(){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool Slide::checkempty(){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(!matrix[i][j]) return 1;
        }
    }
    return 0;
}

bool Slide::Gamestatus(){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(matrix[i][j]==2048) return 1; 
        }
    }
    return 0;
}

bool Slide::movement(int dir){
    
    if(dir==0){
        bool move=0;
        queue<int>merge;
        vector<int>v;
        int a,b;
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                if(matrix[i][j]) merge.push(matrix[i][j]);
                matrix[i][j] =0;
            }
            while(!merge.empty()){
                a=merge.front();
                merge.pop();
                if(merge.empty()){
                    v.push_back(a);
                    break;
                }
                b=merge.front();
                if(a==b){
                    merge.pop();
                    merge.push(a+b);

                }else{
                    v.push_back(a);
                }
            }
            if(v.size()<4)move=1;
            for(int j=0;j<v.size();j++){
                matrix[i][j]=v[j];
            }
            v.clear();
        }
        return move;
    }

    if(dir==1){
        bool move=0;
        queue<int>merge;
        vector<int>v;
        int a,b;
        for(int i=0;i<4;i++){
            for(int j=3;j>=0;j--){
                if(matrix[i][j]) merge.push(matrix[i][j]);
                matrix[i][j]=0;
            }
            while(!merge.empty()){
                a=merge.front();
                merge.pop();
                if(merge.empty()){
                    v.push_back(a);
                    break;
                }
                b=merge.front();
                if(a==b){
                    merge.pop();
                    merge.push(a+b);

                }else{
                    v.push_back(a);
                }
            }
            if(v.size()<4)move=1;
            for(int j=3;j>=(4-v.size());j--){
                matrix[i][j]=v[4-j-1];
            }
            v.clear();
        }
        return move;
    }

    if(dir==3){
        bool move=0;
        queue<int>merge;
        vector<int>v;
        int a,b;
        for(int j=0;j<4;j++){
            for(int i=3;i>=0;i--){
                if(matrix[i][j]) merge.push(matrix[i][j]);
                matrix[i][j] =0;
            }
            while(!merge.empty()){
                a=merge.front();
                merge.pop();
                if(merge.empty()){
                    v.push_back(a);
                    break;
                }
                b=merge.front();
                if(a==b){
                    merge.pop();
                    merge.push(a+b);

                }else{
                    v.push_back(a);
                }
            }
            if(v.size()<4)move=1;
            for(int i=3;i>=(4-v.size());i--){
                matrix[i][j]=v[4-i-1];
            }
            v.clear();
        }
        return move;
    }

    if(dir==2){
        bool move=0;
        queue<int>merge;
        vector<int>v;
        int a,b;
        for(int j=0;j<4;j++){
            for(int i=0;i<4;i++){
                if(matrix[i][j]) merge.push(matrix[i][j]);
                matrix[i][j] =0;
            }
            while(!merge.empty()){
                a=merge.front();
                merge.pop();
                if(merge.empty()){
                    v.push_back(a);
                    break;
                }
                b=merge.front();
                if(a==b){
                    merge.pop();
                    merge.push(a+b);

                }else{
                    v.push_back(a);
                }
            }
            if(v.size()<4)move=1;
            for(int i=0;i<v.size();i++){
                matrix[i][j]=v[i];
            }
            v.clear();
        }
        return move;
    }
}

int main(){
    Slide sld;
    //get the random slide 
    srand(time(0));
    int x=rand()%4;
    int y=rand()%4;
    sld.placeslide(x,y);
    while(!sld.issafe(x,y)){
        x=rand()%4;
        y=rand()%4;
    }
    //cout<<x<<" "<<y<<endl;
    sld.placeslide(x,y);
    printf("Your Game started!\n");
    sld.print_matrix();
    printf("PRESS 0 to move left\n");
    printf("PRESS 1 to move right\n");
    printf("PRESS 2 to move top\n");
    printf("PRESS 3 to move bottom\n");
    int dir;
    bool win=0;
    while(sld.checkempty()){
        cin>>dir;
        if(sld.movement(dir)){
            if(sld.Gamestatus()){
                cout<<"Hurrah! you won the match!"<<endl;
                win=1;
            }
            while(!sld.issafe(x,y)){
                x=rand()%4;
                y=rand()%4;
            }
            sld.placeslide(x,y);
            sld.print_matrix();
            x=rand()%4;
            y=rand()%4;
        }

    }
    if(!win) cout<<"Gameover"<<endl;
    return 0;
}