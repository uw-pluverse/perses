#include <jni.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include "afl_coverage_jni.h"

// AFL default setting
#define DEFAULT_PERMISSION 0600

JNIEXPORT jint JNICALL Java_org_perses_fuzzer_coveragecollector_AFLCoverageCollector_00024Companion_setupSharedMemory
 (JNIEnv *env, jobject caller, jint map_size)
{
    int shm_id = shmget(IPC_PRIVATE, map_size, IPC_CREAT | IPC_EXCL | DEFAULT_PERMISSION);
    return shm_id;
}

JNIEXPORT jobject JNICALL Java_org_perses_fuzzer_coveragecollector_AFLCoverageCollector_00024Companion_getSharedMemory
 (JNIEnv *env, jobject caller, jint shm_id, jint map_size)
{
    int *shm_ptr = (int*)shmat(shm_id, NULL, 0);
    return env->NewDirectByteBuffer(shm_ptr, map_size);
}

JNIEXPORT void JNICALL Java_org_perses_fuzzer_coveragecollector_AFLCoverageCollector_00024Companion_closeSharedMemory
 (JNIEnv *env, jobject caller, jint shm_id)
{
    shmctl(shm_id, IPC_RMID, NULL);
}
