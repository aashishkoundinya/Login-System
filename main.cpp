#include<iostream>
#include<string.h>
#include<fstream>
#include<istream>
#include<stdlib.h>

using namespace std;

void login();
void registr();
void forgot();

int main()
{
    int choice;
    cout<<"\n\n---------------HOME PAGE---------------\n\n";
    cout<<"1. Login"<<endl;
    cout<<"2. Register"<<endl;
    cout<<"3. Forgot"<<endl;
    cout<<"\n\nEnter your choice : ";
    cin>>choice;
    switch(choice)
    {
        case 1: login();
                break;

        case 2: registr();
                break;

        case 3: forgot();
                break;

        default: system("cls");
                cout<<"Invalid Choice!!";
                main();        

    }
}

void login()
{
    static int count;
    string user, pass, u, p;
    system("cls");
    cout<<"Enter your username : ";
    cin>>user;
    cout<<"Enter your password : ";
    cin>>pass;

    ifstream input("database.txt");
    while(input >> u >> p)
    {
        if(u==user && p==pass)
        {
            count = 1;
            system("cls");
        }
    }

    input.close();
    if(count==1)
    {
        cout<<"Welcome "<<user<<" you are logged in\n\n";
        main();
    }

    else{
        cout<<"Login error \n";
        main();
    }
}

void registr()
{
    string reguser, regpass;
    system("cls");
    cout<<"Choose your username : ";
    cin>>reguser;
    cout<<"Chose your password : ";
    cin>>regpass;

    ofstream reg("database.txt", ios::app);
    reg << reguser << ' ' << regpass << endl;
    system("cls");
    cout<<"Registration Successfull!!";
    main();
}

void forgot()
{
    int choi;
    cout<<"\n1. Search your account by Username ";
    cout<<"\n2. Search your account by Password ";
    cout<<"\n3. Home Page ";
    cout<<"\n\nEnter your choice : ";
    cin>>choi;

    switch(choi)
    {
        case 1: {
            int ex=0;
            string searchuser, su, sp;
            cout<<"Enter your remembered Username : ";
            cin>>searchuser;

            ifstream searchu("database.txt");
            while(searchu >> su >> sp)
            {
                if(su==searchuser)
                {
                    ex=1;
                    break;
                }
            }

            searchu.close();
            if(ex==1)
            {
                cout<<"\nAccount Found!! ";
                cout<<"\nYour Password is : "<<sp;
                main();
            }

            else
            {
                cout<<"\nAccout not found!!\n";
                main();
            }
            break;
        }

        case 2: {
            int exi=0;
            string searchpass, su2, sp2;
            cout << "Enter the remembered password : ";
		    cin >> searchpass;

		    ifstream searchp("database.txt");
		    while (searchp >> su2 >> sp2) 
            {
			   if (sp2 == searchpass) 
               {
				  exi = 1;
				  break;
			   }
		    }

		    searchp.close();
		    if (exi == 1) 
            {
			cout << "\n\nThe account was found \n\n";
			cout << "Your username is: " << su2;
			cout << "\nYour password is: " << sp2;
			cin.get();
			cin.get();
            system("cls");
			main();
            
		   }
		break;
        }

        case 3: { 
            system("cls");
            main();
            break;
        }

        default:{
            cout<<"You have given a wrong choice , press any key to try again";
            forgot();
            break;
        }
    }
}