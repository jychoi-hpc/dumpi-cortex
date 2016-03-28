#ifndef CORTEX_DEBUG_H
#define CORTEX_DEBUG_H

#define HEADER(name) fprintf(stderr,"%s %s:%d ",name,__FILE__,__LINE__)

#define INFO(msg, ...) { HEADER("[INFO]"); fprintf(stderr, msg, ##__VA_ARGS__); }

#define WARN(msg, ...) { HEADER("[WARNING]"); fprintf(stderr, msg, ##__VA_ARGS__); }

#define ERROR(msg, ...) { HEADER("[ERROR]"); fprintf(stderr, msg, ##__VA_ARGS__); exit(-1); }

#define ASSERT(cond) if(!(cond)) { HEADER("[ASSERT]"); fprintf(stderr,"Assertion failed: %s\n", #cond); exit(-1); }

#endif
