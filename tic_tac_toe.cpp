// TIC TACO TOE GAME. NxN arr


#include <iostream>
#include <cstdlib>  // για system cls

using namespace std;

#define N 3

class tic{
    public:

        tic();  // constructor '-'
        ~tic(); // destructor

        //play method
        void play(int x, int y, char &ref_pl);   

        // check if someone won
        bool check_win();

        // print table
        void print_game();
        
    private:
        char arr[N][N];
};



int main(){

    tic gm;
    char pl = 'X';

    int x,y;
    
    
    
    while(1){
        
        system("cls");
        gm.print_game();
        cout<<"PLAYER "<<pl<<" PLAYS: ";
        cin >> x >> y;

        gm.play(x, y, pl); 
        if( gm.check_win() )    break;

        pl = ( pl == 'X' ) ? 'O' : 'X'; // Α΄λλαγη παικτη
        
    }
    
     
    return 0;   // deconstructing
}


// constructor
tic::tic(){

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++)  
            arr[i][j] = '-';
    }
}

// destructor
tic::~tic(){
    cout<<"\n\n"<<"Deconstructing"<<endl;
}

// printing method
void tic::print_game(){
    cout<<"\n";
    for(int i=0; i<N; i++){
        cout<<"\n";
        for(int j=0; j<N; j++)  
            cout<<arr[i][j]<< "\t";   
    }
    cout<<"\n\n";
}

//playing method
void tic::play(int x, int y, char &ref_pl){

    while(1){

        while( ( x>=N || x<0 ) || ( y>=N || y<0 )  ){
            system("cls");
            cout<<"\n"<<"The space you requested is out of limits"<<endl;
            cout<<"Please try again"<<endl;
            print_game();
            cout<<"PLAYER "<<ref_pl<<" PLAYS: ";
            cin >> x >> y;
        }
        if(arr[x][y]=='-'){
            arr[x][y] = ref_pl;
            break;
        }
        else{
            system("cls");
            cout<<"\n"<<"The requested space is already occupied with: "<<arr[x][y]<<endl;
            cout<<"Please try again"<<endl;
            print_game();
            cout<<"PLAYER "<<ref_pl<<" PLAYS: ";
            cin >> x >> y;
        }
    }
}

//checking method
bool tic::check_win(){

    int x_count,y_count;

    // rows(γραμμες)
    for(int i=0; i<N ; i++){
        x_count = 0;
        y_count = 0;
        for(int j=0; j<N; j++){
            if(arr[i][j]=='X')      x_count++;
            if(arr[i][j]=='O')      y_count++;                

            if( x_count>=1 && y_count>=1 )  // δεν υπαρχει περιπτωση να βγει θετικο ποτε
                break;
            else if( x_count == N ){
                cout<<"\nX WON!";
                print_game();
                return true;
            }
            else if( y_count == N ){
                cout<<"\nO WON!";
                print_game();
                return true;
            }
        }    
    }

    // columns(στηλες)
    for(int j=0; j<N; j++){
        x_count = 0;
        y_count = 0;
        for(int i=0; i<N; i++){
            if(arr[i][j]=='X')      x_count++;
            else if(arr[i][j]=='O') y_count++;                

            if( x_count>=1 && y_count>=1 )  // δεν υπαρχει περιπτωση να βγει θετικο ποτε
                break;
            else if( x_count == N ){
                cout<<"\nX WON!";
                print_game();
                return true;
            }
            else if( y_count == N ){
                cout<<"\nO WON!";
                print_game();
                return true;
            }
        }
    }

    //main diagonal
    x_count = 0;
    y_count = 0;
    for(int i=0; i<N; i++){
        if(arr[i][i] == 'X')      x_count++;
        else if(arr[i][i] == 'O') y_count++;

            if( x_count>=1 && y_count>=1 )  // δεν υπαρχει περιπτωση να βγει θετικο ποτε
                    break;
            else if( x_count == N ){
                    cout<<"\nX WON!";
                    print_game();
                    return true;
            }
            else if( y_count == N ){
                    cout<<"\nO WON!";
                    print_game();
                    return true;
            }
    }
    


    // reverse diagonal
    x_count = 0;
    y_count = 0;
    for(int i=0; i<N; i++){
        if(arr[i][N-1-i] == 'X')      x_count++;
        else if(arr[i][N-1-i] == 'O') y_count++;

        if( x_count>=1 && y_count>=1 )  // δεν υπαρχει περιπτωση να βγει θετικο ποτε
            break;
        else if( x_count== N ){
                cout<<"\nX WON!";
                print_game();
                return true;
        }
        else if( y_count== N ){
            cout<<"\nO WON!";
            print_game();
            return true;
        }
    }

    bool draw = true;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if ( arr[i][j] == '-' ){
                draw = false;
                break;
            }
        }
        if (!draw) break;
    }

    if (draw){
        cout<<"\nIts a Draw"<<endl;
        print_game();
        return true;
    }
    return false;
}