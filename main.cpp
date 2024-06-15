/*
 * @Author: Ivan Chichvarin ichichvarin@humanplus.ru
 * @Date: 2024-06-15 13:22:03
 * @LastEditors: Ivan Chichvarin ichichvarin@humanplus.ru
 * @LastEditTime: 2024-06-15 13:49:39
 * @FilePath: /optimiseUndefined/main.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <cstdint>
#include <iostream>
#include <optional>
#include <limits>

using namespace std;

template <typename T>
optional<T> SafeAdd(T a, T b) {
  if((a > 0)&&(b > 0)){
    if(a > std::numeric_limits<T>::max() - b){
        return (nullopt);
    }
  }else if((a < 0)&&(b < 0)){
    if(a < std::numeric_limits<T>::min() - b){
        return (nullopt);
    }
  }
  return (a + b);
} 

int main() {
    int64_t a;
    int64_t b;
    cin >> a >> b;
     auto res = SafeAdd(a, b);
    if (res.has_value()) {
        cout << res.value() << endl;
    }
    else {
        cout << "Overflow!" << endl;
    }
}