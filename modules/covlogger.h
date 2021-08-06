#ifndef COVLOGGER_H
#define COVLOGGER_H

#include <cstdio>

#define COVERAGE_LOG_TOKEN EntryRaiiObject obj ## __LINE__ (__PRETTY_FUNCTION__);

struct EntryRaiiObject {
  EntryRaiiObject(const char *f) : f_(f) { printf("Entered into %s", f_); }
  ~EntryRaiiObject() { printf("Exited from %s", f_); }
  const char *f_;
};

#endif