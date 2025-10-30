#include <iostream>
#include <limits>

bool isPyth(unsigned a, unsigned b, unsigned c)
{
    unsigned max = (a > b ? a : b) > c ? (a > b ? a : b) : c;
    unsigned min = (a > b ? b : a) > c ? c : (a > b ? a : b);
    unsigned remain = a + b + c - max - min;
    max *= max;
    min *= min;
    remain *= remain;
    
    return (max == min + remain);
}

int main()
{
    unsigned a, b, c;
    unsigned max = std::numeric_limits<unsigned>::max();
    std::cout << std::numeric_limits<unsigned>::min();
    if (!(std::cin >> a >> b >> c)){
        return 1;
    }

    int cnt = 0;
    while(true){
        if (a > max / a || b > max / b || c > max / c || a + b > max - c){
            return 2; 
        }
        if(isPyth(a, b ,c)){ 
            cnt++;
        }
        a = b;
        b = c;
        if (!(std::cin >> c)){
            break;
        }
        if (std::cin.fail() && !std::cin.eof()){
            return 1;
        }
    }
    return cnt;
}