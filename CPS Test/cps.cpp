#include <iostream>
#include <thread>
#include <atomic>
#include <chrono>
#include <conio.h>

std::atomic<bool> start_clicking(false);
std::atomic<bool> stop_clicking(false);
std::atomic<int> click_count(0);

void clickListener() {
    while (!start_clicking.load()) {
        std::this_thread::yield();
    }

    while (!stop_clicking.load()) {
        if (_kbhit() && _getch() == 13) {
            ++click_count;
        }
    }
}

int main() {
    std::cout << "Press Enter key as fast as you can for 10 seconds once you start." << std::endl;
    std::cout << "Press Enter to start..." << std::endl;
    std::cin.get();

    start_clicking.store(true);
    std::thread click_thread(clickListener);

    std::this_thread::sleep_for(std::chrono::seconds(10));

    stop_clicking.store(true);
    click_thread.join();

    int total_clicks = click_count.load();
    double click_speed = static_cast<double>(total_clicks) / 10.0;

    std::cout << "fin" << std::endl;
    std::cout << "Total clicks: " << total_clicks << std::endl;
    std::cout << "Click speed: " << click_speed << " cps" << std::endl;


    if (total_clicks <= 50) {
        std::cout << "-_-" << std::endl;
    } else if (total_clicks >= 51 && total_clicks <= 79) {
        std::cout << "yeah good!" << std::endl;
    } else if (total_clicks > 80) {
        std::cout << "terrific!" << std::endl;
    }

    std::this_thread::sleep_for(std::chrono::seconds(4));
    return 0;
}
