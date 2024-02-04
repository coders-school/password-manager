#include <string>

#include "PasswordManager.h"
#include "DataBase/DataBaseHandler.hpp"
#include "DataBase/DataBaseCommon.hpp"

int main()
{
    std::string password = "haslo";
    PasswordManager passwordManager(password);

    try
    {
        DataBaseHandler dataBaseHandler(DataBaseCommon::dataBasePath);

        std::cout << "Db is working" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Error occured" << std::endl;
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}