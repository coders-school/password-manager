#include <string>

#include "PasswordManager.h"
#include "DataBase/DataBaseHandler.hpp"
#include "DataBase/DataBaseCommon.hpp"

int main()
{
    std::string password = "haslo";
    PasswordManager passwordManager(password);
    const std::vector<std::string> passwordValues{
        "1", "test", "test", "test", "test", "test", "test", "test", "Modify_Time", "Expiry_Time"};
    try
    {
        DataBaseHandler dataBaseHandler(DataBaseCommon::dataBasePath);
        std::cout << "dataBase is working" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Error occured" << std::endl;
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
