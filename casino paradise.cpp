#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
#include<stdlib.h>
#include<string>
#include<string.h>
#include<conio.h>
using namespace std;
int bet_innew;
int loss=0,gain=0,waggered=0;
int bet_in=100;
class game1{
	public:
void matka(){
	cin.ignore();
	int user, open1, open2, open3, close1, close2, close3,betamt,winamt=0;
    for (int j = 0; j < 100; j++) {
        cout <<"\t " << j;
    }
    do {
        cout << "\nChoose your bet amount:\n10$, 50$, 100$, 500$, 1000$\n";
        cin >> betamt;
        
        if (betamt != 10 && betamt != 50 && betamt != 100 && betamt != 500 && betamt != 1000) {
            cout << "Enter a proper bet.\n";
        } else if (bet_in - betamt < 0) {
            cout << "Insufficient balance . Try again.\n";
        } else {
            bet_in -= betamt;
			waggered+=betamt; 
            break; 
        }
    } while (true);
    
    cout << " \n\n choose  your number: \n";
    cin >> user;
    srand(static_cast<unsigned int>(time(0))); 
   
    close1 = rand() % 10;
    close2 = rand() % 10;
    close3 = rand() % 10;

   
    int close = close1 + close2 + close3;
    int closef = close % 10;

   
    open1 = rand() % 10;
    open2 = rand() % 10;
    open3 = rand() % 10;

   
    int open = open1 + open2 + open3;
    int openf = open % 10;
    int fdigit = (openf * 10) + closef;

   
    cout << "Open numbers = " << open1 << " " << open2 << " " << open3 << endl;
    cout << "Close numbers = " << close1 << " " << close2 << " " << close3 << endl;
    cout << "Number is " << fdigit << endl;

   
    if (fdigit == user)
       {
          winamt=betamt*10;
        cout << "You win  $"<<winamt<<endl;
		bet_in=bet_in+(betamt*10);
		gain++;
		}
    else{
    	
        cout << "You lose! \n";
		loss++;
    }
        
        cout<<"Your balance is $"<<bet_in<<endl;

}
};
class game2:public game1{
public:
void dice_spice(){
	
	int dice1,dice2,bet;
	int user,sum=0,choice,mul=0;
	cout<<"Welcome to Dice spice \n \n";
	cout<<" \t Bets are on multiple, indivisual and sum \n\n";
 do {
        cout << "Enter your bet\n";
        cin >> bet;

        if (bet_in - bet < 0) {
            cout << "You have insufficient balance...try again\n";
        } else {
            bet_in -= bet; 
            waggered+=bet;
            break; 
        }
    } while (true);

	
	do{
	cout<<"Enter your number \n";
	cin>>user;
	if(user<1||user>36)
	cout<<"Enter proper number between 1-12 \n";
	}while(user<1||user>36);
	
	
	 srand(static_cast<unsigned int>(time(0)));
	 dice1=(rand()%6)+1;
	dice2=(rand()%6)+1;
	sum=dice1+dice2;
	mul=dice1*dice2;
	cout<<"\n Dice 1 = "<<dice1<<"\n Dice 2 = "<<dice2<<" \n Sum of dice = "<<sum<<"\n Multiple of dice = "<<mul<<endl;
	
	if(user==dice1){
		cout<<"\n\n Your choice matches dice 1 \n";cout<<" You win 5x"<<endl;
		bet*=5;bet_in+=bet;
		gain++;
	}
	else if(user==dice2){
		cout<<"\n\n Your choice matches dice 2 \n";cout<<" You win 5x"<<endl;
		bet=bet_in*5;bet_in+=bet;
		gain++;
	}
	else if(user==sum){
		cout<<"\n\n Your choice matches the sum \n";cout<<" You win 3x"<<endl;
		bet*=3;bet_in+=bet;
		gain++;
	}
	else if(user==mul){
		cout<<"\n\n Your choice matches dice 1 \n";cout<<" You win 8x"<<endl;
		bet*=8;bet_in+=bet;
		gain++;
	}

	else{
		
	 cout<<"\n No bets won \n Your balance is $"<<bet_in<<endl;
	 loss++;
	 }
	
}
};
class game3:public game2{
	public:
void high_low(){
	char user;
	int comp1;
	int bett;
	
	srand(static_cast<unsigned int>(time(0)));
	comp1=(rand()%500)+1;
    
    int comp2;
    cout<<"Welcom to High_low \n" ;
	 do {
        cout << "Enter your bet\n";
        cin >> bett;

        if (bet_in - bett < 0) {
            cout << "You have insufficient balance...try again\n";
        } else {
            bet_in -= bett; 
            waggered+=bett;
            break; 
        }
    } while (true);
    cout<<"The number appeared is "<<comp1<<endl<<endl;
    cout<<"Will the nect number be high or low \n Type 'h' or 'l' \n";cin>>user;
    comp2=rand()%500;
    cout<<"The number is "<<comp2<<endl;
    if(user=='h'&&comp2>comp1 || user=='l'&&comp1>comp2){
    	cout<<"You win"<<endl;
    	bet_in+=(bett*2);
    	cout<<"Balance = $ "<<bet_in<<endl;
    	gain++;
    	
    }
    else {cout<<"try again \n";loss++;}
    cout<<"Your balance is $"<<bet_in<<endl<<endl;
    
}
void report(){
	int profit=0;
	profit=bet_in-100-bet_innew;
	
	cout<<"Number of bets won = "<<gain<<endl;
	cout<<"Number of bets lost = "<<loss<<endl;
	cout<<"Money waggered = "<<waggered<<endl;
	if(profit<0){
		cout<<"You are in loss of $"<<profit<<endl;
	}
	else if(profit==0){
		cout<<"You balance is 0$ \n";
	}
	else{
	cout<<"Total profit earned = "<<profit<<endl;}
	cout<<"Total bets played = "<<gain+loss<<endl;
}
void lucky_dip(){
	int bet,num[7],ran[7],win=0,nowin=0;
	do {
        cout << "Enter your bet\n";
        cin >> bet;

        if (bet_in - bet < 0) {
            cout << "You have insufficient balance...try again\n";
        } else {
            bet_in -= bet; 
            waggered+=bet;
            break; 
        }
    } while (true);
    
    cout<<"Enter your 6  lucky numbers \n";
    for(int i=0;i<6;i++){
    	scanf("%d",&num[i]);
    }
    cout<<"\n Enter your bonus number \n";cin>>num[5];
  
    for (int j = 0; j < 7; j++) {
        ran[j] = rand() % 60 + 1;  
    }
	cout << "\nGenerated random numbers:\n";
    for (int j = 0; j < 7; j++) {
        cout << ran[j] << " ";
    }
    cout << endl;
    for (int i = 0; i < 7; i++) {
        int matchCount = 0;  
        for (int j = 0; j < 7; j++) {
            if (num[i] == ran[j]) {
                win++;
            }
        }
        if (matchCount == 0) {
            nowin++;
            
        }
    }
    switch(win){
    	case 1: cout<<"You have 1 match \n";gain++;bet*=1.20;break;
    	case 2: cout<<"You have 2 matches \n";gain++;bet*=2;break;
    	case 3: cout<<"You have 3 matches \n";gain++;bet*=3;break;
    	case 4: cout<<"you have 4 matches \n";gain++;bet*=4;break;
    	case 5: cout<<"you have 5 matches \n";gain++;bet*=5;break;
    	case 6: cout<<"you have 6 matches \n";gain++;bet*=100;break;
    	case 0: cout<<"no wins \n";loss++;break;
    	deafult:cout<<"Error compiling \n";
    }
    bet_in+=bet;
}
};

//roulette code starts here.


void roulette_col();
void roulette_eoo();

int choice_r;
int arr_red[] = { 1,3,5,7,9,12,14,16,18,19,21,23,25,27,30,32,34,36 };
int arr_black[] = { 2,4,6,8,10,11,13,15,17,20,22,24,26,28,29,31,33,35 };
int total[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36};



void roulette_row()
{int bet;
	cout<<"ROW 1:   ";
	for(int i = 0; i<12;i++)
	{
		cout<<total[i]<<"\t";
	}
cout<<endl<<endl;
	cout<<"ROW 2:   ";
	for(int i =12; i<24;++i)
	{
		cout<<total[i]<<"\t";
	}
cout<<endl<<endl;
	cout<<"ROW 3:   ";
	for(int i = 24; i<36;++i)
	{
		cout<<total[i]<<"\t";
	}
	cout<<endl<<endl;
do {
        cout << "Enter your bet\n";
        cin >> bet;

        if (bet_in - bet < 0) {
            cout << "You have insufficient balance...try again\n";
        } else {
            bet_in -= bet; 
            waggered+=bet;
            break; 
        }
    } while (true);
	int chr_r;
	cout<<"Enter a the ROW number (1,2,3): ";
	cin>>chr_r;

if(chr_r >0  || chr_r < 4)
{
	
	srand(static_cast <unsigned int>(time(0)));
	int ran_rr = total[rand() % sizeof(total)/(sizeof(total[0]))];
	cout<<ran_rr<<endl;
	int bet;
    
	for(int i = 0; i<12;i++)
	{
		if(ran_rr == total[i])
		{
			if(chr_r == 1)
			{
				cout<<"You win "<<endl;		
				bet= bet*1.8;
				bet_in+=bet;
				cout<<" You win : "<<bet;
				gain++;
					}
			else {cout<<"\n\n Better luck next time\n\n";
			loss++;

			}
		}
		
	}

	for(int i =12; i<24;++i)
	{
		if(ran_rr == total[i])
		{
			if(chr_r == 2)
			{
				cout<<"You win "<<endl;
				bet = bet*1.8;
				bet_in+=bet;
				gain++;
				cout<<"Your score is: "<<bet_in;
			}
			else {cout<<"\n\n Better luck next time\n\n";
			loss++;
}
		}
	}

for(int i = 24; i<36;++i)
	{
		if(ran_rr == total[i])
		{
			if(chr_r == 3)
			{
				cout<<"Its ROW "<<chr_r<<endl;
				bet_in = bet_in*1.8;gain++;
				cout<<"Your score is: "<<bet_in;
			}
			else {cout<<"\n\n   The row is: 3  \nBetter luck next time\n\n";
			loss++;
cout<<"Your score: "<<bet_in;}
		}
	}
}


else {
	cout<<"\n\n Invalid Input! \n\n";
	return;
}

}

void roulette_num()
{
int num;
cout << "Enter a number: ";
cin >> num;

if (num > 36 || num < 0)
{
cout << "Invalid Input!";
return;
}
srand(static_cast<unsigned int>(time(0)));
int r_num = total[rand() % (sizeof(total)/sizeof(total[0]))];
cout<<"The number is: "<<r_num<<endl<<endl;
int bet;
do {
        cout << "Enter your bet\n";
        cin >> bet;

        if (bet_in - bet < 0) {
            cout << "You have insufficient balance...try again\n";
        } else {
            bet_in -= bet; 
            waggered+=bet;
            break; 
        }
    } while (true);
if(num == r_num)
{
	cout<<endl<<"HORRAY! You won!"<<endl<<endl;
	bet = bet*1.8; bet_in+=bet;gain++;
				
}
else {cout<<"Sorry! Better Luck Next Time"<<endl;
loss++;
}
}

void roulette_col()
{
	int bet;
	char co_r;
	char c = '0';
do {
        cout << "Enter your bet\n";
        cin >> bet;

        if (bet_in - bet < 0) {
            cout << "You have insufficient balance...try again\n";
        } else {
            bet_in -= bet; 
            waggered+=bet;
            break; 
        }
    } while (true);
cout<<"Enter your color Red or Black(R/B): ";
cin>>co_r;

if(co_r == 'r' || co_r == 'R' || co_r == 'b' || co_r == 'B')
{
	srand(static_cast<unsigned int>(time(0)));
	int r_num = total[rand() % (sizeof(total)/(sizeof(total[0])))];
	
	for(int i = 0; i < sizeof(arr_red) / sizeof(arr_red[0]); i++)
	{
		if(arr_red[i] == r_num)
		{
			 c = 'R';	
		}
	}
	for(int i =0; i < sizeof(arr_black) / sizeof(arr_black[0]); i++)
	{
	
	  if(arr_black[i] == r_num)
	  {
  		 c = 'B';
  	   }
	}
	
	if(c == 'R')
	{
		if(co_r == 'r' || co_r == 'R')
		{
		cout<<"Color is  red you win "<<endl;
		bet = bet*1.8;bet_in+=bet;
				cout<<"Your balance is $"<<bet_in;
		}
		else {
			cout<<" BLACK ";
			
		}
	}
	else if(c == 'B')
	{
		if(co_r == 'b' || co_r == 'B')
		{
			cout<<"Color is  Black you win "<<endl;
			bet = bet*1.8;bet_in+=bet;gain++;
				
		}
		else {
			cout<<" RED  Sorry! Better Luck Next Time"<<endl;loss++;
			
            
		}
	}


}

else {
cout<<endl<<endl<<"Invalid input!"<<endl;
return;
}

}

void roulette_eoo()
{
	int bet;
	char co_r;
do {
        cout << "Enter your bet\n";
        cin >> bet;

        if (bet_in - bet < 0) {
            cout << "You have insufficient balance...try again\n";
        } else {
            bet_in -= bet;
			waggered+=bet; 
            break; 
        }
    } while (true);
cout<<"Enter your color ODD or EVEN(O/E): ";
cin>>co_r;
if(co_r == 'o' || co_r == 'O' || co_r == 'e' || co_r == 'E')
{
	srand(static_cast<unsigned int>(time(0)));
	int r_num = total[rand() % (sizeof(total)/(sizeof(total[0])))];
	
	if(r_num % 2 == 0)
	{
		if(co_r == 'e' || co_r == 'E')
		{
		cout<<r_num<<" is Even  YOU WON!"<<endl;
		bet = bet*1.8;bet_in+=bet;
		gain++;
			
		}
		else {cout<<r_num<<"Better Luck Next Time";
		loss++;

		}
	}
	else if(r_num % 2 != 0)
	{
		if(co_r == 'O' || co_r == 'o')
		{
		cout<<r_num<<" is odd  YOU WON!"<<endl;
		bet = bet*1.8;bet_in+=bet;gain++;
				
		}
		else {cout<<r_num<<" Better Luck Next Time";
		loss++;
		
		}
	}

}
}


void roulette_input()
{
	do{
		cout<<"\n\n";
cout << "1. NUMBER" << endl;
cout << "2. RED OR BLACK" << endl;
cout << "3. EVEN OR ODD" << endl;
cout<<"4. Row \n";
cout<<"5. to exit roulette \n";
cout << "Enter a choice: ";
cin >> choice_r;
switch(choice_r){
	case 1: roulette_num();break;
	case 2: roulette_col();break;
	case 3:roulette_eoo();break;
	case 4:roulette_row();break;
	default:cout<<"try again \n";
}}while(choice_r!=5);
}

void roulette_display()
{

cout << "Red: ";
for (int i = 0; i < (sizeof(arr_red) / sizeof(arr_red[0])); i++)
{
cout<<setw(7)<< arr_red[i]<<"\t";
}
cout << endl << endl << "Black: ";
for (int i = 0; i < (sizeof(arr_black) / sizeof(arr_black[0])); i++)
{
cout<<setw(7) << arr_black[i] << "\t";
}
}

// sports bet code starts from here

string team1,team2;
int score[] = {0,1,2,3,4,5},bet,choice;
int score2[] = {5,4,3,2,1};
float so = 100;
char pre_f;
void sports_pr()
{
int n1,n2;
do {
        cout << "Enter your bet\n";
        cin >> bet;

        if (bet_in - bet < 0) {
            cout << "You have insufficient balance...try again\n";
        } else {
            bet_in -= bet; 
            waggered+=bet;
            break; 
        }
    } while (true);
cout<<"Predict the score: "<<endl<<endl<<"team A"<<" ";
cin>>n1;
cout<<endl<<endl<<"team B"<<" ";
cin>>n2;

srand(static_cast<unsigned int>(time(NULL)));
int ran_tem1 = score[rand() % sizeof(score)/(sizeof(score[0]))];




srand(static_cast<unsigned int>(time(NULL)));
int ran_tem2 = score2[rand() % sizeof(score)/(sizeof(score[0]))];


cout<<"team A "<<ran_tem1<<" - team B"<<ran_tem2;
if(n1 == ran_tem1 && n2 == ran_tem2)
{
    cout<<"\n\n\n You won\n\n";
    bet*=3;
    bet_in+=bet;gain++;
}
else {
    cout<<"\n\n\n Better luck next time";
    loss++;
    
}
}

void win_lose()
{
    cout<<"Enter your team name: ";
	cin>>team1;
cout<<"Enter the opposition team name: ";
cin>>team2;

srand(static_cast<unsigned int>(time(NULL)));
int ran_tem1 = score[rand() % sizeof(score)/(sizeof(score[0]))];




srand(static_cast<unsigned int>(time(NULL)));
int ran_tem2 = score2[rand() % sizeof(score)/(sizeof(score[0]))];


cin.ignore();
cout<<"Will your team Win or Lose or Draw(W/L/D): ";
cin>>pre_f;
cout<<team1<<" "<<ran_tem1<<" : "<<ran_tem2<<" "<<team2<<endl;

if(ran_tem1 > ran_tem2)
{
    if(pre_f == 'W' || pre_f == 'w')
    {
        cout<<"Your team won!";
    bet*=2;bet_in+=bet;gain++;
    }
    else if(pre_f == 'l' || pre_f == 'L' || pre_f == 'd' || pre_f == 'D'){
        cout<<"You lose...try again \n";loss++;
        
    }
    else {
        cout<<"Invalid input!";
        return;
    }
}
else if(ran_tem1 < ran_tem2)
{
    if(pre_f == 'l' || pre_f == 'L')
    {
        cout<<team1<< "You win!";
       bet*=2;bet_in+=bet;gain++;
    }
    else if(pre_f == 'w' || pre_f == 'W' || pre_f == 'd' || pre_f == 'D'){
        
        cout<<"Try again Your team lost\n";loss++;
    }
    else {
        cout<<"Invalid input!";
        return;
    }
}
else {
    if(pre_f == 'd' || pre_f == 'D')
    {
        cout<<team1<< "Draw! you win";
        bet*=2;bet_in+=bet;gain++;
        
    }
    else if(pre_f == 'w' || pre_f == 'W' || pre_f == 'l' || pre_f == 'L'){
        cout<<team1<<"You Lost!";loss++;
        cout<<" try again \n";
        
    }
    else {
        cout<<"Invalid input!"<<endl;
        return;
    }
}
}
void sports_bet(){
do{
cout<<"\n Enter 1 for score prediction \n";
cout<<"Enter 2 for game prediction \n";
cout<<"Enter 3 to exit sports bet \n";
cin>>choice;
switch(choice){
	case 1: sports_pr();break;
	case 2: win_lose();break;
	default:cout<<"Enter valid input \n";
}}while(choice!=3);
}
void instructions(){
  string roulette = "A classic casino game where players bet on the outcome of a spinning wheel. Bets can be placed on specific numbers, colors, or odd/even.";
    string diceSpice = "Two dice are rolled. Player chooses a number from 2 to 36. If the number appears as a sum, multiple, or on either die, the player wins.";
    string sportsBet = "Players wager on the outcome of sports events. The payout depends on the bet type and the odds provided by the bookmaker.";
    string luckyDip = "Player picks 6 numbers. 6 numbers are drawn randomly. The payout increases based on how many numbers match.";
    string luckyDraw = "A lottery-style game where players pick numbers, and results are based on a random draw, offering varying payouts.";
    string highLow = "A number is shown to the player, and they guess whether the next number will be higher or lower. Correct guesses result in payouts.";
    
   
    cout << "Casino Games Information:\n" << endl;
    cout << left << setw(15) << "Roulette \n"   << ": " << roulette << endl;
    cout << left << setw(15) << "Dice Spice \n" << ": " << diceSpice << endl;
    cout << left << setw(15) << "Sports Bet \n" << ": " << sportsBet << endl;
    cout << left << setw(15) << "Lucky Dip \n"  << ": " << luckyDip << endl;
    cout << left << setw(15) << "Lucky Draw \n" << ": " << luckyDraw << endl;
    cout << left << setw(15) << "High Low \n"   << ": " << highLow << endl;
}



	void exhaust(){
	if(bet_in==0){
	cout<<"You have exhausted your balance \n";
	cout<<"Press 1 to recharge \n";
	int rec;
	cin>>rec;
	
	if(rec==1){
		cout<<"Enter amount \n";
		cin>>bet_innew;
		bet_in+=bet_innew;
		waggered+=bet_in;
	}
 }
}
const int MAX = 10;
string usernames[MAX];
string passwords[MAX];
int flag = 0;
void create_account() {
    if (flag >= MAX) {
        cout << "User limit reached. Cannot create more accounts." << endl;
        return;
    }

    string username, password;
    cout << "Enter a username: ";
    cin >> username;

    for (int i = 0; i < flag; i++) {
        if (usernames[i] == username) {
            cout << "Username already exists. Try a different one." << endl;
            return;
        }
    }

    cout << "Enter a password: ";
    cin >> password;

    usernames[flag] = username;
    passwords[flag] = password;
    flag++;

    cout << "Account created successfully!" << endl;
}

bool login() {
    string username, password;
    cout << "Enter your username: ";
    cin >> username;
    cout << "Enter your password: ";
    cin >> password;

    for (int i = 0; i < flag; i++) {
        if (usernames[i] == username && passwords[i] == password) {
            cout << "Login successful!" << endl;
            
           
            cout<<"welcome "<<username<<endl;
        
            return true;
        }
    }

    cout << "Invalid credentials. Try again." << endl;
    return false;
}

bool account() {
    int choice;
   
    
   
    do {
    	
        cout << "\n1. Create an account\n2. Login\n Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                create_account();
                break;
            case 2:
                if(login()){
                return true;}
                
                break;
            case 3:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 3);

    return false;
}




int main(){
	char name[59];
	int age,choi;
	
	cout<<"\t\t \t WELCOME TO CASINO PARADSIE \n";
	do{
	cout<<"Enter age, restricted (18+ only)\n";
	cin>>age;
	if(age<18){
		cout<<"Age limit restricted \n";
	}
	}while(age<18);
 
	
  if(account()){
	
	cout<<"\n\n You get $100 as welcome bonus \n\n";
game3 s;


do{
	if(bet_in==0){
exhaust();
	}
	cout<<"\n\n";
cout<<"Enter 0 to check your balance \n";	
cout<<"enter 1 for Lucky draw \n";
cout<<"Enter 2 for dice spice \n";
cout<<"Enter 3 for high low \n";
cout<<"Enter 4 for lucky dip \n";
cout<<"Enter 5 for sports bet \n";
cout<<"enter 6 for roulette \n";
cout<<"enter 7 to analyze your report \n";
cout<<"Enter 8 to view instructions of the games\n";
cout<<"Enter 9 to exit \n";
cin>>choi;

switch(choi){
	case 0: cout<<"Balance = $"<<bet_in<<endl;break;
	case 1: s.matka();
	break;
	case 2: s.dice_spice();break;
	case 3: s.high_low();break;
	case 4: s.lucky_dip();break;
	case 5: sports_bet();break;
	case 7: s.report();break;
	case 6:roulette_display();roulette_input();break;
	case 8: instructions();break;
	default: cout<<"Thanks for playing .. see you again \n";
}

}while(choi!=9 );
	
	
  }

}


