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
        if (this->year > d2.get_year()) {
            return 1;
        } else if (this->year < d2.get_year()) {
            return -1;
        } else {
            if (this->month > d2.get_month()) {
                return 1;
            } else if (this->month < d2.get_month()) {
                return -1;
            } else {
                if (this->date > d2.get_date()) {
                    return 1;
                } else if (this->date < d2.get_date()) {
                    return -1;
                } else {
                    return 0;
                }
            }
        }
    }

    // Function to check if the date is valid
    bool isValidDate() {
        // Check if month is valid
        if (month < 1 || month > 12) {
            return false;
        }

        // Check if date is valid for the given month
        int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        // Check for leap year
        bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if (isLeapYear && month == 2) {
            days_in_month[1] = 29;  // February has 29 days in a leap year
        }

        // Validate day based on the month
        if (date < 1 || date > days_in_month[month - 1]) {
            return false;
        }

        return true;  // If all checks passed, the date is valid
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

    // Function to check if the time is valid
    bool isValidTime() {
        // Check if hour is valid (0 - 23)
        if (hour < 0 || hour > 23) {
            return false;
        }

        // Check if minute is valid (0 - 59)
        if (minute < 0 || minute > 59) {
            return false;
        }

        return true;  // If both hour and minute are within valid ranges
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

public:
    void Add_customer(){

    }
};

class Admin : public Person {
protected:

public:
    // Function to add a new admin
    void Add_admin(){

    }

    // Function to remove an admin
    void Remove_admin(){

    }

    // Function to modify admin details
    void Modify_admin(){

    }

    // Function to manage theatres
    void Add_theatre(){

    }   // Adds a theatre
    void Delete_theatre(){

    } // Deletes a theatre

    // Function to manage shows
    void Add_show_to_theatre(){

    } // Adds a show to a theatre

    void delete_show_from_theatre(){

    }

};

class Ticket{
private:
    int ticketprice;



     
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
    void setName(string theatre_name) {
        this->name = theatre_name;
    }

    void setLocation(string theatre_location) {
        this->location = theatre_location;
    }

    void setCity(string theatre_city) {
        this->city = theatre_city;
    }

    void setCapacity(int theatre_capacity) {
        this->capacity = theatre_capacity;
    }

    void setOwnerName(string owner) {
        this->owner_name = owner;
    }

    void setRows(int row_count) {
        this->rows = row_count;
    }

    void setColumns(int column_count) {
        this->columns = column_count;
    }

    void setSeatsTrack(vector<vector<Seat*>> seat_matrix) {
        this->seats_track = seat_matrix;
    }

    void setShowsTrack(vector<vector<Show*>> show_matrix) {
        this->shows_track = show_matrix;
    }

    // Getter methods
    string getName() {
        return this->name;
    }

    string getLocation() {
        return this->location;
    }

    string getCity() {
        return this->city;
    }

    int getCapacity() {
        return this->capacity;
    }

    string getOwnerName() {
        return this->owner_name;
    }

    int getRows() {
        return this->rows;
    }

    int getColumns() {
        return this->columns;
    }

    vector<vector<Seat*>> getSeatsTrack() {
        return this->seats_track;
    }

    vector<vector<Show*>> getShowsTrack() {
        return this->shows_track;
    }
};
