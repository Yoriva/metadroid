#pragma once

// We're not including the DBG_EntOfVars and DBG_AssertFunction routines
// mentioned in the SDK util.h, so we're going to unset DEBUG here so that
// we don't get "unresolved symbol" errors.
#ifdef DEBUG
#undef DEBUG
#endif

// Inlcude local enginecallbacks wrapper *first* so that the g_engfuncs
// type is correct and the <enginecallback.h> header protection is already
// defined.
#include "enginecallbacks.h"
#ifndef ACTIVITY_H
#include <util.h>
#endif // ACTIVITY_H

char* UTIL_VarArgs(const char* format, ...);
void UTIL_HudMessage(edict_t* pEntity, const hudtextparms_t& textparms, const char* pMessage);

#if defined(AMX_NOPROPLIST)
inline int ENTINDEX(const edict_t *pEdict) {
	return (*g_engfuncs.pfnIndexOfEdict)(pEdict);
}
#endif

inline char* ENTITY_KEYVALUE(edict_t *entity, char *key) {
	return(INFOKEY_VALUE(GET_INFOKEYBUFFER(entity), key));
}

inline void ENTITY_SET_KEYVALUE(edict_t *entity, char *key, char *value) {
	SET_CLIENT_KEYVALUE(ENTINDEX(entity), GET_INFOKEYBUFFER(entity), key, value);
}

inline char* SERVERINFO(char *key) {
	return(ENTITY_KEYVALUE(INDEXENT(0), key));
}

inline void SET_SERVERINFO(char *key, char *value) {
	SET_SERVER_KEYVALUE(GET_INFOKEYBUFFER(INDEXENT(0)), key, value);
}

inline char* LOCALINFO(char *key) {
	return(ENTITY_KEYVALUE(NULL, key));
}

inline void SET_LOCALINFO(const char *key, const char *value) {
	SET_SERVER_KEYVALUE(GET_INFOKEYBUFFER(NULL), (char *)key, (char *)value);
}