#include <iostream>
#include <stack>

int main () {
    std::stack<std::string> s;

    s.push("Book_1");
    s.push("Book_2");
    s.push("Book_3");

    // casting the original stack [Preserve]
    std::stack<std::string> temp = s;

   while (!temp.empty()) {
    std::cout << temp.top() << " ";
    temp.pop();
   }
   
    return 0;
}


/*
    The only way to iterate over stack is to use ---> while loop
    * Stack does not supports for loop iteration ie (index bassed)
            |-> also iterators
    * Stack use conditional iteration


    // Iterators usually supports the containers which have the begin and end method
*/