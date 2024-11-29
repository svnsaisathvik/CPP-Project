# **Movie Ticket Booking System**

## **Team Details**

| Name | Roll No | Email |
|------|---------|-------|
| SVN Sai Sathvik | IMT2023001 | SVN.Sathvik@iiitb.ac.in |
| Kh Sudhir | IMT2023546 | Kh.Sudhir@iiitb.ac.in |
| Kasam Likith | IMT2023573 | Likith.Kasam@iiitb.ac.in |
| K Jitin | IMT2023057 | KVS.Jitin@iiitb.ac.in |
| Sai Ganesh | IMT2023525 | Ganesh.Upadrasta@iiitb.ac.in |
| Kapil Aditya Reddy | IMT2023052 | KKR.Aditya@iiitb.ac.in |

## **Project Overview**

The Movie Booking System is a terminal-based application developed to streamline the process of booking movie tickets. By leveraging the interoperability between C++ and Java via JNI, the system provides an efficient and modular design for managing:

- User profiles
- Available movies
- Seat selection
- Ticket bookings

## **Scope**

### **Current Scope**

**Core Features:**
- Displaying available movies and showtimes
- User registration and authentication
- Seat selection and ticket booking via terminal interface
- Generating and displaying booking receipts

**Technology Integration:**
- Combining C++ (backend logic) with Java (main interface) using JNI
- Streamlined cross-language function calls

### **Future Scope**

- Transition to Graphical User Interface (GUI)
- Real-time payment systems and e-wallet support
- Cloud-based data storage
- Multiple concurrent user support
- Personalized movie recommendations

## **Objectives**

1. **Streamline Movie Ticket Booking Process**
   - Develop an efficient system for browsing movies, selecting seats, and booking tickets

2. **Leverage Language Interoperability**
   - Use C++ for backend logic and Java for main interface via JNI
   - Demonstrate effective cross-language integration

3. **Provide Modular Design**
   - Create well-structured modules for:
     * User management
     * Movie management
     * Booking functionalities

4. **Ensure System Efficiency**
   - Design terminal-based interface minimizing resource usage
   - Maintain high functionality

5. **Demonstrate Practical Concept Application**
   - Showcase proficiency in:
     * Object-oriented programming
     * File handling
     * JNI integration

## **Technical Specifications**

### **Programming Languages**

- **Java**:
  - Main function and user interaction
  - Handles terminal-based interface
  - Orchestrates backend calls

- **C++**:
  - Backend logic implementation
  - Manages core operations:
    * Data processing
    * Ticket booking
    * Database management

- **JNI (Java Native Interface)**:
  - Bridges communication between Java and C++

## **Input/Output Requirements**

### **User Inputs**
- Movie selection (title/ID)
- Theatre and show selection
- Seat selection
- Personal booking details

### **Administrative Inputs**
- Movie schedule management
- Pricing updates
- Theatre detail additions

### **User Outputs**
- Available movies and showtimes
- Seat layout and availability
- Booking confirmation details

### **Administrative Outputs**
- Updated movie schedules
- Booking logs

## **Key Features**

### **User Management**
- Secure registration and login
- Profile and booking history management

### **Movie Management**
- Display movies with schedules
- Search and filter by genre/language

### **Booking System**
- Seat selection
- Booking confirmation generation
- Booking cancellation

### **Administrative Features**
- Movie addition/update/removal
- Booking log maintenance

### **Error Handling**
- Input validation
- Duplicate booking prevention
- Informative error messaging

## **Development Setup**

### **Languages and Technologies**
- **C++**: Backend logic (core.cpp, core.so)
- **Java**: Frontend and JNI integration (BookYourShow.java)

### **Key Components**
- Text Files:
  * Customers.txt
  * movies.txt
  * Theatres.txt

- Shared Libraries:
  * core.so (Linux)
  * BookYourShow.dll (Windows)

## **Important Project Files**

- **BookYourShow.java**:
  * Main application logic
  * Terminal user interface
  * Program entry point

- **core.cpp**:
  * Core backend logic
  * Movie and seat management
  * Performance-critical operations

## **Testing and Logging**

- Unit tests for core classes:
  * Movie
  * Show
  * Seat
  * Booking

- Logging mechanisms for:
  * Booking failures
  * Payment errors

## **Conclusion**

A user-friendly movie ticket booking system designed to provide:
- Real-time seat availability
- Secure payment processing
- Efficient booking confirmation

The system aims to simplify and streamline the movie ticket booking experience.
