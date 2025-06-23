#ifndef UTILS_H
#define UTILS_H

int gcd (int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}



#endif // UTILS_H