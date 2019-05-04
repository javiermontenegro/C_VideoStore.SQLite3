#ifndef VIDEO_H
#define VIDEO_H

/*! \file video.h
 *  \brief Definitions for memory allocated entries.
 *
 *  The entry datatype supports the storage of attributes pertaining to
 *  entries from an video store, such as film name, production co,
 *  stars and story line.
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>
#include <sqlite3.h>

#define MAXLENGTH   512

   sqlite3 *db;
   char *zErrMsg;
   int rc;
   char sql[MAXLENGTH];

/*! \typedef video_t
 *  \brief Type definition for video store entries.
 */
struct video
{
  char film_name     [MAXLENGTH];        
  char production_co [MAXLENGTH];
  char director      [MAXLENGTH];         
  char stars         [MAXLENGTH];      
  char language      [MAXLENGTH];   
  char runtime       [MAXLENGTH];
  char country       [MAXLENGTH];
  char release_date  [MAXLENGTH];
  char story_line    [MAXLENGTH];
};
typedef struct video video_t;


/*! \fn bool add_entry(sqlite3* db, video_t* video)
 *  \brief Creates an entry.
 *  \return On success true.
 *  Otherwise false is returned and errno is set appropriately.
 */
extern bool add_entry(sqlite3* db, video_t* video);

/*! \fn  int display_entries(sqlite3* db)
 *  \brief Display entries.
 *  \return On success count of entries.
 *  Otherwise 0 is returned and errno is set appropriately.
 */
extern int display_entries(sqlite3* db);

/*! \fn bool delete_entry(const unsigned int index)
 *  \brief Delete an entry.
 *  \return On success true.
 *  Otherwise false is returned and errno is set appropriately.
 */
extern bool delete_entry(const unsigned int index);

/*! \fn bool edit_entry(const unsigned int index, const unsigned int field_option, video_t* video)
 *  \brief Edit an entry.
 *  \return On success true.
 *  Otherwise false is returned and errno is set appropriately.
 */
extern bool edit_entry(const unsigned int index, const unsigned int field_option, video_t* video);

/*! \fn  int find_entry(sqlite3* db, const char *film_name)
 *  \brief Find a entry.
 *  \return On success count of entries.
 *  Otherwise 0 is returned and errno is set appropriately.
 */
extern int find_entry(sqlite3* db, const char *film_name);

/*! \fn  int assert_credentials(sqlite3* db, const char *username, const char *password)
 *  \brief Find a entry.
 *  \return On success 1.
 *  Otherwise 0 is returned and errno is set appropriately.
 */
extern int assert_credentials(sqlite3* db, const char *username, const char *password);

#endif /* VIDEO_H */
