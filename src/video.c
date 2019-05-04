#include <video.h>

/*! \file video.c
 *  \brief Definitions for memory allocated entries.
 *
 *  Definition functions for data entries.
 */


bool add_entry(sqlite3* db, video_t* video)
{

   rc = sqlite3_open("video.db", &db);
   
   if( rc ) {
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      return false;
   }//End if

    sprintf(sql, "INSERT INTO videos (film_name, production_co, director, " \
            "stars, language, runtime, country, release_date, story_line) " \   
            "VALUES ('%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s')",
            video->film_name, video->production_co, video->director,
            video->stars, video->language, video->runtime, video->country,
            video->release_date, video->story_line);

   rc = sqlite3_exec(db, sql, 0, NULL, &zErrMsg);
   
   if( rc != SQLITE_OK ) {
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
      sqlite3_close(db);
      return false;
   }//End if

   sqlite3_close(db);
    return true;
}/* end add entry */


int display_entries(sqlite3* db)
{
   unsigned int c;

   int callback(void *data, int argc, char **argv, char **azColName){
     c = 0;
     for(int i = 0; i<argc; i++){
       printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
       c++; 
     }   
     printf("\n");   
     return 0;
   }

   rc = sqlite3_open("video.db", &db);
   if( rc ) {
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      return 0;
   }//End if

   rc = sqlite3_exec(db, "SELECT * FROM videos", callback, NULL, &zErrMsg);
   
   if( rc != SQLITE_OK ) {
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
      sqlite3_close(db);
      return 0;
   }//End if

   sqlite3_close(db);
   return c;
} /* end display entries */


bool delete_entry(const unsigned int index)
{
   rc = sqlite3_open("video.db", &db);
   if( rc ) {
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      return false;
   }//End if
    
   sprintf(sql, "DELETE FROM videos WHERE id = %d", index);
   rc = sqlite3_exec(db, sql, 0, NULL, &zErrMsg);
   
   if( rc != SQLITE_OK ) {
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
      sqlite3_close(db);
      return false;
   }//End if

   sqlite3_close(db);
   return true;
}/* end delete entry */

bool edit_entry(const unsigned int index, const unsigned int field_option, video_t* video){

    switch( field_option )
      {
        case 1:
          {
            sprintf(sql, "UPDATE videos SET film_name = '%s' WHERE id=%d", 
              video->film_name, index);
          } break;
        case 2:
          {
            sprintf(sql, "UPDATE videos SET production_co = '%s' WHERE id=%d", 
              video->production_co, index);
          } break;
        case 3:
          {
            sprintf(sql, "UPDATE videos SET director = '%s' WHERE id=%d", 
              video->director, index);
          } break;
        case 4:
          {
            sprintf(sql, "UPDATE videos SET stars = '%s' WHERE id=%d", 
              video->stars, index);
          } break;
        case 5:
          {
            sprintf(sql, "UPDATE videos SET language = '%s' WHERE id=%d", 
              video->language, index);
          } break;
        case 6:
          {
            sprintf(sql, "UPDATE videos SET runtime = '%s' WHERE id=%d", 
              video->runtime, index);
          } break; 
        case 7:
          {
            sprintf(sql, "UPDATE videos SET country = '%s' WHERE id=%d", 
              video->country, index);
          } break;
        case 8:
          {
            sprintf(sql, "UPDATE videos SET release_date = '%s' WHERE id=%d", 
              video->release_date, index);
          } break; 
        case 9:
          {
            sprintf(sql, "UPDATE videos SET story_line = '%s' WHERE id=%d", 
              video->story_line, index);
          } break;                                                         
   }//End switch 

   rc = sqlite3_open("video.db", &db);
   
   if( rc ) {
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      return false;
   }//End if

   rc = sqlite3_exec(db, sql, 0, NULL, &zErrMsg);
   
   if( rc != SQLITE_OK ) {
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
      sqlite3_close(db);
      return false;
   }//End if

   sqlite3_close(db);
    return true;
}/* end edit entry */


int find_entry(sqlite3* db, const char *film_name)
{
   unsigned int c;

   int callback(void *data, int argc, char **argv, char **azColName){
     c = 0;
     for(int i = 0; i<argc; i++){
       printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
       c++; 
     }   
     printf("\n");   
     return 0;
   }

   rc = sqlite3_open("video.db", &db);
   if( rc ) {
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      return 0;
   }//End if

   sprintf(sql, "SELECT * FROM videos WHERE film_name LIKE '%s'", film_name);

   rc = sqlite3_exec(db, sql, callback, NULL, &zErrMsg);
   
   if( rc != SQLITE_OK ) {
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
      sqlite3_close(db);
      return 0;
   }//End if

   sqlite3_close(db);
    return c;
} /* end find entry */


int assert_credentials(sqlite3* db, const char *username, const char *password)
{
   unsigned int k;
   const char* data = "Verify login credentials\n";

   int callback(void *data, int argc, char **argv, char **azColName){
     
   fprintf(stderr, "%s: ", (const char*)data);
   k = (int) strtol(argv[0], NULL, 10);     
   
   return 0;
}

   rc = sqlite3_open("video.db", &db);
   
   if( rc ) {
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      return(0);
   }//End if

   sprintf(sql, "SELECT COUNT(*) AS resp FROM videos WHERE username LIKE '%s' AND password LIKE '%s'", username, password);

   /* Execute SQL statement */
   rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);
   
   if( rc != SQLITE_OK ) {
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   }//End if
   sqlite3_close(db);

   return k;
}//End assert credentials

