//
// Created by Dana on 20.03.2020.
//

#ifndef SCHEDULER_IDGENERATOR_H
#define SCHEDULER_IDGENERATOR_H

#include <deque>

using ID = unsigned int;

class IDGenerator {
    static ID getID();
    static std::deque<ID> idPool;
    ID nextID;
    ID lastID;
};


#endif //SCHEDULER_IDGENERATOR_H
