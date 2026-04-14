#include <iostream>
#include <vector>

/* Returns highest temperature,
   or -1 if no temperatures given. */
int findPeakHeat(const std::vector<int>& temps) {
    // Write your implementation here.
}

int main() {
    // High temperatures forecast for the next 7 days.
    std::vector<int> weeklyForecast = {62, 63, 65, 68, 69, 66, 65};

    std::cout << "--- Weather Report ---" << std::endl;
    std::cout << "Max temp this week will be " << findPeakHeat(weeklyForecast) << std::endl;
    return 0;
}