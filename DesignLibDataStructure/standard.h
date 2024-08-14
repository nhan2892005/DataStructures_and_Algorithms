#ifndef STANDARD_H
#define STANDARD_H

template <typename PHUCNHAN> void Swap(PHUCNHAN& a, PHUCNHAN& b) {
    PHUCNHAN temp = a;
    a = b;
    b = temp;
}
template <typename PHUCNHAN> PHUCNHAN Min(const PHUCNHAN& a, const PHUCNHAN& b) {
    return a < b ? a : b;
}
template <typename PHUCNHAN> PHUCNHAN Max(const PHUCNHAN& a, const PHUCNHAN& b) {
    return a > b ? a : b;
}
template <typename PHUCNHAN> PHUCNHAN Abs(const PHUCNHAN& a) {
    return a < 0 ? -a : a;
}
template <typename PHUCNHAN> PHUCNHAN GCD(PHUCNHAN a, PHUCNHAN b) {
    while (b != 0) {
        PHUCNHAN temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
template <typename PHUCNHAN> PHUCNHAN LCM(PHUCNHAN a, PHUCNHAN b) {
    return a / GCD(a, b) * b;
}

#endif