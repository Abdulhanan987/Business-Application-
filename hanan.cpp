#include <iostream> //including all the librarries
#include <conio.h>
#include <string>
#include <limits>
#include <windows.h>
#include <fstream>
using namespace std;
 // function prortotypes
void printHeader();
//prints the header of application
string menu(string op);
//this will print and takes input from user about his desired option
void output(string Name[], string departure[], string arrival[], string legspace[], string extrafood[], string clas[], string Date[], string ID[], float price, int logincount, string reviews[], string gender[], string age[], string country[], bool budgetresult, string dayofdeparture[], bool discountavail, string airline[], int ticketprice, int budgetforCustomer);
//this will print all the information of user
int cal1(string leg[], string food[], int logincount, int totalprice, int ticketprice, string clas[], int business, int legspace, int foodservice);
//this will calculate the price of ticket after extra cahrges.
string login(string login);
//this will print the login screen and takes input from user
string signIn(string name, string password, string users[], string passwords[], string roles[], int usersCount);
//this will check the sign in option
bool signUp(string name, string password, string role, string users[], string passwords[], string roles[], int &usersCount, int userArrSize,string customers[],int customercount);
//this will sign up the user
void personalInformation(string name[], string country[], string ID[], string gender[], string age[], int logincount);
//this will takes the input from user about his personal information
void flightInformation(string arrival[], string departure[], string date[], string dayOfDeparture[], int logincount,string availableDepartue[],string availableArrivals[],int departurecount,int arrivalcount);
//this will takes input from user about his fligth information
string classSelection(string clas[], int logincount);
//this will takes input from user about his class
void InflightServices(string leg[], string food[], int logincount);
// this will take input from user about the services he want to take
string reviews(string reviews[], int logincount);
// this will takes input from user about his reviews
string OwnerInterface(string op);
// this will print the owner interface and takes input from user
bool Addemployee(string name, string ID, string employee[], string IDNUM[], int &logincount,string username, string usernameforemployee[]);
// this will add the employees  
int totalprice(int total);
string subMenuBeforeMainMenu(string message);
// this will print the submenu
bool removeEmployee(string removingEmployee, string name[], string ID[], int &logincount, string usernameForEmployee[]);
// this will remove the employees
void addAirline(string airline[], string airlinecode[], int &aircount);
// this will add the airlines by the owner
void customerReviews(string customerReviews[], int logincount);
// this will print the customer reviews
bool budget(int budget, int ticketprice);
// this will check the budget entered by user
void availableAirline(string airline[], int &count);
//  by this the user can see the available airlines 
void selectairline(string airlines[], int airlineChoice, int aircount,string selectedairlines[],int logincount);
// this function takes input from user about his selected airlines
void employeeList(string employee[], string IDnum[],string username[], int &logincount);
// this will view the employee list
int pricealloaction(int &ticketprice);
// this will allocates the price of tickets
void extraCharges(int &business, int &legspace, int &food);
// this will allocates the charges of services
int salaryfixation(int &salary);
// this will takes input about the salary the admin wants to pay
int salarymanagement(string employee[], int count, int &totalrevenue, string IDnum[], int salary);
//  this will allocates the salaray to the employees 
void discount(string discount[], int &dayscount);
//  this will takes input from admin about the discount days
void viewDiscountOptions(string discount[], int dayscount);
// 
string discountday(string discountday[], int dayscount, int option);
float percentageOfDiscount(float &percentage);
bool isDiscountAvailable(string day[], int logincount, int daysofdiscount, string discount[]);
float discountedvalue(int &totalprice, float percentage);
string Employeeinterface(string op);
int ticketscount(int logincount);
void viewselectedAirlines(string selectedairline[], int logincount);
void viewselectedServices(string leg[], string food[], string clas[], int logincount);
void profitandLoss(int &totalrevenue);
void announcementToEmployee(string &announcement);
void viewAnnouncements(string announcement);
void cancelllationOfTicket(string name[], string ID[], string gender[], int &totalrevenue, string age[], string departure[], string arrival[], string leg[], string food[], string clas[], string date[], string day[], int &price, string reviews[], int logincount, string airline[]);
bool check_number(string check, int length);
bool check_int(string check);
bool checkeEmpty(string check);
void setColor(int color);
void printaAeroplane();
void clearscreen();
void printscreen();
void viewCustomerInformation(string name[], string ID[], string country[], string gender[], string age[], string arrival[], string departure[], string date[], string day[], int logincount);
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
bool checkstring(string check); 
void signUpinterface();
void signininterface();
void adminMenu();
void customerMenu();
void managerMenu();
void loading();
bool checkSpace(string check);
void loginmenu();
int stoiFunction(string result);
bool checkPlaces(string arrival[], string departure[], int logincount);
void checkUser(string name, string username[] , int &logincount);
void userMenuForSigningAgian(string Name[],string country[],string gender[],string age[],string departure[],string arrival[],string legspace[],string extrafood[],string Date[],string dayofdeparture[],string ID[],int price,string clas[],string airline[],string reviews[],int logincount);
void outputAgain(string Name[],string country[],string gender[],string age[],string departure[],string arrival[],string legspace[],string extrafood[],string Date[],string dayofdeparture[],string ID[],string clas[],string airline[],string reviews[],int logincount);
bool checkCNIC(string ID[],string IDnum,int logincount);
void shedule(string departure[],string arrival[],int &logincountfordeparture, int &logincountForarrival);
void viewShedule(string arrival[],string departure[],int &departurecount,int &arrivalcount);
bool checkDeparture(string availableDeparture[],string departure,int logincount,string arrival[],int logincount1);
bool checkArrival(string availableArrival[],string arrival,int logincount,string departure[],int logincount1);
string getField(string record, int field);
void readData(string names[], string passwords[],string roles[], int &idx);
void readDataForSignUp(string name,string password,string role,int &usersCount);
void addEmployeeData(string name,string ID,string usernameForEmployee[],int logincount);
void AirlineData(string airline,string airlineCode);
void addPrice(int ticketprice);
void addExtraCharges(int business,int legspace,int food);
void discountData(string discount[],int discountcount);
void announcementData(string announcement);
void sheduleData(string departure[],string arrival[],int departurecount,int arrivalcount);
bool checkSpaces(string var);
bool checkSpaces(string var) ;
void addEmployeeDataAfterRemoval(string employee[],string ID[],string username[],int &logincount);
bool removeEmployeeData(string removingEmployee,string employees[],string ID[],string username[],int &logincount); 
void printBudgetRequirements(string leg[], string food[], int logincount, int totalrevenue, int &ticketprice, string clas[], int business, int legspace, int foodservice);
void readExtraCharges(int &clas,int &leg,int &food ) ;
void daysData(int departurecount,int arrivalcount);
void readDiscountPercentage(float &discountpercentage); 
void totalrevenueData(int totalrevenue);
void readTotalrevenue(int &totalrevenue);
void addTickestCount(int logincount) ;
void readLogincount(int &logincount);
void readReviews(string reviews[],int &var) ;
bool checkDays(string check);
void cancelTicketMessage();
void storeUserData(string name,string Name[],string country[],string gender[],string age[],string departure[],string arrival[],string legspace[],string extrafood[],string Date[],string dayofdeparture[],string ID[],int price,string clas[],string airline[],string reviews[],int logincount,int signIncount[]);
bool checkSignInAgain(string name,int &customercount,string Name[],string country[],string gender[],string age[],string departure[],string arrival[],string legspace[],string extrafood[],string Date[],string dayofdeparture[],string ID[],string clas[],string airline[],string reviews[]);
bool checkRoles(string roles);
void hideCursor();
main()
{
  hideCursor();
  int arrsize = 100; 
  int number=0;
  // parallel arrays for signing up the users
  string Username[arrsize];
  string uPassword[arrsize];
  string roles[arrsize];
  string usernameForCustomer[arrsize];
  int customercount=0;
  int checkCustomerCount=0;
  int usercount = 0;
  int loginoption = 0;
  int usercountforCus = 100, price = 0;
  int signIncount[100] ;
  // parallel arrays for the functionalities of user
  string nameOfUser[usercountforCus], country[usercountforCus], ID[usercountforCus], leg[usercountforCus], food[usercountforCus];
  string date[usercountforCus];
  string departure[usercountforCus], arrival[usercountforCus];
  string genderOfUser[usercountforCus];
  string ageofuser[usercountforCus];
  string clas[usercountforCus], customerreviews[usercountforCus];
  int logincount = 0;
  int totalrevenue = 0;
  // parallel arrays for the functionalities of owner
  string employee[100];
  string IDNum[100];
  string airline[100];
  string aircode[100];
  int aircount = 0;
  string usernameForEmployee[100];
  int logincount1 = 0;
  int budgetforCus[usercountforCus];
  bool budgetresult;
  int count;
  string dayOfDeparture[usercountforCus];
  string airlineChoice;
  int ticketprice = 0;
  int business = 0, legspace = 0, foodservice = 0;
  int salary;
  int discountcount = 10;
  string discountonTicket[discountcount];
  int dayscountOfDiscount;
  string resultofDiscount;
  float discountPercetage;
  bool discountavail;
  string selectedairline[100];

  string announcement;
  int cancelledTickets;
  int result1;
  int budgetforCustomer;
  //parallel arrays for functionalities of employees
  string arrivalcount[arrsize];
  string departurecount[arrsize];
  int countOfDeparture;
  int countOfArrival;
  int cancelcount =0;

  system("cls");
  printaAeroplane();
  loading();



  while (loginoption != 3)
  { // loop for signinng in and out

    setColor(FOREGROUND_RED);
    printscreen();
    loginmenu();

    subMenuBeforeMainMenu("login"); 
    string call1;
    string call = login(call1);
    if (call == "1")
    { 
      //cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
      printscreen();
      signininterface();
      string name;
      string password;
      string role;
      cout << subMenuBeforeMainMenu("SignIn") << endl; 
      while (true)
      {
        SetConsoleTextAttribute(h, 11);
        cout << "Enter the username: " << endl;
        SetConsoleTextAttribute(h, 15);
        getline(cin, name);
        if (checkeEmpty(name) == 1 ||checkSpaces(name)==1) 
        {
          SetConsoleTextAttribute(h, 4);
          cout << "Invalid input." << endl;
          SetConsoleTextAttribute(h, 15);
        }
        else
        {
          break;
        }
      }

      while (true)
      {
        SetConsoleTextAttribute(h, 11);
        cout << "Enter the password(must be 8): " << endl;
        SetConsoleTextAttribute(h, 15);
        getline(cin, password); 
        if (checkeEmpty(password) == 1 || checkSpace(password) == 1 || check_number(password, 8) == 1||checkSpaces(password)==1) 
        {
          SetConsoleTextAttribute(h, 4);
          cout << "Invalid input. " << endl;
          SetConsoleTextAttribute(h, 15);
        }
        else
        {
          break;
        }
      }
     
      
      
         role = signIn(name, password, Username, uPassword, roles, usercount); 
      
      

      if (role == "user" || role == "User" || role == "Customer" || role == "customer") 
      { // loop for the functionalaities of user
        setColor(FOREGROUND_INTENSITY); 
         
           
        readLogincount(logincount);  
        if(checkSignInAgain(name,customercount,nameOfUser,country,genderOfUser,ageofuser,departure,arrival,leg,food,date,dayOfDeparture,ID,clas,selectedairline,customerreviews))
        {
          outputAgain(nameOfUser,country,genderOfUser,ageofuser,departure,arrival,leg,food,date,dayOfDeparture,ID,clas,selectedairline,customerreviews,customercount);
          getch();  
          
        
        }
        
        else
        {
 while (true) 
          {
            printscreen();   
            customerMenu();  
            cout<<subMenuBeforeMainMenu("User");    
            string op;
            string result = menu(op);
            if(result=="1")
            {
              printscreen();
              viewShedule(arrivalcount,departurecount,countOfDeparture,countOfArrival); 
              clearscreen();
            }
           else if (result == "3")
            {
              printscreen();
              personalInformation(nameOfUser, country, ID, genderOfUser, ageofuser, logincount);
              clearscreen();
            }
            else if (result == "4")
            {
              printscreen();
              flightInformation(arrival, departure, date, dayOfDeparture, logincount,departurecount,arrivalcount,countOfDeparture,countOfArrival);
              clearscreen();
            }
            else if (result == "5")
            {
              printscreen();
              InflightServices(leg, food, logincount);
              clearscreen();
            }
            else if (result == "6")
            {
              printscreen();
              classSelection(clas, logincount); 
              clearscreen();
            }
            else if (result == "7")
            {
              printscreen();
              
             
                 readExtraCharges(business,legspace,foodservice);  
                 printBudgetRequirements(leg,food,logincount,totalrevenue,ticketprice,clas,business,legspace,foodservice);
                 readDiscountPercentage(discountPercetage);

              clearscreen(); 
            }
            else if (result == "8")   
            {
              budgetforCustomer;
              printscreen();
               string CheckForResult;
               while(true)
               {
                  SetConsoleTextAttribute(h, 11); 
              cout << "Enter your budget: ";
              SetConsoleTextAttribute(h, 15);
              getline(cin,CheckForResult);
              if(checkeEmpty(CheckForResult)==1||check_int(CheckForResult)==1)
              {
                SetConsoleTextAttribute(h, 4);
                cout<<"Invalid input."<<endl;
                 SetConsoleTextAttribute(h, 15);
              }
              else
              {
                break;
              }
               }
               budgetforCustomer=stoi(CheckForResult);
              
              int priceOfticket = cal1(leg, food, logincount, totalrevenue, ticketprice, clas, business, legspace, foodservice);
              
              budgetresult = budget(priceOfticket, budgetforCustomer); 
              if (budgetresult == true)
              {
                SetConsoleTextAttribute(h, 2);  
                cout << "The budget is enough." << endl; 
                SetConsoleTextAttribute(h, 15);
              }
              else
              {
                SetConsoleTextAttribute(h, 4);
                cout << "The budget is not enough." << endl;
                SetConsoleTextAttribute(h, 15);
              }

              clearscreen();
            }
            else if (result == "11")  
            {
              printscreen();
              reviews(customerreviews, logincount);  
              clearscreen();
            }
            else if (result == "9")  
            {    
              string check_for_result;
              printscreen();
              int airlinechoice;
              availableAirline(airline, aircount); 
              SetConsoleTextAttribute(h, 11); 
              while(true)
              { 
              cout << "Select your choice:";
              SetConsoleTextAttribute(h, 15); 
              //cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
              getline(cin, check_for_result);  
              if(checkeEmpty(check_for_result)==1||check_int(check_for_result)==1) 
              {
                SetConsoleTextAttribute(h,4); 
                cout<<"Invalid input."<< endl;  

              }
              else
              {
                break;
              }
              }
              airlinechoice = stoi(check_for_result);  
              selectairline(airline, airlinechoice, aircount,selectedairline,logincount); 
              
              clearscreen();
            }
            else if (result == "2") 
            {
              printscreen();
              viewDiscountOptions(discountonTicket, dayscountOfDiscount);

              clearscreen();
            }
            else if (result == "10")
            {
              printscreen();  
              price = cal1(leg, food, logincount, totalrevenue, ticketprice, clas, business, legspace, foodservice);
              discountavail = isDiscountAvailable(dayOfDeparture, logincount, dayscountOfDiscount, discountonTicket);
              if (discountavail == true) 
              {
                result1 = discountedvalue(price, discountPercetage);      
                SetConsoleTextAttribute(h, 2);
                cout << "The total price after discount is: " << result1 << endl;
                SetConsoleTextAttribute(h, 15);
                readTotalrevenue(totalrevenue) ;
                totalrevenue = totalrevenue + result1;
                totalrevenueData(totalrevenue);  
              }
              else
              {
                SetConsoleTextAttribute(h, 11);
                cout << "The total price is: " << price << endl;
                SetConsoleTextAttribute(h, 15);
                readTotalrevenue(totalrevenue);
                totalrevenue = totalrevenue + price; 
                totalrevenueData(totalrevenue); 
              }
              clearscreen();
              totalprice(totalrevenue);
            }

            else if (result == "12")
            {
              printscreen();

              if (budgetresult == true)
              {
                if (discountavail == true) 
                {
                  output(nameOfUser, departure, arrival, leg, food, clas, date, ID, result1, logincount, customerreviews, genderOfUser, ageofuser, country, budgetresult, dayOfDeparture, discountavail, selectedairline, ticketprice, budgetforCustomer);
                }
                else 
                {
                  output(nameOfUser, departure, arrival, leg, food, clas, date, ID, price, logincount, customerreviews, genderOfUser, ageofuser, country, budgetresult, dayOfDeparture, discountavail, selectedairline, ticketprice, budgetforCustomer);
                }
              }
              else
              {
                SetConsoleTextAttribute(h, 4);
                cout << "Your ticket has not confirmed.";
                SetConsoleTextAttribute(h, 15);
              }
              clearscreen(); 
            }

            else if (result == "13")   
            {    if(cancelcount>0)  
            {
              cout<<"You have already cancelled the ticket."<<endl; 
              clearscreen();
            }
            else
            {
              if (isDiscountAvailable(dayOfDeparture, logincount, dayscountOfDiscount, discountonTicket))

                {
                cancelllationOfTicket(nameOfUser, ID, genderOfUser, totalrevenue, ageofuser, departure, arrival, leg, food, clas, date, dayOfDeparture, result1, customerreviews, logincount, selectedairline);
                totalrevenue = totalrevenue - result1; 
                result1=0;
                totalrevenueData(totalrevenue);  
                } 
              else 
              {  
                cancelllationOfTicket(nameOfUser, ID, genderOfUser, totalrevenue, ageofuser, departure, arrival, leg, food, clas, date, dayOfDeparture, price, customerreviews, logincount, selectedairline);
                totalrevenue = totalrevenue - price; 
                price=0; 
                totalrevenueData(totalrevenue); 
              } 
              
            }
                  
                
              cancelTicketMessage(); 
              clearscreen();
              cancelcount ++;
              
            }
            else if (result == "14")  
            {   signIncount[logincount]=1; 
                if(isDiscountAvailable(dayOfDeparture, logincount, dayscountOfDiscount, discountonTicket)) 
                {    
                  storeUserData(name,nameOfUser,country,genderOfUser,ageofuser,departure,arrival,leg,food,date,dayOfDeparture,ID,result1,clas,selectedairline,customerreviews,logincount,signIncount);
                }
                else 
                { 
               storeUserData(name,nameOfUser,country,genderOfUser,ageofuser,departure,arrival,leg,food,date,dayOfDeparture,ID,price,clas,selectedairline,customerreviews,logincount,signIncount);
                }
                if(cancelcount==1) 
                {
                  logincount =logincount; 
                }
                else 
                {
                 logincount++; 
                }
                 
               addTickestCount(logincount); 
              break;
            }
            else
            {
              SetConsoleTextAttribute(h, 4); 
              cout << "Invalid option: ";
              SetConsoleTextAttribute(h, 15);
              clearscreen();
            }
        }
        } 
      }  
      else if (role == "Owner" || role == "owner" || role == "admin" || role == "Admin") 
      { // loop for the functionalities of admin
        setColor(FOREGROUND_GREEN);
        while (true)
        {  
          printscreen();
          adminMenu();
          subMenuBeforeMainMenu("Owner");
          string op;
          string choice = OwnerInterface(op);
          if (choice == "1") 
          {
           // cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            system("cls");
            printHeader();
            string name;
            string ID;
             string var;
            while (true)
            {
              SetConsoleTextAttribute(h, 11);
              cout << "Enter the name: ";
              SetConsoleTextAttribute(h, 15);
              getline(cin, name); 
              if (checkeEmpty(name) == 1 || checkstring(name) == 1) 
              {
                SetConsoleTextAttribute(h, 4);
                cout << "Invalid input." << endl;
                SetConsoleTextAttribute(h, 15);
              }
              else
              {
                break;
              }
            }

            while (true)
            {
              SetConsoleTextAttribute(h, 11); 
              cout << "Enter the ID(must be 13 integers): ";
              SetConsoleTextAttribute(h, 15);
              getline(cin, ID); 
              if (check_int(ID) == 1 || check_number(ID, 13) == 1)
              {
                SetConsoleTextAttribute(h, 4); 
                cout << "Invalid input." << endl;
                SetConsoleTextAttribute(h, 15);
              }
              else
              {
                break;
              }
            }
            while (true)
            {
              SetConsoleTextAttribute(h, 11);
              cout << "Enter the username you want to allocate to employee: ";
              SetConsoleTextAttribute(h, 15);
             
              getline(cin, var);
              if (checkeEmpty(var) == 1)
              {
                SetConsoleTextAttribute(h, 4);
                cout << "Invalid input. " << endl;
                SetConsoleTextAttribute(h, 15);
              }
              else
              {
                break;
              }
            }

            if (Addemployee(name, ID, employee, IDNum, logincount1,var, usernameForEmployee))  
            {
              SetConsoleTextAttribute(h, 2);
              cout << "Employee added sucessfully" << endl;  
              SetConsoleTextAttribute(h, 15);
            }
            else
            {
              SetConsoleTextAttribute(h, 4);
              cout << "Username or ID alredy present" << endl;
              SetConsoleTextAttribute(h, 15);
            }

            clearscreen();
          }
          else if (choice == "2")
          { 
           // cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            printscreen();
            string removingEmployee; 
            SetConsoleTextAttribute(h, 11); 
            while (true) 
            {
              cout << "Enter the Username of employee you want to remove: ";
              SetConsoleTextAttribute(h, 15);
              getline(cin, removingEmployee);
              if (checkeEmpty(removingEmployee) == 1) 
              {
                SetConsoleTextAttribute(h, 4);
                cout << "Invalid input. " << endl;
                SetConsoleTextAttribute(h, 15); 
              }
              else
              {
                break;
              }
            }

            if (removeEmployee(removingEmployee, employee, IDNum, logincount1, usernameForEmployee)) 
            {
              SetConsoleTextAttribute(h, 2);
              cout << "Employee removed sucessfully" << endl;
              SetConsoleTextAttribute(h, 15);
             
            }
            else
            {
              SetConsoleTextAttribute(h, 4); 
              cout << "Employee not found.";
              SetConsoleTextAttribute(h, 15);
            }
            clearscreen();
          }
          else if (choice == "12")
          {
            printscreen();
            SetConsoleTextAttribute(h, 2);
            readTotalrevenue(totalrevenue); 
            cout << "The total revenue generated is : " << totalrevenue << endl; 
            SetConsoleTextAttribute(h, 15);
            clearscreen();
          }
          else if (choice == "3")
          { 
            printscreen(); 
            addAirline(airline, aircode, aircount);
            clearscreen();
          }
          else if (choice == "11")
          {
            printscreen();

            SetConsoleTextAttribute(h, 15);
            readLogincount(logincount);
            customerReviews(customerreviews, logincount); 
            clearscreen();
          }
          else if (choice == "4")
          {
            printscreen(); 
            employeeList(employee, IDNum,usernameForEmployee, logincount1); 
            clearscreen();
          }
          else if (choice == "5")
          {
            printscreen();
            pricealloaction(ticketprice);
            clearscreen();
          }
          else if (choice == "6")
          {
            printscreen();
            extraCharges(business, legspace, foodservice);
            clearscreen();
          }
          else if (choice == "7")
          {
            printscreen();
            salaryfixation(salary);
            SetConsoleTextAttribute(h, 11);
            cout << "Select the employee whose salary you want to pay:" << endl;
            SetConsoleTextAttribute(h, 15);
            salarymanagement(employee, logincount1, totalrevenue, IDNum, salary);
            clearscreen();
          }
          else if (choice == "8")
          {
            printscreen();
            discount(discountonTicket, dayscountOfDiscount);
            clearscreen();
          }
          else if (choice == "9")
          {
            printscreen();  
            SetConsoleTextAttribute(h, 11);
            cout << "Enter the percentage of discount you want to give:";
            SetConsoleTextAttribute(h, 15);
            percentageOfDiscount(discountPercetage);
            clearscreen();
          }
          else if (choice == "10")
          {
            printscreen();
            announcementToEmployee(announcement); 
            clearscreen();
          }
          else if (choice == "13")
          {
            break;
          }
          else
          {
            SetConsoleTextAttribute(h, 4);
            cout << "Invalid option." << endl;
            SetConsoleTextAttribute(h, 15);
            clearscreen();
          }
        }
      }
      else if (role == "employee" || role == "Employee" || role == "manager" || role == "Manager")
      {
        setColor(FOREGROUND_BLUE);  
        // loop for the functionalities of employee
        while (true)
        {
          printscreen();
          managerMenu();
          string op;
          string choice1 = Employeeinterface(op);
          if(choice1=="1")
          {
             printscreen(); 
             shedule(departurecount,arrivalcount,countOfDeparture,countOfArrival);
          }
          else if (choice1 == "2") 
          {
            printscreen(); 
            SetConsoleTextAttribute(h, 11); 
            readLogincount(logincount); 
            cout << "There have been " << ticketscount(logincount) << " tickest sold today." << endl; 
            SetConsoleTextAttribute(h, 15); 

            clearscreen();
          }
          else if (choice1 == "3")
          {
            printscreen();
            viewselectedAirlines(selectedairline, logincount);
            clearscreen();
          }
          else if (choice1 == "4")
          {
            printscreen();
            viewselectedServices(leg, food, clas, logincount);
            clearscreen();
          }
          else if (choice1 == "5")
          {
            printscreen();
            profitandLoss(totalrevenue);
            clearscreen();
          }
          else if (choice1 == "6")
          {
            printscreen();
            viewAnnouncements(announcement);
            clearscreen();
          }
          else if (choice1 == "7")
          {
            printscreen();
            viewCustomerInformation(nameOfUser, ID, country, genderOfUser, ageofuser, arrival, departure, date, dayOfDeparture, logincount);
            clearscreen();
          }
          else if (choice1 == "8")
          {
            break;
          }
          else
          {
            SetConsoleTextAttribute(h, 4);
            cout << "Invalid option." << endl;
            SetConsoleTextAttribute(h, 15);
            clearscreen();
          }
        }
      }
      else
      {
        SetConsoleTextAttribute(h, 4);
        cout << "Undefined" << endl;
        SetConsoleTextAttribute(h, 15);
        clearscreen();
      }
    }

    else if (call == "2")  
    { // loop for signing up users
      setColor(FOREGROUND_RED); 
      //cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
      printscreen();
      signUpinterface();
      SetConsoleTextAttribute(h, 11);
      cout << subMenuBeforeMainMenu("SignUp") << endl;
      cout << "*.......................*" << endl;
      SetConsoleTextAttribute(h, 15);
      string name;
      string password;
      string role;
      while (true)
      {
        cout << "Enter the username: "; 
        getline(cin, name);
        if (checkeEmpty(name) == 1 ||checkSpaces(name)==1)   
        {
          SetConsoleTextAttribute(h, 4);
          cout << "Invalid input." << endl; 
          SetConsoleTextAttribute(h, 15); 
        }
        else
        {
          break;
        }
      }
      while (true)
      {
        SetConsoleTextAttribute(h, 11);
        cout << "Enter the password(must be 8 characters): ";
        SetConsoleTextAttribute(h, 15);
        getline(cin, password);
        if (checkeEmpty(password) == 1 || checkSpace(password) || check_number(password, 8)||checkSpaces(password)==1)
        {
          SetConsoleTextAttribute(h, 4);
          cout << "Invalid input. " << endl;
          SetConsoleTextAttribute(h, 15);
        }
        else
        {
          break;
        }
      }
      while (true)
      {
        SetConsoleTextAttribute(h, 11); 
        cout << "Enter your role(admin,customer,manager): ";
        SetConsoleTextAttribute(h, 15);
        getline(cin, role);
        if (checkeEmpty(role) == 1 || checkstring(role) == 1||checkSpaces(role)==1||checkRoles(role)==1)
        {
          SetConsoleTextAttribute(h, 4); 
          cout << "Invalid input." << endl; 
          SetConsoleTextAttribute(h, 15);
        }
        else
        {
          break;
        }
      }

      bool isTrue = signUp(name, password, role, Username, uPassword, roles, usercount, arrsize,usernameForCustomer,customercount);
      
      if (isTrue) 
      {  
        SetConsoleTextAttribute(h, 2);  
        cout << "Signed up succesfully" << endl;
        SetConsoleTextAttribute(h, 15);
      }
      if(!isTrue)
      {
        SetConsoleTextAttribute(h, 4);
        cout << "Not signed up successfully" << endl;   
        SetConsoleTextAttribute(h, 15); 
      }
      clearscreen();
    }
    else if (call == "3")   
    {
      setColor(FOREGROUND_RED);
      system("cls");
      break;
    }

    else
    {
      SetConsoleTextAttribute(h, 4);  
      cout << "Invalid option: " << endl;
      SetConsoleTextAttribute(h, 15);
      clearscreen();
    }
  }
}
//the main function ends here
void readExtraCharges(int &clas,int &leg,int &food ) 
{
         fstream file;
         file.open("ExtraCharges.txt",ios::in);
         string var;
          getline(file,var); 
          leg=stoi(getField(var,1));
          food = stoi(getField(var,2));  
          clas = stoi(getField(var,3));
          file.close();

}
void readLogincount(int &logincount) 
{
        fstream file;
        file.open("TicketsData.txt",ios::in);
        file >> logincount;
        file.close();
}
void cancelTicketMessage()
{
   cout<<"If you want to book the ticket again fill out the above options again otherwise you will not be able to book the ticket."<<endl;
   
}

void printBudgetRequirements(string leg[], string food[], int logincount, int totalrevenue, int &ticketprice, string clas[], int business, int legspace, int foodservice)
{
        SetConsoleTextAttribute(h, 11);
            fstream file; 
            file.open("addPrice.txt",ios::in);
              file >> ticketprice;

                cout << "Your budget should be greater than $" << cal1(leg, food, logincount, totalrevenue, ticketprice, clas, business, legspace, foodservice) << endl;
                SetConsoleTextAttribute(h, 15);  
}
void printHeader()

{ // function for printing header
  cout << endl
       << endl
       << endl;
  SetConsoleTextAttribute(h, 9);
  cout << "                             |                              ";
  SetConsoleTextAttribute(h, 13);
  cout << "  ____  _           __        ___                                                ";
  SetConsoleTextAttribute(h, 9);
  cout << " |" << endl;
  SetConsoleTextAttribute(h, 9);
  cout << "                             |                              ";
  SetConsoleTextAttribute(h, 13);
  cout << " / ___|| | ___   _  \\ \\      / (_)_ __   __ _ ___                                ";
  SetConsoleTextAttribute(h, 9);
  cout << " |" << endl;
  SetConsoleTextAttribute(h, 9);
  cout << "                             |                              ";
  SetConsoleTextAttribute(h, 13);
  cout << " \\___ \\| |/ / | | |  \\ \\ /\\ / /| | '_ \\ / _` / __|                               ";
  SetConsoleTextAttribute(h, 9);
  cout << " |" << endl;
  SetConsoleTextAttribute(h, 9);
  cout << "                           .-'-.                            ";
  SetConsoleTextAttribute(h, 13);
  cout << "  ___) |   <| |_| |   \\\\ V V / | | | | | (_| \\__ \\                              ";
  SetConsoleTextAttribute(h, 9);
  cout << ".-'-." << endl;
  SetConsoleTextAttribute(h, 9);
  cout << "                          ' ___ '                           ";
  SetConsoleTextAttribute(h, 13);
  cout << " |____/|_|\\_\\__,  |    \\_/\\_/  |_|_| |_|\\__, |___/                             ";
  SetConsoleTextAttribute(h, 9);
  cout << "' ___ '" << endl;
  SetConsoleTextAttribute(h, 9);
  cout << "                ---------'  .-.  '---------                 ";
  SetConsoleTextAttribute(h, 13);
  cout << "             _|___/                       |___/                      ";
  SetConsoleTextAttribute(h, 9);
  cout << "---------'  .-.  '---------" << endl;
  SetConsoleTextAttribute(h, 9);
  cout << "_________________________'  '-'  '_________________________ ";
  SetConsoleTextAttribute(h, 13);
  cout << "            / \\  (_)_ __| (_)_ __   ___  ___        ";
  SetConsoleTextAttribute(h, 9);
  cout << " _________________________'  '-'  '_________________________" << endl; 
  SetConsoleTextAttribute(h, 9);
  cout << " ''''''-|---|--/    \\==][^',_m_,'^][==/    \\--|---|-''''''";
  SetConsoleTextAttribute(h, 13);
  cout << "             / _ \\ | | '__| | | '_ \\ / _ \\/ __|         ";
  SetConsoleTextAttribute(h, 9);
  cout << "''''''-|---|--/    \\==][^',_m_,'^][==/    \\--|---|-''''''" << endl; 
  SetConsoleTextAttribute(h, 9);
  cout << "               \\    /  ||/   H   \\||  \\    /             ";
  SetConsoleTextAttribute(h, 13);
  cout << "             / ___ \\| | |  | | | | | |  __/\\__ \\                       ";
  SetConsoleTextAttribute(h, 9);
  cout << "\\    /  ||/   H   \\||  \\    /" << endl;
  SetConsoleTextAttribute(h, 9);
  cout << "                '--'   OO   O|O   OO   '--'                 ";
  SetConsoleTextAttribute(h, 13); 
  cout << "         /_/   \\_\\_|_|  |_|_|_| |_|\\___||___/                       ";
  SetConsoleTextAttribute(h, 9);
  cout << " '--'   OO   O|O   OO   '--'" << endl;
  SetConsoleTextAttribute(h, 15);
  cout << endl; 
}

string menu(string op)  
{ // function for printing the menu of user
  SetConsoleTextAttribute(h, 11);
  ////cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  cout << "\t\t\t\t\t\tSelect one of the following option: " << endl;
  cout << "\t\t\t\t\t\t1. View the shedule:" <<endl;
  cout << "\t\t\t\t\t\t2. View the days in which discount is available: " << endl; 
  cout << "\t\t\t\t\t\t3. Add personal information: " << endl;
  cout << "\t\t\t\t\t\t4. Ticket booking:" << endl;
  cout << "\t\t\t\t\t\t5. In fligth Services:" << endl;
  cout << "\t\t\t\t\t\t6. Class Selection: " << endl;
  cout << "\t\t\t\t\t\t7. View budget requirements:" << endl;
  cout << "\t\t\t\t\t\t8. Enter your budget:" << endl;
  cout << "\t\t\t\t\t\t9. View Available Airlines" << endl;
  cout << "\t\t\t\t\t\t10. View the price: " << endl;
  cout << "\t\t\t\t\t\t11. Reviews:" << endl;
  cout << "\t\t\t\t\t\t12. Ticket reciept: " << endl; 
  cout << "\t\t\t\t\t\t13. Cancel the ticket:" << endl;
  cout << "\t\t\t\t\t\t14. logout" << endl;
  SetConsoleTextAttribute(h, 15);
  cout << "\t\t\t\t\t\tYour option: " << endl; 

  getline(cin, op);
  return op;   
}
string getField(string record, int field) 
{
int commaCount = 1;
string item;
for (int x = 0; x < record.length(); x++)
{
if (record[x] == ',')
{
commaCount = commaCount + 1;
}
else if (commaCount == field)
{
item = item + record[x];
}
}
return item;
}
void readData(string names[], string passwords[],string roles[], int &idx)
{
string record;
fstream data;
data.open("Newfile.txt", ios::in); 
while (!(data.eof()))
{
getline(data, record);
names[idx] = getField(record, 1);
passwords[idx] = getField(record, 2); 
roles[idx]=getField(record,3); 

idx = idx + 1; 
}
}
string login(string login) 

{
  // function for login

  cout << endl
       << endl 
       << endl
       << endl;
  SetConsoleTextAttribute(h, 11);
  cout << "\t\t\t\t\t\t1. Sign In: " << endl; 

  cout << "\t\t\t\t\t\t2. Sign Up: " << endl; 
  cout << "\t\t\t\t\t\t3. Exit: " << endl; 
  SetConsoleTextAttribute(h, 15);
  cout << "\t\t\t\t\t\tEnter your choice within the given options: ";
  getline(cin,login); 
  return login; 
}
bool signUp(string name, string password, string role, string users[], string passwords[], string roles[], int &usersCount, int userArrSize,string customers[],int customercount) 
{ // function for signUp
  system("cls");
  printHeader(); 




  fstream file; 
  file.open("Newfile.txt",ios::in);
  string var;
     
   bool isFound = false;
     int x=0;
     while(!file.eof())   
  {   getline(file,var);  
        users[x]=getField(var,1); 
        passwords[x]=getField(var,2); 
        roles[x]=getField(var,3); 
    if ((role == "Owner" || role == "owner" || role == "Admin" || role == "admin") && (roles[x] == "owner" || roles[x] == "Owner" || roles[x] == "admin" || roles[x] == "Admin") || ((role == "Employee" || role == "employee" || role == "manager" || role == "Manager") && (roles[x] == "employee" || roles[x] == "Employee" || roles[x] == "Manager" || roles[x] == "manager")))
    {
      isFound = true;     
      break; 
    }
    x++;
  }
 
  for (int index = 0; index < x; index++)
  {
    if (name == users[index] && password == passwords[index])  
    {

      isFound = true;
      break;
    }
  }
  if (isFound == true)
  {
    return 0;
  }
  else if (usersCount < userArrSize)    
  {
     
    readDataForSignUp(name,password,role,usersCount); 

    usersCount++; 
    return true;
  }

  else
  {
    return false;
  }

  
}
void readDataForSignUp(string name,string password,string role,int &usersCount)   
{       fstream file;
  

      file.open("Newfile.txt",ios::app); 
      file << name <<",";
      file << password <<",";
      file << role <<endl; 
      usersCount++;
      file.close(); 


  } 
string signIn(string name, string password, string users[], string passwords[], string roles[], int usersCount)

{
  // function for SignIn 

  readData(users,passwords,roles,usersCount); 
  
  
  for (int x = 0; x < usersCount; x++) 
  {
    if (name == users[x] && password == passwords[x])  
    {

      return roles[x];  
      
      break;
    }
  }
  SetConsoleTextAttribute(h, 4);
  return "Wrong information";    
}


void viewShedule(string arrival[],string departure[],int &departurecount,int &arrivalcount) 
{      fstream line;
      string var1;
       line.open("Daysdata.txt",ios::in);
       getline(line,var1);
       departurecount =stoi(getField(var1,1));
       arrivalcount=stoi(getField(var1,2));
       line.close();
   cout<<"Arrival places: "<<endl;  
       fstream file;
       file.open("SheduleData.txt",ios::in); 
         string var;
         getline(file,var);
         
        for(int index=0;index<arrivalcount;index++)  
        { arrival[index]=  getField(var,index+1); 
          cout<<arrival[index]<<endl;
        }
        cout<<"Departure places: "<<endl;
           getline(file,var);
        for(int x=0;x<departurecount;x++)
        {   departure[x]= getField(var,x+1);
          cout<<departure[x]<<endl;
        }
        file.close();
}

void output(string Name[], string departure[], string arrival[], string legspace[], string extrafood[], string clas[], string Date[], string ID[], float price, int logincount, string reviews[], string gender[], string age[], string country[], bool budgetresult, string dayofdeparture[], bool discountavail, string airline[], int ticketprice, int budgetforCustomer)
{  
  string discountavailability;     
  SetConsoleTextAttribute(h, 2);
  string resultOfBudget = "Fligth status is OK. ";
  SetConsoleTextAttribute(h, 15);

  // function for printing the ticket receipt
  if (discountavail == true)
  {
    SetConsoleTextAttribute(h, 4);
    discountavailability = "You have availed the discount.";
    SetConsoleTextAttribute(h, 15);
  }

  if (discountavail == false)
  {
    SetConsoleTextAttribute(h, 4);
    discountavailability = "You have not availed the discount.";
    SetConsoleTextAttribute(h, 15);
  }

  if (price == 0) 
  {
    SetConsoleTextAttribute(h, 4);
    cout << "\t\t\t\t\t\tYou have not booked the ticket.";
    SetConsoleTextAttribute(h, 15);
  }
  else
  {
    SetConsoleTextAttribute(h, 11);
    cout << "\t\t\t\t\t\t" << Name[logincount] << endl; 
    cout << "\t\t\t\t\t\t" << country[logincount] << endl; 
    cout << "\t\t\t\t\t\t" << gender[logincount] << endl;
    cout << "\t\t\t\t\t\t" << age[logincount] << endl;
    cout << "\t\t\t\t\t\tDeparture: " << departure[logincount] << endl;
    cout << "\t\t\t\t\t\tArrival: " << arrival[logincount] << endl; 
    cout << "\t\t\t\t\t\tServices:" << endl;
    cout << "\t\t\t\t\t\tLeg Space: " << legspace[logincount] << endl;
    cout << "\t\t\t\t\t\tFood Service: " << extrafood[logincount] << endl;
    cout << "\t\t\t\t\t\tDate of Departure: " << Date[logincount] << endl;
    cout << "\t\t\t\t\t\tDay of departure:" << dayofdeparture[logincount] << endl;
    cout << "\t\t\t\t\t\tID No:" << ID[logincount] << endl;
    cout << "\t\t\t\t\t\tTicket Price: $" << price << endl; 
    cout << "\t\t\t\t\t\tFligth status:" << resultOfBudget << endl;
    cout << "\t\t\t\t\t\tSelected Class:" << clas[logincount] << endl;
    cout << "\t\t\t\t\t\tDiscount status:" << discountavailability << endl;
    cout << "\t\t\t\t\t\tYour selected airline: " << airline[logincount] << endl;
    cout << "\t\t\t\t\t\tReviews: " << reviews[logincount] << endl; 
    SetConsoleTextAttribute(h, 15);       
  }
}


bool checkSignInAgain(string name,int &customercount,string Name[],string country[],string gender[],string age[],string departure[],string arrival[],string legspace[],string extrafood[],string Date[],string dayofdeparture[],string ID[],string clas[],string airline[],string reviews[]) 
{     string var;  
     fstream file; 
     file.open("UsersData.txt",ios::in); 
      int x=0; 
      while(!file.eof())  
      {
        getline(file,var); 
       if( getField(var,1)==name&&stoi(getField(var,17))==1) 
       {  customercount=stoi(getField(var,18)); 
           Name[customercount]=getField(var,2);
           country[customercount]=getField(var,3);
           gender[customercount]=getField(var,4);
           age[customercount]=getField(var,5);
           departure[customercount]=getField(var,6);
           arrival[customercount]=getField(var,7);
           legspace[customercount]=getField(var,8);
           extrafood[customercount]=getField(var,9);
           Date[customercount]=getField(var,10);
           dayofdeparture[customercount]=getField(var,11);
           ID[customercount]=getField(var,12);
           clas[customercount]=getField(var,14);
           airline[customercount]=getField(var,15);
           reviews[customercount]=getField(var,16);

           return true; 
           break; 
       }
      }
      file.close(); 
     return false; 
}

void storeUserData(string name,string Name[],string country[],string gender[],string age[],string departure[],string arrival[],string legspace[],string extrafood[],string Date[],string dayofdeparture[],string ID[],int price,string clas[],string airline[],string reviews[],int logincount,int signIncount[])
{    
    fstream file; 
    file.open("UsersData.txt",ios::app); 
    file<<name<<","<<Name[logincount]<<","<<country[logincount]<<","<<gender[logincount]<<","<<age[logincount]<<","<<departure[logincount]<<","<<arrival[logincount]<<","<<legspace[logincount]<<","<<extrafood[logincount]<<","<<Date[logincount]<<","<<dayofdeparture[logincount]<<","<<ID[logincount]<<","<<price<<","<<clas[logincount]<<","<<airline[logincount]<<","<<reviews[logincount]<<","<<signIncount[logincount]<<","<<logincount<<","<<endl;
    file.close();
}
  void outputAgain(string Name[],string country[],string gender[],string age[],string departure[],string arrival[],string legspace[],string extrafood[],string Date[],string dayofdeparture[],string ID[],string clas[],string airline[],string reviews[],int logincount)  
  {     string resultOfBudget = "Fligth status is OK. ";
        fstream file;
        file.open("UsersData.txt",ios::in);
        string var;
        while(!file.eof()) 
        {
          getline(file,var);  
          
     
        }
        if(Name[logincount]=="")
        {
        resultOfBudget="your ticket has been cancelled";
        }
    SetConsoleTextAttribute(h, 11);  
    cout << "\t\t\t\t\t\t" << Name[logincount] << endl; 
    cout << "\t\t\t\t\t\t" << country[logincount] << endl;
    cout << "\t\t\t\t\t\t" << gender[logincount] << endl;
    cout << "\t\t\t\t\t\t" << age[logincount] << endl;
    cout << "\t\t\t\t\t\tDeparture: " << departure[logincount] << endl; 
    cout << "\t\t\t\t\t\tArrival: " << arrival[logincount] << endl; 
    cout << "\t\t\t\t\t\tServices:" << endl; 
    cout << "\t\t\t\t\t\tLeg Space: " << legspace[logincount] << endl; 
    cout << "\t\t\t\t\t\tFood Service: " << extrafood[logincount] << endl; 
    cout << "\t\t\t\t\t\tDate of Departure: " << Date[logincount] << endl; 
    cout << "\t\t\t\t\t\tDay of departure:" << dayofdeparture[logincount] << endl;  
    cout << "\t\t\t\t\t\tID No:" << ID[logincount] << endl; 
    cout << "\t\t\t\t\t\tFligth status:" << resultOfBudget << endl; 
    cout << "\t\t\t\t\t\tSelected Class:" << clas[logincount] << endl; 
    cout << "\t\t\t\t\t\tYour selected airline: " << airline[logincount] << endl;   
    cout << "\t\t\t\t\t\tReviews: " << reviews[logincount] << endl; 
    SetConsoleTextAttribute(h, 15);
  }
 

int cal1(string leg[], string food[], int logincount, int totalprice, int ticketprice, string clas[], int business, int legspace, int foodservice)
{ // function for calculating the price after extra cgarges

  int price1;
  if ((leg[logincount] == "Yes" || leg[logincount] == "yes") && (food[logincount] == "No" || food[logincount] == "no") && (clas[logincount] == "Business"||clas[logincount]=="business"))
  {
    price1 = ticketprice + legspace + business;
  }

  else if ((leg[logincount] == "Yes" || leg[logincount] == "yes") && (food[logincount] == "Yes" || food[logincount] == "yes") && (clas[logincount] == "Business"||clas[logincount]=="business"))
  {
    price1 = ticketprice + legspace + foodservice + business;
  } 

  else if ((leg[logincount] == "No" || leg[logincount] == "no") && (food[logincount] == "Yes" || food[logincount] == "yes") && (clas[logincount] == "Business"||clas[logincount]=="business"))
  {
    price1 = ticketprice + foodservice + business;
  }

  else if ((leg[logincount] == "No" || leg[logincount] == "no") && (food[logincount] == "No" || food[logincount] == "no") && (clas[logincount] == "Business"||clas[logincount]=="business"))
  {
    price1 = ticketprice + business;
  }
  else if ((leg[logincount] == "Yes" || leg[logincount] == "yes") && (food[logincount] == "Yes" || food[logincount] == "yes") && (clas[logincount] == "Economy"||clas[logincount]=="economy"))
  {
    price1 = ticketprice + foodservice + legspace;
  }
  else if ((leg[logincount] == "No" || leg[logincount] == "no") && (food[logincount] == "Yes" || food[logincount] == "yes") && (clas[logincount] == "Economy"||clas[logincount]=="economy"))
  {
    price1 = ticketprice + foodservice;
  }
  else if ((leg[logincount] == "Yes" || leg[logincount] == "yes") && (food[logincount] == "No" || food[logincount] == "no") && (clas[logincount] == "Ecocnomy"||clas[logincount]=="economy"))
  {
    price1 = ticketprice + legspace;
  }
  else if ((leg[logincount] == "No" || leg[logincount] == "no") && (food[logincount] == "No" || food[logincount] == "no") && (clas[logincount] == "Economy"||clas[logincount]=="economy"))
  {
    price1 = ticketprice;
  }
  else if (leg[logincount] == "yes" || leg[logincount] == "Yes"&&(food[logincount]=="Yes"||food[logincount]=="yes"))
  {
    price1 = ticketprice + legspace + foodservice;
  }
  else if (leg[logincount] == "no" || leg[logincount] == "No"&&(food[logincount]=="No"||food[logincount]=="no"))
  {
    price1 = ticketprice;
  }
  else if (food[logincount] == "Yes" || food[logincount] == "yes"&&(leg[logincount]=="No"||leg[logincount]=="no"))
  {
    price1 = ticketprice + foodservice;
  }
  else if (food[logincount] == "No" || food[logincount] == "no"&&(leg[logincount]=="Yes"||leg[logincount]=="yes"))
  {
    price1 = ticketprice + legspace;
  }
  else if (clas[logincount] == "Business" || clas[logincount] == "business")
  {
    price1 = ticketprice + business;
  }
  else if (clas[logincount] == "Economy" || clas[logincount] == "economy")
  {
    price1 = ticketprice;
  }
  else if (leg[logincount] == "Yes" || leg[logincount] == "yes" && (food[logincount] == "Yes" || food[logincount] == "yes"))
  {
    price1 = ticketprice + legspace + foodservice;
  }
  else if (leg[logincount] == "no" || leg[logincount] == "No" && (food[logincount] == "yes" || food[logincount] == "Yes"))
  {
    price1 = ticketprice + foodservice;
  }
  else if (leg[logincount] == "Yes" || leg[logincount] == "yes" && (food[logincount] == "No" || food[logincount] == "no"))
  {
    price1 = ticketprice + legspace;
  }
  else if (leg[logincount] == "No" || leg[logincount] == "no" && (food[logincount] == "No" || food[logincount] == "no"))
  {
    price1 = ticketprice;
  }
  else if (food[logincount] == "Yes" || food[logincount] == "yes" && (clas[logincount] == "Business" || clas[logincount] == "business"))
  {
    price1 = ticketprice + foodservice + business;
  }
  else if (food[logincount] == "No" || food[logincount] == "no" && (clas[logincount] == "Business" || clas[logincount] == "business"))
  {
    price1 = ticketprice + business;
  }
  else if (food[logincount] == "No" || food[logincount] == "no" && (clas[logincount] == "Economy" || clas[logincount] == "economy"))
  {
    price1 = ticketprice;
  }
  else if (food[logincount] == "Yes" || food[logincount] == "yes" && (clas[logincount] == "Economy" || clas[logincount] == "economy"))
  {
    price1 = ticketprice;
  }
  else if (leg[logincount] == "Yes" || leg[logincount] == "yes" && (clas[logincount] == "Economy" || clas[logincount] == "economy"))
  {
    price1 = ticketprice + legspace;
  }
  else if (leg[logincount] == "No" || leg[logincount] == "no" && (clas[logincount] == "Economy" || clas[logincount] == "economy"))
  {
    price1 = ticketprice; 
  }
  else if (leg[logincount] == "No" || leg[logincount] == "no" && (clas[logincount] == "Business" || clas[logincount] == "business"))
  {
    price1 = ticketprice + business;
  }
  else if (leg[logincount] == "Yes" || leg[logincount] == "yes" && (clas[logincount] == "Business" || clas[logincount] == "business"))
  {
    price1 = ticketprice + business + legspace;
  }
  else if (leg[logincount] == "" && food[logincount] == "" && (clas[logincount] == ""))
  {
    price1 = ticketprice;
  }

  logincount++;
  return price1;
}
void checkUser(string name, string username[] , int &logincount) 
{  
  username[logincount] = name;      
  logincount++;

}
float discountedvalue(int &totalprice, float percentage) 
{ // function to calculte rhe discounted value
  float finalprice;
  finalprice = totalprice - totalprice * (percentage / 100);
  return finalprice;   
}

void personalInformation(string name[], string country[], string ID[], string gender[], string age[], int logincount) 
{ // function to take input from user
  ////cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  while (true)
  {
    SetConsoleTextAttribute(h, 11);
    cout << "Enter your name: ";
    SetConsoleTextAttribute(h, 15);
    getline(cin, name[logincount]); 
    if (checkeEmpty(name[logincount]) == 1 || checkstring(name[logincount]) == 1) 
    {
      SetConsoleTextAttribute(h, 4); 
      cout << "Invalid input. " << endl;
      SetConsoleTextAttribute(h, 15);
    }
    else
    {
      break;
    }
  }
  while (true)
  {
    SetConsoleTextAttribute(h, 11);  
    cout << "Enter the country you live in: ";
    SetConsoleTextAttribute(h, 15);
    getline(cin, country[logincount]); 
    if (checkeEmpty(country[logincount]) == 1 || checkstring(country[logincount]) == 1)
    {
      SetConsoleTextAttribute(h, 4);
      cout << "Invalid input. " << endl;
      SetConsoleTextAttribute(h, 15);
    }
    else
    {
      break;
    }
  }

  while (true)
  {
    SetConsoleTextAttribute(h, 11);
    cout << "Enter your ID Number: ";
     string IDnum;
    SetConsoleTextAttribute(h, 15);
    getline(cin, IDnum);
    
    if (check_number(IDnum, 13) == 1 || check_int(IDnum) == 1 || checkeEmpty(IDnum) == 1||checkCNIC(ID,IDnum,logincount)==1) 
    {
      SetConsoleTextAttribute(h, 4);
      cout << "Invalid input or this CNIC is already present." << endl;
      SetConsoleTextAttribute (h, 15);
    }
    else
    {
      ID[logincount]=IDnum;
      break;
    }
  }

  while (true)
  {
    SetConsoleTextAttribute(h, 11);
    cout << "Enter your gender:";
    SetConsoleTextAttribute(h, 15);
    getline(cin, gender[logincount]);
    if (checkeEmpty(gender[logincount]) == 1 || (gender[logincount] != "male" && gender[logincount] != "female" && gender[logincount] != "Male" && gender[logincount] != "Female") || checkSpace(gender[logincount]))
    {
      SetConsoleTextAttribute(h, 4);
      cout << "Invalid input." << endl;
      SetConsoleTextAttribute(h, 15);
    }
    else
    {
      break;
    }
  }
  while (true)
  {
    SetConsoleTextAttribute(h, 11);
    cout << "Enter your age:";
    SetConsoleTextAttribute(h, 15);
    getline(cin,age[logincount]);
    if (checkeEmpty(age[logincount]) == 1 || check_int(age[logincount]) == 1 || checkSpace(age[logincount]))
    {
      SetConsoleTextAttribute(h, 4);
      cout << "Invalid input. " << endl;
      SetConsoleTextAttribute(h, 15);
    }
    else
    {
      break;
    }
  }
  
}
bool checkRoles(string roles)
{
    if(roles!="user"&&roles!="User"&&roles!="Customer"&&roles!="customer"&&roles!="Admin"&&roles!="admin"&&roles!="owner"&&roles!="Owner"&&roles!="Manager"&&roles!="manager")
    {
      return 1;
    }
    else 
    return 0;
}
void readDiscountPercentage(float &discountpercentage)
{
  fstream file;
  file.open("PercentageData.txt",ios::in);
  file>>   discountpercentage;
  file.close();
}
int totalprice(int total)
{ // returns the total price
  return total;
}
bool checkArrival(string availableArrival[],string arrival,int logincount,string departure[],int logincount1)
{     
  for(int x=0;x<logincount;x++) 
{
   if(arrival==availableArrival[x]) 
   {
    return 0;
   }
}
return 1;
   
}

bool checkDeparture(string availableDeparture[],string departure,int logincount,string arrival[],int logincount1) 
{    
  for(int x=0;x<logincount;x++) 
  {
    if(departure==availableDeparture[x])
    {
      return 0;   
    }
  }
  return 1;
} 

void flightInformation(string arrival[], string departure[], string date[], string dayOfDeparture[], int logincount,string availableDepartue[],string availableArrivals[],int departurecount,int arrivalcount) 
{ // takes input about flight
    viewShedule(availableArrivals,availableDepartue,departurecount,arrivalcount);
  ////cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  
  while (true)
  {
    SetConsoleTextAttribute(h, 11);
    cout << "Enter the place of departure: ";
    SetConsoleTextAttribute(h, 15);  
    getline(cin, departure[logincount]);
    if (checkeEmpty(departure[logincount]) == 1 || checkstring(departure[logincount]) == 1||checkDeparture(availableDepartue,departure[logincount],departurecount,availableArrivals,arrivalcount)==1)
    {
      SetConsoleTextAttribute(h, 4);
      cout << "Invalid input or this place is not present in the record." << endl; 
      SetConsoleTextAttribute(h, 15);
    }
    else
    {
      break;
    }
  }
  while (true)
  {
    SetConsoleTextAttribute(h, 11); 
    cout << "Enter the place of arrival: "; 
    SetConsoleTextAttribute(h, 15);
    getline(cin, arrival[logincount]);
    if (checkeEmpty(arrival[logincount]) == 1 || checkstring(arrival[logincount]) == 1 || checkPlaces(arrival, departure, logincount) == 1||checkArrival(availableArrivals,arrival[logincount],arrivalcount,availableDepartue,departurecount)==1)
    {
      SetConsoleTextAttribute(h, 4);
      cout << "Invalid input. " << endl;
      SetConsoleTextAttribute(h, 15);
    }

    else
    {
      break;
    }
  }
  while (true)
  {
    SetConsoleTextAttribute(h, 11);
    cout << "Enter the date of departure: ";
    SetConsoleTextAttribute(h, 15);

    getline(cin, date[logincount]);
    if (checkeEmpty(date[logincount]) == 1) 
    {
      SetConsoleTextAttribute(h, 4);
      cout << "Invalid input." << endl;
      SetConsoleTextAttribute(h, 15);
    }
    else
    {
      break;
    }
  }
  while (true)
  {
    SetConsoleTextAttribute(h, 11); 
    cout << "Enter the day of departure(the first letter must be capital): ";
    SetConsoleTextAttribute(h, 15);
    getline(cin, dayOfDeparture[logincount]);
    if (checkeEmpty(dayOfDeparture[logincount]) == 1 || checkstring(dayOfDeparture[logincount]) == 1||checkDays(dayOfDeparture[logincount])==1) 
    {
      SetConsoleTextAttribute(h, 4); 
      cout << "Invalid input. " << endl; 
      SetConsoleTextAttribute(h, 15);
    }
    else
    {
      break;
    }
  }
   
}

void InflightServices(string leg[], string food[], int logincount) 
{ // takes input about inflight services
  ////cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  SetConsoleTextAttribute(h, 11);
  cout << "Which services you want to avail: " << endl;
  SetConsoleTextAttribute(h, 15);
  while (true)
  {
    SetConsoleTextAttribute(h, 11);
    cout << "Extra leg space(Yes/No): ";
    SetConsoleTextAttribute(h, 15);
    getline(cin, leg[logincount]);
    if (checkeEmpty(leg[logincount]) == 1 || checkstring(leg[logincount]) == 1)
    {
      SetConsoleTextAttribute(h, 4);
      cout << "Invalid input. " << endl;
      SetConsoleTextAttribute(h, 15);
    }
    else
    {
      break;
    }
  }
  while (true)
  {
    SetConsoleTextAttribute(h, 11);
    cout << "Food Service(Yes/No):";
    SetConsoleTextAttribute(h, 15);
    getline(cin, food[logincount]);
    if (checkeEmpty(food[logincount]) == 1 || checkstring(food[logincount]) == 1) 
    {
      SetConsoleTextAttribute(h, 4); 
      cout << "Invalid input." << endl; 
      SetConsoleTextAttribute(h, 15); 
    }
    else
    {
      break;
    }
  }
  
}
string subMenuBeforeMainMenu(string message) 
{ // returns the submenu
  string menu = message + "Menu";
  return menu;
  SetConsoleTextAttribute(h, 11);
  cout << "*.......................*" << endl;  
  SetConsoleTextAttribute(h, 15);
}
void printscreen()
{
  system("cls");
  printHeader();
}

string classSelection(string clas[], int logincount)  
{ // returns the class selected by the user
  ////cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
  SetConsoleTextAttribute(h, 11);
  cout << "Select your class: " << endl;
  cout << " Economy" << endl;
  cout << " Business" << endl;
  SetConsoleTextAttribute(h, 15);
  while (true)
  {
    SetConsoleTextAttribute(h, 11);
    cout << " Write your class here: ";
    SetConsoleTextAttribute(h, 15);
    getline(cin, clas[logincount]);
    if (checkeEmpty(clas[logincount]) == 1 || checkstring(clas[logincount]) == 1)
    {
      SetConsoleTextAttribute(h, 4);
      cout << "Invalid input." << endl; 
      SetConsoleTextAttribute(h, 15);
    }
    else
    {
      break;
    }
  }
   
  return clas[logincount];
}

string reviews(string review[], int logincount)  
{ // returns the reviews entered by user
  ////cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
  while (true)
  {
    SetConsoleTextAttribute(h, 11);
    cout << "Enter your reviews: ";
    SetConsoleTextAttribute(h, 15);
    getline(cin, review[logincount]); 
    if (checkeEmpty(review[logincount]) == 1)  
    {
      SetConsoleTextAttribute(h, 4); 
      cout << "Invalid input." << endl;
      SetConsoleTextAttribute(h, 15);  
    }
    else
    {
      break;
    }
  }
 
    
   
  return review[logincount];
  
}
bool budget(int budget, int ticketprice) 
{ // checks if the enetred budget is enough or not.
  bool statement;

  if (budget >= ticketprice)
  {
    statement = false;
  }
  else
  {
    statement = true;
  }
  return statement;
}
void availableAirline(string airline[], int &count) 
{ // printsavailable airlines enterd by the owner
    fstream file;  
    file.open("AirlineData.txt",ios::in); 
    string var; 
    int x=0; 
    while(!file.eof())  
  {
      getline(file,var);     
      airline[x]=getField(var,1);  
  
    
    x++; 
    count++;
  }
  for(int index=0;index<x-1;index++) 
  {
   SetConsoleTextAttribute(h, 11); 
    cout << "\t\t\t\t\t\t" << index + 1 << ". " << airline[index] << endl;          
    SetConsoleTextAttribute(h, 15);
  }
}

void selectairline(string airlines[], int airlineChoice, int aircount,string selectedairlines[],int logincount)
{ // returns the selected airline
  string result;

  if (airlineChoice - 1 > aircount) 
  {
    SetConsoleTextAttribute(h, 4);
    result = "Invalid option.";
    SetConsoleTextAttribute(h, 15); 
  }
  else
  {
    selectedairlines[logincount] = airlines[airlineChoice - 1];   
  }
  
}
void viewDiscountOptions(string discount[], int dayscount) 
{ // prints the days on which discount is available
      fstream file; 
      file.open("DiscountData.txt",ios::in);
      string var;
      int index=0;
     
      while(!file.eof()) 
      {
        file >>var; 
        discount[index]=getField(var,index+1);       
        index++;  
      
      }
      file.close();
  for (int x = 0; x < index; x++)  
  {      
    SetConsoleTextAttribute(h, 11);
    cout << x + 1 << ". " << discount[x] << endl; 
    SetConsoleTextAttribute(h, 15); 
  }
}
string discountday(string discountday[], int dayscount, int option)
{ // returns the option selected by user
  cin >> option;   
  return discountday[option - 1]; 
}
bool isDiscountAvailable(string day[], int logincount, int daysofdiscount, string discount[]) 
{ // checks whether discount is avaible or not
      fstream file;
      string variable;
      file.open("Discountdata.txt",ios::in);
      int x=0;
         
      while(!file.eof())
      { 
         getline(file,variable);
       discount[x]=getField(variable,x+1); 
       x++;
      }

      
  bool isFound = false;
  for (int index = 0; index <x; index++)
  {
    if (day[logincount] == discount[index])
    {
      isFound = true;
      break;
    }
  }
  return isFound; 
}

string OwnerInterface(string op)   
{ // prints the owner interface
  SetConsoleTextAttribute(h, 11);
  cout << "\t\t\t\t\tSelect one of the folowing option: " << endl; 
  cout << "\t\t\t\t\t1. Add employee: " << endl; 
  cout << "\t\t\t\t\t2. Remove employee: " << endl; 
  cout << "\t\t\t\t\t3. Add Airline:  " << endl; 
  cout << "\t\t\t\t\t4. View employee list:" << endl; 
  cout << "\t\t\t\t\t5. Price allocation:" << endl; 
  cout << "\t\t\t\t\t6. Price allocation for services:" << endl; 
  cout << "\t\t\t\t\t7. Salary allocation to employees:  " << endl; 
  cout << "\t\t\t\t\t8. Discount allocation:" << endl; 
  cout << "\t\t\t\t\t9. Enter the percentage of discount:  " << endl; 
  cout << "\t\t\t\t\t10. Announce something to the employee: " << endl; 
  cout << "\t\t\t\t\t11. Customer reviews:" << endl; 
  cout << "\t\t\t\t\t12. Revenue interface: " << endl; 
  cout << "\t\t\t\t\t13. Log out" << endl; 
  cout << "\t\t\t\t\tEnter your choice : " << endl;
  SetConsoleTextAttribute(h, 15); 
  getline(cin,op);
  return op;
}
void addEmployeeData(string name,string ID,string usernameForEmployee[],int logincount)
{
  fstream file;   
  file.open("Employeedata.txt",ios::app);    
  file << name <<",";   
  file << ID <<",";   
  file << usernameForEmployee[logincount]<<",";   
  file << endl;   
  
  file.close();   
}
bool Addemployee(string name, string ID, string employee[], string IDNUM[], int &logincount,string username, string usernameforemployee[]) 
{ // add the employee
    fstream file; 
    file.open("Employeedata.txt",ios::in);   
    string var; 
    int index=0;
    while(!file.eof())
    {
         getline(file,var);
         employee[index]=getField(var,1);  
         IDNUM[index] = getField(var,2);
         usernameforemployee[index]=getField(var,3); 
         
         index ++;
        
    }
    file.close();
  bool isFound = true;
  for (int x = 0; x < index-1; x++) 
  {
    if (username == usernameforemployee[x] || ID == IDNUM[x])   
    {
      isFound = false;
      break;
    }
  }
  if (isFound == true) 
  {
    employee[logincount] = name; 
    IDNUM[logincount] = ID;
    usernameforemployee[logincount] =username;  
    addEmployeeData(name,ID,usernameforemployee,logincount);     
    logincount++;      
  }

  return isFound; 
}
bool removeEmployeeData(string removingEmployee,string employees[],string ID[],string username[],int &logincount)   
{    string result; 
  fstream file;
  file.open("Employeedata.txt",ios::in);  
  string var;  
  int x=0; 
  while(!file.eof())  
  { 
   getline(file,var);     
   result= getField(var,3);  
   if(result==removingEmployee)   
   {        
     employees[x]="";    
     ID[x]="";   
     username[x]="";     
     addEmployeeDataAfterRemoval(employees,ID,username,logincount); 
     return true;     
   }

   x++;
  }
  file.close();  
  return false;   
}

void addEmployeeDataAfterRemoval(string employee[],string ID[],string username[],int &logincount) 
{
    int z=-1;
    fstream file; 
    file.open("Employeedata.txt",ios::out);   
    for(int x=0;x<logincount;x++) 
    {
      if(employee[x]=="") 
      {
        z=x;
        continue;
      }
      file << employee[x]<<","<<ID[x]<<","<<username[x]<<","<<endl; 
    }
    if(z!=-1) 
    {
      logincount--; 
    }
    
}
bool removeEmployee(string removingEmployee, string name[], string ID[], int &logincount, string usernameForEmployee[]) 
{ // removes the employee
     bool isfound =false; 
    if( removeEmployeeData(removingEmployee,name,ID,usernameForEmployee,logincount) ) 
    {     
      isfound = true;
    }
  
  return isfound;
}
void AirlineData(string airline,string airlineCode)  

{
  fstream file;
  file.open("AirlineData.txt",ios::app); 
  file << airline <<",";
  file << airlineCode <<","<< endl;
  file.close();
  
  
}
int revenueInterface(int totalprice) 
{ 
  // returns the total revenue
   readTotalrevenue(totalprice);  
  return totalprice; 
}
void addAirline(string airline[], string airlinecode[], int &aircount) 
{ 
  // adds the airline enetred by owner
  ////cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  string var; 
  bool isFound = true;
  string var1;
  while (true)
  {
    SetConsoleTextAttribute(h, 11);
    cout << "Enter the Airline: ";
    SetConsoleTextAttribute(h, 15);
    getline(cin, var1);
    if (checkeEmpty(var1) == 1)
    {
      SetConsoleTextAttribute(h, 4);
      cout << "invalid input." << endl;
      SetConsoleTextAttribute(h, 15);
    }
    else
    {
      break;
    }
  }

  while (true)
  {
    SetConsoleTextAttribute(h, 11);
    cout << "Enter the Airline Code(must be 3 integers): ";
    SetConsoleTextAttribute(h, 15);
    getline(cin, var);
    if (check_int(var) == 1 || check_number(var, 3) == 1 || checkeEmpty(var) == 1)
    {
      SetConsoleTextAttribute(h, 4);
      cout << "Invalid input." << endl;
      SetConsoleTextAttribute(h, 15);
    }
    else
    {
      break;
    }
  }
  fstream file;
     file.open("AirlineData.txt",ios::in); 
     string variable;
     int x=0;
     while(!file.eof())
     {
        getline(file,variable); 
        airlinecode[x]= getField(variable,2);
        airline[x]=getField(variable,1); 
        x++;
        aircount++; 
     }
     file.close();
  for (int index = 0; index <x-1 ; index++)   
  {    
    if (var == airlinecode[index] || airline[index] == var1) 
    {
      SetConsoleTextAttribute(h, 4);
      cout << "Airline alredy present." << endl;
      SetConsoleTextAttribute(h, 15); 
      isFound = false;
      break;
    }
  }
  if (isFound == true)
  {  AirlineData(var1,var); 
     
    airline[aircount] = var1;
    airlinecode[aircount] = var;
    aircount++;
  }
}
void readReviews(string reviews[],int &var) 
{    fstream file;
     file.open("UsersData.txt",ios::in);
     string line;
     while(!file.eof())
     {
         getline(file,line);
         reviews[var]=getField(line,16); 
         var++;
     }

}
void customerReviews(string customerReviews[], int logincount)  
{ 
  // prints the customer reviews
  int var=0;
    readReviews(customerReviews,var); 

  SetConsoleTextAttribute(h, 11);

  if (logincount == 0)   
  {
    cout << "There are no customer reviews yet." << endl;  
  }
  else
  {
    for (int index = 0; index < var-1; index++) 
    {
      if (customerReviews[index] == "")  
      {
        cout << "This customer has not shared any reviews or the ticket has been cancelled." << endl; 
      }
      else
      {
        cout << customerReviews[index] << endl;
        SetConsoleTextAttribute(h, 15); 
      }
    }
  }
}
void employeeList(string employee[], string IDnum[],string username[], int &logincount) 
{ 
  // prints the employee list
    fstream file; 
    file.open("Employeedata.txt",ios::in); 
    string var;
  SetConsoleTextAttribute(h, 11);
  cout << "\t\t\t\t\t\t\tName"
       << "\t\t "
       << "ID" <<"\t\tUsername" <<endl;
  SetConsoleTextAttribute(h, 15);
  int index=0;
   while(!file.eof()) 
  {    getline(file,var);  
      SetConsoleTextAttribute(h, 11); 
       employee[index]=getField(var,1);     
        IDnum[index]=getField(var,2);
        username[index]=getField(var,3);
        index++;    
        
  }
  file.close(); 
  for(int x=0;x<index-1;x++)  
  {
      cout << "\t\t\t\t\t\t\t" <<employee[x] << "\t\t " << IDnum[x] <<"\t\t"<<username[x]<< endl;    
    SetConsoleTextAttribute(h, 15);  
  }
   
  
}
void addPrice(int ticketprice)
{
    fstream file;
    file.open("addPrice.txt",ios::out);  
    file << ticketprice; 
    file.close();
    
}
int pricealloaction(int &ticketprice)  
{ // allocates the price to the user
  ////cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  
  string var1; 
  SetConsoleTextAttribute(h, 11);
  while (true)
  {
    cout << "Enter the price of ticket: ";
    SetConsoleTextAttribute(h, 15);

    getline(cin, var1); 
    if (check_int(var1) == 1 || checkeEmpty(var1) == 1) 
    {
      cout << "Invalid input." << endl;
    }
    else
    {
      break;
    }
  }

  ticketprice = stoi(var1);      
  addPrice(ticketprice);  
  return ticketprice; 
}
void addExtraCharges(int business,int legspace,int food)
{
  fstream file;
  file.open("ExtraCharges.txt",ios::out); 
   file << legspace<<","<<food<<","<<business<<endl;
   
}
void extraCharges(int &business, int &legspace, int &food)
{ // takes input from owner about extra charges
  ////cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  string leg, foodservice, clas;
  while (true)
  {
    SetConsoleTextAttribute(h, 11);
    cout << "Enter the charges for legspace:";
    SetConsoleTextAttribute(h, 15);
    getline(cin, leg);
    if (check_int(leg) == 1 || checkeEmpty(leg) == 1)
    {
      SetConsoleTextAttribute(h, 4);
      cout << "Invalid input." << endl;
      SetConsoleTextAttribute(h, 15);
    }
    else
    {
      break;
    }
  }
  while (true)
  {
    SetConsoleTextAttribute(h, 11);
    cout << "Enter the charges for food service: ";
    SetConsoleTextAttribute(h, 15);
    getline(cin, foodservice);
    if (check_int(foodservice) == 1 || checkeEmpty(foodservice) == 1)
    {
      SetConsoleTextAttribute(h, 4);
      cout << "Invalid input. " << endl;
      SetConsoleTextAttribute(h, 15);
    }
    else
    {
      break;
    }
  }
  while (true)
  {
    SetConsoleTextAttribute(h, 11);
    cout << "Enter the charges for business class: ";
    SetConsoleTextAttribute(h, 15);
    getline(cin, clas);
    if (check_int(clas) == 1 || checkeEmpty(clas) == 1) 
    {
      SetConsoleTextAttribute(h, 4);
      cout << "Invalid input." << endl;
      SetConsoleTextAttribute(h, 15);
    }
    else
    {
      break;
    }
  }
  legspace = stoi(leg);
  food = stoi(foodservice);
  business = stoi(clas);
  addExtraCharges(business,legspace,food); 
}
int salaryfixation(int &salary)
{ // takes input from owner about salary
  ////cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
  string checkSalary;
  SetConsoleTextAttribute(h, 11);
  while (true)
  {
    cout << "How much salary do you want to pay: "; 
    SetConsoleTextAttribute(h, 15);
    getline(cin, checkSalary);  
    if (check_int(checkSalary) == 1 || checkeEmpty(checkSalary) == 1)   
    {
      SetConsoleTextAttribute(h, 4);
      cout << "Invalid input." << endl;
    }
    else
    {
      break;
    }
  }
  salary = stoi(checkSalary); 

  return salary;  
}
void readTotalrevenue(int &totalrevenue) 
{
  fstream file;
  file.open("TotalrevenueData.txt",ios::in);
  file >> totalrevenue;
  file.close();
}
int salarymanagement(string employee[], int count, int &totalrevenue, string IDnum[], int salary) 
{ // allocates the salary to employee
     fstream file;
     file.open("Employeedata.txt",ios::in); 
     string var; 
     int index=0;
     while(!file.eof())  
     {
           getline(file,var);
           employee[index]=getField(var,1); 
           IDnum[index]=getField(var,2); 
           index++; 
           
     }
     readTotalrevenue(totalrevenue); 
  string answer;
  
  for (int x = 0; x < index-1; x++) 
  {
    if ((employee[x] != "" && IDnum[x] != ""))  
    {
      SetConsoleTextAttribute(h, 11);  
      cout << employee[x] << "\t"
           << "Yes/No:"; 
      SetConsoleTextAttribute(h, 15);
      cin >> answer;

      if (answer == "Yes" || answer == "yes")
      {
        totalrevenue = totalrevenue - salary;  
        totalrevenueData(totalrevenue); 
      }
    }

    else
    {
      totalrevenue = totalrevenue;  
      totalrevenueData(totalrevenue); 
    }
  }

  return totalrevenue; 
}
void clearscreen()
{
  SetConsoleTextAttribute(h, 11);
  cout << "Press any key to continue: " << endl;
  SetConsoleTextAttribute(h, 15);
  getch();
}
void discountData(string discount[],int discountcount)
{
  fstream file;
  file.open("DiscountData.txt",ios::out); 
  if(discountcount==0)
  {
     file<<"";
  }
  else
  {
    for(int x=0;x<discountcount;x++)
  {
    file << discount[x]<<","; 
  }
  }
  
  file.close();
}
void discount(string discount[], int &dayscount) 
{ // takes input from owner about discount option.
  ////cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  SetConsoleTextAttribute(h, 11);
  cout << "Enter on how many days you want to give discount: ";
  SetConsoleTextAttribute(h, 15);
  cin >> dayscount;
  for (int index = 0; index < dayscount; index++)
  {
    while (true)
    {

      SetConsoleTextAttribute(h, 11);
      cout << "Enter the day on which you want to give discount: ";
      SetConsoleTextAttribute(h, 15);
      cin.ignore();
      getline(cin, discount[index]);
      if (checkstring(discount[index]) == 1 || checkeEmpty(discount[index]) == 1) 
      {        
        SetConsoleTextAttribute(h, 4);
        cout << "Invalid input." << endl; 
      }
      else
      {
        break;
      }
    }
  }
  discountData(discount,dayscount);  
}
void announcementData(string announcement)  
{
    fstream file;
    file.open("AnnouncementData.txt",ios::out);
    file << announcement;
    file.close();
}

void announcementToEmployee(string &announcement) 
{ // takes input from owner about announcements
  ////cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  SetConsoleTextAttribute(h, 11);
  while (true)
  {
    cout << "What you want to announce to employee:";
    SetConsoleTextAttribute(h, 15);
    getline(cin, announcement);
    if (checkeEmpty(announcement) == 1)
    {
      SetConsoleTextAttribute(h, 4);
      cout << "Invalid input." << endl;
    }
    else

    {
      break;
    }
  }
  announcementData(announcement);
}
void percentageData(float percentage)
{
    fstream file;
    file.open("PercentageData.txt",ios::out);
    file << percentage;
    file.close();
}
float percentageOfDiscount(float &percentage) 
{ // takes input regarding to percenrage of discount
   ////cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    string result;
    getline(cin,result);
    percentage=stof(result);  

    percentageData(percentage);  
  return percentage;
}
string Employeeinterface(string op)
{ // prints the employee interface
  SetConsoleTextAttribute(h, 11);
  ////cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
  cout << "\t\t\t\t\t\tSelect one of the following option:" << endl;
  cout << "\t\t\t\t\t\t1. Enter the shedule of tckets: "<<endl;
  cout << "\t\t\t\t\t\t2. View how many tickets have been sold." << endl;
  cout << "\t\t\t\t\t\t3. View which airlines have been selected." << endl;
  cout << "\t\t\t\t\t\t4. View which services have been selected." << endl;
  cout << "\t\t\t\t\t\t5. Profit and loss calculation:" << endl;
  cout << "\t\t\t\t\t\t6. View announcements from owner: " << endl;
  cout << "\t\t\t\t\t\t7. View information of customer:" << endl;      
  
  cout << "\t\t\t\t\t\t8. Log out." << endl; 
  SetConsoleTextAttribute(h, 15);
    getline(cin,op); 
  return op;
}
void loading() 
{
  cout << "\t\t\t\t _                    _ _     " << endl; 
  cout << "\t\t\t\t| |    ___   __ _  __| (_)_ __   __ _  " << endl;
  cout << "\t\t\t\t| |   / _ \\ / _` |/ _` | | '_ \\ / _` | " << endl;
  cout << "\t\t\t\t| |__| (_) | (_| | (_| | | | | | (_| |  " << endl;
  cout << "\t\t\t\t|_____\\___/ \\__,_|\\__,_|_|_| |_|\\__, |   " << endl;
  cout << "\t\t\t\t                                |___/    " << endl;
  cout << "\t\t\t\t\t\t\t.";
  for (int x = 0; x < 10; x++)
  {
    cout << ".";
    Sleep(500);
  }
}
void loginmenu()
{
  SetConsoleTextAttribute(h, 11);
  cout << "\t\t\t\t\t\t\t _                _         __  __      " << endl;
  cout << "\t\t\t\t\t\t\t| |    ___   __ _(_)_ __   |  \\/  | ___ _ __  _   _ " << endl;
  cout << "\t\t\t\t\t\t\t| |   / _ \\ / _` | | '_ \\  | |\\/| |/ _ \\ '_ \\| | | |  " << endl;
  cout << "\t\t\t\t\t\t\t| |__| (_) | (_| | | | | | | |  | |  __/ | | | |_| |   " << endl;
  cout << "\t\t\t\t\t\t\t|_____\\___/ \\__, |_|_| |_| |_|  |_|\\___|_| |_|\\__,_|  " << endl;
  cout << "\t\t\t\t\t\t\t            |___/                                     " << endl; 
}
void addTickestCount(int logincount) 
{
  fstream file;
  file.open("TicketsData.txt",ios::out);
  file << logincount << endl;  
  file.close(); 
}
int ticketscount(int logincount) 
{ // counts how many tickets have been sold
     
     fstream file;
     file.open("TicketsData.txt",ios::in);
    file >> logincount; 
  return logincount; 
}

void viewselectedAirlines(string selectedairline[], int logincount)  
{ // prints the seleted airlines
    fstream file; 
    string var; 
    file.open("UsersData.txt",ios::in); 
    int x=0;
    while(!(file.eof()))
    {   
      getline(file,var);
      
      selectedairline[x]=getField(var,15);
      x++;
    }
    file.close(); 
  for (int index = 0; index < x-1; index++)  
  {
    SetConsoleTextAttribute(h, 11); 
     
   
    if(selectedairline[index]=="")
    {      SetConsoleTextAttribute(h, 11);
         cout<<"The ticket has been cancelled."<<endl;

     }
     else
     {
       cout << index + 1 << ". " << selectedairline[index] << endl; 
    SetConsoleTextAttribute(h, 15); 
     }
  }
}
void viewselectedServices(string leg[], string food[], string clas[], int logincount) 
{ // prints the selected services
     fstream file;
     file.open("UsersData.txt",ios::in);
     string var;
     int x=0;
     while(!file.eof())
     {
        getline(file,var);
         leg[x]=getField(var,8);
         food[x]=getField(var,9); 
         x++;
     }
     file.close();
     
  SetConsoleTextAttribute(h, 11); 
  cout << "LegService  Foodservice   " << endl;  
  SetConsoleTextAttribute(h, 15);
  for (int index = 0; index < x-1; index++)  
  {
    SetConsoleTextAttribute(h, 11);
    cout << leg[index] << "     " << food[index]  << endl; 
    SetConsoleTextAttribute(h, 15);
    if(leg[index]==""&&food[index]=="")
    {
      cout<<"Cancelled  Cancelled"<<endl; 
    }
    else if(leg[index]=="")
    {
      cout<<"Cancelled"<<endl;
    }
    else if (food[index]=="")
    {
      cout<<"Cancelled"<<endl; 
    }
  }
}
void totalrevenueData(int totalrevenue)
{
    fstream file;
    file.open("TotalRevenueData.txt",ios::out);
    file << totalrevenue;
    file.close();
}
void profitandLoss(int &totalrevenue)  
{ // calcultes whether there is profit or loss
   ////cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
  string fuel;  
  SetConsoleTextAttribute(h, 11); 
  while(true)
  {
    cout << "Enter the expenses of fuel: ";
  SetConsoleTextAttribute(h, 15);
  getline(cin,fuel);
    if(check_int(fuel)==1||checkeEmpty(fuel)==1) 
    {
      SetConsoleTextAttribute(h, 4); 
      cout << "Invalid input."<<endl;
    }
    else 
    {
      break;
    }
  }
   string electricity;  
     while(true)
     {
     SetConsoleTextAttribute(h, 11);
  cout << "Enter the expenses of electricity: ";
  SetConsoleTextAttribute(h, 15); 
 
  getline(cin,electricity); 
  if(checkeEmpty(electricity)==1||check_int(electricity)==1)
  {
    SetConsoleTextAttribute(h, 4);
  cout << "Invalid input. "<<endl;
  SetConsoleTextAttribute(h, 15); 
  }
  else 
  {
    break;
  }

     }
  
    readTotalrevenue(totalrevenue);
  int totalexpenses = stoi(fuel) + stoi(electricity);
  if (totalexpenses > totalrevenue) 
  {     int result;
    result = totalexpenses - totalrevenue; 
    
    SetConsoleTextAttribute(h, 4);
    cout << "There has been loss of $" << result << endl;
    SetConsoleTextAttribute(h, 15);
    for (int x = 0; x < 10; x++)
    {
      SetConsoleTextAttribute(h, 4);  
      cout << "|" << endl;
      if (x + 1 == 10)
      {
        cout << "________LOSS_________" << endl;  
      }
    }
  }
  else if (totalrevenue > totalexpenses) 
  {   int result;
    result = totalrevenue - totalexpenses; 
    
    SetConsoleTextAttribute(h, 2);
    cout << "There has been profit of $" <<result << endl;
    SetConsoleTextAttribute(h, 15);
    for (int x = 0; x < 10; x++)
    {
      SetConsoleTextAttribute(h, 2);
      cout << "|" << endl;
      if (x + 1 == 10)
      {
        cout << "_________Profit______________" << endl;
      }
    }
  }
}
void viewAnnouncements(string announcement) 
{ // view the announvemets from owner
    fstream file;
    file.open("AnnouncementData.txt",ios::in);
    getline(file,announcement);
    file.close();
  ////cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  SetConsoleTextAttribute(h, 11);
  cout << announcement << endl;
  SetConsoleTextAttribute(h, 15);
}
void viewCustomerInformation(string name[], string ID[], string country[], string gender[], string age[], string arrival[], string departure[], string date[], string day[], int logincount)
{      
  ////cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
  SetConsoleTextAttribute(h, 11);
  cout << "Enter the name of customer whose Information you want to see:";
  SetConsoleTextAttribute(h, 15);
  string nameofUser; 
  getline(cin, nameofUser);  
  fstream file;
  file.open("UsersData.txt",ios::in);
  string var;
  while(!file.eof()) 
  {
     getline(file,var);  
     if(nameofUser==getField(var,2)) 
     {  logincount = stoi(getField(var,18)); 
           name[logincount]=getField(var,2);
           ID[logincount]=getField(var,12);
           country[logincount]=getField(var,3);
           gender[logincount]=getField(var,4);
           age[logincount]=getField(var,5);
           arrival[logincount]=getField(var,6);
           departure[logincount]=getField(var,7);
           date[logincount]=getField(var,10);
           day[logincount]=getField(var,11); 
           break;
     }
  
  }
     if(name[logincount]=="")
     {   SetConsoleTextAttribute(h, 11);  
        cout<<"No such customer is present or the ticket has been cancelled."<<endl;
     }
  else
  {
   SetConsoleTextAttribute(h, 11);  
      cout << name[logincount] << endl;  
      cout << ID[logincount] << endl;   
      cout << country[logincount] << endl; 
      cout << gender[logincount] << endl;
      cout << age[logincount] << endl;
      cout << arrival[logincount] << endl;
      cout << departure[logincount] << endl;
      cout << date[logincount] << endl;
      cout << day[logincount] << endl; 
      cout << endl;
      SetConsoleTextAttribute(h, 15);
  }
 
  SetConsoleTextAttribute(h, 15);
    
  
      
    }
   
  


void cancelllationOfTicket(string name[], string ID[], string gender[], int &totalrevenue, string age[], string departure[], string arrival[], string leg[], string food[], string clas[], string date[], string day[], int &price, string reviews[], int logincount, string airline[])
{ // cancells the ticket of user
  totalrevenue = totalrevenue - price;
  name[logincount] = " ";
  ID[logincount] = " ";
  gender[logincount] = " ";
  age[logincount] = " ";
  departure[logincount] = " ";
  arrival[logincount] = " ";
  leg[logincount] = " ";
  food[logincount] = " ";
  clas[logincount] = " ";
  date[logincount] = " ";
  day[logincount] = " ";
  price = 0;
  reviews[logincount] = " ";
  airline[logincount] = " ";
}

bool check_number(string check, int length)
{ // function to check the length of input.

  if (check.size() != length)
  {
    return 1;
  }
  return 0;
}
bool check_int(string var)
{ // function to check whether the input is  integer

  for (int x = 0; var[x] != '\0'; x++)
  {

    int num = var[x];
    if (num != 48 && num != 49 && num != 50 && num != 51 && num != 52 && num != 53 && num != 54 && num != 55 && num != 56 && num != 57)
    {

      return 1;
    }
  }
  return 0;
}
bool checkDays(string check)
{
    if(check=="Sunday"||check=="Monday"||check=="Tuesday"||check=="Wednesday"||check=="Thursday"||check=="Friday"||check=="Saturday")
    {
      return 0;
    }
    else
    return 1;
}
bool checkeEmpty(string check)
{
  if (check == "")
  {
    return 1;
  }
  return 0;
}
bool checkSpace(string check)
{
  for (int x = 0; check[x] != '\0'; x++)
  {
    int num = check[x];
    if (num == 32)
    {
      return 1;
    }
  }
  return 0;
}
void setColor(int color)
{
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
void printaAeroplane()
{
  cout << endl;
  cout << endl;
  cout << endl;
  cout << endl;
  cout << endl;
  cout << endl;
  SetConsoleTextAttribute(h, 11);
  cout << "\t\t\t\t__        __   _                            _          ____  _    " << endl;
  cout << "\t\t\t\t\\ \\      / /__| | ___ ___  _ __ ___   ___  | |_ ___   / ___|| | ___   _ " << endl;
  cout << "\t\t\t\t \\ \\ /\\ / / _ \\ |/ __/ _ \\| '_ ` _ \\ / _ \\ | __/ _ \\  \\___ \\| |/ / | | |   " << endl;
  cout << "\t\t\t\t  \\ V  V /  __/ | (_| (_) | | | | | |  __/ | || (_) |  ___) |   <| |_| |  " << endl;
  cout << "\t\t\t\t__ \\_/\\_/ \\___|_|\\___\\___/|_| |_| |_|\\___|  \\__\\___/  |____/|_|\\_\\__,  |  " << endl;

  cout << "\t\t\t\t\\ \\      / (_)_ __   __ _ ___     / \\  (_)_ __| (_)_ __   ___  ___ |___ /  " << endl;

  cout << "\t\t\t\t \\ \\ /\\ / /| | '_ \\ / _` / __|   / _ \\ | | '__| | | '_ \\ / _ \\/ __|      " << endl;
  cout << "\t\t\t\t  \\ V  V / | | | | | (_| \\__ \\  / ___ \\| | |  | | | | | |  __/\\__ \\      " << endl;
  cout << "\t\t\t\t   \\_/\\_/  |_|_| |_|\\__, |___/ /_/   \\_\\_|_|  |_|_|_| |_|\\___||___/     " << endl;
  cout << "\t\t\t\t                   |___/                                                " << endl;
}
void gotoxy(int x, int y)
{
  COORD coordinates;
  coordinates.X = x;
  coordinates.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
void hideCursor()
{
  HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

  CONSOLE_CURSOR_INFO cursorInfo;
  GetConsoleCursorInfo(consoleHandle, &cursorInfo);
  cursorInfo.bVisible = false;
  SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}
bool checkstring(string check)
{
  for (int x = 0; check[x] != '\0'; x++)
  {
    int num = check[x];
    if (num == 48 || num == 49 || num == 50 || num == 51 || num == 52 || num == 53 || num == 54 || num == 55 || num == 56 || num == 57)
    {
      return 1;
    }
  }
  return 0;
}
void signUpinterface()
{
  SetConsoleTextAttribute(h, 11);
  cout << "\t\t\t\t\t\t\t ____  _               _   _         __  __   " << endl;
  cout << "\t\t\t\t\t\t\t/ ___|(_) __ _ _ __   | | | |_ __   |  \\/  | ___ _ __  _   _ " << endl;
  cout << "\t\t\t\t\t\t\t\\___ \\| |/ _` | '_ \\  | | | | '_ \\  | |\\/| |/ _ \\ '_ \\| | | |  " << endl;
  cout << "\t\t\t\t\t\t\t ___) | | (_| | | | | | |_| | |_) | | |  | |  __/ | | | |_| |         " << endl;
  cout << "\t\t\t\t\t\t\t|____/|_|\\__, |_| |_|  \\___/| .__/  |_|  |_|\\___|_| |_|\\__,_|        " << endl;
  cout << "\t\t\t\t\t\t\t         |___/              |_|                                      " << endl;
}
void signininterface() 
{
  SetConsoleTextAttribute(h, 11);
  cout << "\t\t\t\t\t\t\t ____  _               ___         __  __     " << endl;
  cout << "\t\t\t\t\t\t\t/ ___|(_) __ _ _ __   |_ _|_ __   |  \\/  | ___ _ __  _   _ " << endl;
  cout << "\t\t\t\t\t\t\t\\___ \\| |/ _` | '_ \\   | || '_ \\  | |\\/| |/ _ \\ '_ \\| | | |  " << endl;
  cout << "\t\t\t\t\t\t\t ___) | | (_| | | | |  | || | | | | |  | |  __/ | | | |_| |       " << endl;
  cout << "\t\t\t\t\t\t\t|____/|_|\\__, |_| |_| |___|_| |_| |_|  |_|\\___|_| |_|\\__,_|   " << endl;
  cout << "\t\t\t\t\t\t\t         |___/                                                 " << endl
       << endl;
}
void adminMenu()
{
  SetConsoleTextAttribute(h, 11);
  cout << "\t\t\t\t\t\t\t    _       _           _         __  __     " << endl;
  cout << "\t\t\t\t\t\t\t   / \\   __| |_ __ ___ (_)_ __   |  \\/  | ___ _ __  _   _ " << endl;
  cout << "\t\t\t\t\t\t\t  / _ \\ / _` | '_ ` _ \\| | '_ \\  | |\\/| |/ _ \\ '_ \\| | | | " << endl;
  cout << "\t\t\t\t\t\t\t / ___ \\ (_| | | | | | | | | | | | |  | |  __/ | | | |_| |  " << endl;
  cout << "\t\t\t\t\t\t\t/_/   \\_\\__,_|_| |_| |_|_|_| |_| |_|  |_|\\___|_| |_|\\__,_|   " << endl 
       << endl;
}
void customerMenu()
{
  SetConsoleTextAttribute(h, 11);
  cout << "\t\t\t\t\t\t\t  ____          _                                 __  __    " << endl;
  cout << "\t\t\t\t\t\t\t / ___|   _ ___| |_ ___  _ __ ___   ___ _ __     |  \\/  | ___ _ __  _   _ " << endl; 
  cout << "\t\t\t\t\t\t\t| |  | | | / __| __/ _ \\| '_ ` _ \\ / _ \\ '__|    | |\\/| |/ _ \\ '_ \\| | | |" << endl;
  cout << "\t\t\t\t\t\t\t| |__| |_| \\__ \\ || (_) | | | | | |  __/ |       | |  | |  __/ | | | |_| | " << endl;
  cout << "\t\t\t\t\t\t\t \\____\\__,_|___/\\__\\___/|_| |_| |_|\\___|_|       |_|  |_|\\___|_| |_|\\__,_| " << endl
       << endl;
}
void managerMenu()   
{
  SetConsoleTextAttribute(h, 11);
  cout << "\t\t\t\t\t\t\t __  __                                        __  __       " << endl;
  cout << "\t\t\t\t\t\t\t|  \\/  | __ _ _ __   __ _  __ _  ___ _ __     |  \\/  | ___ _ __  _   _ " << endl;
  cout << "\t\t\t\t\t\t\t| |\\/| |/ _` | '_ \\ / _` |/ _` |/ _ \\ '__|    | |\\/| |/ _ \\ '_ \\| | | | " << endl;
  cout << "\t\t\t\t\t\t\t| |  | | (_| | | | | (_| | (_| |  __/ |       | |  | |  __/ | | | |_| |  " << endl;
  cout << "\t\t\t\t\t\t\t|_|  |_|\\__,_|_| |_|\\__,_|\\__, |\\___|_|       |_|  |_|\\___|_| |_|\\__,_| " << endl;
  cout << "\t\t\t\t\t\t\t                         |___/                                          " << endl
       << endl; 
}
void sheduleData(string departure[],string arrival[],int departurecount,int arrivalcount)
{
     fstream file;
     file.open("SheduleData.txt",ios::out);     
     for(int x=0;x<departurecount;x++)
     {
      file<<departure[x]<<",";
     }
      file << departurecount<<",";
     file<<endl;;
     for(int x=0;x<arrivalcount;x++)
     {
      file <<arrival[x]<<",";
     }
     file<<endl;
     file.close();
}
void daysData(int departurecount,int arrivalcount)
{
  fstream file;
  file.open("Daysdata.txt",ios::out);
  file << departurecount <<","<<arrivalcount<<","<<endl;

}
void shedule(string departure[],string arrival[],int &logincountfordeparture, int &logincountForarrival)
{       ////cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
  string arival;
   while(true)
{   SetConsoleTextAttribute(h,11);
   cout<<"Enter how many places of departure you want to give: "; 
   
    SetConsoleTextAttribute(h,15);
    getline(cin,arival);
    if(check_int(arival)==1||checkeEmpty(arival)==1) 
    {  SetConsoleTextAttribute(h,4);
      cout<<"Invalid input. "<<endl; 
    }
    else 
    {    
      break;
    }
}
    
    logincountfordeparture=stoi(arival);
    SetConsoleTextAttribute(h,11);
    cout<<"Enter the places of departure: "<<endl; 
    for(int x=0;x<logincountfordeparture;x++)
    {  
       while (true)
    {

      getline(cin,departure[x]);
      if(checkeEmpty(departure[x])==1||checkstring(departure[x])==1)
      {
        SetConsoleTextAttribute(h,4);
 cout<<"Invalid input. "<<endl;   
      }
      else 
      {
        break;
      }
     
    }
      
    }
    string deprture;
    while(true)
    {    SetConsoleTextAttribute(h,11);
      cout<<"Enter how many places of arrival you want to give: ";
       SetConsoleTextAttribute(h,15);
      getline(cin,deprture);
      if(check_int(deprture)==1||checkeEmpty(deprture)==1)   
      {   SetConsoleTextAttribute(h,4);
        cout<<"Invalid input. "<<endl;   
      }
      else 
      {  
        break;
      }
    }
    logincountForarrival=stoi(deprture);
    SetConsoleTextAttribute(h,11);
    cout<<"Enter the places of arrival: "<<endl; 
    for(int x=0;x<logincountForarrival;x++)
    {    while(true)
    {
         SetConsoleTextAttribute(h,15);
       getline(cin,arrival[x]);
       if(checkeEmpty(arrival[x])==1||checkstring(arrival[x])==1)
       {    SetConsoleTextAttribute(h,4);
        cout<<"Invalid input."<<endl;
       }
       else 
       {
        break;
       }
    }
    }
    sheduleData(departure,arrival,logincountfordeparture,logincountForarrival);
    daysData(logincountfordeparture,logincountForarrival);
}
bool checkPlaces(string arrival[], string departure[], int logincount)
{
  if (arrival[logincount] == departure[logincount])
  {
    return 1;
  }
  else
  {
    return 0;
  }
}
bool checkCNIC(string ID[],string IDnum,int logincount)  
{     fstream file;
    file.open("Usersdata.txt",ios::in); 
    string var;
    int x=0;
    while(!file.eof())
    {
      getline(file,var);
      ID[x]=getField(var,12); 
      x++;
    }
    file.close();
  for (int index=0;index<x-1;index++)  
  {
    if(IDnum==ID[index])
    {
      return 1;
    }
  }
   
  return 0;
 
}
bool checkSpaces(string var)  
{     
    int num;
    for(int x=0;var[x]!='\0';x++) 
    {
         num=x;
    }
   if(var[0]==' '||var[num]==' '||var[0]=='\0') 
          {
            return 1;
          }
  
  return 0;
}
