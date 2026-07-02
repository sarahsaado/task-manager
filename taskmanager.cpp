#include "taskmanager.hpp"

Task::Task(const std::string & desc) {
    description = desc;
    status = "Not started";
}

std::string Task::getDescription() const {
    return description;
}

std::string Task::getStatus() const {
    return status;
}

void Task::setDescription(const std::string& desc) {
    description = desc;
}

void Task::setStatus(const std::string &stat) {
    status = stat;
}
