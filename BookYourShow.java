public class BookYourShow {
    static {
        System.loadLibrary("BookYourShowLib"); // Load the JNI library
    }

    // Native methods for Booking_Manager
    public native void handleExistingCustomer();
    public native void addNewCustomer();

    // Native methods for Admin
    public native void addTheatre(String name, String location, String city, int capacity, String ownerName, int rows, int columns);
    public native void addShow(String theatreName, String movieName, int startHour, int startMinute, int endHour, int endMinute,
                               int day, int month, int year, String language, String cast, String rating, String overview);
    public native void deleteTheatre(String theatreName);
    public native void deleteMovie(String movieName);
    public native void deleteShow(String theatreName, int startHour, int startMinute);

    // Native methods for saving and loading data
    public native void save();
    public native void start();

    public static void main(String[] args) {
        BookYourShow system = new BookYourShow();
        system.start(); // Load data at the beginning

        System.out.println("Welcome to BookYourShow.");
        System.out.println("We know you are interested in movies. Go ahead and grab the seats for your favorite movie!");

        java.util.Scanner scanner = new java.util.Scanner(System.in);

        while (true) {
            System.out.println("1. Login as a Customer");
            System.out.println("2. Login as an Admin");
            System.out.println("3. Signup");
            System.out.println("4. Exit");
            int command = scanner.nextInt();

            if (command == 1) {
                system.handleExistingCustomer();
            } else if (command == 2) {
                System.out.print("Enter the secret key: ");
                String key = scanner.next();
                if (!key.equals("123456")) {
                    continue;
                }

                System.out.println("1. Add Theatre");
                System.out.println("2. Add Show");
                System.out.println("3. Delete Theatre");
                System.out.println("4. Delete Movie");
                System.out.println("5. Delete Show");
                int adminCommand = scanner.nextInt();

                if (adminCommand == 1) {
                    System.out.print("Enter Theatre Name: ");
                    String name = scanner.next();
                    System.out.print("Enter Location: ");
                    String location = scanner.next();
                    System.out.print("Enter City: ");
                    String city = scanner.next();
                    System.out.print("Enter Capacity: ");
                    int capacity = scanner.nextInt();
                    System.out.print("Enter Owner Name: ");
                    String ownerName = scanner.next();
                    System.out.print("Enter Number of Rows: ");
                    int rows = scanner.nextInt();
                    System.out.print("Enter Number of Columns: ");
                    int columns = scanner.nextInt();

                    system.addTheatre(name, location, city, capacity, ownerName, rows, columns);
                } else if (adminCommand == 2) {
                    System.out.print("Enter Theatre Name: ");
                    String theatreName = scanner.next();
                    System.out.print("Enter Movie Name: ");
                    String movieName = scanner.next();
                    System.out.print("Enter Start Time (Hour Minute): ");
                    int startHour = scanner.nextInt();
                    int startMinute = scanner.nextInt();
                    System.out.print("Enter End Time (Hour Minute): ");
                    int endHour = scanner.nextInt();
                    int endMinute = scanner.nextInt();
                    System.out.print("Enter Date (Day Month Year): ");
                    int day = scanner.nextInt();
                    int month = scanner.nextInt();
                    int year = scanner.nextInt();
                    System.out.print("Enter Language: ");
                    String language = scanner.next();
                    System.out.print("Enter Cast: ");
                    String cast = scanner.next();
                    System.out.print("Enter Rating: ");
                    String rating = scanner.next();
                    System.out.print("Enter Overview: ");
                    String overview = scanner.next();

                    system.addShow(theatreName, movieName, startHour, startMinute, endHour, endMinute, day, month, year,
                                   language, cast, rating, overview);
                } else if (adminCommand == 3) {
                    System.out.print("Enter Theatre Name: ");
                    String theatreName = scanner.next();
                    system.deleteTheatre(theatreName);
                } else if (adminCommand == 4) {
                    System.out.print("Enter Movie Name: ");
                    String movieName = scanner.next();
                    system.deleteMovie(movieName);
                } else if (adminCommand == 5) {
                    System.out.print("Enter Theatre Name: ");
                    String theatreName = scanner.next();
                    System.out.print("Enter Start Time (Hour Minute): ");
                    int startHour = scanner.nextInt();
                    int startMinute = scanner.nextInt();
                    system.deleteShow(theatreName, startHour, startMinute);
                }
            } else if (command == 3) {
                system.addNewCustomer();
            } else if (command == 4) {
                system.save(); // Save data before exiting
                break;
            }
        }
        scanner.close();
    }

}
