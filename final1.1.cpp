#include <iostream>
#include <cstdlib>// for time
#include <unistd.h>// for time
#include <stdlib.h>// for colour
#include <fstream> // for files
using namespace std;

void display( int t1[4] , int t2[4] , int s1[4] , int s2[4] ){
    
    cout<<"Train departure time"<<" "<<" "<<" "<<" "<<" "<<"Train Return time"<<" "<<" "<<" "<<" "<<" "<<" "<<" "<<"Seats Going up"<<" "<<" "<<" "<<" "<<" "<<" "<<" "<<"Seats Going down"<<endl;
    for(int i = 0; i < 4 ; i++)
    {
    cout<<t1[i]<<"\t""\t""\t""\t"<<t2[i]<<"\t""\t""\t""\t"<<s1[i]<<"\t""\t""\t""\t"<<s2[i]<<endl;
    }

}
bool validateTimes(int tUp, int tDown) {
    // Valid departure times: 9, 11, 13, 15
    // Valid return times: 10, 12, 14, 16
    int validDepartureTimes[4] = {9, 11, 13, 15};
    int validReturnTimes[4] = {10, 12, 14, 16};

    // Check if tUp is a valid departure time
    bool validUp = false;
    for (int i = 0; i < 4; i++) {
        if (tUp == validDepartureTimes[i]) {
            validUp = true;
            break;
        }
    }

    // Check if tDown is a valid return time
    bool validDown = false;
    for (int i = 0; i < 4; i++) {
        if (tDown == validReturnTimes[i]) {
            validDown = true;
            break;
        }
    }

    // Return true only if both tUp and tDown are valid
    return validUp && validDown;
}


int main()
{
 int seatup[4]={100,100,100,100}; // going up seats
  int seatdown[4]={100,100,100,100}; // going down seats
 int timego[4] = {9,11,13,15};   // DEPARTURE TIMES
 int timereturn[4] = {10,12,14,16};  // RETURN TIMES
 int portal,retry,retry2,tickets,timeup,timedown,bill,type , x , admin1 , gticket, eticket, revenue;
gticket = 0;
eticket = 0;
revenue = 0;
 string password ="admin123"; 
 string enteredpassword;
 string name;
 string announcements = "0";
 ofstream out("file.txt");
 ifstream in("file.txt");
retry2 = 0;
 

n:

cout<<"----------------------"<<endl;
cout<<"RAILWAY TICKET SYSTEM"<<endl;
cout<<"[1] VIEW TIMINGS"<<endl;
cout<<"[2] BOOK TICKETS"<<endl;
cout<<"[3] ADMIN"<<endl;
cout<<"[4] VIEW ANNOUNCEMENTS"<<endl;
cout<<"----------------------"<<endl;
cout<<"ENTER YOUR CHOICE"<<endl;
cin>>portal;

switch (portal)
{
case(1):
    //VIEW TIMINGS    BUSINESS OR ECONOMY
    cout<<"Loading..."<<endl;
    cout.flush();
    sleep(1);
    cout<<"Price of Two-way ticket is 20$ for Economy and 50$ For Gold"<<endl;
    cout<<"NOTE WE OFFER 20% DISCOUNT ON PURCHASING OF 10 OR MORE TICKETS"<<endl;

    display(timego,timereturn,seatup,seatdown);
    cout<<"Enter 1 to return to menu"<<endl;
    while(retry2 != 1){
   cin>>retry2; 
 }
        if(retry2 == 1){
          cout<<"Loading..."<<endl;
            cout.flush();
            sleep(2);
            goto n;


}
    break;







case(2):
    //BOOK TICKET ADD ECONOMY AND GOLD TICKETS // TRY TO ASSIGN SEAT NO TOO.
     cout<<"Loading..."<<endl;
    cout.flush();
    sleep(1);
    cout<<"Price of Two-way ticket is 20$ for Economy and 50$ For Gold"<<endl;
    cout<<"NOTE WE OFFER 20% DISCOUNT ON PURCHASING OF 10 OR MORE TICKETS"<<endl;
    display(timego,timereturn,seatup,seatdown);
    cout<<"Enter your  Full name"<<endl;
    cin.ignore();
    getline(cin,name);
    cout<<"Enter how many tickets do you want to buy"<<endl;
    cin>>tickets;
    cout<<"What type of Ticket do you want: "<<endl;
    cout<<"[1] Gold = 50$"<<endl;
    cout<<"[2] Economy = 20$"<<endl;
    cin>>type;
    if (type == 1)
    {
          if(tickets>=10){
    bill = ((tickets * 50) * 0.8);
    }
    else{
    bill = (tickets * 50);
    }
    }
    else if (type == 2){
          if(tickets>=10){
    bill = ((tickets * 20) * 0.8);
    }
    else{
    bill = (tickets * 20);
    } 
    }
    else{
            printf("\033[1;31m Invalid choice returning to menu\033[0m\n"); // prints text in red colour
            
            cout<<"Loading..."<<endl;
            cout.flush();
            sleep(2);
            goto n;
    }
    
    cout<<"Enter your time of departure"<<endl;
    cin>>timeup;
    cout<<"Enter your time of Return"<<endl;
    cin>>timedown;
    //making time checks to make sure the user chooses a time for return later than the time of departure (user is just dumb)
   if(timeup == 9){
    if(timedown < 9 ){
            printf("\033[1;31m Invalid Time selection (Return time can not be before departure time) returning to menu\033[0m\n"); // prints text in red colour
            cout.flush();
            sleep(2);
            goto n;
    }
   }
   if(timeup == 11){
    if(timedown < 11 ){
            printf("\033[1;31m Invalid Time selection (Return time can not be before departure time) returning to menu\033[0m\n"); // prints text in red colour
            cout.flush();
            sleep(2);
            goto n;
    }
   }
    if(timeup == 13){
    if(timedown < 13 ){
            printf("\033[1;31m Invalid Time selection (Return time can not be before departure time) returning to menu\033[0m\n"); // prints text in red colour
            cout.flush();
            sleep(2);
            goto n;
    }
   }
   if(timeup == 15){
    if(timedown < 15 ){
            printf("\033[1;31m Invalid Time selection (Return time can not be before departure time) returning to menu\033[0m\n"); // prints text in red colour
            cout.flush();
            sleep(2);
            goto n;
    }
   }
   if (validateTimes(timeup, timedown)) {
        cout << "Times are valid." << endl;
        // Continue with the rest of your program logic...
    } else {
        printf("\033[1;31m Invalid Time selection, Please refer to the timings\033[0m\n"); // prints text in red colour
            cout.flush();
            sleep(2);
        goto n;
    }

    //updating database for seats availble
    if(timeup == 9){
     x = 0;
    }if(timeup == 11){
     x = 1;
    }if(timeup == 13){
     x = 2;
    }if(timeup == 15){
     x = 3;
    }
     if(seatup[x]<tickets){
        printf("\033[1;31m Seats are not Availble Please refer to the Schedule shown\033[0m\n"); // prints text in red colour
            
            cout<<"Loading..."<<endl;
            cout.flush();
            sleep(2);
            goto n;
    }
 
    seatup[x] = seatup[x] - tickets;
      if(timedown== 10){
     x = 0;
    }if(timedown == 12){
     x = 1;
    }if(timedown == 14){
     x = 2;
    }if(timedown == 16){
     x = 3;
    }
      if(seatdown[x]<tickets){
        printf("\033[1;31m Seats are not Availble Please refer to the Schedule shown\033[0m\n"); // prints text in red colour
            
            cout<<"Loading..."<<endl;
            cout.flush();
            sleep(2);
            goto n;
    }
    seatdown[x] = seatdown[x] - tickets;


    if(type == 1){
gticket = gticket + tickets;
    }
    if(type == 2){
eticket = eticket + tickets;

    }
    revenue = revenue + bill;
// bill has been calculated earlier just outputting it after making checks
    cout<<"Total Bill is: "<< bill <<endl;
    out<<"-------------------------------------------------------"<<endl;
    out<<"Name : "<<name<<endl;
    out<<"time up : "<<timeup<<endl;
    out<<"time down : "<<timedown<<endl;
    out<<"tickets : "<<tickets<<endl;
    out<<"Bill : " <<bill<<endl;
      cout<<"Returning to Main menu"<<endl;
            cout.flush();
            sleep(2);

    goto n;
    break;






case(3):
   r:
    //ADMIN also add train timings change or add announcement delays; also print end day summary and total profit etc

    cout<<"Enter password for admin access"<<endl;
    cin>>enteredpassword;
    if(enteredpassword == password){   // admin control accessed
    
    printf("\033[1;32m Admin portal successfully accessed\033[0m\n"); // prints text in green colour
     }
    else{

        
        printf("\033[1;31m Incorrect Password\033[0m\n"); // prints text in red colour
        cout<<"[1] GO TO MAIN MENU"<<endl;
        cout<<"[2] RETRY PASSWORD"<<endl;
        cin>>retry;
        if(retry == 1){
          goto n;
        }
        else if(retry == 2){
          goto r;
        }
        else{
           
            printf("\033[1;31m Invalid choice returning to menu\033[0m\n"); // prints text in red colour
            
            cout<<"Loading..."<<endl;
            cout.flush();
            sleep(2);
            goto n;
        }
    }

    //admin portal accessed options
    cout<<"[1]  Update Announcements" <<endl;
    cout<<"[2]  Print Day End Summary" <<endl;
    cout<<"[3]  End Program"<<endl;
    cin>>admin1;
     
        if(admin1 == 1){
            cout<<"Enter the announcement you want to display or enter 0 if there are no announcements"<<endl;
            cin.ignore();
         getline(cin,announcements);
          printf("\033[1;32m ANNOUNCEMENT MADE SUCCESSFULY RETURNING TO MENU\033[0m\n"); // prints text in green colour
          cout.flush();
            sleep(2);
            goto n;


        }
        else if(admin1 == 2){
          //  string i;
          //  while(getline(in,i)){cout<<i<<endl;}
         cout<<"Total tickets sold: "<< gticket + eticket <<endl;
         cout<<"Total Gold tickets sold: "<< gticket<<endl;
         cout<<"Total Economy tickets sold: "<< eticket <<endl;
         cout<<"Total revenue generated: "<<"$"<<revenue<<endl;
         
         


            break;
         //END DAY CODE

        }
        else if(admin1 == 3){

            cout<<"Progamram ended"<<endl;
            break;
        }
        else{
           
            printf("\033[1;31m Invalid choice returning to menu\033[0m\n"); // prints text in red colour
            
            cout<<"Loading..."<<endl;
            cout.flush();
            sleep(2);
            goto n;
        }
case(4):
//announcements tab
if (announcements == "0" ){
 cout<<"No announcements at the Moment"<<endl;
cout<<"Enter 1 to return to menu"<<endl;
 cin>>retry;
 while(retry != 1){
   cin>>retry; 
 }
        if(retry == 1){
          cout<<"Loading..."<<endl;
            cout.flush();
            sleep(2);
            goto n;


}
}
cout<<announcements<<endl;

     cout.flush();
    cout<<"Enter 1 to return to menu"<<endl;
     cin>>retry;
     while(retry != 1){
    cin>>retry; 
 }
 if(retry == 1){
cout<<"Loading..."<<endl;
cout.flush();
sleep(2);
 goto n;


}

break;


default:
            printf("\033[1;31m Invalid choice returning to menu\033[0m\n"); // prints text in red colour
            
            cout<<"Loading..."<<endl;
            cout.flush();
            sleep(2);
            goto n;
break;




    } // ending of swtich case bracket

   
    return 0;
}