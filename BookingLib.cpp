#include "core.cpp"

JNIEXPORT void JNICALL Java_BookingSystem_addTheatre(JNIEnv *env,jobject obj,jstring name,jstring location,jstring city,jint capacity,jstring ownerName,jint rows,jint columns){

    const char *cname=env->GetStringUTFChars(name,0);
    const char *cLocation=env->GetStringUFChars(location,0);
    const char *cCity=env->GetStringUTFChars(city,0);
    const char *cOwnerName=env->GetStringUTFChars(ownerName,0);

    Admin admin;
    admin.add_theatre(cName,cLocation,cCity,capacity,cOwnerName,rows,columns);

    env->ReleaseStringUTFChars(name,cName);
    env->ReleaseStringUTFChars(location,cLocation);
    env->ReleaseStringUTFChars(city,cCity);
    env->ReleaseStringUTFChars(ownerName,cOwnerName);
}

JNIEXPORT void JNICALL Java_BookingSystem_addShow(JNIEnv *env, jobject obj,
                                                  jstring theatreName, jstring movieName, jstring language,jint startHour,jint startMinute,jint endHour,jint endMinute,jstring cast,jstring rating,jstring overview){
    const char *cTheatreName = env->GetStringUTFChars(theatreName, 0);
    const char *cMovieName = env->GetStringUTFChars(movieName, 0);
    const char *cLanguage = env->GetStringUTFChars(language, 0);
    const char *cCast = env->GetStringUTFChars(cast, 0);
    const char *cRating = env->GetStringUTFChars(rating, 0);
    const char *cOverview = env->GetStringUTFChars(overview, 0);

    Admin admin; 

    admin.add_show(cTheatreName, cMovieName, startHour,startMinute,endHour,endMinute,cCast,cRating,cOverview);

    env->ReleaseStringUTFChars(theatreName, cTheatreName);
    env->ReleaseStringUTFChars(movieName, cMovieName);
    env->ReleaseStringUTFChars(language, cLanguage);
    env->ReleaseStringUTFChars(cast, cCast);
    env->ReleaseStringUTFChars(rating, cRating);
    env->ReleaseStringUTFChars(overview, cOverview);

}

JNIEXPORT void JNICALL Java_BookingSystem_handleExistingCustomer(JNIEnv *env, jobject obj) {
    Booking_Manager manager;
    manager.handleExistingCustomer();

}

JNIEXPORT void JNICALL Java_BookingSystem_deleteShow(JNIEnv *env, jobject obj,jstring theatreName,jint startHour,jint startMinute){
    
    const char* cTheatreName=env->GetStringUTFChars(theatreName,0);
    string theatreNameCpp(cTheatreName);

    
    Admin admin;
    admin.delete_show(theatreNameCpp,startHour,startMinute);

    env->ReleaseStringUTFChars(theatreName,cTheatreName);
}

JNIEXPORT void JNICALL Java_BookingSystem_deleteMovie(JNIEnv *env,jobject obj,jstring movieName){
    const char* cmovieName=env->GetStringUTFChars(theatreName,0);
    
    Admin admin;
    admin.delete_movie(cmovieName);

    env->ReleaseStringUTFChars(cmovieName);
}
JNIEXPORT void JNICALL Java_BookingSystem_deleteTheatre(JNIEnv *env,jobject obj,jstring theatreName){
    const char* cTheatreName=env->GetStringUTFChars(theatreName,0);
    Admin admin;
    admin.delete_theatre(cTheatreName);
}

JNIEXPORT void JNICALL Java_BookingSystem_addNewCustomer(JNIEnv *env,jobject obj){
    Booking_Manager manager;
    manager.add_Customer();
}

JNIEXPORT void JNICALL Java_BookingSystem_handleExistingCustomer(JNIEnv *env,jobject obj){
    Booking_Manager manager;
    manager.handleExistingCustomer();
}

JNIEXPORT void JNICALL Java_BookingSystem_Start(JNIEnv *env,jobject obj){
    Start();
}

JNIEXPORT void JNICALL Java_BookingSystem_Save(JNIEnv *env,jobject obj){
    Save();
}



