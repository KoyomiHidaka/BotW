#include <iostream>
#include <tgbot/tgbot.h>
#include <unordered_map>
#pragma execution_character_set("utf-8")


using namespace TgBot;
using namespace std;



int main()
{
    TgBot::Bot bot("7203022991:AAHgQgzs7g0scjPS1zX2xAzL_ZQpTwsie5Q");



































    

    // Блок запуска бота

    try {
        TgBot::TgLongPoll longPoll(bot);
        while (true) {
            cout << "Long poll started^^" << endl;
            longPoll.start();
        }
    }
    catch (TgBot::TgException& e) {
        cout << "error: " << e.what() << endl;
    }

    return 0;


}








