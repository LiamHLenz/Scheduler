#include <iostream>
#include "Core/Tasks/TaskManager.h"
#include "Core/Calendar/CalendarGenerator.h"

#include "boost/date_time/gregorian/gregorian.hpp"

int main() {


    //TODO: include asserts/error throwing
    //TODO: the way of creating and accessing tasks needs to be different
    TaskManager tm;

    auto ducks = tm.createProject("Ducks");
    auto roombas = tm.createProject("Roombas");

    auto dance = tm.createTask("make your statement, face your fear");
    auto release = tm.createTask("release the ducks", ducks);
    auto summon = tm.createTask("dummon", ducks);
    auto pet = tm.createTask("put laser on roomba", roombas);
    auto empower = tm.createTask("appease superintelligence", roombas);
    tm.testPrintTasks();

    tm.transferTask(summon, 2);
    tm.deleteTask(4);
    tm.deleteProject(1);
    tm.createTask("test", 0);
    tm.createProject("Program");

    tm.testPrintTasks();

    CalendarGenerator cG{};
    cG.createTimeslotRule(3, 16, 0, 30);
    cG.createTimeslotRule(5, 13, 15, 90);
    cG.createTimeslotRule(4, 14, 45, 120);
    cG.createTimeslotRule(4, 11, 0, 30);
    cG.printRules();
    Calendar calendar = cG.generateCalendar(boost::gregorian::date(2021, 01,01), boost::gregorian::date(2021, 01, 07));
    calendar.printTimeslots();


    //Scheduler scheduler {tm, calendar};
    //scheduler.schedule();
    //scheduler.printSchedule();


    return 0;
}