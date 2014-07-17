c : src/main.c
		gcc -o bin/mysqlclient $$(mysql_config --cflags) src/main.c $$(mysql_config --libs)
