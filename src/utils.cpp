#include "wasmig/utils.h"
#include <fcntl.h>
#include <unistd.h>
#include <cstdio>
#include <string>
#include <spdlog/spdlog.h>

FILE* open_image(const char* file, const char* flag) {
    FILE *fp = fopen(file, flag);
    if (fp == NULL) {
        spdlog::error("faield to open file: {}", file);
        return NULL;
    }
    return fp;
}

FILE* open_image_with_prefix(const char* file, const char* flag,
                             const char *file_prefix) {
    if (!file_prefix || file_prefix[0] == '\0') {
        return open_image(file, flag);
    }

    std::string path = std::string(file_prefix) + file;
    return open_image(path.c_str(), flag);
}

int is_page_dirty(uint64_t pagemap_entry) {
    return (pagemap_entry>>62&1) | (pagemap_entry>>63&1);
}

int is_page_soft_dirty(uint64_t pagemap_entry) {
    return (pagemap_entry >> 55 & 1);
}
