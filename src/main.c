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
}

void createConnection(ConnInfo* info) {
  MYSQL *conn = mysql_init(NULL);
  if(!mysql_real_connect(info->conn,  info->server,  info->user,  info->password,  info->database,  0,  NULL,  0 )) {
    fprintf(stderr, "%s\n", mysql_error(conn));
  }
  info->conn = conn;
}

main() {
  ConnInfo info;
  MYSQL_RES *res;
  MYSQL_ROW *row;

  initInfo(&info);
  createConnection(&info);

  mysql_query(info.conn, "select * from user_table");
  res = mysql_use_result(info.conn);

  while((row = mysql_fetch_row(res))) {
     printf(row[0]);
  }

  mysql_free_result(res);
  mysql_close(info.conn);
}
