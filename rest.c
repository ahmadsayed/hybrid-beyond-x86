/**
 * rest.c
 * Small Rest API that read Mysql DB
 * to compile with gcc, run the following command
 * sudo apt install default-libmysqlclient-dev
 * sudo apt install libulfius-dev uwsc
 * gcc rest.c -o rest  -L/usr/lib/`uname -m`-linux-gnu/libulfius.so -lulfius  `mysql_config --cflags --libs`
 */
#include <stdio.h>
#include <ulfius.h>
#include <mysql.h>
#include <string.h>
#include <unistd.h>
#define PORT 8080

void finish_with_errors(MYSQL *con, struct _u_response * response) {
  printf("%s\n", mysql_error(con));
  mysql_close(con);
  ulfius_set_string_body_response(response, 500, "DB Connection Error");

}
/**
 * Callback function for the web application on /helloworld url call
 */
int callback_hello_world (const struct _u_request * request, struct _u_response * response, void * user_data) {
  MYSQL *con = mysql_init(NULL);
  if(con == NULL) {
    printf("%s\n", mysql_error(con));
    ulfius_set_string_body_response(response, 500, "DB Connection Error");
    return U_CALLBACK_CONTINUE;
  }
  if (mysql_real_connect(con, "mysql-svc", "ahmed", "Abc2020$Abc2020$", "14in4", 0, NULL, 0) == NULL) {
    printf("%s\n", mysql_error(con));
    mysql_close(con);
    ulfius_set_string_body_response(response, 500, "DB Connection Error");
    return U_CALLBACK_CONTINUE;
  }
  if (mysql_query(con, "SELECT offering_id, L30_, Offering_Portfolio, Theme  FROM offering")) {
    finish_with_errors(con, response);
    return  U_CALLBACK_CONTINUE;
  }
  MYSQL_RES *result = mysql_store_result(con);
  if (result == NULL) {
    finish_with_errors(con, response);
    return U_CALLBACK_CONTINUE;
  }
  int num_fields = mysql_num_fields(result);
  char *headers[num_fields];
  MYSQL_FIELD *field;
  unsigned int name_field;
  char *field_name = "name";
  for(unsigned int i = 0; (field = mysql_fetch_field(result)); i++) {
    headers[i] = field->name;
    if (strcmp(field_name, headers[i]) == 0) {
        name_field = i;
    }
  }

  MYSQL_ROW row;
  int row_count = 0;
  char buffer[999999];
  buffer[0] = '\0';
  strcat(buffer,"[");
  while((row = mysql_fetch_row(result))) {
    if (row_count !=0) {
      strcat(buffer,",");
    }
    row_count++;
    strcat(buffer, "{");
    char row_buff[255];
    sprintf(row_buff, "\"%s\":\"%s\"", headers[0], row[0] ? row[0] : "NULL");
    strcat(buffer, row_buff);
    for (int i=1; i < num_fields; i++) {
      char rows_buff[255];
      sprintf(rows_buff, ",\"%s\":\"%s\"", headers[i],row[i] ? row[i] : "NULL");
      strcat(buffer, rows_buff);
    }
    strcat(buffer, "}\n");
  }
  strcat(buffer,"]");
  mysql_free_result(result);
  ulfius_set_string_body_response(response, 200, buffer);
  mysql_close(con);
  return U_CALLBACK_CONTINUE;
}

/**
 * main function
 */
int main(void) {
  struct _u_instance instance;

  // Initialize instance with the port number
  if (ulfius_init_instance(&instance, PORT, NULL, NULL) != U_OK) {
    fprintf(stderr, "Error ulfius_init_instance, abort\n");
    return(1);
  }

  // Endpoint list declaration
  ulfius_add_endpoint_by_val(&instance, "GET", "/offering", NULL, 0, &callback_hello_world, NULL);

  // Start the framework
  if (ulfius_start_framework(&instance) == U_OK) {
    printf("Start framework on port %d\n", instance.port);

    // Wait for the user to press <enter> on the console to quit the application
    while (1) sleep(1);
  } else {
    fprintf(stderr, "Error starting framework\n");
  }
  printf("End framework\n");

  ulfius_stop_framework(&instance);
  ulfius_clean_instance(&instance);

  return 0;
}
  
