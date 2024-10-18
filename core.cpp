#include <bits/stdc++.h>
using namespace std;




// vector<Show*> all_shows;

class Date {
private:
    int date;
    int month;
    int year;

public:
    // Setter methods
    void Set_date(int d) {
        this->date = d;
    }

    void Set_month(int m) {
        this->month = m;
    }

    void Set_year(int y) {
        this->year = y;
    }

    // Getter methods
    int get_date() {
        return this->date;
    }

    int get_month() {
        return this->month;
    }

    int get_year() {
        return this->year;
    }

    // Compare function
    int compare(Date d2) {
        // Compare years
        if (this->year > d2.get_year()) {
            return 1;
        } else if (this->year < d2.get_year()) {
            return -1;
        } else {
            // Compare months
            if (this->month > d2.get_month()) {
                return 1;
            } else if (this->month < d2.get_month()) {
                return -1;
            } else {
                // Compare days
                if (this->date > d2.get_date()) {
                    return 1;
                } else if (this->date < d2.get_date()) {
                    return -1;
                } else {
                    return 0; // Both dates are equal
                }
            }
        }
    }
};

class Time {
private:
    int hour;
    int minute;

public:
    // Setter methods
    void Set_hour(int h) {
        this->hour = h;
    }

    void Set_minute(int m) {
        this->minute = m;
    }

    // Getter methods
    int get_hour() {
        return this->hour;
    }

    int get_minute() {
        return this->minute;
    }

    // Compare function
    int compare(Time t2) {
        // Compare hours first
        if (this->hour > t2.get_hour()) {
            return 1; // 'this' time is later
        } else if (this->hour < t2.get_hour()) {
            return -1; // 'this' time is earlier
        } else {
            // If hours are the same, compare minutes
            if (this->minute > t2.get_minute()) {
                return 1; // 'this' time is later
            } else if (this->minute < t2.get_minute()) {
                return -1; // 'this' time is earlier
            } else {
                return 0; // Both times are equal
            }
        }
    }
};


bool compareTime(Time existingStart, Time existingEnd, Time newStart, Time newEnd) {
    // No conflict if new show ends before or exactly when the existing show starts
    if (newEnd.compare(existingStart) <= 0) {
        return false;  // No conflict
    }

    // No conflict if new show starts after or exactly when the existing show ends
    if (newStart.compare(existingEnd) >= 0) {
        return false;  // No conflict
    }

    // Otherwise, there is a conflict
    return true;
}


class Person{
protected:
    string name;
    int age;
    string email;
public:

    void Set_name(string n){
        this->name = name;
    }
    void Set_age(int a){
        this->age = a;
    }
    void Set_email(string e){
        this->email = e;
    }
    string get_name(){
        return this->name;
    }
    int get_age(){
        return this->age;
    }
    string get_email(){
        return this->email;
    }
    Person(){

    }
    Person(string n,int a,string e){
        this->Set_name(n);
        this->Set_age(a);
        this->Set_email(e);
    }

};

class Customer: public Person{
protected:
    string phoneNumber;
    vector<Ticket> CustomerBookings;
    string password;
public:
    Customer(){

    }
    Customer(string name,int age,string email,string phoneNumber,string pass):Person(name,age,email){
        this->phoneNumber=phoneNumber;
        this->password == pass;
    }
    // void Add_customer(string name,int age,string email,string phnumber,string password){
    //     for(auto i:Customers){
    //         if(i->get_email() == email){
    //             cout << "another customer with same email already exists" << endl;
    //             return; 
    //         }
    //     }
    //     Customer customer1(name,age,email,phnumber,password);
    //     Customers.push_back(&customer1);
    //     cout << "customer had sucessfully registered" << endl;
    //     return;


    // }
    // void login(string email,string password){
    //     Customer *customer1 = new Customer;
    //     int changed = 0;
    //     for(auto i: Customers){
    //         if(i->get_email() == email){
    //             customer1 = i;
    //             changed = 1;
    //         }
    //     }
        
    //     if(changed == 0){
    //         cout << "no such person with the given email exist no please signup" << endl;
    //         return;
    //     }
    // }

    void bookShow(Ticket ticket){
        this->CustomerBookings.push_back(ticket);

    }
    string get_PhoneNumber(){
        return this->phoneNumber;
    }
    bool match_password(string pass){
        if(this->password == pass){
            return true;
        }
        else{
            return false;
        }
    }
    void cancelBooking(Show show){
        for(auto it=this->CustomerBookings.begin();it!=this->CustomerBookings.end();
        ){
            if(it->get_Show().get_MovieName()==show.get_MovieName()){
                it=this->CustomerBookings.erase(it);
            }
            else{
                ++it;
            }
        }
    }
    
};

class Admin: public Person{
protected:

public:
    void add_theatre(string name,string location,string city,int capacity,string o_name,int rows,int columns){
        Theatre *theatre1 = new Theatre();
        theatre1->set_Name(name);
        theatre1->set_Location(location);
        theatre1->set_City(city);
        theatre1->set_Capacity(capacity);
        theatre1->set_OwnerName(o_name);
        theatre1->set_Rows(rows);
        theatre1->set_Columns(columns);
        Booking_Manager b;
        b.add_Theatre(theatre1);
    }   
    void add_show(string theatre_name, string m_name, Time start_time, Time end_time, Date date, string lang, string cast, string rating, string overview) {
        Theatre *theatre1;
        int changed = 0;

        // Find the theatre by name
        for (auto i : Theatres) {
            if (theatre_name == i->get_Name()) {
                theatre1 = i;
                changed = 1;
                break;
            }
        }

        if (changed == 0) {
            cout << "No such theatre exists" << endl;
            return;
        }

        // Check for time conflicts with existing shows
        for (auto existing_show : theatre1->get_ShowsTrack()) {
            // Assuming compareTime is your function that checks for time overlap
            if (date.compare(existing_show->get_MovieDate())) { // First, check if the dates are the same
                if (compareTime(existing_show->get_MovieStartTime(), existing_show->get_MovieEndTime(), start_time, end_time)) {
                    cout << "Time conflict with another show!" << endl;
                    return;
                }
            }
        }

        // If no conflict, proceed to add the show
        Show *show1 = new Show;
        show1->set_MovieName(m_name);
        show1->set_MovieStartTime(start_time);
        show1->set_MovieEndTime(end_time);
        show1->set_MovieDate(date);
        show1->set_Language(lang);
        show1->set_Cast(cast);
        show1->set_Rating(rating);
        show1->set_MovieOverview(overview);

        theatre1->add_show(show1);  // Add the show to the theatre
        cout << "Show added successfully!" << endl;
    }


    void delete_theatre(string theatre_name){
        Theatre *theatre1;
        int changed = 0;

        // Find the theatre by name
        int j=0;
        for (auto i : Theatres) {
            if (theatre_name == i->get_Name()) {
                theatre1 = i;
                changed = 1;
                break;
            }
            j++;
        }
        if (changed == 0) {
            cout << "No such theatre exists" << endl;
            return;
        }  
        Theatres.erase(Theatres.begin()+j);
        delete theatre1;
    }
    void delete_movie(string movie_name){
        int j=0;
        for(auto i: Movies){
            if(i == movie_name){
                break;
            } 
            j++;
        }
        if(j == Movies.size()){
            cout << "no such movie present" << endl;
            return;
        }
        Movies.erase(Movies.begin()+j);
        // j=0;
        // for(auto &i:all_shows){
        //     if(i->get_MovieName() == movie_name){

        //     }
        // }

    }
    void delete_show(string theatre_name,Time start_time){
        Theatre *theatre1;
        int changed = 0;

        // Find the theatre by name
        int j=0;
        for (auto i : Theatres) {
            if (theatre_name == i->get_Name()) {
                theatre1 = i;
                changed = 1;
                break;
            }
            j++;
        }
        if(changed == 0){
            cout << "no such theatre" << endl;
            return;
        }
        theatre1->delete_show(start_time);

    }
    
};


class Seat{
private:
    int row_number;
    int seat_number;
    bool isAvailable;
public:
    void Set_row_number(int n){
        this->row_number = n;
    }
    void Set_seat_number(int n){
        this->seat_number = n;
    }
    void Set_isAvailable(bool b){
        this->isAvailable = b;
    }
    int get_row_number(){
        return row_number;
    }
    int get_seat_number(){
        return seat_number;
    }
    bool get_isAvailable(){
        return this->isAvailable;
    }


};

class Show {
private:
    string movie_name;
    Time movie_start_time;
    Time movie_end_time;
    Date movie_date;
    string language;
    string cast;
    string rating;
    string movie_overview;

public:
    // Setter methods
    void set_MovieName(string name) {
        this->movie_name = name;
    }

    void set_MovieStartTime(Time start_time) {
        this->movie_start_time = start_time;
    }

    void set_MovieEndTime(Time end_time) {
        this->movie_end_time = end_time;
    }

    void set_MovieDate(Date date){
        this->movie_date = date;
    }
    void set_Language(string lang) {
        this->language = lang;
    }

    void set_Cast(string cast_members) {
        this->cast = cast_members;
    }

    void set_Rating(string movie_rating) {
        this->rating = movie_rating;
    }

    void set_MovieOverview(string overview) {
        this->movie_overview = overview;
    }

    // Getter methods
    string get_MovieName() {
        return this->movie_name;
    }

    Time get_MovieStartTime() {
        return this->movie_start_time;
    }

    Time get_MovieEndTime() {
        return this->movie_end_time;
    }

    string get_Language() {
        return this->language;
    }

    string get_Cast() {
        return this->cast;
    }

    string get_Rating() {
        return this->rating;
    }

    string get_MovieOverview() {
        return this->movie_overview;
    }
    Date get_MovieDate(){
        return this->movie_date;
    }
};

class Ticket{
    protected:
        Seat seat;
        Theatre theatre;
        Show show;
    public:
        void set_Show(Show show){
            this->show=show;
        }
        void set_Seat(Seat seat){
            this->seat=seat;
        }
        void set_Theatre(Theatre theatre){
            this->theatre=theatre;
        }
        Seat get_Seat(){
            return seat;
        }
        Theatre get_Theatre(){
            return theatre;
        }
        Show get_Show(){
            return show;
        }




};


class Theatre {
protected:
    string name;
    string location;
    string city;
    int capacity;
    string owner_name;
    int rows;
    int columns;
    vector<vector<Seat*>> seats_track;
    vector<Show*> shows_track;

public:
    // Setter methods
    void set_Name(string theatre_name) {
        this->name = theatre_name;
    }

    void set_Location(string theatre_location) {
        this->location = theatre_location;
    }

    void set_City(string theatre_city) {
        this->city = theatre_city;
    }

    void set_Capacity(int theatre_capacity) {
        this->capacity = theatre_capacity;
    }

    void set_OwnerName(string owner) {
        this->owner_name = owner;
    }

    void set_Rows(int row_count) {
        this->rows = row_count;
    }

    void set_Columns(int column_count) {
        this->columns = column_count;
    }

    void set_SeatsTrack(int rows,int columns) {
        // this->seats_track = seat_matrix;
        for(int i=0;i<columns;i++){
            vector<Seat*> row_seats;
            for(int j=0;j<rows;j++){
                Seat *seat1 = new Seat;
                seat1->Set_isAvailable(true);
                seat1->Set_row_number(j+1);
                seat1->Set_seat_number(i+1);
                row_seats.push_back(seat1);
            }
            this->seats_track.push_back(row_seats);
        }
    }

    // void set_ShowsTrack(vector<vector<Show*> show_matrix) {
    //     this->shows_track = show_matrix;
    // }

    void add_show(Show *show1){
        this->shows_track.push_back(show1);
    }

    // Getter methods
    string get_Name() {
        return this->name;
    }

    string get_Location() {
        return this->location;
    }

    string get_City() {
        return this->city;
    }

    int get_Capacity() {
        return this->capacity;
    }

    string get_OwnerName() {
        return this->owner_name;
    }

    int get_Rows() {
        return this->rows;
    }

    int get_Columns() {
        return this->columns;
    }

    vector<vector<Seat*>> get_SeatsTrack() {
        return this->seats_track;
    }

    vector<Show*> get_ShowsTrack() {
        return this->shows_track;
    }

    void delete_show(Time stime){
        int j=0;
        Show *show1;
        for(auto i:shows_track){
            if ((i->get_MovieStartTime()).compare(stime) == 0){
               show1 = i;
               break; 
            }
            j++;
        }
        if(j==shows_track.size()){
            cout << "no such show in the given theatre" << endl;
            return;
        }
        shows_track.erase(shows_track.begin()+j);
        delete show1;
        cout << "deleted the show sucessfully" << endl;
    }
};
vector<Theatre*> Theatres;
vector<Customer*> Customers;
vector<string> Movies;

class Booking_Manager{
protected:
    
public:
    void add_Theatre(Theatre *theatre){
        // Theatre* theatre=new Theatre();
        Theatres.push_back(theatre);
    }
    void add_movie(){

    }
    void add_NewCustomer(){
        string name;
        cout<<"Username:";
        cin>>name;
        string email;
        cout<<"Email Id:";
        cin>>email;
        int age;
        cout<<"Enter your age:";
        cin>>age;
        string phoneNumber;
        cout<<"Enter phone number:";
        cin>>phoneNumber;
        string password;
        while(1){
            cout << "Enter the password" << endl;
            string pass;
            cin >> pass;
            cout << "confirm the password" << endl;
            string pass1;
            cin >> pass1;
            if(pass == pass1){
                password = pass1;
                break;
            }
            cout<< "confirmation password is not matched please try again" << endl;
        }
        for(auto i:Customers){
            if(i->get_email() == email){
                cout << "other customer already exists if the same email" << endl;
                return;
            }
        }
        Customer* customer=new Customer(name,age,email,phoneNumber,password);
        Customers.push_back(customer);
        handleBooking();
    }
    void handleExistingCustomer(){
        string email;
        bool found=false;
        Customer *cust1 = new Customer;
        cout << "enter email id: ";
        cin >> email; 
        for(auto &it:Customers){
            if(it->get_email()==email){
                found=true;
                cust1 = it;
            }
        }
        if(!found){
            cout<<"No User Exists with the current details"<<endl;
            return;
        }
        string pass;
        while(1){
            cout << "Enter password: " << endl;
            cin >> pass;
            if(!(cust1->match_password(pass))){
                cout << "invalid password try again" << endl;//what to do here if the user wants to change the email he has entered??
            }
            else{
                break;
            }
        }
        handleBooking(cust1);
    }
    void handleBooking(Customer *customer){
        cout<<"Press 1 to book a movie"<<endl;
        cout<<"Press 2 to check your previous bookings"<<endl;
        int command;
        cin>>command;
        if(command==1){
            cout<<"Select a movie(enter the serial number of the movie you want to book)"<<endl;
            int i=1;
            for(auto& movie:Movies){
                cout<<i<<". "<<movie<<endl;
            }
            int index;
            cin>>index;
            string movieName=Movies[index-1];
            cout<<"Select a date for the movie"<<endl;
            set<pair<int,int>> dates;
            for(auto &theatre:Theatres){
                for(auto &shows:theatre->get_ShowsTrack()){
                    dates.insert(make_pair(shows->get_MovieDate().get_date(),shows->get_MovieDate().get_month()));
                }
            }
            int date;
            cout<<"Type the date you are looking for:";
            cin>>date;
            for(auto &theatre:Theatres){
                for(auto &shows:theatre->get_ShowsTrack()){
                    if(shows->get_MovieName()==movieName && shows->get_MovieDate().get_date()==date){
                        cout<<theatre->get_Name()<<" "<<theatre->get_Location()<<" "<<theatre->get_City()<<" "<<theatre->get_Capacity()<<endl;
                        cout<< shows->get_MovieName() << " " 
                                << shows->get_MovieStartTime().get_hour() << " "<<shows->get_MovieStartTime().get_minute()<<" " 
                                << shows->get_MovieEndTime().get_hour() <<" "<<shows->get_MovieEndTime().get_minute()<< endl;      
                    }
                }
            }
        }
    }     
    
};

