#ifndef JESH_EVENTTYPE_H_
#define JESH_EVENTTYPE_H_

// Event types are enumerated here so that they can be
// referred to specifically, for things like "listen for kMouseMove events"
typedef enum {
    kUnknownEvent,
    kMouseMove,
    kKeyPress,
    kKeyRelease,
    kNumEventTypes
} EventType;

#endif // JESH_EVENTTYPE_H_
