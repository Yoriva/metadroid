// Fires only in a dedicated/listen-server context; the client gets dropped with
// a "Failed to init MM" path long before it needs us.
#include "precompiled.h"
#include "physint.h"

static int mm_SV_CreateEntity(edict_t *ent, const char *szName)
{
	if (!ent || !szName || !szName[0])
		return -1;

	auto fptr = (void (*)(entvars_t *))g_GameDLL.sys_module.getsym(szName);
	if (!fptr)
		return -1;

	fptr(&ent->v);
	return 0;
}

extern "C" int Server_GetPhysicsInterface(int version, server_physics_api_t *physics_api, physics_interface_t *table)
{
	if (version != SV_PHYSICS_INTERFACE_VERSION)
		return 0;
	if (!table)
		return 0;

	(void)physics_api;

	memset(table, 0, sizeof(*table));
	table->version = SV_PHYSICS_INTERFACE_VERSION;
	table->SV_CreateEntity = mm_SV_CreateEntity;

	return 1;
}
