#include <bits/stdc++.h>
#include<fstream>
using namespace std;
// vector<Show*> all_shows;
class Ticket;
class Show;
class Seat;
class Person;
class Customer;
class Admin;
class Theatre;
class Date {
private:
    int date;
    int month;
    int year;

public:
    // Setter methods
    Date(int date,int month,int year){
        this->date=date;
        this->month=month;
        this->year=year;
    }
    Date()=default;
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
    Time(int hour,int minute){
        this->hour=hour;
        this->minute=minute;
    }
    Time()=default;
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



class Seat{
private:
    int row_number;
    int seat_number;
    bool isAvailable;
public:
    Seat()=default;
    Seat(int rowNumber,int seatNumber,bool isAvailable=true){
        this->row_number=rowNumber;
        this->seat_number=seatNumber;
        this->isAvailable=isAvailable;
    }
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
    vector<vector<Seat*>> seats_track;

public:
    // Setter methods
    Show()=default;
    Show(string movieName,Date movieDate,Time startTime,Time endTime,string language){
        this->movie_name=movieName;
        this->movie_date=movieDate;
        this->movie_start_time=startTime;
        this->movie_end_time=endTime;
        this->language=language;
    }
    // Show show(movieName,movieDate,startTime,endTime,language);
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
    void set_SeatsTrack(int rows,int columns) {
        // this->seats_track = seat_matrix;
        for(int i=0;i<rows;i++){
            vector<Seat*> row_seats;
            for(int j=0;j<columns;j++){
                Seat *seat1 = new Seat;
                seat1->Set_isAvailable(true);
                seat1->Set_row_number(i+1);
                seat1->Set_seat_number(j+1);
                row_seats.push_back(seat1);
            }
            this->seats_track.push_back(row_seats);
        }
    }
    vector<vector<Seat*>> show_SeatsTrack() {
        return this->seats_track;
    }
        vector<vector<Seat*>> getSeatstrack(){
        return this->seats_track;
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

class Theatre {
protected:
    string name;
    string location;
    string city;
    int capacity;
    string owner_name;
    int rows;
    int columns;
    vector<Show*> shows_track;

public:
    // Setter methods
    void set_Name(string theatre_name) {
        this->name = theatre_name;
    }
    // Theatre theatre(theatreName,theatreLocation);
    Theatre()=default;
    Theatre(string name,string location){
        this->name=name;
        this->location=location;
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



    vector<Show*> get_ShowsTrack() {
        return this->shows_track;
    }

    void delete_show(Time stime){//this should be there already checked
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
class Ticket{
    protected:
        Seat seat;
        Theatre theatre;
        Show show;
    public:
        Ticket(Show show,Theatre theatre,Seat seat){
            this->show=show;
            this->theatre=theatre;
            this->seat=seat;
        }
        Ticket()=default;
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

vector<Theatre*> Theatres;
vector<Customer*> Customers;
vector<string> Movies;

class Person{
protected:
    string name;
    int age;
    string email;
public:

    void Set_name(string n){
        this->name = n;
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
        this->password = pass;
    }

    void bookShow(Ticket ticket){
        int rowNo=ticket.get_Seat().get_row_number();
        int columnNo=ticket.get_Seat().get_seat_number();
        // ticket.get_Theatre().getSeatstrack()[rowNo-1][columnNo-1]->Set_isAvailable(false);
        string theatreName=ticket.get_Theatre().get_Name();
        string theatreLocation=ticket.get_Theatre().get_Location();
        string movieName=ticket.get_Show().get_MovieName();
        Date movieDate=ticket.get_Show().get_MovieDate();
        int rowNumber=ticket.get_Seat().get_row_number();
        int seatNumber=ticket.get_Seat().get_seat_number();
        int startHour=ticket.get_Show().get_MovieStartTime().get_hour();
        int startMinute=ticket.get_Show().get_MovieStartTime().get_minute();
        for(Theatre* &theatre:Theatres){
                cout<<"Theatre Name: "<<theatre->get_Name()<<endl;
                cout<<"Actual "<<theatreName<<endl;
                if(theatre->get_Name()==theatreName and theatre->get_Location()==theatreLocation){
                    cout<<"Name: "<<theatre->get_Name()<<endl;

                    for(Show* &show:theatre->get_ShowsTrack()){
                        if(show->get_MovieName()==movieName and show->get_MovieDate().get_date()==movieDate.get_date() and show->get_MovieDate().get_month()==movieDate.get_month() and show->get_MovieDate().get_year()==movieDate.get_year() and show->get_MovieStartTime().get_hour()==startHour and show->get_MovieStartTime().get_minute()==startMinute){
                            show->getSeatstrack()[rowNumber-1][seatNumber-1]->Set_isAvailable(false);
                        }
                    }

                }
            }    
        this->CustomerBookings.push_back(ticket);

    }
    string get_PhoneNumber(){
        return this->phoneNumber;
    }
    string get_password(){
        return this->password;
    }
    vector<Ticket>& get_CustomerBookings(){
        return this->CustomerBookings;
    }
    bool match_password(string pass){
        if(this->password == pass){
            return true;
        }
        else{
            return false;
        }
    }
    void cancelBooking(int i){
        this->CustomerBookings.erase(this->CustomerBookings.begin()+i);
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
        // theatre1->set_SeatsTrack(rows,columns); //added seats track in theatre
        theatre1->set_Columns(columns);
        // Booking_Manager b; //why?
        Theatres.push_back(theatre1);
    }   
    void add_show(string theatre_name, string m_name, Time start_time, Time end_time, Date date, string lang, string cast, string rating, string overview) {
        Theatre *theatre1;
        int changed = 0;

        // Find the theatre by name
        for (auto &i : Theatres) {
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
            if (!date.compare(existing_show->get_MovieDate())) { // First, check if the dates are the same  //added a not because it returns 0;
                if (compareTime(existing_show->get_MovieStartTime(), existing_show->get_MovieEndTime(), start_time, end_time)) {
                    cout << "Time conflict with another show!" << endl;
                    return;
                }
            }
        }

        // If no conflict, proceed to add the show
        Show *show1 = new Show();
        show1->set_MovieName(m_name);
        show1->set_MovieStartTime(start_time);
        show1->set_MovieEndTime(end_time);
        show1->set_MovieDate(date);
        show1->set_Language(lang);
        show1->set_Cast(cast);
        show1->set_Rating(rating);
        show1->set_SeatsTrack(theatre1->get_Rows(),theatre1->get_Columns());
        show1->set_MovieOverview(overview);

        //adding the movie name if the show had a new movie which is not added to our movies list till now
        auto it = find(Movies.begin(),Movies.end(),m_name);
        if(it == Movies.end()){
            Movies.push_back(m_name);
        }

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
        //deleting all the tickets that are having shows in this theatre
        int m;
        for(auto i:Customers){
            m=0;
            for(auto j:i->get_CustomerBookings()){
                if(j.get_Theatre().get_Name() == theatre1->get_Name()){
                    i->cancelBooking(m);
                }
                m++;
            }
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
        //deleting all the tickets that are having their movie as the movie we are deleting
        int m;
        for(auto i:Customers){
            m=0;
            for(auto j:i->get_CustomerBookings()){
                if(j.get_Show().get_MovieName() == movie_name){
                    i->cancelBooking(m);
                }
                m++;
            }
        }
        // here delete movie means he should also delete all the shows which are in different theatres.
        Movies.erase(Movies.begin()+j);

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
        //delting all the tickets that are corresponding to this show in the customers ticket booking list
        int m=0;
        for(auto i:Customers){
            m=0;
            for(auto j:i->get_CustomerBookings()){
                if((j.get_Theatre().get_Name() == theatre1->get_Name()) && (j.get_Show().get_MovieStartTime().compare(start_time) == 0)){
                    i->cancelBooking(m);
                }
                m++;
            }
        }
        theatre1->delete_show(start_time);
    }
    
};





class Booking_Manager{
protected:
    
public:
    
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
        handleBooking(customer);
    }
    void handleExistingCustomer(){
        string email;
        bool found=false;
        Customer *cust1 = new Customer;
        cout << "Enter email id: ";
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
                cout << "Invalid password try again" << endl;//what to do here if the user wants to change the email he has entered??
            }
            else{
                break;
            }
        }
        handleBooking(cust1);
    }
    void handleBooking(Customer *customer){
        cout<<"Press 1 to book a movie"<<endl;
        cout<<"Press 2 to check your previous bookings or cancel any of the previous bookings"<<endl;
        int command;
        cin>>command;
        if(command==1){
            int i=1;
            for(auto& movie:Movies){
                cout<<i++<<". "<<movie<<endl;
            }
            cout<<"Select a movie(enter the serial number of the movie you want to book):"<<endl;
            int index;
            cin>>index;
            string movieName=Movies[index-1];
            set<pair<int,int>> dates;
            for(auto &theatre:Theatres){
                for(auto &shows:theatre->get_ShowsTrack()){
                if(shows->get_MovieName()==movieName){
                    dates.insert(make_pair(shows->get_MovieDate().get_date(),shows->get_MovieDate().get_month()));
                    }
                }
            }
            cout<<"Select a date for the movie"<<endl;
            cout<<"Available Dates"<<endl;
            for(auto it=dates.begin();it!=dates.end();++it){
                cout<<it->first<<" "<<it->second<<endl;
            }
            int showIndex;
            vector<Theatre*> filteredTheatres;
            vector<Show*> filteredShows;
            while(1){
            cout<<"Type the date and month you are looking for(from above list):"<<endl;
            int date,month;
            cin>>date>>month;
            int i=1;
            for (auto &theatre : Theatres) {
                showIndex = 0;
                for (auto &shows : theatre->get_ShowsTrack()) {
                    showIndex++;
                    if (shows->get_MovieName() == movieName && 
                        shows->get_MovieDate().get_date() == date && 
                        shows->get_MovieDate().get_month() == month) {
                        
                        cout<<"Show :"<<i++<<endl;
                        cout << "-------------------------------------------------" << endl;
                        cout << "Theatre " << ":" << endl;
                        cout << "Name      : " << theatre->get_Name() << endl;
                        cout << "Location  : " << theatre->get_Location() << endl;
                        cout << "City      : " << theatre->get_City() << endl;
                        cout << "Capacity  : " << theatre->get_Capacity() << endl;
                        cout << "-------------------------------------------------" << endl;

                        // Print show details in a readable format
                        cout << "Show Details:" << endl;
                        cout << "Movie Name     : " << shows->get_MovieName() << endl;
                        cout << "Start Time     : " 
                            << shows->get_MovieStartTime().get_hour() << ":" 
                            << setw(2) << setfill('0') << shows->get_MovieStartTime().get_minute() << endl;
                        cout << "End Time       : " 
                            << shows->get_MovieEndTime().get_hour() << ":" 
                            << setw(2) << setfill('0') << shows->get_MovieEndTime().get_minute() << endl;
                        cout << "-------------------------------------------------" << endl;

                        // Add theatre to the filtered list
                        filteredTheatres.push_back(theatre);
                        filteredShows.push_back(shows);
                    }
                }
            }
            cout<<"Type 1 if you want to continue\nType 2 If you want to see on another date\nType 3 If you want to return\n";
            int type;
            cin>>type;
            if(type==1){
                break;
            }
            else if(type==3){
                return;
            }
            else{
                continue;
            }
        }
        cout<<"Type the serial number of the show you want to book"<<endl;
        int sno;
        cin>>sno;
        Theatre* theatre=filteredTheatres[sno-1];
        Show* show=filteredShows[sno-1];
        i = 1;
        cout << "   ";
        for (int j = 1; j <= theatre->get_Columns(); j++) {
            cout << setw(3) << j;
        }
        cout << endl;
        cout << "   ";
        for (int j = 1; j <= theatre->get_Columns(); j++) {
            cout << "---";
        }
        cout << endl;
        for (auto &row : show->show_SeatsTrack()) {
            cout << setw(2) << i++ << " | ";  
            for (auto &elem : row) {
                cout << (elem->get_isAvailable() ? " A " : "NA ");
            }
            cout << endl;
        }
        cout << endl << "Legend:" << endl;
        cout << "A  - Available Seat" << endl;
        cout << "NA - Not Available Seat" << endl;

        cout<<"Please select the row number and column number from the available seats"<<endl;
        int rowNo,columnNo;
        cin>>rowNo>>columnNo;
        Seat* seat=new Seat();
        seat->Set_row_number(rowNo);
        seat->Set_seat_number(columnNo);
        seat->Set_isAvailable(false);
        Ticket* ticket=new Ticket();
        ticket->set_Seat(*seat);
        ticket->set_Show(*show);
        ticket->set_Theatre(*theatre);
        customer->bookShow(*ticket);
        }
    else if(command==2){
        int f=0;
        for(auto &Customer:Customers){
            int i=1;
            // cout<<customer->get_name()<<" "<<customer->get_email()<<" "<<customer->get_PhoneNumber()<<endl;
            // cout<<Customer->get_name()<<" "<<Customer->get_email()<<" "<<Customer->get_PhoneNumber()<<endl;
            if(Customer->get_name()==customer->get_name() and Customer->get_email()==customer->get_email() and Customer->get_PhoneNumber()==customer->get_PhoneNumber()){
                cout<<Customer->get_CustomerBookings().size()<<endl;
                if(Customer->get_CustomerBookings().size()>0){
                    f=1;
                }
                for(auto &ticket: Customer->get_CustomerBookings()) {
                    cout << "Booking #" << i++ << endl;
                    cout << "Movie Name: " << ticket.get_Show().get_MovieName() << endl;
                    cout << "Date: " 
                        << ticket.get_Show().get_MovieDate().get_date() << "-" 
                        << ticket.get_Show().get_MovieDate().get_month() << "-" 
                        << ticket.get_Show().get_MovieDate().get_year() << endl;
                    cout << "Start Time: " 
                        << ticket.get_Show().get_MovieStartTime().get_hour() << ":" 
                        << ticket.get_Show().get_MovieStartTime().get_minute() << endl;
                    cout << "End Time: " 
                        << ticket.get_Show().get_MovieEndTime().get_hour() << ":" 
                        << ticket.get_Show().get_MovieEndTime().get_minute() << endl;
                    cout << "Language: " << ticket.get_Show().get_Language() << endl;
                    cout << "Theatre Name: " << ticket.get_Theatre().get_Name() << endl;
                    cout << "Location: " << ticket.get_Theatre().get_Location() << ", " 
                        << ticket.get_Theatre().get_City() << endl;
                    cout << "Seat: Row " << ticket.get_Seat().get_row_number() 
                        << ", Seat " << ticket.get_Seat().get_seat_number() << endl;
                    cout << "-----------------------------------------" << endl;
                }

            }
        }
        cout<<"Do you want to cancel any of the above bookings?\nType 1 if you want to cancel\nType 2 to exit"<<endl;
        int cancelBooking;
        cin>>cancelBooking;
        if(cancelBooking==1){
            cout<<"Type the serial number of the bookings you want to cancel"<<endl;
            int no;
            cin>>no;
            if(f){
                customer->cancelBooking(no-1);
                handleBooking(customer);
            }
        }
        else{
            return;
        }
    }
    }     
    
};
    void saveCustomers(){
        ofstream outFile("Customers.txt",ios::trunc);
        if(!outFile){
            cerr<<"Error Opening file.\n";
            return;
        }
        for(const auto& customer:Customers){
            outFile<< customer->get_name()<<" "<<customer->get_age()<<" "<<customer->get_email()<<" "<<customer->get_PhoneNumber()<<" "<<customer->get_password();

            outFile<<" "<<customer->get_CustomerBookings().size()<<endl;
            for(auto& ticket:customer->get_CustomerBookings()){
                outFile<<ticket.get_Show().get_MovieName()<<endl;
                outFile<<ticket.get_Show().get_MovieDate().get_date()<<" "<<ticket.get_Show().get_MovieDate().get_month()<<" "<<ticket.get_Show().get_MovieDate().get_year()<<endl;
                outFile<<ticket.get_Show().get_MovieStartTime().get_hour()<<" "<<ticket.get_Show().get_MovieStartTime().get_minute()<<endl;
                outFile<<ticket.get_Show().get_MovieEndTime().get_hour()<<" "<<ticket.get_Show().get_MovieEndTime().get_minute()<<endl;
                outFile<<ticket.get_Show().get_Language()<<endl;
                outFile<<ticket.get_Theatre().get_Name()<<endl;
                outFile<<ticket.get_Theatre().get_Location()<<endl;
                outFile<<ticket.get_Seat().get_row_number()<<endl;
                outFile<<ticket.get_Seat().get_seat_number()<<endl;
            }
        }
    }
    void loadCustomers(){
        ifstream inFile("Customers.txt");
        if(!inFile){
            return;
        }
        string name,email,phoneNumber,password;
        int age,numBookings;
        Customers.clear();
        while(inFile>>name>>age>>email>>phoneNumber>>password>>numBookings){
            Customer* customer=new Customer(name,age,email,phoneNumber,password);
            for(int i=0;i<numBookings;i++){
                // cout<<"I went in atleast"<<endl;
                string movieName,language,theatreName,theatreLocation;
                int date,month,year,startHour,startMinute,endHour,endMinute;
                int rowNumber,seatNumber;

                inFile.ignore();
                getline(inFile,movieName);
                inFile>>date>>month>>year;
                // cout<<"date: "<<date<<" "<<"month: "<<month<<" "<<"year: "<<year<<endl;
                inFile>>startHour>>startMinute;
                // cout<<"startHour: "<<startHour<<"startMinute: "<<startMinute<<endl;
                inFile>>endHour>>endMinute;
                // cout<<"endHour: "<<endHour<<"endMinute: "<<endMinute<<endl;
                inFile.ignore();
                getline(inFile,language);
                // cout<<"language: "<<language<<endl;
                getline(inFile,theatreName);
                // cout<<"theatreName: "<<theatreName<<endl;
                getline(inFile,theatreLocation);
                inFile>>rowNumber>>seatNumber;
                // cout<<"rowNumber: "<<rowNumber<<"seatNumber: "<<seatNumber<<endl;

                Date movieDate(date,month,year);
                Time startTime(startHour,startMinute);
                Time endTime(endHour,endMinute);
                Show show(movieName,movieDate,startTime,endTime,language);
                Theatre theatre(theatreName,theatreLocation);
                Seat seat(rowNumber,seatNumber,false);
                for(Theatre* &theatre:Theatres){
                    cout<<"Theatre Name: "<<theatre->get_Name()<<endl;
                    cout<<"Actual "<<theatreName<<endl;
                    if(theatre->get_Name()==theatreName and theatre->get_Location()==theatreLocation){
                        cout<<"Name: "<<theatre->get_Name()<<endl;

                        for(Show* &show:theatre->get_ShowsTrack()){
                            if(show->get_MovieName()==movieName and show->get_MovieDate().get_date()==movieDate.get_date() and show->get_MovieDate().get_month()==movieDate.get_month() and show->get_MovieDate().get_year()==movieDate.get_year() and show->get_MovieStartTime().get_hour()==startHour and show->get_MovieStartTime().get_minute()==startMinute){
                                show->getSeatstrack()[rowNumber-1][seatNumber-1]->Set_isAvailable(false);
                            }
                        }

                    }
                }
                Ticket ticket(show,theatre,seat);
                // cout<<"Pushed "<<i<<"th ticket"<<endl;

                customer->get_CustomerBookings().push_back(ticket);

                
            }
            // cout<<"I am pushing it here also"<<endl;
            Customers.push_back(customer);
        }

    }
void saveMovies(){
    ofstream outFile("movies.txt",ios::trunc);
    if(!outFile){
        cerr<<"Error Opening file for opening movies"<<endl;
        return;
    }
    set<string> existingMovies;
    ifstream inFile("movies.txt");
    string movie;
    while(getline(inFile,movie)) {
        if(!movie.empty()){
            existingMovies.insert(movie);
        }
    }
    inFile.close();
    for (const auto& movie : Movies) {
        if (existingMovies.find(movie) == existingMovies.end()) {
            outFile << movie << endl; // Append movie to the file
        }
    }

    outFile.close();
}

void loadMovies() {
    ifstream inFile("movies.txt");
    if(!inFile){
        cerr<<"Error opening file for loading movies.\n";
        return;
    }
    Movies.clear();
    string movie;
    while (getline(inFile, movie)) {
        if (!movie.empty()) {
            Movies.push_back(movie);
        }
    }

    inFile.close();
}
void saveTheatres() {
    ofstream outFile("Theatres.txt", ios::trunc);
    if (!outFile) {
        cerr << "Error opening file for saving theatres.\n";
        return;
    }

    for (const auto& theatre : Theatres) {
        // Save theatre details
        outFile << theatre->get_Name() << endl;
        outFile << theatre->get_Location() << endl;
        outFile << theatre->get_City() << endl;
        outFile << theatre->get_Capacity() << endl;
        outFile << theatre->get_Rows() << endl;
        outFile << theatre->get_Columns() << endl;
        outFile << theatre->get_ShowsTrack().size() << endl; // Number of shows

        // Save each show
        for (const auto& show : theatre->get_ShowsTrack()) {
            outFile << show->get_MovieName() << endl;
            Date movieDate = show->get_MovieDate();
            outFile << movieDate.get_date() << " " << movieDate.get_month() << " " << movieDate.get_year() << endl;
            Time startTime = show->get_MovieStartTime();
            outFile << startTime.get_hour() << " " << startTime.get_minute() << endl;
            Time endTime = show->get_MovieEndTime();
            outFile << endTime.get_hour() << " " << endTime.get_minute() << endl;
            outFile << show->get_Language() << endl;
            outFile << show->get_Cast() << endl;
            outFile << show->get_Rating() << endl;
            outFile << show->get_MovieOverview() << endl;
        }
    }

    outFile.close();
    // cout << "Theatres and shows saved successfully.\n";
}

// Function to load theatres and their shows from "Theatres.txt"
void loadTheatres() {

    ifstream inFile("Theatres.txt");
    if (!inFile) {
        cerr << "Error opening file for loading theatres.\n";
        return;
    }

    Theatres.clear(); // Clear existing theatres to avoid duplication
    string theatreName, location, city, movieName, language, cast, rating, overview;
    int capacity, rows, columns, numShows, date, month, year, startHour, startMinute, endHour, endMinute;

    while (getline(inFile, theatreName)) { // Read each theatre
        getline(inFile, location);
        getline(inFile, city);
        inFile >> capacity >> rows >> columns >> numShows;
        inFile.ignore();

        Theatre* theatre = new Theatre(theatreName, location);
        theatre->set_City(city);
        theatre->set_Capacity(capacity);
        // cout<<"rows set to "<<rows<<endl;
        theatre->set_Rows(rows);
        // cout<<"columns set to"<<columns<<endl;
        theatre->set_Columns(columns);
        // theatre->set_SeatsTrack(rows,columns);
        cout<<"I came to shows "<<endl;

        for (int i = 0; i < numShows; ++i) { // Read each show for the theatre
            getline(inFile, movieName);
            inFile >> date >> month >> year >> startHour >> startMinute >> endHour >> endMinute;
            inFile.ignore(); // Ignore newline character after endMinute
            getline(inFile, language);
            getline(inFile, cast);
            getline(inFile, rating);
            getline(inFile, overview);

            Date movieDate(date, month, year);
            Time startTime(startHour, startMinute);
            Time endTime(endHour, endMinute);
            Show* show = new Show(movieName, movieDate, startTime, endTime, language);
            show->set_Cast(cast);
            show->set_Rating(rating);
            show->set_MovieOverview(overview);
            show->set_SeatsTrack(rows,columns);

            theatre->add_show(show);
        }
        cout<<"Theatres pushed"<<endl;
        Theatres.push_back(theatre);
    }

    inFile.close();
}

int main(){
    cout<<"Welcome to BookYourShow.\nWe know you are intereseted in movies.Go ahead and grab the seats for your favourite movie as soon as possible!!"<<endl;
    cout<<"----------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    loadTheatres();
    loadCustomers();
    loadMovies();
    while(1){
        cout << "Enter 1 to login as a Customer" << endl;
        cout << "Enter 2 to login as an Admin" << endl;
        cout << "Enter 3 to Signup" << endl;
        cout<<" Enter 4 to Exit" << endl;
        int command;
        cin >> command;
        if(command == 1){
            Booking_Manager b;
            b.handleExistingCustomer();
        }
        else if(command == 2){
            string key;
            cout << "Enter the secret key: ";
            cin >> key;
            if(key != "123456"){
                continue;
            }
            cout << "Want to add theatre PRESS 1" << endl;
            cout << "Want to add show PRESS 2" << endl;
            cout << "Want to delete theatre PRESS 3" << endl;
            cout << "Want to delete movie PRESS 4" << endl;
            cout << "Want to delete show PRESS 5" << endl;
            int type;
            cin >> type;
            if(type == 1){
                string name, location, city, o_name;
                int capacity, rows, columns;
                
                cout << "Please enter the theatre name: ";
                cin >> name;

                cout << "Please enter the location: ";
                cin >> location;

                cout << "Please enter the city: ";
                cin >> city;

                cout << "Please enter the capacity: ";
                cin >> capacity;

                cout << "Please enter the owner's name: ";
                cin >> o_name;

                cout << "Please enter the number of rows in the theatre: ";
                cin >> rows;

                cout << "Please enter the number of columns in the theatre: ";
                cin >> columns;
                Admin a;

                a.add_theatre(name,location,city,capacity,o_name,rows,columns);
                // delete &a;

            }
            else if(type == 2){
                string theatre_name, m_name, lang, cast, rating, overview;
                int start_timehour, start_timeminute, end_timehour, end_timeminute;
                int dateday, datemonth, dateyear;
                
                Date date;
                Time start_time, end_time;

                cout << "Please enter the theatre name: ";
                cin >> theatre_name;

                cout << "Please enter the movie name: ";
                cin >> m_name;

                cout << "Please enter the start time (hour and minute): ";
                cin >> start_timehour >> start_timeminute;

                // Set start_time using the setter methods
                start_time.Set_hour(start_timehour);
                start_time.Set_minute(start_timeminute);

                cout << "Please enter the end time (hour and minute): ";
                cin >> end_timehour >> end_timeminute;

                // Set end_time using the setter methods
                end_time.Set_hour(end_timehour);
                end_time.Set_minute(end_timeminute);

                cout << "Please enter the date (day, month, year): ";
                cin >> dateday >> datemonth >> dateyear;

                // Set date using the setter methods
                date.Set_date(dateday);
                date.Set_month(datemonth);
                date.Set_year(dateyear);

                cout << "Please enter the language: ";
                cin >> lang;

                cout << "Please enter the cast: ";
                cin >> cast;

                cout << "Please enter the rating: ";
                cin >> rating;

                cout << "Please enter the overview: ";
                cin >> overview;
                Admin a;
                a.add_show(theatre_name,m_name,start_time,end_time,date,lang,cast,rating,overview);
                // delete &a;
            }
            else if(type == 3){
                string theatre_name;
                cout << "Please enter the theatre name: ";
                cin >> theatre_name;
                Admin a;
                a.delete_theatre(theatre_name);
                // delete &a;
            }
            else if(type == 4){
                string movie_name;
                cout << "Please enter movie name: ";
                cin >> movie_name;
                Admin a;
                a.delete_movie(movie_name);
                // delete &a;
            }
            else if(type == 5){
                string theatre_name;
                int start_timehour;
                int start_timeminute;
                Time start_time;
                cout << "Please enter the theatre name: ";
                cin >> theatre_name;
                cout << "Please enter the start time (hour and minute): ";
                cin >> start_timehour >> start_timeminute;
                start_time.Set_hour(start_timehour);
                start_time.Set_minute(start_timeminute);
                Admin a;
                a.delete_show(theatre_name,start_time);
            }
        }
        else if(command == 3){
            Booking_Manager b;
            b.add_NewCustomer();
        }
        else if(command==4){
            saveCustomers();
            saveMovies();
            saveTheatres();
            break;
        }
    }
}