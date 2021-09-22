
#include "stack.hpp"

int main() 
{
    RECREATE_DUMP_STACK_FILE

	Stack::Stack test_stck("stck3", 5);
    
    test_stck.push(5);

    test_stck.dump();

    return 0;
}
