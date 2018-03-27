/*********************************/
/* Codu07                        */
/* Email: wtzhuque@163.com       */
/*********************************/

#include "engine.h"

#include <stdio.h>

namespace codu {

Engine::Engine() {
}

Engine::~Engine() {
}
    
int Engine::init() {
    fprintf(stderr, "init engine succ\n");
    return 0;
}

int Engine::destroy() {
    fprintf(stderr, "destroy engine succ\n");
    return 0;
}

int Engine::put(const std::string& key, const std::string& value) {
    return 0;
}

int Engine::get(const std::string& key, std::string* value) {
    return 0;
}

} // namespace codu
