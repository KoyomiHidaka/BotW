#include <iostream>
#include <tgbot/tgbot.h>
#include <unordered_map>
#pragma execution_character_set("utf-8")

bool inRunning = true;
using namespace TgBot;
using namespace std;

const int64_t adminid = 869613280;


int main()
{
    int startingi = 1;
    Bot bot("7203022991:AAHgQgzs7g0scjPS1zX2xAzL_ZQpTwsie5Q");
    bot.getEvents().onCommand("start", [&bot](Message::Ptr message) {
        ReplyKeyboardMarkup::Ptr keyboard(new ReplyKeyboardMarkup);
        KeyboardButton::Ptr button1(new KeyboardButton);
        button1->text = "Начать";
        KeyboardButton::Ptr button2(new KeyboardButton);
        button2->text = "Взять перерыв";
        keyboard->keyboard.push_back({ button1, button2 });
        keyboard->oneTimeKeyboard = true;
        bot.getApi().sendMessage(message->chat->id, "Кнопка начать - начнет отчет проведенного времени работы\n Кнопка стоп - Приостановит время и начнет новый таймер отдыха", false, 0, keyboard);
        });
    int64_t lastUpdateId = 0;
    vector<Update::Ptr> updates = bot.getApi().getUpdates();
    for (const auto& update : updates) {
        if (update->updateId > lastUpdateId) {
            lastUpdateId = update->updateId;
        }
    }






    bot.getEvents().onCommand("stop", [&bot, &startingi](Message::Ptr message) {
        if (message->from->id == adminid) {
            bot.getApi().sendMessage(message->chat->id, "Программа приостановила свою работу...!");
            system("exit");
            startingi = 2;
        }
        else {
            bot.getApi().sendMessage(message->chat->id, "У вас недостаточно прав для совершения данной операции");
        }
        });

    try {
        printf("Bot username: %s\n", bot.getApi().getMe()->username.c_str());
        TgLongPoll longPoll(bot, 60, lastUpdateId + 1);
        while (inRunning) {
            auto updates = bot.getApi().getUpdates(lastUpdateId + 1);
            for (auto& update : updates) {
                lastUpdateId = update->updateId;
            }
            if (startingi == 2) {
                break;
            }
            printf("Long poll started\n");
            longPoll.start();
        }
    }
    catch (TgException& e) {
        printf("error: %s\n", e.what());
    }
    return 0;
}








