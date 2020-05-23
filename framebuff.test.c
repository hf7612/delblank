#include <stdio.h>
class l
{
private:
    /* data */
public:
    l(/* args */);
    ~l();
    void y(){ printf(" feefgg ");}
};

l::l(/* args */)
{
    printf(" aaaaaaaaa ");
}

l::~l()
{
}

int main()
{
    l l1;
    l1.y();
}