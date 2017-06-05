// Main
#include <iostream>
#include "../include/DBHandler.h"

using namespace std;
using namespace pqxx;


int main(int argc, char* argv[])
{
    DB::SERVICES::DBHandler &dbHandlerInstance = DB::SERVICES::DBHandler::getInstance();
    string l_sqlQuerry = "SELECT * FROM get_player_data_function();";
    size_t querryCount = dbHandlerInstance.count(l_sqlQuerry);
    cout << "Querry count for get_player_data_function() = " << querryCount << endl;

    result results = dbHandlerInstance.querry(l_sqlQuerry);
    // Results can be accessed and iterated again. Even after the connection has been closed.
    for (auto row: results)
    {
        cout << "Row: ";
        // Iterate over fields in a row.
        for (auto field: row)
        {
            cout << field.c_str() << " ";
        }
        cout << endl;
    }
    dbHandlerInstance.commit();
    dbHandlerInstance.disconnect();
    return 0;
}

//clear && g++ DBHandler.cpp Functions.cpp Main.cpp -I/usr/local/include -L/usr/local/lib -lconfig++ -lpqxx -lpq -o dbhandler && ./dbhandler
