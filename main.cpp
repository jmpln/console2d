#include "display.h"
#include <vector>

int main() {

    Display disp;
    std::vector<Point2D> tr1 = {{20,5}, {20,10}, {30,10}},
                         tr2 = {{50,5}, {40,15}, {60,10}},
                         sq1 = {{70,5}, {80,5}, {80,10}, {70,10}},
                         sq2 = {{110,5}, {100,5}, {100,10}, {120,10}};

    disp.Draw(tr1);
    disp.Draw(tr2);
    disp.Draw(sq1);
    disp.Draw(sq2);

    disp.Show();
    return 0;
}

