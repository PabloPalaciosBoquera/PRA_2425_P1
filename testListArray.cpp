#include <iostream>
#include <stdexcept>
#include "ListArray.h"

int main() {
    ListArray<int> l;

    std::cout << l;
    std::cout << "size(): " << l.size() << "\n";
    std::cout << "empty(): " << std::boolalpha << l.empty() << "\n\n";

    l.prepend(0);
    l.prepend(-5);
    l.append(5);
    l.append(10);

    std::cout << l;
    std::cout << "size(): " << l.size() << "\n";
    std::cout << "empty(): " << std::boolalpha << l.empty() << "\n\n";

    std::cout << "l.get(0) => " << l.get(0) << "; l[0] => " << l[0] << "\n";
    std::cout << "l.get(3) => " << l.get(3) << "; l[3] => " << l[3] << "\n";

    std::cout << "l.remove(3) => " << l.remove(3) << ":\n";
    std::cout << "l.remove(1) => " << l.remove(1) << ":\n";
    std::cout << "l.remove(0) => " << l.remove(0) << ":\n\n";

    std::cout << l;
    std::cout << "size(): " << l.size() << "\n";
    std::cout << "empty(): " << std::boolalpha << l.empty() << "\n\n";

    l.prepend(33);
    l.append(14);
    std::cout << l;
    std::cout << "size(): " << l.size() << "\n";
    std::cout << "empty(): " << std::boolalpha << l.empty() << "\n";
    std::cout << "l.search(14) => " << l.search(14) << "\n";
    std::cout << "l.search(55) => " << l.search(55) << "\n";

    auto try_op = [&](const char* fn_desc, auto fn){
        try { fn(); }
        catch (const std::out_of_range& ex) {
            std::cout << fn_desc << " => std::out_of_range: " << ex.what() << "\n";
        }
    };

    try_op("l.insert(-1, 99)", [&]{ l.insert(-1, 99); });
    try_op("l.insert(4, 99)",  [&]{ l.insert(4, 99);  });
    try_op("l.get(-1)",        [&]{ (void)l.get(-1);   });
    try_op("l.get(3)",         [&]{ (void)l.get(3);    });
    try_op("l.remove(-1)",     [&]{ (void)l.remove(-1);} );
    try_op("l.remove(3)",      [&]{ (void)l.remove(3); } );

    return 0;
}
