#include <bits/stdc++.h>
using namespace std;

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

public:
    Customer(string name,int age,string email,string phoneNumber):Person(name,age,email){
        this->phoneNumber=phoneNumber;
    }
    void Add_customer(){

    }
    void login(){

    }
    void bookShow(Ticket ticket){
        this->CustomerBookings.push_back(ticket);

    }
    string get_PhoneNumber(){
        return this->phoneNumber;
    }
    void cancelBooking(Show show){
        for(auto it=this->CustomerBookings.begin();it!=this->CustomerBookings.end();
        ){
            if(it->get_Show().getMovieName()==show.getMovieName()){
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
    }   
    void add_show(){
        
    }

    void delete_theatre(){

    }
    void delete_movie(){

    }
    void delete_show(){

    }
    
};


class Seat{
private:
    string row_number;
    string seat_number;
    bool isAvailable;
public:
    void Set_row_number(string n){
        this->row_number = n;
    }
    void Set_seat_number(string n){
        this->seat_number = n;
    }
    void Set_isAvailable(bool b){
        this->isAvailable = b;
    }
    string get_row_number(){
        return row_number;
    }
    string get_seat_number(){
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
    void setMovieName(string name) {
        this->movie_name = name;
    }

    void setMovieStartTime(Time start_time) {
        this->movie_start_time = start_time;
    }

    void setMovieEndTime(Time end_time) {
        this->movie_end_time = end_time;
    }

    void setLanguage(string lang) {
        this->language = lang;
    }

    void setCast(string cast_members) {
        this->cast = cast_members;
    }

    void setRating(string movie_rating) {
        this->rating = movie_rating;
    }

    void setMovieOverview(string overview) {
        this->movie_overview = overview;
    }

    // Getter methods
    string getMovieName() {
        return this->movie_name;
    }

    Time getMovieStartTime() {
        return this->movie_start_time;
    }

    Time getMovieEndTime() {
        return this->movie_end_time;
    }

    string getLanguage() {
        return this->language;
    }

    string getCast() {
        return this->cast;
    }

    string getRating() {
        return this->rating;
    }

    string getMovieOverview() {
        return this->movie_overview;
    }
    Date getMovieDate(){
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
    vector<vector<Show*>> shows_track;

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

    void set_SeatsTrack(vector<vector<Seat*>> seat_matrix) {
        this->seats_track = seat_matrix;
    }

    void set_ShowsTrack(vector<vector<Show*>> show_matrix) {
        this->shows_track = show_matrix;
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

    vector<vector<Show*>> get_ShowsTrack() {
        return this->shows_track;
    }
};

class Booking_Manager{
protected:
    vector<Theatre*> Theatres;
    vector<Customer*> Customers;
    vector<Show> Movies;
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
        Customer* customer=new Customer(name,age,email,phoneNumber);
        Customers.push_back(customer);
        handleBooking();
    }
    void handleExistingCustomer(){
        string name,phoneNumber;
        bool found=false;
        cout<<"Enter Username:";
        cin>>name;
        cout<<"Enter PhoneNumber:";
        cin>>phoneNumber;
        for(auto &it:Customers){
            if(it->get_name()==name and it->get_PhoneNumber()==phoneNumber){
                found=true;
            }
        }
        if(!found){
            cout<<"No User Exists with the current details"<<endl;
            return;
        }
        else{
            handleBooking();
        }

    }
    void handleBooking(){
        cout<<"Press 1 to book a movie"<<endl;
        cout<<"Press 2 to check your previous bookings"<<endl;
        int command;
        cin>>command;
        if(command==1){
            cout<<"Select a movie(enter the serial number of the movie you want to book)"<<endl;
            int i=1;
            for(auto& movie:Movies){
                cout<<i<<". "<<movie.getMovieName()<<endl;
            }
            int index;
            cin>>index;
            string movieName=Movies[index-1].getMovieName();
            cout<<"Select a date for the movie"<<endl;
            for(auto &theatre:Theatres){
                for(auto &shows:theatre->get_ShowsTrack()){
                    for(auto &show:shows){
                        cout<<show->getMovieDate().get_date()<<endl;
                    }
                }
            }
            int date;
            cin>>date;
            for(auto &theatre:Theatres){
                for(auto &shows:theatre->get_ShowsTrack()){
                    for(auto &show:shows){
                        cout<<show->getMovieDate().get_date()<<endl;
                    }
                }
            }
        }
    }     
    
};

