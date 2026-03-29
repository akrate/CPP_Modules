#include "Serializer.hpp"

int main()
{
    Data da;
    da.id = 12;
    da.s1 = "oussama";
    da.s2 = "akrate";

    uintptr_t test =  Serializer::serialize(&da);

    Data *d = Serializer::deserialize(test);
    std::cout << d->id << "  " << d->s1 << "   " << d->s2 << std::endl;
}
