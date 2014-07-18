#include <mysql.h>
#include <stdio.h>

typedef struct ConnInfo {
  MYSQL* conn;
  char* server;
  char* user;
  char* password;
  char* database;
} ConnInfo;

void initInfo(ConnInfo *info) {
  info->server = "localhost";
  info->user = "root";
  info->password = "1234";
  info->database = "db_aiadoc";

//   fprintf(stdout, "%s\n", info->server);
//   fprintf(stdout, "%s\n", info->user);
//   fprintf(stdout, "%s\n", info->password);
//   fprintf(stdout, "%s\n", info->database);
}

void createConnection(ConnInfo *info) {
  MYSQL *conn = mysql_init(NULL);
  int ok = mysql_real_connect(conn, info->server, info->user, info->password, info->database, 0, NULL, 0);
  if(!ok) {
    fprintf(stderr, "%s", mysql_error(conn));
  }
  info->conn = conn;
}

int main() {

  ConnInfo info;
  MYSQL_RES *result;
  MYSQL_ROW *row;
  MYSQL_FIELD *field;

  initInfo(&info);
  createConnection(&info);

  mysql_query(info.conn, "select * from user_table");
  result = mysql_use_result(info.conn);

  while((row = mysql_fetch_row(result)) != NULL) {

    printf("\n");
    printf("id|%s\n", row[0] ? row[0] : "NULL");
    printf("name|%s\n", row[1] ? row[1] : "NULL");
    printf("pass|%s\n", row[2] ? row[2] : "NULL");
  }

//   mysql_free_result(result);
//   mysql_close(info.conn);

  return 0;
}
