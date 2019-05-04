#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h> 


int main(int argc, char* argv[]) {
   sqlite3 *db;
   char *zErrMsg = 0;
   int rc;
   char *sql;

   /* Open database */
   rc = sqlite3_open("video.db", &db);
   
   if( rc ) {
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      return(0);
   }//End if

   /* Create SQL statement */
   sql = "CREATE TABLE users("  \
      "id INT PRIMARY KEY NOT NULL," \
      "username       CHAR(50) NOT NULL," \
      "password       CHAR(50) NOT NULL);" \
      "CREATE TABLE videos(" \
      "id INTEGER PRIMARY KEY AUTOINCREMENT," \
      "film_name      CHAR(50) NOT NULL," \
      "production_co  CHAR(50)," \
      "director       CHAR(50)," \
      "stars          CHAR(50)," \
      "language       CHAR(50)," \
      "runtime        CHAR(50)," \
      "country        CHAR(50)," \
      "release_date   CHAR(50)," \
      "story_line     CHAR(250));" \
      "INSERT INTO users (id,username,password) " \
      "VALUES (1, 'admin', '12345');";

   /* Execute SQL statement */
   rc = sqlite3_exec(db, sql, 0, NULL, &zErrMsg);
   
   if( rc != SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   } else {
      fprintf(stdout, "Setup database successfully\n");
   }//End if

   sqlite3_close(db);
   return 0;
}//End main