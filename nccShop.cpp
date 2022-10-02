//nccAssignment6
//admin panel acc => username admin /password admin

#include "iostream"
using namespace std;

class Shop{
public:
        string username[100];
        string password[100];
        int amount[100];
        int userID = 0;
        string products[100];
        int price[100];
        

        int locate = 0;
        int currentID = 0;
        int currentProductID = 0;
        int number = 0;
        Shop(){
            cout<<"Welcome to our shop"<<endl;

        }
        int reGister();
        int login();
        int mainMenu();
        int allInfo();
        int details();

        int adminPanel();
        int addProducts();
        
        int toCheckUername(string Dname);
        
        int productsDetails();
        int buyProducts();
        int addmoney();
        int toCheckProduct(int id);
};
int Shop::adminPanel(){
    int adminPaneloption = 0;
    cout<<"Press 1 to add products..:"<<endl;
    
    cout<<"Press 2 to go Main Menu..:"<<endl;
    cout<<"Press 3 to see product details..:"<<endl;
    cout<<"Press 4 to quit..:"<<endl;
    cin>>adminPaneloption;
    if(adminPaneloption == 1){
        addProducts();
    }else if(adminPaneloption == 2){
        mainMenu();
    }else if(adminPaneloption == 3){
        productsDetails();
    }else if(adminPaneloption == 4){
        mainMenu();
    }
}

int Shop::addProducts(){
    int aNumber;
    string aProduct;
    int aPrice;
    cout<<"how many products do u want :"<<endl;
    cin>>aNumber;

    for (int i = 0; i < aNumber; i++){

        cout<<"Enter product name..:"<<endl;
        cin>>aProduct;
        products[i] = aProduct;

        cout<<"Enter price :"<<endl;
        cin>>aPrice;
        price[i] = aPrice;

        number++;
    }
    adminPanel();
    
}

int Shop::toCheckUername(string Dname){
    for (int i = 0; i < locate; i++){
        if(Dname == username[i]){
            return 1;
        }else{
            return 10;
        }
    }
}

int Shop::productsDetails(){
    cout<<"Products are"<<endl;
    cout<<"*******************"<<endl;
    for (int i = 0; i < number; i++){

        currentProductID = i;
        
        cout<<"Product ID -"<<currentProductID + 1<<endl;
        cout<<"Produt name -"<<products[i]<<endl;
        cout<<"Price -"<<price[i]<<endl;
    }
    details();
}

int Shop::buyProducts(){
    
    int productID = 0; 
    cout<<"Enter Product ID to buy..:"<<endl;
    cin>>productID;
    int status = toCheckProduct(productID);
    if(status == 1){
        cout<<"Product buy Successfully..."<<endl;
        amount[currentID] = amount[currentID]-price[productID-1];
        allInfo();
        details();
    }else if(status == 10){
        cout<<"we don't have this product..."<<endl;
        productsDetails();
        buyProducts();
    }
}

int Shop::toCheckProduct(int id){
    for (int i = 0; i < number; i++){
        if(id < number){
            return 1;
        }else{
            return 10;
        }
    }
}

int Shop::addmoney(){
    int addAmount = 0;
    cout<<"Enter amount to add money your account ... :"<<endl;
    cin>>addAmount;
    amount[currentID] = amount[currentID]+addAmount;
    cout<<amount[currentID]<<endl;
    details();
}

int Shop::reGister(){
    string rusername;
    string rpassword;
    string rcpassword;
    int ramount;
    cout<<"Welcome from Registeration.."<<endl;
    cout<<"Enter username to register.. :"<<endl;
    cin>>rusername;
    cout<<"Enter password for "<<rusername<<endl;
    cin>>rpassword;
    cout<<"Enter confirm password for..."<<rusername<<endl;
    cin>>rcpassword;
    cout<<"Enter amount.."<<endl;
    cin>>ramount;

    if(rpassword == rcpassword){
        username[locate] = rusername;
        password[locate] = rpassword;
        amount[locate] = ramount;
        cout<<"Registeration Success..."<<endl;
        locate++;
        allInfo();
    }else{
        cout<<"Try agin"<<endl;
        mainMenu();
    }   
}

int Shop::login(){

    string lusername;
    string lpassword;
    cout<<"This is from Login"<<endl;
    cout<<"Enter username to login:";
    cin>>lusername;
    cout<<"Enter pass to login for :"<<lusername<<endl;
    cin>>lpassword;

    if(lusername == "admin" && lpassword == "admin"){
        currentID = 1234;
        cout<<"Login Success"<<endl;
        adminPanel();
    }
    for(int i=0; i<=locate ; i++){
        if(lusername == username[i] && lpassword== password[i]){
            cout<<"Login Success"<<endl;
            currentID = i;
            details();
        }
    }
    return 100;   
}

int Shop::details(){
    int option;
    
    cout<<"Press 1 to buy products "<<endl;
    cout<<"Press 2 to see details products "<<endl;
    cout<<"Press 3 to Add money to account"<<endl;
    cout<<"Press 4 to Quit.."<<endl;
    cin>>option;
    
    if(option == 1){
        buyProducts();
    }else if(option == 2){
      productsDetails();
    }else if(option == 3){
        addmoney();
    }else{
        mainMenu();
    }

}


int Shop::mainMenu(){
    int option;

    while (true)
    {
        cout<<"Press 1 to register..:"<<endl;
        cout<<"Press 2 to login..:"<<endl;
        cout<<"Press 3 to Quit..:"<<endl;
        cin>>option;
        if(option == 1){
            //register
            reGister();

        }else if(option == 2){
            // login
            int status = login();
            if(status == 100){
                cout<<"something wrong.."<<endl;
            }
        }else{
            cout<<"Ta Ta See U"<<endl;
            return 0;
        }
    }
    
}

int Shop::allInfo(){

    cout<<"Username"<<endl;
    for(int i=0; i<=locate ; i++){
        cout<<"   "<<username[i]<<endl;
    }

    cout<<"password are :"<<endl;
    for(int i ; i<= locate ; i++){
        cout<<"  "<<password[i]<<endl;
    }

    cout<<"amount are :"<<endl;
    for(int i ; i<= locate ; i++){
        cout<<"  "<<amount[i]<<endl;
    }
}

int main(){
    Shop _obj;
    int ex =  _obj.mainMenu();
    if(ex == 0){
        exit(1);
    }

}
