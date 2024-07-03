#include <iostream>
#include <tgbot/tgbot.h>
#include <unordered_map>
#include <chrono>
#include <ctime>
#pragma execution_character_set("utf-8")


using namespace TgBot;
using namespace std;



int main()
{
    TgBot::Bot bot("7203022991:AAHgQgzs7g0scjPS1zX2xAzL_ZQpTwsie5Q");





    bot.getEvents().onCommand("start", [&bot](Message::Ptr message) {



        // if button1 pressed
        auto now = chrono::system_clock::now();
        auto futureTime = now + chrono::hours(4) + chrono::minutes(30);
        auto duration = chrono::duration_cast<chrono::milliseconds>(futureTime - now).count();
        this_thread::sleep_for(std::chrono::milliseconds(duration));
        bot.getApi().sendMessage(message->chat->id, "TEST");



    });





   


    

















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








