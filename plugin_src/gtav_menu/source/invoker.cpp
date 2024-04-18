#include "invoker.h"
#include "imports.h"
int v_nt_counter;
void *nativesTableAddr;
NativeArg_s nativeArg;
u64 args[30];

void setVectors() {
	while (nativeArg.vectorCount) {
		nativeArg.vectorCount--;

		vector33* argVector = nativeArg.argVectors[nativeArg.vectorCount];
		vector44 tempVector = nativeArg.tempVectors[nativeArg.vectorCount];
		argVector->x = tempVector.x;
		argVector->y = tempVector.y;
		argVector->z = tempVector.z;
	}
}
char buffer2[255];
void callHash(u64 hash) {
((void(*)(NativeArg_s*))(hash + 0x400000))(&nativeArg);// native address + game base
}

void resetArgs() {
	nativeArg.argCount = 0;
	nativeArg.vectorCount = 0;
	nativeArg.argValues = nativeArg.returnValue = args;
}
