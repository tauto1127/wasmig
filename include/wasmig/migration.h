// include/example.h
#ifndef WASM_MIGRATION_H
#define WASM_MIGRATION_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdbool.h>
#include <sys/types.h>
#include <unistd.h>
#include <wasmig/utils.h>
#include <wasmig/state.h>
#include <wasmig/codepos.h>

#ifdef __cplusplus
extern "C" {
#endif

int wasmig_checkpoint_memory(uint8_t* memory, uint32_t cur_page);
int wasmig_checkpoint_memory_with_prefix(uint8_t* memory, uint32_t cur_page,
                                         const char *file_prefix);
int wasmig_checkpoint_global(uint64_t* values, uint32_t* types, int len);
int wasmig_checkpoint_global_with_prefix(uint64_t* values, uint32_t* types,
                                         int len, const char *file_prefix);
int wasmig_checkpoint_global_v2(TypedArray globals);
int wasmig_checkpoint_global_v2_with_prefix(TypedArray globals,
                                            const char *file_prefix);
int wasmig_checkpoint_pc(uint32_t func_idx, uint32_t offset);
int wasmig_checkpoint_pc_with_prefix(uint32_t func_idx, uint32_t offset,
                                     const char *file_prefix);
int wasmig_checkpoint_stack_v2(size_t size, BaseCallStackEntry *call_stack);
int wasmig_checkpoint_stack_v3(size_t size, BaseCallStackEntry *call_stack);
int wasmig_checkpoint_stack_v4(size_t size, CallStackEntry *call_stack);
int wasmig_checkpoint_stack_v4_with_prefix(size_t size,
                                           CallStackEntry *call_stack,
                                           const char *file_prefix);

Array8 wasmig_restore_memory();
Array8 wasmig_restore_memory_with_prefix(const char *file_prefix);
Array64 wasmig_restore_global(Array8 types);
Array64 wasmig_restore_global_with_prefix(Array8 types,
                                          const char *file_prefix);
TypedArray wasmig_restore_global_v2();
TypedArray wasmig_restore_global_v2_with_prefix(const char *file_prefix);
CodePos wasmig_restore_pc();
CodePos wasmig_restore_pc_with_prefix(const char *file_prefix);
CallStack wasmig_restore_stack();
CallStack wasmig_restore_stack_with_prefix(const char *file_prefix);

#ifdef __cplusplus
}
#endif

#endif
