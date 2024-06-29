#include <iostream>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <ctime>

int main() {
    // random num
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    std::cout << "Be ready to press ENTER...\n";

    int waitTime = 2000 + (std::rand() % 3000);
    std::this_thread::sleep_for(std::chrono::milliseconds(waitTime));

    std::cout << "PRESS IT\n";

    // clock start
    auto start = std::chrono::high_resolution_clock::now();

    std::cin.get();
    // clock end
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> reactionTime = end - start;

    std::cout << "Your reaction time is " << reactionTime.count() << " milliseconds.\n";


    if (reactionTime.count() <= 250) {
        std::cout << "That is fast!\n";
    } else if (reactionTime.count() <= 324) {
        std::cout << "Yeah, good!\n";
    } else {
        std::cout << ":/\n";
    }

    std::this_thread::sleep_for(std::chrono::seconds(3));
    return 0;
}
