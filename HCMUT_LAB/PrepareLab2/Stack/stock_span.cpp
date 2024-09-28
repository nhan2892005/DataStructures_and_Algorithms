/*
The stock span problem is a financial problem where we have a series of daily price quotes for a stock and we need to calculate the span of the stock’s price for each day.

The span Si of the stock’s price on a given day i is defined as the maximum number of consecutive days just before the given day, for which the price of the stock on the current day is less than its price on the given day, plus 1 (for itself).

For example: take the stock's price sequence [100, 80, 60, 70, 60, 75, 85]. (See image above)

The given input span for 100 will be 1, 80 is smaller than 100 so the span is 1, 60 is smaller than 80 so the span is 1, 70 is greater than 60 so the span is 2 and so on.

Hence the output will be [1, 1, 1, 2, 1, 4, 6].



Requirement. Write a program to calculate the spans from the stock's prices.

Input. A list of whitespace-delimited stock's prices read from standard input.

Output. A list of space-delimited span values printed to standard output.
*/

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> stockSpan(vector<int> prices) {
    stack<int> s;
    vector<int> res(prices.size(), 1);
    for(int i = 0; i < prices.size(); i++){
        while(!s.empty() && prices[s.top()] <= prices[i]){
            res[i] += 1;
            s.pop();
        }
        s.push(i);
    }
    return res;
}