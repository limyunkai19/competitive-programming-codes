// My implementation Floyd cycle finding algorithm
// Solve UVa problem: UVa 350 https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=286

#include <iostream>

using namespace std;

int base, offset, mod;
inline int next(int x) {
    return (x * base + offset) % mod;
}

// return 0-index of start, and cycle length
pair<int, int> floydCycleFinding(int start) {
    auto tortoise = start, hare = start;
    do {
        hare = next(next(hare));
        tortoise = next(tortoise);
    } while(tortoise != hare);


    // tortoise == hare now
    int cycleEntry = 0; hare = start;
    while(tortoise != hare) {
        hare = next(hare);
        tortoise = next(tortoise);
        cycleEntry++;
    }

    int cycleLength = 1; hare = next(hare);
    while(tortoise != hare) {
        hare = next(hare);
        cycleLength++;
    }

    return {cycleEntry, cycleLength};
}

int main() {
    int t = 0;
    while(++t) {
        int seed;
        cin >> base >> offset >> mod >> seed;
        if(base == 0 && offset == 0 && mod == 0 && seed == 0)
            return 0;

        cout << "Case " << t << ": " << floydCycleFinding(seed).second << '\n';
    }
    return 0;
}
