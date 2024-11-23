public class BookingSystem {
    static {
        System.loadLibrary("BookingLib");
    }

    // Native methods
    public native void addTheatre(String name, String location, String city, int capacity, String ownerName, int rows, int columns);
    public native void handleExistingCustomer();
    public native void addShow(String theatreName, String movieName, String language, int startHour, int startMinute, int endHour, int endMinute, String cast, String rating, String overview);
    public native void delete_theatre(String theatre_name);
    public native void delete_movie(String movie_name);
    public native void delete_show(String theatre_name,int Start_hour,int Start_minute);
    public native void add_NewCustomer();
    public native void start();
    public native void end();

    public static void main(String[] args) {
        BookingSystem system = new BookingSystem();

        // Call the native method
        system.addTheatre("PVR Cinemas", "Downtown", "Metropolis", 500, "John Doe", 10, 20);
    }
}
