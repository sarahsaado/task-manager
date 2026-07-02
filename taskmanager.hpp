#ifndef TASKMANAGER_HPP
#define TASKMANAGER_HPP
#include <string>

class Task {
private:
  //our class variables
  std::string description;
  std::string status;
public:
  //our constructor automatically sets the traits of the tasks
  Task(const std::string & desc);

  //getters - returns information form inside the object
  std::string getDescription() const;
  std::string getStatus() const;

  //setters - updates/changes information in the object
  void setDescription(const std::string & desc);
  void setStatus(const std::string & stat);

};

#endif