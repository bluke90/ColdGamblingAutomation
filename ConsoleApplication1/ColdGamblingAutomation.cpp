/*
* Name - ColdGamblingAutomation
* Language - C++
* Description - a simple C++ script to automatically send cold gambling discord bot commands while you are away from your computer
* Author - Blake Ganzerla
* Company - Proton Technologies LLC
* Copyright License - GNU General Public License (GNU GPL)
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <Windows.h>
#include <ctime>
#define Size 50

void PressKey(INPUT input);


int main()
{
    // declare vars
    int count = 0;
    bool donatorCmd;
    time_t now;

    // Console Header
    std::cout << "===============Cold Gambling Bot Automation===================\n";
    std::cout << "= Copyright 2023\n";
    std::cout << "= Author: Blake Ganzerla\n= Company: Proton Technologies LLC \n";
    std::cout << "==============================================================\n\n\n";
    
    // Donator Command
    std::cout << "Enable ' donator ' Command? (Y = yes|N = no):";
    std::string choice;
    std::cin >> choice;

    if (choice == "Y") {
        donatorCmd = true;
    } else {
        donatorCmd = false;
    }
    Sleep(500);

    // wait for enter key event
    std::cout << "Press any key to start...\n";
    std::cin.get();
    std::cin.get();


    // display start msg and sleep 5 sec
    std::cout << "Waiting 5 seconds to activate discord process\n";
    Sleep(5000);

    while (true) {
        INPUT input;

        // /donator
        if (donatorCmd) {
            std::cout << "Simulating Donator command\n";
            input.ki.wVk = VK_DIVIDE;
            PressKey(input);

            input.ki.wVk = 0x44;
            PressKey(input);

            input.ki.wVk = 0x4F;
            PressKey(input);
             
            input.ki.wVk = 0x4E;
            PressKey(input);

            input.ki.wVk = 0x41;
            PressKey(input);

            input.ki.wVk = 0x54;
            PressKey(input);

            input.ki.wVk = 0x4F;
            PressKey(input);

            input.ki.wVk = 0x52;
            PressKey(input);

            Sleep(1000);

            input.ki.wVk = VK_RETURN;
            PressKey(input);

            input.ki.wVk = VK_RETURN;
            PressKey(input);

            Sleep(3000);
        }

        // /fish
        std::cout << "Simulating Fish Command\n";
        input.ki.wVk = VK_DIVIDE;
        PressKey(input);

        input.ki.wVk = 0x46;
        PressKey(input);

        input.ki.wVk = 0x49;
        PressKey(input);

        input.ki.wVk = 0x53;
        PressKey(input);

        input.ki.wVk = 0x48;
        PressKey(input);

        Sleep(1000);

        input.ki.wVk = VK_RETURN;
        PressKey(input);

        input.ki.wVk = VK_RETURN;
        PressKey(input);

        Sleep(3000);

        // /mine
        std::cout << "Simulating Mine command\n";
        input.ki.wVk = VK_DIVIDE;
        PressKey(input);

        input.ki.wVk = 0x4D;
        PressKey(input);

        input.ki.wVk = 0x49;
        PressKey(input);

        input.ki.wVk = 0x4E;
        PressKey(input);

        input.ki.wVk = 0x45;
        PressKey(input);

        Sleep(1000);

        input.ki.wVk = VK_RETURN;
        PressKey(input);

        input.ki.wVk = VK_RETURN;
        PressKey(input);

        Sleep(3000);

        // /vote
        std::cout << "Simulating Vote command\n";
        input.ki.wVk = VK_DIVIDE;
        PressKey(input);
        input.ki.wVk = 0x56;
        PressKey(input);

        input.ki.wVk = 0x4F;
        PressKey(input);

        input.ki.wVk = 0x54;
        PressKey(input);

        input.ki.wVk = 0x45;
        PressKey(input);

        Sleep(1000);

        input.ki.wVk = VK_RETURN;
        PressKey(input);

        input.ki.wVk = VK_RETURN;
        PressKey(input);

        Sleep(3000);
        count++;
       

        // Get current time
        now = time(0);
        struct tm* tmp;
        char TIME_STR[Size];
        time(&now);

        tmp = localtime(&now);

        strftime(TIME_STR, sizeof(TIME_STR), "%I:%M%p", tmp);

        std::cout << "\nCommand set has been simulated  " << count << "  times, completed at - " << TIME_STR << "\n\n";

        Sleep(301000);
        
    }

}

void PressKey(INPUT in) {
    // Keyboard Setup
    in.type = INPUT_KEYBOARD;
    in.ki.wScan = 0;
    in.ki.dwExtraInfo = 0;
    
    // keypress event
    in.ki.dwFlags = 0;
    SendInput(1, &in, sizeof(INPUT));

    // Key up event
    in.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &in, sizeof(INPUT));

    return;
}
