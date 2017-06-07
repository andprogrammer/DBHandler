# DBHandler
DBHandler for postgresql RDBMS.

#Required libraries:

1) libconfig++

sudo apt-get install libconfig++-dev

2) libpqxx

sudo apt-get install libpqxx-4.0v5

3) postgresql

sudo apt-get install postgresql postgresql-contrib

#Compilation:

clear && g++ DBHandler.cpp Functions.cpp Main.cpp -I/usr/local/include -L/usr/local/lib -lconfig++ -lpqxx -lpq -o dbhandler && ./dbhandler

#Import sql dump:

psql -U [user] -h [host] [dbname] < mydbDump.sql
