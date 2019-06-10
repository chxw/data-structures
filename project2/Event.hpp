#ifndef EVENT_HPP
#define EVENT_HPP

#include <string>

class Event{
public:
  Event();
  Event(int day, int hour, int minute, std::string description);
  Event(const Event& other);
  Event& operator=(const Event& other);
  ~Event();

  bool startBefore(const Event* another) const;
  bool startAfter(const Event* another) const;
  bool startAtSameTime(const Event* another) const;

  bool startBefore(int day, int hour, int minute) const;
  bool startAfter(int day, int hour, int minute) const;
  bool startAt(int day, int hour, int minute) const;

  int getDay() const;
  int getHour() const;
  int getMinute() const;
  std::string getDescription() const;
  std::string toString() const;

private:
  int dd;
  int HH;
  int MM;
  std::string desc;
};

#endif
