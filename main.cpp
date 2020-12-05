#include <iostream>
#include "tdttt_if.h"
#include "tdttt.h"

using namespace std;

int main()
{
    tdttt_if_init();
    tdttt_if_training();
    tdttt_if_play_against_human();

    return 0;
}
